%token T_Void 1
%token T_Int 2
%token T_Double 3
%token T_Bool 4
%token T_String 5
%token T_Class 6
%token T_Interface 7
%token T_Null 8
%token T_This 9
%token T_Extends 10
%token T_Implements 11
%token T_For 12
%token T_While 13
%token T_If 14
%token T_Else 15
%token T_Return 16
%token T_Break 17
%token T_New 18
%token T_NewArray 19
%token T_Print 20
%token T_ReadInteger 21
%token T_ReadLine 22
  /* 2 Identifiers */
%token T_Identifier 23
%token T_TypeIdentifier 24
  /* The 4 kinds of constants (literals) */
%token T_IntConstant 25
%token T_BoolConstant 26
%token T_DoubleConstant 27
%token T_StringConstant 28
  /* The 24 other tokens
     + - * / % < <= > >= = == != && || ! ; , . [ ] ( ) { } */
%token T_Plus 29
%token T_Minus 30
%token T_Times 31
%token T_Div 32
%token T_Mod 33
%token T_Less 34
%token T_LessEqual 35
%token T_Greater 36
%token T_GreaterEqual 37
%token T_Assign 38
%token T_Equal 39
%token T_NotEqual 40
%token T_And 41
%token T_Or 42
%token T_Not 43
%token T_Semicolon 44
%token T_Comma 45
%token T_Dot 46
%token T_LBracket 47
%token T_RBracket 48
%token T_LParen 49
%token T_RParen 50
%token T_LBrace 51
%token T_RBrace 52


%{
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include "tokentype.h"
#include "parsetree.h"

#include "semantics.h"  // New: a series of semantics objects

  /* we are building parse trees */
#define YYSTYPE ParseTree *

using namespace std;

 extern Token *myTok;
 extern int yylineno;
 int yylex();

 ParseTree *top;

 /* stack<Token *> opstack;  // used this last time.  Might not need this time?
    Token *optok; */

 %}

%%
Program: Decls

Decls: Decl { $$ = new ParseTree("program", $1); top = $$; }
    | Decls Decl { $1->addChild($2); }
Decl: VariableDecl | FunctionDecl | ClassDecl | InterfaceDecl

  /* interface declarations */
InterfaceDecl: T_Interface Y_Identifier T_LBrace T_RBrace { $$ = new ParseTree("interface", $2);
                    Token *tok = $2->token;
                    semantics *test = currentScope->local_lookup(tok->text);
                    if (test) semantic_error("Interface redefined", tok->line);
                    currentInterface = new S_interface;
                    currentInterface->name = tok->text;
                    currentInterface->line = tok->line;
                    currentScope->insert(tok->text, currentInterface);
                    all_decls.push_back(currentInterface);
                    $$->sem = currentInterface;
                }
    | InterfaceDecl2
InterfaceDecl2: T_Interface InterfaceMiddle T_RBrace { $$ = $2;
                    Token *tok = $2->children[0]->token;
                    semantics *test = currentScope->local_lookup(tok->text);
                    if (test) semantic_error("Interface redefined", tok->line);
                    openscope();
                    currentInterface = new S_interface;
                    currentInterface->name = tok->text;
                    currentInterface->line = tok->line;
                    for(ParseTree * child : $2->children){
                        if (!(child == $2->children[0])){
                            S_function * curr = new S_function;
                            Token *tok = child->children[1]->token;
                            curr->name = tok->text;
                            for (ParseTree * f_tree : child->children[2]->children){
                                S_variable * this_formal = dynamic_cast<S_variable *>(f_tree->sem);
                                curr->formals.push_back(this_formal);
                            }
                            S_type *ret_type = dynamic_cast<S_type *>(child->children[0]->sem);
                            (ret_type)? curr->returnType = ret_type : curr->returnType = NULL;
                            currentInterface->functions.push_back(curr);
                        }
                    }
                    $$->symtab = closescope();
                    currentScope->insert(tok->text, currentInterface);
                    all_decls.push_back(currentInterface);
                    $$->sem = currentInterface;
                }
InterfaceMiddle: Y_Identifier T_LBrace Prototype { $$ = new ParseTree("interface", $1, $3); }
    | InterfaceMiddle Prototype { $1 -> addChild($2); }

