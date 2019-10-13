#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 60 "decaf.y"
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

 
#line 44 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define T_Void 1
#define T_Int 2
#define T_Double 3
#define T_Bool 4
#define T_String 5
#define T_Class 6
#define T_Interface 7
#define T_Null 8
#define T_This 9
#define T_Extends 10
#define T_Implements 11
#define T_For 12
#define T_While 13
#define T_If 14
#define T_Else 15
#define T_Return 16
#define T_Break 17
#define T_New 18
#define T_NewArray 19
#define T_Print 20
#define T_ReadInteger 21
#define T_ReadLine 22
#define T_Identifier 23
#define T_TypeIdentifier 24
#define T_IntConstant 25
#define T_BoolConstant 26
#define T_DoubleConstant 27
#define T_StringConstant 28
#define T_Plus 29
#define T_Minus 30
#define T_Times 31
#define T_Div 32
#define T_Mod 33
#define T_Less 34
#define T_LessEqual 35
#define T_Greater 36
#define T_GreaterEqual 37
#define T_Assign 38
#define T_Equal 39
#define T_NotEqual 40
#define T_And 41
#define T_Or 42
#define T_Not 43
#define T_Semicolon 44
#define T_Comma 45
#define T_Dot 46
#define T_LBracket 47
#define T_RBracket 48
#define T_LParen 49
#define T_RParen 50
#define T_LBrace 51
#define T_RBrace 52
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    5,    4,    4,    8,
    8,   11,   11,    9,   12,   12,   14,   14,   13,   13,
   15,   15,   16,   16,   16,   16,   16,   16,   16,   16,
   18,   18,   24,   25,   19,   20,   27,   27,   21,   22,
   22,   23,   17,   17,   26,   26,   34,   34,   36,   36,
   38,   38,   38,   40,   40,   40,   40,   40,   43,   43,
   43,   48,   48,   48,   48,   51,   51,   51,   55,   55,
   55,   55,   55,   55,   55,   55,   55,   56,   56,   56,
   56,   56,   32,   32,   32,   65,   66,   58,   58,   67,
   67,   31,   31,   59,   59,    6,    6,    6,   68,   68,
   68,   68,   69,   70,   60,   61,   62,   63,   71,   72,
   73,   74,   75,    7,   57,   64,   28,   29,   30,   10,
   33,   35,   47,   49,   50,   52,   53,   42,   44,   45,
   46,   39,   41,   37,   54,
};
static const short yylen[] = {                            2,
    1,    1,    2,    1,    1,    2,    2,    6,    6,    0,
    1,    1,    3,    4,    0,    1,    1,    2,    0,    1,
    1,    2,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    5,    3,    5,    9,    0,    1,    2,    2,
    3,    5,    0,    1,    3,    1,    3,    1,    3,    1,
    3,    3,    1,    3,    3,    3,    3,    1,    3,    3,
    1,    3,    3,    3,    1,    2,    2,    1,    1,    1,
    1,    1,    3,    3,    3,    4,    6,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    4,    4,    4,    0,
    1,    1,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
  120,  109,  110,  111,  112,  113,    0,    0,    2,    4,
    5,    0,    0,    0,   96,   97,   98,   99,  100,  101,
  102,  103,    3,    6,  114,    0,    0,    0,  104,    0,
    0,   12,    0,    0,    0,    0,    7,    0,    0,    0,
    0,    8,   13,    9,   17,    0,    0,  116,  115,    0,
    0,    0,  118,  117,    0,    0,  119,    0,    0,  105,
  107,  106,  108,  124,  135,    0,    0,   24,    0,    0,
   21,    0,   25,   26,   27,   28,   29,   30,   31,   32,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   65,    0,    0,   69,   71,   72,   78,   79,
   80,   81,   82,    0,   85,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,   22,   23,   39,   40,
    0,    0,  121,    0,  122,    0,  134,    0,  132,  133,
    0,    0,  128,  129,  130,  131,    0,    0,    0,    0,
  123,    0,    0,  125,  126,  127,    0,    0,    0,   70,
    0,    0,    0,    0,    0,   38,    0,    0,    0,    0,
    0,   74,   75,   73,   92,    0,    0,   41,    0,   45,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   62,   63,   64,   86,    0,    0,    0,    0,    0,   76,
    0,    0,   88,    0,   87,   89,    0,   35,   33,    0,
   95,    0,   93,   42,    0,   77,    0,    0,   36,
};
static const short yydgoto[] = {                          7,
    8,    9,   10,   11,   12,   33,   67,   34,   68,   14,
   35,   46,   69,   47,   70,   71,   72,   73,   74,   75,
   76,   77,   78,   79,   80,   81,  157,   82,   83,   84,
  166,   85,  124,   86,  126,   87,  128,   88,  131,   89,
  132,  137,   90,  138,  139,  140,  142,   91,   92,  147,
   93,  148,  149,   94,   95,   96,   97,   98,  202,   99,
  100,  101,  102,  103,  104,  105,  167,   15,   16,   17,
   18,   19,   20,   21,   22,
};
static const short yysindex[] = {                        14,
    0,    0,    0,    0,    0,    0,    0,   14,    0,    0,
    0,  -36,  -10,   17,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    5,  -37,   31,    0,   82,
   82,    0,  -10,   33,   59,   46,    0,   -1,   82,   -1,
   82,    0,    0,    0,    0,  286,   82,    0,    0,   85,
   92,   39,    0,    0,  100,  103,    0,  117,  126,    0,
    0,    0,    0,    0,    0,   39,  134,    0,   61,  286,
    0,   76,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,    2,  137,   99,  102,  152,   51,  162,   71,
  301,  322,    0,  322,   78,    0,    0,    0,    0,    0,
    0,    0,    0,  157,    0,    0,   39,   39,   -1,   17,
   39,  108,  161,  170,   39,    0,    0,    0,    0,    0,
  163,   39,    0,   39,    0,   39,    0,   39,    0,    0,
   39,   39,    0,    0,    0,    0,   39,   39,   39,   39,
    0,   39,   39,    0,    0,    0,   39,   39,   39,    0,
   78,   78,   17,   39,   39,    0,  181,  186,  216,  192,
  156,    0,    0,    0,    0,  201,  206,    0,    4,    0,
  152,   51,  162,  162,   71,   71,   71,   71,  301,  301,
    0,    0,    0,    0,  217,  220,   39,  286,   -1,    0,
   74,   39,    0,  232,    0,    0,  237,    0,    0,  240,
    0,  246,    0,    0,   39,    0,  247,  286,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,  291,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  257,    0,    0,  260,
  260,    0,    0,    0,  265,    0,    0,    0,    0,    0,
  151,    0,    0,    0,    0,  -18,  196,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  328,    0,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  374,   64,   -9,   88,  106,  193,
  466,    0,    0,    0,  397,    0,    0,    0,    0,    0,
    0,    0,    0,  351,    0,    0,  275,    0,    0,    0,
    0,    0,    0,    0,  272,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  420,  443,    0,    0,  272,    0,    0,    0,  241,    0,
    0,    0,    0,    0,    0,  273,    0,    0,    0,    0,
  140,  276,  579,  592,  238,  530,  548,  566,  489,  512,
    0,    0,    0,    0,    0,    0,    0,  281,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  278,
    0,    0,    0,    0,  288,    0,    0,  281,    0,
};
static const short yygindex[] = {                         0,
    0,  331,   27,    0,   13,    1,  -11,  305,  -34,    0,
    0,    0,    0,    0,    0,  -65,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -52,  141,    0,    0,    0,
  233,  -21,    0,    0,    0,  230,    0,  249,    0,   30,
    0,    0,  214,    0,    0,    0,    0,  109,  -83,    0,
  350,    0,    0,    0,   95,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  187,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 643
static const short yytable[] = {                        109,
   13,   27,   28,   42,  117,   44,  143,   24,   13,   48,
   49,   30,   25,  114,    1,    2,    3,    4,    5,   55,
   56,   37,   58,   59,   25,   43,   60,   61,   62,   63,
  121,   64,   48,   19,   48,   48,   26,    6,   48,   25,
   48,   48,   32,   32,   65,  120,   48,   49,  192,   41,
   66,   43,   29,  194,  156,  158,   55,   56,  161,   58,
   59,   25,  165,   60,   61,   62,   63,   45,   64,  165,
  150,  170,  150,  106,  159,    2,    3,    4,    5,   31,
   43,   65,   38,    2,    3,    4,    5,   66,   20,  129,
  130,  143,  143,  143,  143,   40,   25,    6,  160,  141,
   64,  185,  165,   39,  150,    6,  150,   46,   46,  150,
  150,   46,  116,   46,   46,  150,  150,  150,  150,  118,
  150,  150,  198,  153,  154,  150,  150,  150,   50,   50,
  119,   50,   50,  107,  197,   50,  123,   50,   50,  203,
  108,  184,  209,  125,   53,   53,   53,   53,  110,   53,
   53,  111,  156,   53,  199,   53,   53,  162,   15,   15,
  173,  174,   15,   15,   15,  112,   15,   15,   15,   15,
   15,   15,   15,   15,  113,   15,   15,   15,   15,  201,
   15,   47,  115,   47,   47,  122,  151,   47,  152,   47,
   47,  200,  127,   15,   15,  133,  134,  135,  136,   15,
  191,   15,   15,   16,   16,  155,  168,   16,   16,   16,
  163,   16,   16,   16,   16,   16,   16,   16,   16,  164,
   16,   16,   16,   16,  187,   16,   58,   58,   58,   58,
  189,   58,   58,   58,   58,  188,   58,   58,   16,   16,
   58,  190,   58,   58,   16,  192,   16,   16,   34,   34,
  179,  180,   34,   34,   34,  193,   34,   34,   34,   34,
   34,   34,   34,   34,  195,   34,   34,   34,   34,  196,
   34,   54,   54,   54,   54,  204,   54,   54,   54,   54,
  205,   54,   54,   34,   34,   54,   26,   54,   54,   34,
    1,   34,   34,   48,   49,  206,  208,   50,   51,   52,
    7,   53,   54,   55,   56,   57,   58,   59,   25,   10,
   60,   61,   62,   63,   11,   64,   49,   49,   37,   49,
   49,   90,   91,   49,   43,   49,   49,   94,   65,   48,
   49,  144,  145,  146,   66,   36,   41,   37,   23,   55,
   56,  186,   58,   59,   25,  207,   60,   61,   62,   63,
  175,  176,  177,  178,  169,  171,   83,   83,   83,   83,
   83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
   66,   83,   83,   83,   83,   83,  172,   83,   83,   84,
   84,   84,   84,   84,   84,   84,   84,   84,   84,   84,
   84,   84,   84,    0,   84,   84,   84,   84,   84,    0,
   84,   84,   70,   70,   70,   70,   70,   70,   70,   70,
   70,    0,   70,   70,   70,   70,    0,   70,   70,   70,
   70,   70,    0,   70,   70,   68,   68,   68,   68,   68,
   68,   68,   68,   68,    0,   68,   68,   68,   68,    0,
   68,   68,    0,    0,   68,    0,   68,   68,   67,   67,
   67,   67,   67,   67,   67,   67,   67,    0,   67,   67,
   67,   67,    0,   67,   67,    0,    0,   67,    0,   67,
   67,   66,   66,   66,   66,   66,   66,   66,   66,   66,
    0,   66,   66,   66,   66,    0,   66,   66,    0,    0,
   66,    0,   66,   66,   61,   61,  181,  182,  183,   61,
   61,   61,   61,    0,   61,   61,   61,   61,    0,   61,
   61,    0,    0,   61,    0,   61,   61,   59,   59,    0,
    0,    0,   59,   59,   59,   59,    0,   59,   59,   59,
   59,    0,   59,   59,    0,    0,   59,    0,   59,   59,
   60,   60,    0,    0,    0,   60,   60,   60,   60,    0,
   60,   60,   60,   60,    0,   60,   60,    0,    0,   60,
    0,   60,   60,   55,   55,   55,   55,    0,   55,   55,
   55,   55,    0,   55,   55,    0,    0,   55,    0,   55,
   55,   56,   56,   56,   56,    0,   56,   56,   56,   56,
    0,   56,   56,    0,    0,   56,    0,   56,   56,   57,
   57,   57,   57,    0,   57,   57,   57,   57,    0,   57,
   57,    0,    0,   57,    0,   57,   57,   51,   51,   51,
   51,    0,   51,   51,    0,    0,   51,    0,   51,   51,
   52,   52,   52,   52,    0,   52,   52,    0,    0,   52,
    0,   52,   52,
};
static const short yycheck[] = {                         52,
    0,   13,   14,   38,   70,   40,   90,   44,    8,    8,
    9,   49,   23,   66,    1,    2,    3,    4,    5,   18,
   19,   33,   21,   22,   23,   44,   25,   26,   27,   28,
   83,   30,   42,   52,   44,   45,   47,   24,   48,   23,
   50,   51,   30,   31,   43,   44,    8,    9,   45,   51,
   49,   39,   48,   50,  107,  108,   18,   19,  111,   21,
   22,   23,  115,   25,   26,   27,   28,   41,   30,  122,
   92,  124,   94,   47,  109,    2,    3,    4,    5,   49,
   44,   43,   50,    2,    3,    4,    5,   49,   52,   39,
   40,  175,  176,  177,  178,   50,   23,   24,  110,   29,
   30,  154,  155,   45,  126,   24,  128,   44,   45,  131,
  132,   48,   52,   50,   51,  137,  138,  139,  140,   44,
  142,  143,  188,   46,   47,  147,  148,  149,   41,   42,
   44,   44,   45,   49,  187,   48,   38,   50,   51,  192,
   49,  153,  208,   42,   39,   40,   41,   42,   49,   44,
   45,   49,  205,   48,  189,   50,   51,   50,    8,    9,
  131,  132,   12,   13,   14,   49,   16,   17,   18,   19,
   20,   21,   22,   23,   49,   25,   26,   27,   28,  191,
   30,   42,   49,   44,   45,   49,   92,   48,   94,   50,
   51,  191,   41,   43,   44,   34,   35,   36,   37,   49,
   45,   51,   52,    8,    9,   49,   44,   12,   13,   14,
   50,   16,   17,   18,   19,   20,   21,   22,   23,   50,
   25,   26,   27,   28,   44,   30,   34,   35,   36,   37,
   15,   39,   40,   41,   42,   50,   44,   45,   43,   44,
   48,   50,   50,   51,   49,   45,   51,   52,    8,    9,
  142,  143,   12,   13,   14,   50,   16,   17,   18,   19,
   20,   21,   22,   23,   48,   25,   26,   27,   28,   50,
   30,   34,   35,   36,   37,   44,   39,   40,   41,   42,
   44,   44,   45,   43,   44,   48,   47,   50,   51,   49,
    0,   51,   52,    8,    9,   50,   50,   12,   13,   14,
   44,   16,   17,   18,   19,   20,   21,   22,   23,   50,
   25,   26,   27,   28,   50,   30,   41,   42,   44,   44,
   45,   50,   50,   48,   44,   50,   51,   50,   43,    8,
    9,   31,   32,   33,   49,   31,   51,   50,    8,   18,
   19,  155,   21,   22,   23,  205,   25,   26,   27,   28,
  137,  138,  139,  140,  122,  126,   29,   30,   31,   32,
   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,
   49,   44,   45,   46,   47,   48,  128,   50,   51,   29,
   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
   40,   41,   42,   -1,   44,   45,   46,   47,   48,   -1,
   50,   51,   29,   30,   31,   32,   33,   34,   35,   36,
   37,   -1,   39,   40,   41,   42,   -1,   44,   45,   46,
   47,   48,   -1,   50,   51,   29,   30,   31,   32,   33,
   34,   35,   36,   37,   -1,   39,   40,   41,   42,   -1,
   44,   45,   -1,   -1,   48,   -1,   50,   51,   29,   30,
   31,   32,   33,   34,   35,   36,   37,   -1,   39,   40,
   41,   42,   -1,   44,   45,   -1,   -1,   48,   -1,   50,
   51,   29,   30,   31,   32,   33,   34,   35,   36,   37,
   -1,   39,   40,   41,   42,   -1,   44,   45,   -1,   -1,
   48,   -1,   50,   51,   29,   30,  147,  148,  149,   34,
   35,   36,   37,   -1,   39,   40,   41,   42,   -1,   44,
   45,   -1,   -1,   48,   -1,   50,   51,   29,   30,   -1,
   -1,   -1,   34,   35,   36,   37,   -1,   39,   40,   41,
   42,   -1,   44,   45,   -1,   -1,   48,   -1,   50,   51,
   29,   30,   -1,   -1,   -1,   34,   35,   36,   37,   -1,
   39,   40,   41,   42,   -1,   44,   45,   -1,   -1,   48,
   -1,   50,   51,   34,   35,   36,   37,   -1,   39,   40,
   41,   42,   -1,   44,   45,   -1,   -1,   48,   -1,   50,
   51,   34,   35,   36,   37,   -1,   39,   40,   41,   42,
   -1,   44,   45,   -1,   -1,   48,   -1,   50,   51,   34,
   35,   36,   37,   -1,   39,   40,   41,   42,   -1,   44,
   45,   -1,   -1,   48,   -1,   50,   51,   39,   40,   41,
   42,   -1,   44,   45,   -1,   -1,   48,   -1,   50,   51,
   39,   40,   41,   42,   -1,   44,   45,   -1,   -1,   48,
   -1,   50,   51,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 52
#if YYDEBUG
static const char *yyname[] = {

"end-of-file","T_Void","T_Int","T_Double","T_Bool","T_String","T_Class",
"T_Interface","T_Null","T_This","T_Extends","T_Implements","T_For","T_While",
"T_If","T_Else","T_Return","T_Break","T_New","T_NewArray","T_Print",
"T_ReadInteger","T_ReadLine","T_Identifier","T_TypeIdentifier","T_IntConstant",
"T_BoolConstant","T_DoubleConstant","T_StringConstant","T_Plus","T_Minus",
"T_Times","T_Div","T_Mod","T_Less","T_LessEqual","T_Greater","T_GreaterEqual",
"T_Assign","T_Equal","T_NotEqual","T_And","T_Or","T_Not","T_Semicolon",
"T_Comma","T_Dot","T_LBracket","T_RBracket","T_LParen","T_RParen","T_LBrace",
"T_RBrace",
};
static const char *yyrule[] = {
"$accept : Program",
"Program : Decls",
"Decls : Decl",
"Decls : Decls Decl",
"Decl : VariableDecl",
"Decl : FunctionDecl",
"VariableDecl : Variable T_Semicolon",
"Variable : Type Y_Identifier",
"FunctionDecl : Type Y_Identifier T_LParen Formalsq T_RParen StmtBlock",
"FunctionDecl : Y_Void Y_Identifier T_LParen Formalsq T_RParen StmtBlock",
"Formalsq :",
"Formalsq : Formals",
"Formals : Variable",
"Formals : Formals T_Comma Variable",
"StmtBlock : T_LBrace StmtVarsq Stmtsq T_RBrace",
"StmtVarsq :",
"StmtVarsq : StmtVars",
"StmtVars : VariableDecl",
"StmtVars : StmtVars VariableDecl",
"Stmtsq :",
"Stmtsq : Stmts",
"Stmts : Stmt",
"Stmts : Stmts Stmt",
"Stmt : Exprq T_Semicolon",
"Stmt : StmtBlock",
"Stmt : IfStmt",
"Stmt : WhileStmt",
"Stmt : ForStmt",
"Stmt : BreakStmt",
"Stmt : ReturnStmt",
"Stmt : PrintStmt",
"IfStmt : MatchedIf",
"IfStmt : OpenIf",
"MatchedIf : T_If Expr StmtBlock T_Else StmtBlock",
"OpenIf : T_If Expr StmtBlock",
"WhileStmt : T_While T_LParen Expr T_RParen Stmt",
"ForStmt : T_For T_LParen ForExprq T_Semicolon Expr T_Semicolon ForExprq T_RParen Stmt",
"ForExprq :",
"ForExprq : Expr",
"BreakStmt : Y_Break T_Semicolon",
"ReturnStmt : Y_Return T_Semicolon",
"ReturnStmt : Y_Return Expr T_Semicolon",
"PrintStmt : Y_Print T_LParen Actuals T_RParen T_Semicolon",
"Exprq :",
"Exprq : Expr",
"Expr : LValue Y_Assign Expr",
"Expr : Expr2",
"Expr2 : Expr2 Y_Or Expr3",
"Expr2 : Expr3",
"Expr3 : Expr3 Y_And Expr4",
"Expr3 : Expr4",
"Expr4 : Expr4 Y_Equal Expr5",
"Expr4 : Expr4 Y_NotEqual Expr5",
"Expr4 : Expr5",
"Expr5 : Expr5 Y_Less Expr6",
"Expr5 : Expr5 Y_LessEqual Expr6",
"Expr5 : Expr5 Y_Greater Expr6",
"Expr5 : Expr5 Y_GreaterEqual Expr6",
"Expr5 : Expr6",
"Expr6 : Expr6 Y_Plus Expr7",
"Expr6 : Expr6 Y_Minus Expr7",
"Expr6 : Expr7",
"Expr7 : Expr7 Y_Times Expr8",
"Expr7 : Expr7 Y_Div Expr8",
"Expr7 : Expr7 Y_Mod Expr8",
"Expr7 : Expr8",
"Expr8 : Y_Not Expr9",
"Expr8 : Y_Minus Expr9",
"Expr8 : Expr9",
"Expr9 : Constant",
"Expr9 : LValue",
"Expr9 : Y_This",
"Expr9 : Call",
"Expr9 : T_LParen Expr T_RParen",
"Expr9 : T_ReadInteger T_LParen T_RParen",
"Expr9 : T_ReadLine T_LParen T_RParen",
"Expr9 : T_New T_LParen Y_Identifier T_RParen",
"Expr9 : T_NewArray T_LParen Expr T_Comma NewArrayType T_RParen",
"Constant : Y_IntConstant",
"Constant : Y_DoubleConstant",
"Constant : Y_BoolConstant",
"Constant : Y_StringConstant",
"Constant : Y_Null",
"LValue : Y_Identifier",
"LValue : FieldAccess",
"LValue : ArrayRef",
"FieldAccess : Expr9 T_Dot Y_Identifier",
"ArrayRef : Expr9 T_LBracket Expr T_RBracket",
"Call : Y_Identifier T_LParen Actualsq T_RParen",
"Call : FieldAccess T_LParen Actualsq T_RParen",
"Actualsq :",
"Actualsq : Actuals",
"Actuals : Expr",
"Actuals : Actuals T_Comma Expr",
"NewArrayType : Type",
"NewArrayType : Y_Identifier",
"Type : Primtype",
"Type : Usertype",
"Type : Lsttype",
"Primtype : Y_Int",
"Primtype : Y_Double",
"Primtype : Y_Bool",
"Primtype : Y_String",
"Usertype : Y_TypeIdentifier",
"Lsttype : Type T_LBracket T_RBracket",
"Y_IntConstant : T_IntConstant",
"Y_DoubleConstant : T_DoubleConstant",
"Y_BoolConstant : T_BoolConstant",
"Y_StringConstant : T_StringConstant",
"Y_Int : T_Int",
"Y_Double : T_Double",
"Y_Bool : T_Bool",
"Y_String : T_String",
"Y_TypeIdentifier : T_TypeIdentifier",
"Y_Identifier : T_Identifier",
"Y_This : T_This",
"Y_Null : T_Null",
"Y_Break : T_Break",
"Y_Return : T_Return",
"Y_Print : T_Print",
"Y_Void : T_Void",
"Y_Assign : T_Assign",
"Y_Or : T_Or",
"Y_Plus : T_Plus",
"Y_Minus : T_Minus",
"Y_Times : T_Times",
"Y_Div : T_Div",
"Y_Mod : T_Mod",
"Y_Less : T_Less",
"Y_LessEqual : T_LessEqual",
"Y_Greater : T_Greater",
"Y_GreaterEqual : T_GreaterEqual",
"Y_Equal : T_Equal",
"Y_NotEqual : T_NotEqual",
"Y_And : T_And",
"Y_Not : T_Not",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 232 "decaf.y"

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
#line 589 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 89 "decaf.y"
	{ yyval = new ParseTree("program", yystack.l_mark[0]); top = yyval; }
break;
case 3:
#line 90 "decaf.y"
	{ yystack.l_mark[-1]->addChild(yystack.l_mark[0]); }
break;
case 7:
#line 95 "decaf.y"
	{ yyval = new ParseTree("variable", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 8:
#line 98 "decaf.y"
	{ yyval = new ParseTree("functiondecl", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 9:
#line 99 "decaf.y"
	{ yyval = new ParseTree("functiondecl", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 10:
#line 100 "decaf.y"
	{ yyval = new ParseTree("formals"); }
break;
case 12:
#line 102 "decaf.y"
	{ yyval = new ParseTree("formals", yystack.l_mark[0]); }
break;
case 13:
#line 103 "decaf.y"
	{ yystack.l_mark[-2]->addChild(yystack.l_mark[0]); }
break;
case 14:
#line 106 "decaf.y"
	{ yyval = new ParseTree("stmtblock", yystack.l_mark[-2], yystack.l_mark[-1]); }
break;
case 15:
#line 107 "decaf.y"
	{ yyval = new ParseTree("vardecls"); }
break;
case 17:
#line 109 "decaf.y"
	{ yyval = new ParseTree("vardecls", yystack.l_mark[0]); }
break;
case 18:
#line 110 "decaf.y"
	{ yystack.l_mark[-1]->addChild(yystack.l_mark[0]); }
break;
case 19:
#line 111 "decaf.y"
	{ yyval = new ParseTree("stmts"); }
break;
case 21:
#line 113 "decaf.y"
	{ yyval = new ParseTree("stmts", yystack.l_mark[0]); }
break;
case 22:
#line 114 "decaf.y"
	{ yystack.l_mark[-1]->addChild(yystack.l_mark[0]); }
break;
case 33:
#line 121 "decaf.y"
	{ yyval = new ParseTree("if", yystack.l_mark[-3], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 34:
#line 122 "decaf.y"
	{ yyval = new ParseTree("if", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 35:
#line 124 "decaf.y"
	{ yyval = new ParseTree("while", yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 36:
#line 127 "decaf.y"
	{ yyval = new ParseTree("for", yystack.l_mark[-6], yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 39:
#line 132 "decaf.y"
	{ yyval = new ParseTree("break", yystack.l_mark[-1]); }
break;
case 40:
#line 134 "decaf.y"
	{ yyval = new ParseTree("return", yystack.l_mark[-1]); }
break;
case 41:
#line 135 "decaf.y"
	{ yyval = new ParseTree("return", yystack.l_mark[-2], yystack.l_mark[-1]); }
break;
case 42:
#line 137 "decaf.y"
	{ yyval = new ParseTree("print", yystack.l_mark[-4], yystack.l_mark[-2]); }
break;
case 43:
#line 140 "decaf.y"
	{ yyval = new ParseTree("nullstmt"); }
break;
case 45:
#line 142 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 47:
#line 144 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 49:
#line 146 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 51:
#line 148 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 52:
#line 149 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 54:
#line 151 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 55:
#line 152 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 56:
#line 153 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 57:
#line 154 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 59:
#line 156 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 60:
#line 157 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 62:
#line 159 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 63:
#line 160 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 64:
#line 161 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 66:
#line 163 "decaf.y"
	{ yyval = new ParseTree("uop", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 67:
#line 164 "decaf.y"
	{ yyval = new ParseTree("uop", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 73:
#line 168 "decaf.y"
	{ yyval = yystack.l_mark[-1]; }
break;
case 74:
#line 169 "decaf.y"
	{ yyval = new ParseTree("readinteger"); }
break;
case 75:
#line 170 "decaf.y"
	{ yyval = new ParseTree("readline"); }
break;
case 76:
#line 171 "decaf.y"
	{ yyval = new ParseTree("new", yystack.l_mark[-1]); }
break;
case 77:
#line 172 "decaf.y"
	{ yyval = new ParseTree("newarray", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 86:
#line 177 "decaf.y"
	{ yyval = new ParseTree("field_access", yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 87:
#line 178 "decaf.y"
	{ yyval = new ParseTree("aref", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 88:
#line 179 "decaf.y"
	{ yyval = new ParseTree("call", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 89:
#line 180 "decaf.y"
	{ yyval = new ParseTree("call", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 90:
#line 181 "decaf.y"
	{ yyval = new ParseTree("actuals"); }
break;
case 92:
#line 183 "decaf.y"
	{ yyval = new ParseTree("actuals", yystack.l_mark[0]); }
break;
case 93:
#line 184 "decaf.y"
	{ yystack.l_mark[-2]->addChild(yystack.l_mark[0]); }
break;
case 95:
#line 187 "decaf.y"
	{ yyval = new ParseTree("usertype", yystack.l_mark[0]); }
break;
case 96:
#line 188 "decaf.y"
	{ yyval = new ParseTree("primtype", yystack.l_mark[0]); }
break;
case 97:
#line 189 "decaf.y"
	{ yyval = new ParseTree("usertype", yystack.l_mark[0]); }
break;
case 98:
#line 190 "decaf.y"
	{ yyval = new ParseTree("arraytype", yystack.l_mark[0]); }
break;
case 105:
#line 197 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 106:
#line 198 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 107:
#line 199 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 108:
#line 200 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 109:
#line 201 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 110:
#line 202 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 111:
#line 203 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 112:
#line 204 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 113:
#line 205 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 114:
#line 206 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 115:
#line 207 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 116:
#line 208 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 117:
#line 209 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 118:
#line 210 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 119:
#line 211 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 120:
#line 212 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 121:
#line 215 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 122:
#line 216 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 123:
#line 217 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 124:
#line 218 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 125:
#line 219 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 126:
#line 220 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 127:
#line 221 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 128:
#line 222 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 129:
#line 223 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 130:
#line 224 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 131:
#line 225 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 132:
#line 226 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 133:
#line 227 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 134:
#line 228 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 135:
#line 229 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
#line 1143 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
