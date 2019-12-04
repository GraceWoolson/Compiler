//#define Tokens

#include <iostream>
#include <vector>
//#include "tokentype.h"
#include "parsetree.h"

#include "semantics.h"  // for variable scopes and semantics objects

extern FILE* yyin;
extern Token *myTok;
extern int yylineno;
extern ParseTree *top;
extern int yydebug;

using namespace std;

int yylex();
int yyparse();


ParseTree * parse_decaf(FILE *);

//global declarations of pass2 so all functions can call it
void pass2(ParseTree * current);

int loopcount = 0;
bool is_in_a_class = false;
Symtab * scope;
S_function * currfunc;
S_class * currclass;




bool is_compatible(S_type * lhs, S_type * rhs){
    S_class * lclass = dynamic_cast<S_class *>(lhs);
    S_interface * linterface = dynamic_cast<S_interface *>(lhs);
    S_primtype * lprim = dynamic_cast<S_primtype *>(lhs);

    S_class * rclass = dynamic_cast<S_class *>(rhs);
    S_interface * rinterface = dynamic_cast<S_interface *>(rhs);
    S_primtype * rprim = dynamic_cast<S_primtype *>(rhs);

    if (lprim || rprim){
        if (!lprim){
            semantic_error("Non-matching types for assignment expression", 0);
        }
        else if (!rprim){
            semantic_error("Non-matching types for assignment expression", 0);
        }
        else if(lprim->name != rprim->name){
            semantic_error("Non-matching types for assignment expression", 0);
        }
    }

    if (lclass && rclass){
        if(lclass != rclass){
            bool is_super = false;
            for (S_class * parent : rclass->inheritedClasses){
                if (lclass == parent){
                    is_super = true;
                }
            }
            if (!is_super){
                semantic_error("Incompatible types", 0);
            }
        }

    }

    if (lclass && rinterface){
        semantic_error("Attempting to pass an interface where a class is expected", 0);
    }

    if (linterface && rclass){
        bool implemented = false;
        for (S_type * interf : rclass->interfaces){
            S_interface * interface = dynamic_cast<S_interface *>(interf);
            if (interface == linterface){
                implemented = true;
            }
        }
        if (!implemented){
            for (S_class * parent : rclass->inheritedClasses){
                for (S_type * interf : parent->interfaces){
                    S_interface * interface = dynamic_cast<S_interface *>(interf);
                    if (interface == linterface){
                        implemented = true;
                    }
                }
            }
        }

        if(!implemented){
            semantic_error("Attempting to pass an incompatible class when an interface is expected", 0);
        }
    }

    if (linterface && rinterface){
        if (linterface != rinterface){
            semantic_error("Incompatible interfaces", 0);
        }
    }

    return true;
}



void pass2_const_or_var(ParseTree * current){
    string text = current->token->text;
    cout << "const or var " << current->token->text << endl;
    if(text == "this"){
        if (!currclass){
            semantic_error("cannot use 'this' outside of a class", 0);
        }
    }
    else{
        S_primtype * constant = dynamic_cast<S_primtype *>(current->sem);
        if (constant){
            cout << "actual constants tho" << endl;
            current->type = constant;
        }
        else{
            cout << "CONSTANTS" << endl;
            semantics * found = scope->lookup(text);

            if (!found){
                semantic_error("Undefined variable", 0);
            }

            S_variable * var = dynamic_cast<S_variable *>(found);
            if (var){
                current->type = var->type;
            }
            /*else{
                for(semantics *sem : all_decls){
                    S_class * isclass = dynamic_cast<S_class *>(sem);
                    S_interface * isinterface = dynamic_cast<S_interface *>(sem);
                    if (isclass){
                        cout << "class found???" << endl;
                        if (isclass->name == current->token->text){
                            current->type = isclass;
                        }
                    }
                    if (isinterface){
                        if (isinterface->name == current->token->text){
                            current->type = isinterface;
                        }
                    }
                }
            }*/
        }
    }
}