Prototype: Type Y_Identifier T_LParen Formalsq T_RParen T_Semicolon { $$ = new ParseTree("prototype", $1, $2, $4); }
    | Y_Void Y_Identifier T_LParen Formalsq T_RParen T_Semicolon { $$ = new ParseTree("prototype", $1, $2, $4); }

  /* class declarations */
ClassDecl:  T_Class Y_Identifier { Token *tok = $2->token;
                    string class_name = tok->text;
                    semantics *curr = topScope->local_lookup(tok->text);
                    if (curr) semantic_error("Class redefined", tok->line);
                    S_class * this_class = new S_class(class_name, tok->line);
                    currentClass = this_class;
                    openscope(); }
        Extendsq { if ($4) { Token *tok = $4->children[0]->token;
                    string class_name = tok->text;
                    S_undefined * temp_parent = new S_undefined;
                    temp_parent -> name = class_name;
                    temp_parent -> line = tok->line;
                    currentClass->parentClass = temp_parent;
                    $$->sem = temp_parent;
                }}
        Implementsq { if ($6) {
            for(ParseTree *i_tree : $6->children){
                Token *tok = i_tree->token;
                string interface_name = tok->text;
                S_undefined * temp_interface = new S_undefined;
                temp_interface->name = interface_name;
                temp_interface->line = tok->line;
                currentClass->interfaces.push_back(temp_interface);
            }
        }}
        T_LBrace Fieldsq T_RBrace { $$ = new ParseTree("class", $2, $4, $6, $9);
                for(ParseTree * child : $9->children){
                    currentClass->fields.push_back(child->sem);
                }
                all_decls.push_back(currentClass);
                topScope->insert(currentClass->name, currentClass);
                $$->sem = currentClass;
                currentClass = nullptr;
                $$->symtab = closescope(); }

    | T_Class Y_TypeIdentifier { Token *tok = $2->token;
                    string class_name = tok->text;
                    semantics *curr = topScope->local_lookup(tok->text);
                    if (curr) semantic_error("Attempted class override", tok->line);
                    S_class * this_class = new S_class(class_name, tok->line);
                    currentClass = this_class;
                    openscope(); }
            Extendsq { if ($4) { Token *tok = $4->children[0]->token;
                        string class_name = tok->text;
                        S_undefined * temp_parent = new S_undefined;
                        temp_parent -> name = class_name;
                        temp_parent -> line = tok->line;
                        currentClass->parentClass = temp_parent;
                        $$->sem = temp_parent;
                    }}
            Implementsq { if ($6) {
                for(ParseTree *i_tree : $6->children){
                    Token *tok = i_tree->token;
                    string interface_name = tok->text;
                    S_undefined * temp_interface = new S_undefined;
                    temp_interface->name = interface_name;
                    temp_interface->line = tok->line;
                    currentClass->interfaces.push_back(temp_interface);
                }
            }}
            T_LBrace Fieldsq T_RBrace { $$ = new ParseTree("class", $2, $4, $6, $9);
                    for(ParseTree * child : $9->children){
                        currentClass->fields.push_back(child->sem);
                    }
                    all_decls.push_back(currentClass);
                    topScope->insert(currentClass->name, currentClass);
                    $$->sem = currentClass;
                    currentClass = nullptr;
                    $$->symtab = closescope(); }

Extendsq: { $$ = nullptr; }
    | T_Extends Y_Identifier { $$ = new ParseTree("extends", $2); }
    | T_Extends Y_TypeIdentifier { $$ = new ParseTree("extends", $2); }
Implementsq: { $$ = nullptr; }
    | Implements
Implements: T_Implements Y_Identifier { $$ = new ParseTree("implements", $2); }
    | Implements T_Comma Y_Identifier { $1->addChild($3); }
Fieldsq: { $$ = new ParseTree("fields"); }
    | Fieldsq VariableDecl { $1 -> addChild($2); }
    | Fieldsq FunctionDecl { $1 -> addChild($2); }


  /* variable declarations */
