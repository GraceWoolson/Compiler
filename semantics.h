
#ifndef SEMANTICS
#define SEMANTICS

#include <map>
#include <set>

struct semantics;
extern set<semantics *> marked;  // used to avoid infinite recursion in cycles.

typedef map <string, semantics *> Dictionary;

struct Symtab {
  // A class to represent symbol tables
  // Chained togeher to represent nested scopes.
 public:
  Dictionary dict;
  int serial;
  static int next_serial;

  Symtab(Symtab *p);
  semantics * lookup(string key);
  semantics * local_lookup(string key);

  void ensure_undefined(string key, int line);  // semantic_error if key already defined
                                      // locally.
  void insert(string key, semantics * item);
  void replace(string key, semantics * item);
  string to_string();
  Symtab * parent;  // outer scope
};


void semantic_error(string msg, int line);
void internal_error(string msg);

struct semantics {
  // pure virtual function:
  virtual string to_string() = 0;
  // at least one pure virtual function makes the class abstract
  // (not instantiable.)
  virtual void replace_undefined(Symtab *) {
    if (marked.count(this)) return;
    marked.insert(this);
  }

  int line;  // line where this semantics object was created.
};

struct S_type : public semantics {
  string name; // usually a decaf symbol, but sometimes
  // a type.  name can't be void.
  virtual bool is_undefined() { return false; }
};

S_type *get_real_type(string n, int line, Symtab *scope);
S_type *lookup_or_make_undefined_type(string type_name);

struct S_variable : public semantics {
  string name;
  string genus;
  int seq_num;
  S_type * type;
  virtual string to_string() { return "S_variable(" + name + ": "
                                                    + type->to_string() + ")"; }
  virtual void replace_undefined(Symtab *scope) {
    if (marked.count(this)) return;
    marked.insert(this);
    if (type->is_undefined())
      type = get_real_type(type->name, line, scope);
    type->replace_undefined(scope);
  }
};

struct S_function : public semantics {
  virtual string to_string() { string print = "S_function "+name+" (";
    for (S_variable * f : formals)
      print += f->to_string() + " ";
    print += string(") -> ") + (returnType ? returnType->to_string() : string("VOID"));
    return print; }
  string name;
  vector<S_variable *> formals;
  S_type * returnType;  // NULL for a void function
  virtual void replace_undefined(Symtab *scope) {
    if (marked.count(this)) return;
    marked.insert(this);
    if (returnType) {
      if (returnType->is_undefined())
	returnType = get_real_type(returnType->name, line, scope);
      else
	returnType->replace_undefined(scope);
    }
    for (S_variable *v : formals)
      v->replace_undefined(scope);
  }
};

struct S_interface : public S_type {
  virtual string to_string() {
    string result = "S_interface "+ name + " ";
    //    for (S_function* f : functions)
    //  result += "Prototype: " + f->to_string() + " ";
    return result;
  }
  vector<S_function *> functions;
  virtual void replace_undefined(Symtab *scope) {
    if (marked.count(this)) return;
    marked.insert(this);
    for (S_function *f : functions)
      f->replace_undefined(scope);
  }
};

struct S_class : public S_type {
  S_class(string name, int line) { this->name = name; this->line = line;
                                   parentClass = nullptr; }
  virtual string to_string() {
    string printed = "S_class " + name
      + (parentClass ? " extends " + parentClass->name : "");
    if (interfaces.size() > 0) {
      printed += " implements ";
      for(S_type *i : interfaces)
	printed += i->name + " ";
    }
    //for (semantics * fld : fields)
    //  printed += " Field: " + fld->to_string() + " ";
    return printed;
  }

  // S_type is used in the following two fields because they might
  // be undefined during pass 1.  --aerc 10/24/2019
  S_type * parentClass;  // extends.
  vector<S_class *> inheritedClasses;
  vector<S_type *> interfaces; // implements.
  vector<semantics *> fields;  // each has to be S_function or S_variable
  virtual void replace_undefined(Symtab *scope) {
    if (marked.count(this)) return;
    marked.insert(this);
    if (parentClass and parentClass->is_undefined()) {
      S_type *type = get_real_type(parentClass->name, line, scope);
      S_class *cl = dynamic_cast<S_class *>(type);
      if (cl)
	parentClass = cl;
      else
	semantic_error(parentClass->name + " is not a class ", line);
    }
    for (size_t i = 0; i < interfaces.size(); i++) {
      S_type *intf = interfaces[i];
      S_type *type = get_real_type(intf->name, line, scope);
      if (not dynamic_cast<S_interface *>(type))
	semantic_error(intf->name + " is not an interface ", line);
      interfaces[i] = type;
      type->replace_undefined(scope);
    }

    // OLD:
    //for (S_type *i : interfaces)
    //  i->replace_undefined(scope);
    for (semantics *f : fields)
      f->replace_undefined(scope);
  }
};

struct S_builtin : public semantics { // not sure what this is for anymore.
  virtual string to_string() { return "S_builtin"; }
};

struct S_undefined : public S_type {
  virtual string to_string() { return "S_undefined: " + name; }
  virtual bool is_undefined() { return true; }
};

struct S_arraytype : public S_type {
  S_type *element_type;  // I'm an array of this type.
  virtual string to_string() { return "S_arraytype(" + element_type->to_string() + ")"; }
  virtual void replace_undefined(Symtab *scope) {
    if (marked.count(this)) return;
    marked.insert(this);
    if (element_type->is_undefined())
      element_type = get_real_type(element_type->name, line, scope);
    else
      element_type->replace_undefined(scope);
  }
};

struct S_primtype : public S_type {
  S_primtype(string name) { this->name = name; }
  virtual string to_string() { return "S_primitive: " + name; }
};


Symtab *closescope();
void openscope();

extern Symtab *currentScope;
extern Symtab *topScope;
extern S_interface* currentInterface;
extern S_class* currentClass;
extern S_function* currentFunction;
extern vector<semantics *> all_decls;
extern int yylineno;

#endif