void pass2_functions(ParseTree * functree){
    //checks for correct return value
    S_function * function = dynamic_cast<S_function *>(functree->sem);
    currfunc = function;
    bool returned = false;

    //calls pass 2 on formals
    pass2(functree->children[2]);
    pass2(functree->children[3]);

    //check that the return matches (goes through stmtblock, 4th child)
    ParseTree * stmts = functree->children[3]->children[1];
    for(ParseTree * child : stmts->children){
        //pass2(child);
        if (child->description == "return"){
            returned = true;

            if(function->returnType == child->type){
                functree->type = child->type;
            }
            else{
                semantic_error("Return of incorrect types", function->line);
            }
        }
    }

    if (function->returnType && !returned){
        semantic_error("No return in non-void function", function->line);
    }
    currfunc = NULL;
}


void pass2_return(ParseTree * retree){
    if(retree->children.size() > 1){
        ParseTree * ret_stmt = retree->children[1];
        //cout << ret_stmt->description << endl;
        pass2(ret_stmt);
        retree->type = ret_stmt->type;
    }

    else{
        retree->type = NULL;
    }
}



void pass2_binop(ParseTree * bintree){

    string op = bintree->children[1]->token->text;
    ParseTree * left = bintree->children[0];
    ParseTree * right = bintree->children[2];
    pass2(left);
    pass2(right);

    if(op == "+" || op == "-" || op == "/" || op == "*" || op == "%"){
        //arithmetic type match
        if(left->type->name != right->type->name){
            semantic_error("Non-matching types for arithmetic expression", 0);
        }
        string type = left->type->name;
        if(type != "int" && type != "double"){
            semantic_error("Non-numeric types for arithmetic expression", 0);
        }

        bintree->type = left->type;

    }
    else if(op == "<" || op == "<=" || op == ">" || op == ">="){
        //relational types match int or double
        if(left->type->name != right->type->name){
            semantic_error("Non-matching types for relational expression", 0);
        }
        string type = left->type->name;
        if(type != "int" && type != "double"){
            semantic_error("Non-numeric types for relational expression", 0);
        }

        bintree->type = new S_primtype("bool");
    }

    else if(op == "==" || op == "!="){
        //equality types match
        if (! is_compatible(left->type, right->type)){
            semantic_error("Non-matching types for relational expression", 0);
        }

        bintree->type = new S_primtype("bool");
    }

    else if(op == "="){
        //assignment type compatibility
        //Interface assignment type compatibility
        cout << "assignment!" << endl;
        //cout << scope->to_string() << endl;
        S_primtype * isprim = dynamic_cast<S_primtype *>(left->type);
        if (isprim){
            if(left->type->name != right->type->name){
                cout << left->type->name << " " << right->type->name << endl;
                semantic_error("Non-matching types for assignment expression", 0);
            }
            bintree->type = left->type;
        }

        else if(left->type->name != right->type->name){
            if(is_compatible(left->type, right->type)){
                bintree->type = left->type;
            }
            else{
                semantic_error("Non-matching types for assignment expression", 0);
            }
        }
    }

    else if(op == "&&" || op == "||"){
        //logical types match
        cout << "logical" << endl;
        if(left->type->name != "bool" || right->type->name != "bool"){
            semantic_error("Non boolean values used in logical expression", 0);
        }
        bintree->type = new S_primtype("bool");
    }
}


void pass2_uop(ParseTree * optree){
    string op = optree->children[0]->token->text;
    pass2(optree->children[1]);

    if(op == "-"){
        if(optree->children[1]->type->name != "int" && optree->children[1]->type->name != "double"){
            semantic_error("Non-numeric type used with negation operator", 0);
        }
        optree->type = optree->children[1]->type;
    }

    if(op == "!"){
        if(optree->children[1]->type->name != "bool"){
            semantic_error("Non-boolean type used with not operator", 0);
        }
        optree->type = new S_primtype("bool");
    }
}



void pass2_variables(ParseTree * vartree){
    cout << "variable" << endl;
    S_variable * variable = dynamic_cast<S_variable *>(vartree->sem);

    S_primtype * isprim = dynamic_cast<S_primtype *>(variable->type);
    if (isprim){
        vartree->type = isprim;
    }

    S_class * isclass = dynamic_cast<S_class *>(variable->type);
    if (isclass){
        vartree->type = isclass;
    }

    S_interface * isinterface = dynamic_cast<S_interface *>(variable->type);
    if (isinterface){
        vartree->type = isinterface;
    }

    S_arraytype * isarray = dynamic_cast<S_arraytype *>(variable->type);
    if (isarray){
        cout << "is an array!!" << endl;
        vartree->type = isarray;
    }
}