VariableDecl: Variable T_Semicolon
Variable: Type Y_Identifier { $$ = new ParseTree("variable", $1, $2);
                        Token *tok = $2->token;
                        string var_name = tok->text;
                        S_type *var_type = dynamic_cast<S_type *>($1->sem);
                        semantics *curr = currentScope->local_lookup(tok->text);
                        if (curr) semantic_error("Variable already defined",tok->line);
                        S_variable *this_var = new S_variable();
                        this_var->type = var_type;
                        this_var->name = var_name;
                        this_var->line = yylineno;
                        currentScope->insert(var_name, this_var);
                        all_decls.push_back(this_var);
                        $$->sem = this_var; }

  /* function declarations */
FunctionDecl: Type Y_Identifier T_LParen {
                    currentFunction = new S_function;
                    Token *tok = $2->token;
                    string func_name = tok->text;
                    semantics *curr = currentScope->local_lookup(func_name);
                    if (curr) semantic_error("Function already defined",tok->line);
                    S_type *var_type = dynamic_cast<S_type *>($1->sem);
                    //string var_type_name = $1->children[0]->token->text;
                    //var_type->name = var_type_name;
                    //Maybe look here HERE WOOLSON
                    //cerr << endl << endl << "THIS IS TESTING LINE 247" << var_type_name << endl << endl;
                    currentFunction->name = func_name;
                    currentFunction->returnType = var_type;
                }
        Formalsq { for(ParseTree *f_tree : $5->children){
                        S_variable * this_formal = dynamic_cast<S_variable *>(f_tree->sem);
                        currentFunction->formals.push_back(this_formal);
                    }
                }
        T_RParen StmtBlock { $$ = new ParseTree("functiondecl", $1, $2, $5, $8);
                    currentScope->insert(currentFunction->name, currentFunction);
                    all_decls.push_back(currentFunction);
                    $$->sem = currentFunction;
                    currentFunction = nullptr; }

    | Y_Void Y_Identifier T_LParen {
                        currentFunction = new S_function;
                        Token *tok = $2->token;
                        string func_name = tok->text;
                        semantics *curr = currentScope->local_lookup(func_name);
                        if (curr) semantic_error("Function already defined",tok->line);
                        //S_type *var_type = dynamic_cast<S_type *>($1->sem);
                        currentFunction->name = func_name;
                        currentFunction->returnType = NULL;
                    }
            Formalsq { for(ParseTree *f_tree : $5->children){
                            S_variable * this_formal = dynamic_cast<S_variable *>(f_tree->sem);
                            currentFunction->formals.push_back(this_formal);
                        }
                    }
            T_RParen StmtBlock { $$ = new ParseTree("functiondecl", $1, $2, $5, $8);
                        currentScope->insert(currentFunction->name, currentFunction);
                        all_decls.push_back(currentFunction);
                        $$->sem = currentFunction;
                        currentFunction = nullptr; }
Formalsq: { $$ = new ParseTree("formals"); }
    | Formals
Formals: Variable { $$ = new ParseTree("formals", $1); }
    | Formals T_Comma Variable { $1->addChild($3); }

  /* Statement Blocks */
StmtBlock: T_LBrace { openscope(); }
            StmtVarsq Stmtsq T_RBrace { $$ = new ParseTree("stmtblock", $3, $4);
                                        $$->symtab = closescope(); }
StmtVarsq: { $$ = new ParseTree("vardecls"); }
    | StmtVars
StmtVars: VariableDecl { $$ = new ParseTree("vardecls", $1); }
    | StmtVars VariableDecl { $1->addChild($2); }
Stmtsq: { $$ = new ParseTree("stmts"); }
    | Stmts
Stmts: Stmt { $$ = new ParseTree("stmts", $1); }
    | Stmts Stmt { $1->addChild($2); }
Stmt: MatchedStmt | UnmatchedStmt
MatchedStmt: Exprq T_Semicolon | StmtBlock | MatchedIf | BreakStmt
    | ReturnStmt | PrintStmt
UnmatchedStmt: OpenIf | ForStmt | WhileStmt

  /* Statements */
MatchedIf: T_If T_LParen Expr T_RParen MatchedStmt T_Else MatchedStmt { $$ = new ParseTree("if", $3, $5, $7); }
OpenIf: T_If T_LParen Expr T_RParen Stmt { $$ = new ParseTree("if", $3, $5); }
    | T_If T_LParen Expr T_RParen MatchedStmt T_Else UnmatchedStmt { $$ = new ParseTree("if", $3, $5, $7); }


