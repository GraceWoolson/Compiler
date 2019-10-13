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
 /* to see about shift reduce errors? https://stackoverflow.com/questions/30447829/rules-are-never-reduced-understanding-why */
Program: Decls

Decls: Decl { $$ = new ParseTree("program", $1); top = $$; }
    | Decls Decl { $1->addChild($2); }
Decl: VariableDecl | FunctionDecl

  /* variable declarations */
VariableDecl: Variable T_Semicolon
Variable: Type Y_Identifier { $$ = new ParseTree("variable", $1, $2); }

  /* function declarations */
FunctionDecl: Type Y_Identifier T_LParen Formalsq T_RParen StmtBlock { $$ = new ParseTree("functiondecl", $1, $2, $4, $6); }
    | Y_Void Y_Identifier T_LParen Formalsq T_RParen StmtBlock { $$ = new ParseTree("functiondecl", $1, $2, $4, $6); }
Formalsq: { $$ = new ParseTree("formals"); }
    | Formals
Formals: Variable { $$ = new ParseTree("formals", $1); }
    | Formals T_Comma Variable { $1->addChild($3); }

  /* Statement Blocks */
StmtBlock: T_LBrace StmtVarsq Stmtsq T_RBrace { $$ = new ParseTree("stmtblock", $2, $3); }
StmtVarsq: { $$ = new ParseTree("vardecls"); }
    | StmtVars
StmtVars: VariableDecl { $$ = new ParseTree("vardecls", $1); }
    | StmtVars VariableDecl { $1->addChild($2); }
Stmtsq: { $$ = new ParseTree("stmts"); }
    | Stmts
Stmts: Stmt { $$ = new ParseTree("stmts", $1); }
    | Stmts Stmt { $1->addChild($2); }
  /* no PrintStmt necessary because it is invoked as a call?? */
Stmt: Exprq T_Semicolon | StmtBlock | IfStmt | WhileStmt | ForStmt | BreakStmt
    | ReturnStmt | PrintStmt

  /* Statements */
IfStmt: MatchedIf | OpenIf
MatchedIf: T_If Expr StmtBlock T_Else StmtBlock { $$ = new ParseTree("if", $2, $3, $5); }
OpenIf: T_If Expr StmtBlock { $$ = new ParseTree("if", $2, $3); }

WhileStmt: T_While T_LParen Expr T_RParen Stmt { $$ = new ParseTree("while", $3, $5); }

  /* inconsistent output (NULL instead of nullstmt) */
ForStmt: T_For T_LParen ForExprq T_Semicolon Expr T_Semicolon ForExprq T_RParen Stmt { $$ = new ParseTree("for", $3, $5, $7, $9); }
ForExprq:
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
NewArrayType: Type | Y_Identifier { $$ = new ParseTree("usertype", $1); }
Type: Primtype { $$ = new ParseTree("primtype", $1); }
    | Usertype { $$ = new ParseTree("usertype", $1); }
    | Lsttype { $$ = new ParseTree("arraytype", $1); }

Primtype: Y_Int | Y_Double | Y_Bool | Y_String
Usertype: Y_TypeIdentifier
Lsttype: Type T_LBracket T_RBracket

  /* terminals */
Y_IntConstant: T_IntConstant { $$ = new ParseTree(myTok); }
Y_DoubleConstant: T_DoubleConstant { $$ = new ParseTree(myTok); }
Y_BoolConstant: T_BoolConstant { $$ = new ParseTree(myTok); }
Y_StringConstant: T_StringConstant { $$ = new ParseTree(myTok); }
Y_Int: T_Int { $$ = new ParseTree(myTok); }
Y_Double: T_Double { $$ = new ParseTree(myTok); }
Y_Bool: T_Bool { $$ = new ParseTree(myTok); }
Y_String: T_String { $$ = new ParseTree(myTok); }
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