void pass2_class(ParseTree * classtree){
    S_class * thisclass = dynamic_cast<S_class *>(classtree->sem);
    currclass = thisclass;
    is_in_a_class = true;
    pass2(classtree->children[3]);
    currclass = NULL;
}


void pass2_fields(ParseTree * fieldtree){
    for (ParseTree * child : fieldtree->children){
        pass2(child);
    }
}



void pass2_stmtblock(ParseTree * blocktree){
    pass2(blocktree->children[0]);
    pass2(blocktree->children[1]);
}

void pass2_vardecls(ParseTree * vartree){
    for (ParseTree * child : vartree->children){
        pass2(child);
    }
}

void pass2_stmts(ParseTree * stmttree){
    for (ParseTree * child : stmttree->children){
        pass2(child);
    }
}



void pass2_interface(ParseTree * itree){
    for (ParseTree * child : itree->children){
        if(child != itree->children[0]){
            pass2(child);
        }
    }
}



void pass2_formals(ParseTree * ftree){
    for (ParseTree * child : ftree->children){
        pass2(child);
    }
}



void pass2_ifstmts(ParseTree * iftree){
    for (ParseTree * child : iftree->children){
        pass2(child);
    }
    if (iftree->children[0]->type->name != "bool"){
        semantic_error("If statement requires a boolean conditional", 0);
    }
}



void pass2_whilestmts(ParseTree * whiletree){
    loopcount += 1;
    for (ParseTree * child : whiletree->children){
        pass2(child);
    }
    if (whiletree->children[0]->type->name != "bool"){
        semantic_error("While statement requires a boolean conditional", 0);
    }
    loopcount -= 1;
}


void pass2_forloops(ParseTree * fortree){
    loopcount += 1;
    for (ParseTree * child : fortree->children){
        if(child){
            pass2(child);
        }
    }
    if (fortree->children[1]->type->name != "bool"){
        semantic_error("Test portion of for loop must have a boolean value", 0);
    }
    loopcount -= 1;
}


void pass2_break(){
    //check if in loop
    if (loopcount <= 0){
        semantic_error("break in a non loop!", 0);
    }
}

void pass2_print(ParseTree * printtree){
    for (ParseTree * child : printtree->children){
        pass2(child);
    }
}

void pass2_readint(ParseTree * inttree){
    inttree->type = new S_primtype("int");
}


//COME BACK TO THESE WOOLSON
void pass2_new(ParseTree * newtree){
    //valid parameters
    ParseTree * child = newtree->children[0];
    bool found = false;
    // need to fix this
    for(semantics *sem : all_decls){
        S_class * isclass = dynamic_cast<S_class *>(sem);
        if (isclass){
            if (isclass->name == child->token->text){
                newtree->type = isclass;
                found = true;
            }
        }
    }
    if (!found){
        semantic_error("New operator requires a class", 0);
    }
}

void pass2_newarray(ParseTree * newtree){
    //valid params
    //works for primitive types only
    ParseTree * num = newtree->children[0];
    ParseTree * arrtype = newtree->children[1];
    pass2(num);
    pass2(arrtype);
    cout << "array type: " <<  arrtype->type << endl;
}

void pass2_field_access(ParseTree * dottree){
    //valid field access
    for (ParseTree * child : dottree->children){
        pass2(child);
    }
}

void pass2_aref(ParseTree * areftree){
    //type check
    for (ParseTree * child : areftree->children){
        pass2(child);
    }

    S_arraytype * arr = dynamic_cast<S_arraytype *>(areftree->children[0]->type);
    if (!arr){
        semantic_error("Attempt to reference an object that is not an array", 0);
    }
    S_primtype * index = dynamic_cast<S_primtype *>(areftree->children[1]->type);
    if (!index || !(index->name == "int")){
        semantic_error("Non-integer index", 0);
    }

    areftree->type = arr->element_type;
}

void pass2_call(ParseTree * calltree){
    for (ParseTree * child : calltree->children){
        pass2(child);
    }
}


void pass2_actuals(ParseTree * actualstree){
    for (ParseTree * child : actualstree->children){
        pass2(child);
    }
}