WhileStmt: T_While T_LParen Expr T_RParen StmtBlock { $$ = new ParseTree("while", $3, $5); }

  /* inconsistent output (NULL instead of nullstmt) */
ForStmt: T_For T_LParen ForExprq T_Semicolon Expr T_Semicolon ForExprq T_RParen Stmt { $$ = new ParseTree("for", $3, $5, $7, $9); }
ForExprq: { $$ = nullptr; }
    | Expr

  /* inconsistent output */
BreakStmt: Y_Break T_Semicolon { $$ = new ParseTree("break", $1); }
  /* inconsistent output */
ReturnStmt: Y_Return T_Semicolon { $$ = new ParseTree("return", $1); }
    | Y_Return Expr T_Semicolon { $$ = new ParseTree("return", $1, $2); }

PrintStmt: Y_Print T_LParen Actuals T_RParen T_Semicolon { $$ = new ParseTree("print", $1, $3); }

  /* Expressions! */
Exprq: { $$ = new ParseTree("nullstmt"); }
    | Expr
Expr: LValue Y_Assign Expr { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr2
Expr2: Expr2 Y_Or Expr3 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr3
Expr3: Expr3 Y_And Expr4 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr4
Expr4: Expr4 Y_Equal Expr5 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr4 Y_NotEqual Expr5 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr5
Expr5: Expr5 Y_Less Expr6 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr5 Y_LessEqual Expr6 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr5 Y_Greater Expr6 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr5 Y_GreaterEqual Expr6 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr6
Expr6: Expr6 Y_Plus Expr7 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr6 Y_Minus Expr7 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr7
Expr7: Expr7 Y_Times Expr8 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr7 Y_Div Expr8 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr7 Y_Mod Expr8 { $$ = new ParseTree("binop", $1, $2, $3); }
    | Expr8
Expr8: Y_Not Expr9 { $$ = new ParseTree("uop", $1, $2); }
    | Y_Minus Expr9 { $$ = new ParseTree("uop", $1, $2); }
    | Expr9
  /* inconsistent output on readinteger and readline */
Expr9: Constant | LValue | Y_This | Call
    | T_LParen Expr T_RParen { $$ = $2; }
    | T_ReadInteger T_LParen T_RParen { $$ = new ParseTree("readinteger"); }
    | T_ReadLine T_LParen T_RParen { $$ = new ParseTree("readline"); }
    | T_New T_LParen Y_Identifier T_RParen { $$ = new ParseTree("new", $3); }
    | T_NewArray T_LParen Expr T_Comma NewArrayType T_RParen { $$ = new ParseTree("newarray", $3, $5); }

  /* No Ops */
Constant: Y_IntConstant | Y_DoubleConstant | Y_BoolConstant | Y_StringConstant | Y_Null
LValue: Y_Identifier | FieldAccess | ArrayRef
FieldAccess: Expr9 T_Dot Y_Identifier { $$ = new ParseTree("field_access", $1, $3); }
ArrayRef: Expr9 T_LBracket Expr T_RBracket { $$ = new ParseTree("aref", $1, $3); }
Call: Y_Identifier T_LParen Actualsq T_RParen { $$ = new ParseTree("call", $1, $3); }
    | FieldAccess T_LParen Actualsq T_RParen { $$ = new ParseTree("call", $1, $3); }
Actualsq: { $$ = new ParseTree("actuals"); }
    | Actuals
Actuals: Expr { $$ = new ParseTree("actuals", $1); }
    | Actuals T_Comma Expr { $1->addChild($3); }

  /* types! */
NewArrayType: Type
    | Y_Identifier { $$ = new ParseTree("usertype", $1);
                string type_name = $1->token->text;
                semantics *thing = topScope->lookup(type_name);
            if (thing == nullptr) {
                S_type *undef_type = new S_undefined;
                undef_type->name = type_name;
                undef_type->line = yylineno;
                $$->sem = undef_type;
            }
            else if (dynamic_cast<S_type *>(thing))
                $$->sem = thing;
            else
                semantic_error(type_name + " is not a type",
                     $1->token->line); }
Type: Primtype
    | Usertype
    | Lsttype

Primtype: Y_Int { $$ = new ParseTree("primtype", $1);
                  $$->sem = topScope->lookup("int"); }
        | Y_Double { $$ = new ParseTree("primtype", $1);
                     $$->sem = topScope->lookup("double"); }
        | Y_Bool { $$ = new ParseTree("primtype", $1);
                   $$->sem = topScope->lookup("bool"); }
        | Y_String { $$ = new ParseTree("primtype", $1);
                     $$->sem = topScope->lookup("string"); }
Usertype: Y_TypeIdentifier { $$ = new ParseTree("usertype", $1);
            string type_name = $1->token->text;
            semantics *thing = topScope->lookup(type_name);
        if (thing == nullptr) {
            S_type *undef_type = new S_undefined;
            undef_type->name = type_name;
            undef_type->line = yylineno;
            $$->sem = undef_type;
        }
        else if (dynamic_cast<S_type *>(thing))
            $$->sem = thing;
        else
            semantic_error(type_name + " is not a type",
                 $1->token->line); }
Lsttype: Type T_LBracket T_RBracket { $$ = new ParseTree("arraytype", $1);
            S_arraytype *this_type = new S_arraytype;
            this_type->element_type = dynamic_cast<S_type *>($1->sem);
            this_type->line = yylineno;
            $$->sem = this_type;
        }

  /* terminals */
Y_IntConstant: T_IntConstant { $$ = new ParseTree(myTok);
                                $$->sem = topScope->lookup("int"); }
Y_DoubleConstant: T_DoubleConstant { $$ = new ParseTree(myTok);
                                $$->sem = topScope->lookup("double"); }
Y_BoolConstant: T_BoolConstant { $$ = new ParseTree(myTok);
                                $$->sem = topScope->lookup("bool"); }
Y_StringConstant: T_StringConstant { $$ = new ParseTree(myTok);
                                $$->sem = topScope->lookup("string");}
Y_Int: T_Int { $$ = new ParseTree(myTok);
                $$->sem = topScope->lookup("int");}
Y_Double: T_Double { $$ = new ParseTree(myTok);
                $$->sem = topScope->lookup("double");}
Y_Bool: T_Bool { $$ = new ParseTree(myTok);
                $$->sem = topScope->lookup("bool");}
Y_String: T_String { $$ = new ParseTree(myTok);
                $$->sem = topScope->lookup("string"); }
Y_TypeIdentifier: T_TypeIdentifier { $$ = new ParseTree(myTok); }
Y_Identifier: T_Identifier { $$ = new ParseTree(myTok); }
Y_This: T_This { $$ = new ParseTree(myTok); }
Y_Null: T_Null { $$ = new ParseTree(myTok); }
Y_Break: T_Break { $$ = new ParseTree(myTok); }
Y_Return: T_Return { $$ = new ParseTree(myTok); }
Y_Print: T_Print { $$ = new ParseTree(myTok); }
Y_Void: T_Void { $$ = new ParseTree(myTok); }

  /* operators */
Y_Assign: T_Assign { $$ = new ParseTree(myTok); }
Y_Or: T_Or { $$ = new ParseTree(myTok); }
Y_Plus: T_Plus { $$ = new ParseTree(myTok); }
Y_Minus: T_Minus { $$ = new ParseTree(myTok); }
Y_Times: T_Times { $$ = new ParseTree(myTok); }
Y_Div: T_Div { $$ = new ParseTree(myTok); }
Y_Mod: T_Mod { $$ = new ParseTree(myTok); }
Y_Less: T_Less { $$ = new ParseTree(myTok); }
Y_LessEqual: T_LessEqual { $$ = new ParseTree(myTok); }
Y_Greater: T_Greater { $$ = new ParseTree(myTok); }
Y_GreaterEqual: T_GreaterEqual { $$ = new ParseTree(myTok); }
Y_Equal: T_Equal { $$ = new ParseTree(myTok); }
Y_NotEqual: T_NotEqual { $$ = new ParseTree(myTok); }
Y_And: T_And { $$ = new ParseTree(myTok); }
Y_Not: T_Not { $$ = new ParseTree(myTok); }

%%

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
