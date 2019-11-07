#include <iostream>
#include <map>
#include <cassert>
#include <vector>
#include <sstream>

using namespace std;

#include "semantics.h"
#include "parsetree.h"

Symtab *topScope = nullptr;
Symtab *currentScope = nullptr;
S_interface* currentInterface = nullptr;
S_class* currentClass = nullptr;
S_function* currentFunction = nullptr;
int currentSeq = 0;  // local variable counter
vector<semantics *> all_decls;  // during pass1, all declarations:  variables, functions, classes, interfaces.



void semantic_error(string msg, int line)
{
  std::cerr << "Semantic error: " << msg << " on line " << line << std::endl;
  exit(1);
}

void internal_error(string msg)
{
  std::cerr << "internal error: " << msg << std::endl;
  exit(2);
}

S_type *lookup_or_make_undefined_type(string type_name)
{
  /* Search topScope for semantics for type_name.  If not found at all,
     create an undefined type. If found and evaluates to a type, 
     return that.  If found and does not evaluate to a type, signal a 
     semantic error. */
  semantics *thing = topScope->lookup(type_name);
  if (thing == nullptr) {
    S_type *undef_type = new S_undefined;
    undef_type->name = type_name;
    undef_type->line = yylineno;
    return undef_type;
  }
  else if (dynamic_cast<S_type *>(thing)) 
    return dynamic_cast<S_type *>(thing);
  else
    semantic_error(type_name + " is not a type", yylineno);
}

S_type *get_real_type(string n, int line, Symtab *scope)  
{
  semantics *thing = scope->local_lookup(n);
  if (!thing)
    semantic_error("Type " + n + " undefined", line);
  S_type *real_type = dynamic_cast<S_type *>(thing);
  if (real_type)
    return real_type;
  else
    semantic_error(n + " is not a type ", line);
  // we'll never get here:
  return nullptr;
}

int get_line(ParseTree *tree)
{
  // find a token with a line number.  For now just traverse children[0]
  if (tree->token)
    return tree->token->line;
  return get_line(tree->children[0]);
}
/* 
string base_type_name(ParseTree *type_tree)
{
  if (type_tree->description=="array")
    return base_type_name(type_tree->children[0]);
  if (type_tree->description=="primtype" ||
      type_tree->description=="usertype")
    return type_tree->children[0]->token->text;
  internal_error("Type tree does not name a type" + type_tree->toString());
  return "";
}

bool is_primitive(string type_name)
{
  return type_name=="int" or
    type_name=="double" or
    type_name=="bool" or
    type_name=="string";
}

*/

// void ensure_type(ParseTree *type_tree, bool create_undefined=true)
// {
//   string base_name = base_type_name(type_tree);
//   if (is_primitive(base_name))
//     return;
//   semantics *definition = topScope->local_lookup(base_name);
//   if (definition and dynamic_cast<S_type *>(definition))  // dyn_cast is null on fail.
//     return;
//   if (definition) 
//     semantic_error("Type " + base_name + " is not a type.", get_line(type_tree));
//   if (create_undefined) {
//     S_type *new_type = new S_type();
//     new_type->name = base_name;
//     topScope->insert(base_name, new_type);
//   }
//   else
//     semantic_error("Type " + base_name + " undefined.", get_line(type_tree));
// }


Symtab::Symtab(Symtab *p) : parent(p) {}

semantics * Symtab::lookup(string key) { 
  semantics *answer;
  return 
    (answer = local_lookup(key)) ? answer : 
    parent ? parent->lookup(key) : nullptr;

}

semantics * Symtab::local_lookup(string key) { 
  return dict[key];
}

void Symtab::insert(string key, semantics * item) {
  assert (dict[key] == nullptr);
  replace(key, item);
}

void Symtab::replace(string key, semantics * item) {
  dict[key] = item;
}

string Symtab::to_string() {
  std::stringstream buf;
  buf << this;
  if (this->parent)
    buf << "<-" << this->parent;
  return buf.str();
}

void openscope()
{
  currentScope = new Symtab(currentScope);
}

Symtab *closescope()
{
  Symtab *v = currentScope;
  currentScope = currentScope->parent;
  return v;
}