void pass2_this(ParseTree * thistree){
    for (ParseTree * child : thistree->children){
        pass2(child);
    }
}

//this code is probably garbage
void pass2_type(ParseTree * current){
    cout << "MADE IT TO PASS2_TYPE " << endl;
    if (current->description == "primtype"){
        ParseTree * child = current->children[0];
        pass2(child);
        cout << "Pass2 type " << child->type->name << endl;
        current->type = child->type;
    }
    if (current->description == "usertype"){
        //S_class * isclass = dynamic_cast<S_class *>(current->sem);
        cout << current->sem << endl;
        if (dynamic_cast<S_type *>(current->sem)){
            //cout << "USERTYPE! " << endl;
            current->type = dynamic_cast<S_type *>(current->sem);
        }
    }
}





void pass2(ParseTree * current){
    //compatible types only for user-declared
    cout << "description " << current->description << endl;

    if (current->description.size() == 0){
        pass2_const_or_var(current);
    }

    else if (current->description == "functiondecl"){
        //compatible return value
        pass2_functions(current);
    }

    else if (current->description == "return"){
        pass2_return(current);

    }

    else if (current->description == "binop"){
        pass2_binop(current);
    }

    else if (current->description == "class"){
        //class object valid in class being declared: class A { A a; }
        //Instance variable lookup is used when scope lookup fails.  Inherited instance variables are found
        Symtab * oldscope = scope;
        scope = current->symtab;
        pass2_class(current);
        scope = oldscope;

    }
    else if (current->description == "interface"){
        Symtab * oldscope = scope;
        scope = current->symtab;
        pass2_interface(current);
        scope = oldscope;
    }

    //else if (current->description == "extends"){}

    //else if (current->description == "implements"){}

    else if (current->description == "fields"){
        pass2_fields(current);
    }

    else if (current->description == "variable"){
        pass2_variables(current);
    }

    else if (current->description == "formals"){
        pass2_formals(current);
    }

    else if (current->description == "stmtblock"){
        Symtab * oldscope = scope;
        scope = current->symtab;
        pass2_stmtblock(current);
        scope = oldscope;
    }

    else if (current->description == "vardecls"){
        pass2_vardecls(current);
    }

    else if (current->description == "stmts"){
        pass2_stmts(current);
    }

    else if (current->description == "if"){
        //expr is a bool
        pass2_ifstmts(current);
    }

    else if (current->description == "while"){
        //expr is a bool
        pass2_whilestmts(current);
    }

    else if (current->description == "for"){
        //check the three exprs (looks just like a c++ for loop)
        pass2_forloops(current);

    }

    else if (current->description == "break"){
        pass2_break();
    }

    else if (current->description == "print"){
        pass2_print(current);
    }

    //else if (current->description == "nullstmt"){} ** might need to make type null or something

    else if (current->description == "uop"){
        //type match
        pass2_uop(current);
    }

    else if (current->description == "readinteger"){
        pass2_readint(current);
    }

    else if (current->description == "new"){
        //valid parameters
        pass2_new(current);
    }

    else if (current->description == "newarray"){
        //valid parameters
        pass2_newarray(current);
    }

    else if (current->description == "field_access"){
        //valid field access
        pass2_field_access(current);
    }

    else if (current->description == "aref"){
        //type check (integer?)
        pass2_aref(current);
    }

    else if (current->description == "call"){
        //actuals in a function call compatible with declared formal types
        //class object accepted in place of an interface object when passing actuals
        //valid/invalid interface object function call
        pass2_call(current);
    }

    else if (current->description == "actuals"){
        pass2_actuals(current);
    }

    else if (current->description == "usertype"){
        pass2_type(current);
    }

    else if (current->description == "primtype"){
        pass2_type(current);
    }

    else if (current->description == "arraytype"){
        pass2_type(current);
    }

    // else if(current->token){
    //     if (current->token->text == "this"){
    //
    //     }
    // }

    //may need to be an else
    else{
        for(ParseTree * child : current->children){
            //cout << "makes it?" << " " << child->description << endl;
            pass2(child);
        }
    }
}










bool types_mismatched(vector<S_variable *> & f1, vector<S_variable *> & f2){
    bool mismatched = false;
    for (size_t i = 0; i < f1.size(); i++){
        if(f1[i]->type != f2[i]->type){
            mismatched = true;
        }
    }
    return mismatched;
}


