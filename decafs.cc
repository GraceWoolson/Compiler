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


bool types_mismatched(vector<S_variable *> & f1, vector<S_variable *> & f2){
    bool mismatched = false;
    for (int i = 0; i < f1.size(); i++){
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


  // after that, replace_undefined in all_decls.
  // (The cout << ... is for debugging only.)
  for (semantics *sem : all_decls) {
    cout << "Replacing all undefined inside " << sem->to_string() << endl;
    sem->replace_undefined(topScope);
  }

  for (semantics *sem : all_decls){
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

  // end of first pass.



  return 0;
#endif
}