bool is_implemented(S_function * function, vector<S_function *> & funcs){
    for (S_function * curr_func : funcs){
        if(curr_func->name == function->name){
            if ((curr_func->returnType != function->returnType) or
              (curr_func->formals.size() != function->formals.size()) or
              types_mismatched(curr_func->formals, function->formals)){
                  return false;
              }
              else{
                  return true;
              }
        }
    }
    return false;
}


int main(int argc, char **argv) {
  /* Make sure there's a given file name */
  if (argc != 2) {
    cout << "USAGE: " << argv[0] << " FILE" << endl;
    exit(1);
  }
  yyin = fopen(argv[1], "r");
  /* and that it exists and can be read */
  if (!yyin) {
    cout << argv[1] << ": No such file or file can't be opened for reading."
	 << endl;
    exit(1);
  }

  yydebug = 1;
#ifdef Tokens
  int tok;
  while ((tok=yylex()) != -1) {
    cout << tok << ' ';
    myTok->print();
  }
  return 0;
#else
  openscope();  // create original scope
  topScope = currentScope;

  topScope->insert("int",new S_primtype("int"));
  topScope->insert("double",new S_primtype("double"));
  topScope->insert("bool",new S_primtype("bool"));
  topScope->insert("string",new S_primtype("string"));

  top = parse_decaf(yyin);
  traverseTree(top, 0, 1);

  marked.clear(); // avoid infinite recursion in what follows.
  set<semantics *> marked;  // the declaration of a set of pointers to objects

  // after that, replace_undefined in all_decls.
  // (The cout << ... is for debugging only.)
  for (semantics *sem : all_decls) {
      cout << "Replacing all undefined inside " << sem->to_string() << endl;
      sem->replace_undefined(topScope);
  }

  bool found_main = false;
  for (semantics *sem : all_decls){
      S_function * this_func = dynamic_cast<S_function *>(sem);
      if ((this_func) && (this_func->name == "main")){
          if(this_func->formals.size() == 0){
              found_main = true;
          }
      }

      S_class * this_class = dynamic_cast<S_class *>(sem);
      if (this_class){
          bool end_generations = false;
          S_class * curr = this_class;
          vector<S_function *> implemented_functions;
          vector<S_variable *> declared_variables;
          while(!end_generations){
              //get all functions and variables
              for(semantics * obj : curr->fields){
                  S_function * func = dynamic_cast<S_function *>(obj);
                  S_variable * var = dynamic_cast<S_variable *>(obj);
                  if (func){
                      for (S_function * decd_func: implemented_functions){
                          if (decd_func->name == func->name){
                              if ((decd_func->returnType != func->returnType) or
                                (decd_func->formals.size() != func->formals.size()) or
                                types_mismatched(decd_func->formals, func->formals))
                                    semantic_error("Invalid function override", func->line);
                          }
                      }
                      implemented_functions.push_back(func);
                  }
                  if (var){
                      //checks if declaring instance variables
                      for (S_variable * decd_var: declared_variables){
                          if (decd_var->name == var->name){
                              semantic_error("Instance variable redefined", var->line);
                          }
                      }
                      declared_variables.push_back(var);
                  }
              }

              //finds parents and checks for circularity
              S_class * parent = dynamic_cast<S_class *>(curr->parentClass);
              if (parent){
                  this_class->inheritedClasses.push_back(parent);
                  if (parent->name == this_class ->name){
                      semantic_error("Class circularity", this_class->line);
                  }
                  curr = dynamic_cast<S_class *>(curr->parentClass);
              }
              else{
                  if(curr->parentClass){
                      semantic_error("Extends non-class", curr->line);
                  }
                  end_generations = true;
              }
          }

          //handles implementing interfaces
          for(S_type * i : this_class->interfaces){
              S_interface * interface = dynamic_cast<S_interface *>(i);
              for(S_function * function : interface->functions){
                  bool correct = is_implemented(function, implemented_functions);
                  if (!correct){
                      semantic_error("Function not implemented",function->line);
                  }
              }
          }
      }
  }

  if (!found_main){
      semantic_error("Main not defined", 0);
  }
  // end of first pass.
  scope = topScope;
  pass2(top);

  return 0;
#endif
}
