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
    0,    1,    1,    2,    2,    2,    2,    6,    6,    8,
    9,    9,   10,   10,    5,    5,   14,   14,   14,   15,
   15,   18,   18,   16,   16,   16,    3,   19,    4,    4,
   12,   12,   21,   21,   20,   22,   22,   24,   24,   23,
   23,   25,   25,   26,   26,   26,   26,   26,   26,   26,
   26,   28,   28,   34,   35,   29,   30,   37,   37,   31,
   32,   32,   33,   27,   27,   36,   36,   44,   44,   46,
   46,   48,   48,   48,   50,   50,   50,   50,   50,   53,
   53,   53,   58,   58,   58,   58,   61,   61,   61,   65,
   65,   65,   65,   65,   65,   65,   65,   65,   66,   66,
   66,   66,   66,   42,   42,   42,   75,   76,   68,   68,
   77,   77,   41,   41,   69,   69,   11,   11,   11,   78,
   78,   78,   78,   79,   80,   70,   71,   72,   73,   81,
   82,   83,   84,   17,    7,   67,   74,   38,   39,   40,
   13,   43,   45,   57,   59,   60,   62,   63,   52,   54,
   55,   56,   49,   51,   47,   64,
};
static const short yylen[] = {                            2,
    1,    1,    2,    1,    1,    1,    1,    4,    1,    3,
    3,    2,    6,    6,    7,    7,    0,    2,    2,    0,
    1,    2,    3,    0,    2,    2,    2,    2,    6,    6,
    0,    1,    1,    3,    4,    0,    1,    1,    2,    0,
    1,    1,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    5,    3,    5,    9,    0,    1,    2,
    2,    3,    5,    0,    1,    3,    1,    3,    1,    3,
    1,    3,    3,    1,    3,    3,    3,    3,    1,    3,
    3,    1,    3,    3,    3,    1,    2,    2,    1,    1,
    1,    1,    1,    3,    3,    3,    4,    6,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    4,    4,    4,
    0,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
  141,  130,  131,  132,  133,    0,    0,  134,    0,    0,
    2,    4,    5,    6,    7,    9,    0,    0,  124,    0,
  117,  118,  119,  120,  121,  122,  123,  135,    0,    0,
    0,    0,    3,    0,    0,    0,   27,    0,    0,    0,
    0,   10,   12,    0,    0,  125,    0,    0,   18,   19,
    0,    0,    0,    0,    8,   11,    0,    0,    0,    0,
   33,    0,    0,   22,   24,    0,   24,    0,    0,   28,
    0,    0,    0,    0,   23,    0,    0,    0,    0,   29,
   34,   30,   15,   25,   26,   16,    0,    0,   38,    0,
    0,   13,   14,  137,  136,    0,    0,    0,  139,  138,
    0,    0,  140,    0,    0,  126,  128,  127,  129,  145,
  156,    0,    0,   45,    0,    0,   42,    0,   46,   47,
   48,   49,   50,   51,   52,   53,   65,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   86,    0,
    0,   90,   92,   93,   99,  100,  101,  102,  103,    0,
  106,   39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   35,   43,   44,   60,   61,    0,    0,  142,    0,
  143,    0,  155,    0,  153,  154,    0,    0,  149,  150,
  151,  152,    0,    0,    0,    0,  144,    0,    0,  146,
  147,  148,    0,    0,    0,   91,    0,    0,    0,    0,
    0,   59,    0,    0,    0,    0,    0,   95,   96,   94,
  113,    0,    0,   62,    0,   66,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   83,   84,   85,  107,
    0,    0,    0,    0,    0,   97,    0,    0,  109,    0,
  108,  110,    0,   56,   54,  116,    0,    0,  114,   63,
    0,   98,    0,    0,   57,
};
static const short yydgoto[] = {                          9,
   10,   11,   12,   13,   14,   15,  113,   16,   32,   43,
   59,   60,   18,   39,   52,   74,   19,   53,   20,  114,
   62,   90,  115,   91,  116,  117,  118,  119,  120,  121,
  122,  123,  124,  125,  126,  127,  203,  128,  129,  130,
  212,  131,  170,  132,  172,  133,  174,  134,  177,  135,
  178,  183,  136,  184,  185,  186,  188,  137,  138,  193,
  139,  194,  195,  140,  141,  142,  143,  144,  248,  145,
  146,  147,  148,  149,  150,  151,  213,   21,   22,   23,
   24,   25,   26,   27,
};
static const short yysindex[] = {                        98,
    0,    0,    0,    0,    0,   -3,  -16,    0,    0,   98,
    0,    0,    0,    0,    0,    0,   25,  -16,    0,  -34,
    0,    0,    0,    0,    0,    0,    0,    0,   40,   40,
    3,   14,    0,   28,   34,   67,    0,   -3,   48,   48,
   22,    0,    0,   25,  -16,    0,  110,  110,    0,    0,
  -16,   38,   75,   72,    0,    0,   77,   80,   25,   94,
    0,  111,  114,    0,    0,  -16,    0,  110,  110,    0,
  116,  110,  116,   27,    0,   93,  131,  136,  110,    0,
    0,    0,    0,    0,    0,    0,  144,  147,    0,  292,
  110,    0,    0,    0,    0,  145,  158,  357,    0,    0,
  177,  182,    0,  190,  193,    0,    0,    0,    0,    0,
    0,  357,  203,    0,  165,  292,    0,  153,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  204,  328,  208,
  220,  229,  221,  107,  168,  124,   37,  386,    0,  386,
  112,    0,    0,    0,    0,    0,    0,    0,    0,  227,
    0,    0,  357,  357,  116,  -16,  357,  232,  237,  243,
  357,    0,    0,    0,    0,    0,  253,  357,    0,  357,
    0,  357,    0,  357,    0,    0,  357,  357,    0,    0,
    0,    0,  357,  357,  357,  357,    0,  357,  357,    0,
    0,    0,  357,  357,  357,    0,  112,  112,  -16,  357,
  357,    0,  258,  257,  288,  266,  280,    0,    0,    0,
    0,  281,  278,    0,    8,    0,  221,  107,  168,  168,
  124,  124,  124,  124,   37,   37,    0,    0,    0,    0,
  283,  282,  357,  292,  116,    0,  104,  357,    0,  289,
    0,    0,  290,    0,    0,    0,  293,  298,    0,    0,
  357,    0,  302,  292,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  359,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   -2,   -2,
    0,    0,    0,    0,  313,    0,    0,    0,  309,  309,
    0,    0,    0,    0,    0,    0,  312,  312,    0,    0,
    0,    0,  317,    0,    0,    0,    0,    0,    0,    0,
    0,  323,    0,    0,    0,    0,    0,  312,  312,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  157,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   -7,
  202,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  392,    0,    0,   21,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  438,  294,  279,  148,  661,  244,  530,    0,    0,    0,
  461,    0,    0,    0,    0,    0,    0,    0,    0,  415,
    0,    0,  330,    0,    0,    0,    0,    0,    0,    0,
  331,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  484,  507,    0,    0,
  331,    0,    0,    0,  247,    0,    0,    0,    0,    0,
    0,  336,    0,    0,    0,    0,  319,  199,  674,  687,
  594,  612,  630,  648,  553,  576,    0,    0,    0,    0,
    0,    0,    0,  344,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  339,    0,    0,    0,
  340,    0,    0,  344,    0,
};
static const short yygindex[] = {                         0,
    0,  381,   81,   10,    0,    0,   -4,    0,    0,  351,
    1,   13,   11,  363,  356,  332,    6,    0,  -12,  -67,
    0,    0,    0,    0,    0, -116,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -90,  146,    0,    0,    0,
  230,  -53,    0,    0,    0,  231,    0,  228,    0,  -15,
    0,    0,   51,    0,    0,    0,    0,   24, -131,    0,
  -44,    0,    0,    0,   -1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  200,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 738
static const short yytable[] = {                        163,
   17,   29,   31,   80,  189,   82,   28,  155,   17,   37,
   17,   30,   35,   36,    1,    2,    3,    4,    5,   28,
    8,  160,    1,    2,    3,    4,    5,    1,    2,    3,
    4,    5,   44,   49,   61,   61,   64,    8,  167,   57,
   58,   44,   45,   50,   40,    8,   64,   28,   17,   38,
    8,   45,  238,   41,   70,   61,   61,  240,   51,   81,
   63,   75,  202,  204,   64,   42,  207,  190,  191,  192,
  211,   34,   41,   55,   17,   46,   17,  211,   83,  216,
   77,   78,   47,   85,  196,   85,  196,  205,   65,  189,
  189,  189,  189,    1,    2,    3,    4,    5,    1,    2,
    3,    4,    5,    6,    7,    2,    3,    4,    5,  231,
  211,    2,    3,    4,    5,   48,    8,  244,  196,   66,
  196,    8,   67,  196,  196,   68,   28,    8,   69,  196,
  196,  196,  196,    8,  196,  196,  197,  255,  198,  196,
  196,  196,  243,   71,   86,  175,  176,  249,  227,  228,
  229,  206,  187,  110,   84,   72,   84,  199,  200,   89,
  202,  219,  220,   73,   36,   36,   79,  245,   36,   36,
   36,  152,   36,   36,   36,   36,   36,   36,   36,   36,
   87,   36,   36,   36,   36,   88,   36,   92,   71,   71,
   93,   71,   71,  153,  230,   71,  164,   71,   71,   36,
   36,  179,  180,  181,  182,   36,  154,   36,   36,   37,
   37,  225,  226,   37,   37,   37,  162,   37,   37,   37,
   37,   37,   37,   37,   37,  156,   37,   37,   37,   37,
  157,   37,  246,  221,  222,  223,  224,  247,  158,   70,
   70,  159,   70,   70,   37,   37,   70,  165,   70,   70,
   37,  161,   37,   37,   55,   55,  168,  169,   55,   55,
   55,  173,   55,   55,   55,   55,   55,   55,   55,   55,
  171,   55,   55,   55,   55,  201,   55,   79,   79,   79,
   79,  208,   79,   79,   79,   79,  209,   79,   79,   55,
   55,   79,  210,   79,   79,   55,  214,   55,   55,   94,
   95,  233,  235,   96,   97,   98,  234,   99,  100,  101,
  102,  103,  104,  105,   28,  236,  106,  107,  108,  109,
   69,  110,   69,   69,  237,  238,   69,  239,   69,   69,
  241,  242,  250,  251,  111,   94,   95,   67,   67,   34,
  112,   67,   79,   67,   67,  101,  102,  252,  104,  105,
   28,  254,  106,  107,  108,  109,   28,  110,    1,   20,
   68,   31,   68,   68,   94,   95,   68,   21,   68,   68,
  111,  166,   32,   58,  101,  102,  112,  104,  105,   28,
  111,  106,  107,  108,  109,  112,  110,   64,  115,   58,
   33,   56,   40,   94,   95,   54,  253,  215,   76,  111,
  232,  218,  217,  101,  102,  112,  104,  105,   28,    0,
  106,  107,  108,  109,    0,    0,    0,    0,    0,    0,
  104,  104,  104,  104,  104,  104,  104,  104,  104,  104,
  104,  104,  104,  104,  112,  104,  104,  104,  104,  104,
    0,  104,  104,  105,  105,  105,  105,  105,  105,  105,
  105,  105,  105,  105,  105,  105,  105,    0,  105,  105,
  105,  105,  105,    0,  105,  105,   91,   91,   91,   91,
   91,   91,   91,   91,   91,    0,   91,   91,   91,   91,
    0,   91,   91,   91,   91,   91,    0,   91,   91,   89,
   89,   89,   89,   89,   89,   89,   89,   89,    0,   89,
   89,   89,   89,    0,   89,   89,    0,    0,   89,    0,
   89,   89,   88,   88,   88,   88,   88,   88,   88,   88,
   88,    0,   88,   88,   88,   88,    0,   88,   88,    0,
    0,   88,    0,   88,   88,   87,   87,   87,   87,   87,
   87,   87,   87,   87,    0,   87,   87,   87,   87,    0,
   87,   87,    0,    0,   87,    0,   87,   87,   82,   82,
    0,    0,    0,   82,   82,   82,   82,    0,   82,   82,
   82,   82,    0,   82,   82,    0,    0,   82,    0,   82,
   82,   80,   80,    0,    0,    0,   80,   80,   80,   80,
    0,   80,   80,   80,   80,    0,   80,   80,    0,    0,
   80,    0,   80,   80,   81,   81,    0,    0,    0,   81,
   81,   81,   81,    0,   81,   81,   81,   81,    0,   81,
   81,    0,    0,   81,    0,   81,   81,   75,   75,   75,
   75,    0,   75,   75,   75,   75,    0,   75,   75,    0,
    0,   75,    0,   75,   75,   76,   76,   76,   76,    0,
   76,   76,   76,   76,    0,   76,   76,    0,    0,   76,
    0,   76,   76,   77,   77,   77,   77,    0,   77,   77,
   77,   77,    0,   77,   77,    0,    0,   77,    0,   77,
   77,   78,   78,   78,   78,    0,   78,   78,   78,   78,
    0,   78,   78,    0,    0,   78,    0,   78,   78,   74,
   74,   74,   74,    0,   74,   74,    0,    0,   74,    0,
   74,   74,   72,   72,   72,   72,    0,   72,   72,    0,
    0,   72,    0,   72,   72,   73,   73,   73,   73,    0,
   73,   73,    0,    0,   73,    0,   73,   73,
};
static const short yycheck[] = {                        116,
    0,    6,    7,   71,  136,   73,   23,   98,   11,   44,
   10,    6,   17,   18,    1,    2,    3,    4,    5,   23,
   24,  112,    1,    2,    3,    4,    5,    1,    2,    3,
    4,    5,   32,   38,   47,   48,   44,   24,  129,   44,
   45,   41,   32,   38,   52,   24,   51,   23,   51,   10,
   24,   41,   45,   51,   59,   68,   69,   50,   11,   72,
   48,   66,  153,  154,   44,   52,  157,   31,   32,   33,
  161,   47,   52,   52,   74,   48,   76,  168,   52,  170,
   68,   69,   49,   74,  138,   76,  140,  155,   51,  221,
  222,  223,  224,    1,    2,    3,    4,    5,    1,    2,
    3,    4,    5,    6,    7,    2,    3,    4,    5,  200,
  201,    2,    3,    4,    5,   49,   24,  234,  172,   45,
  174,   24,   51,  177,  178,   49,   23,   24,   49,  183,
  184,  185,  186,   24,  188,  189,  138,  254,  140,  193,
  194,  195,  233,   50,   52,   39,   40,  238,  193,  194,
  195,  156,   29,   30,   74,   45,   76,   46,   47,   79,
  251,  177,  178,   50,    8,    9,   51,  235,   12,   13,
   14,   91,   16,   17,   18,   19,   20,   21,   22,   23,
   50,   25,   26,   27,   28,   50,   30,   44,   41,   42,
   44,   44,   45,   49,  199,   48,   44,   50,   51,   43,
   44,   34,   35,   36,   37,   49,   49,   51,   52,    8,
    9,  188,  189,   12,   13,   14,   52,   16,   17,   18,
   19,   20,   21,   22,   23,   49,   25,   26,   27,   28,
   49,   30,  237,  183,  184,  185,  186,  237,   49,   41,
   42,   49,   44,   45,   43,   44,   48,   44,   50,   51,
   49,   49,   51,   52,    8,    9,   49,   38,   12,   13,
   14,   41,   16,   17,   18,   19,   20,   21,   22,   23,
   42,   25,   26,   27,   28,   49,   30,   34,   35,   36,
   37,   50,   39,   40,   41,   42,   50,   44,   45,   43,
   44,   48,   50,   50,   51,   49,   44,   51,   52,    8,
    9,   44,   15,   12,   13,   14,   50,   16,   17,   18,
   19,   20,   21,   22,   23,   50,   25,   26,   27,   28,
   42,   30,   44,   45,   45,   45,   48,   50,   50,   51,
   48,   50,   44,   44,   43,    8,    9,   44,   45,   47,
   49,   48,   51,   50,   51,   18,   19,   50,   21,   22,
   23,   50,   25,   26,   27,   28,   44,   30,    0,   51,
   42,   50,   44,   45,    8,    9,   48,   51,   50,   51,
   43,   44,   50,   44,   18,   19,   49,   21,   22,   23,
   50,   25,   26,   27,   28,   50,   30,   44,   50,   50,
   10,   41,   30,    8,    9,   40,  251,  168,   67,   43,
  201,  174,  172,   18,   19,   49,   21,   22,   23,   -1,
   25,   26,   27,   28,   -1,   -1,   -1,   -1,   -1,   -1,
   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,
   39,   40,   41,   42,   49,   44,   45,   46,   47,   48,
   -1,   50,   51,   29,   30,   31,   32,   33,   34,   35,
   36,   37,   38,   39,   40,   41,   42,   -1,   44,   45,
   46,   47,   48,   -1,   50,   51,   29,   30,   31,   32,
   33,   34,   35,   36,   37,   -1,   39,   40,   41,   42,
   -1,   44,   45,   46,   47,   48,   -1,   50,   51,   29,
   30,   31,   32,   33,   34,   35,   36,   37,   -1,   39,
   40,   41,   42,   -1,   44,   45,   -1,   -1,   48,   -1,
   50,   51,   29,   30,   31,   32,   33,   34,   35,   36,
   37,   -1,   39,   40,   41,   42,   -1,   44,   45,   -1,
   -1,   48,   -1,   50,   51,   29,   30,   31,   32,   33,
   34,   35,   36,   37,   -1,   39,   40,   41,   42,   -1,
   44,   45,   -1,   -1,   48,   -1,   50,   51,   29,   30,
   -1,   -1,   -1,   34,   35,   36,   37,   -1,   39,   40,
   41,   42,   -1,   44,   45,   -1,   -1,   48,   -1,   50,
   51,   29,   30,   -1,   -1,   -1,   34,   35,   36,   37,
   -1,   39,   40,   41,   42,   -1,   44,   45,   -1,   -1,
   48,   -1,   50,   51,   29,   30,   -1,   -1,   -1,   34,
   35,   36,   37,   -1,   39,   40,   41,   42,   -1,   44,
   45,   -1,   -1,   48,   -1,   50,   51,   34,   35,   36,
   37,   -1,   39,   40,   41,   42,   -1,   44,   45,   -1,
   -1,   48,   -1,   50,   51,   34,   35,   36,   37,   -1,
   39,   40,   41,   42,   -1,   44,   45,   -1,   -1,   48,
   -1,   50,   51,   34,   35,   36,   37,   -1,   39,   40,
   41,   42,   -1,   44,   45,   -1,   -1,   48,   -1,   50,
   51,   34,   35,   36,   37,   -1,   39,   40,   41,   42,
   -1,   44,   45,   -1,   -1,   48,   -1,   50,   51,   39,
   40,   41,   42,   -1,   44,   45,   -1,   -1,   48,   -1,
   50,   51,   39,   40,   41,   42,   -1,   44,   45,   -1,
   -1,   48,   -1,   50,   51,   39,   40,   41,   42,   -1,
   44,   45,   -1,   -1,   48,   -1,   50,   51,
};
#define YYFINAL 9
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
"Decl : ClassDecl",
"Decl : InterfaceDecl",
"InterfaceDecl : T_Interface Y_Identifier T_LBrace T_RBrace",
"InterfaceDecl : InterfaceDecl2",
"InterfaceDecl2 : T_Interface InterfaceMiddle T_RBrace",
"InterfaceMiddle : Y_Identifier T_LBrace Prototype",
"InterfaceMiddle : InterfaceMiddle Prototype",
"Prototype : Type Y_Identifier T_LParen Formalsq T_RParen T_Semicolon",
"Prototype : Y_Void Y_Identifier T_LParen Formalsq T_RParen T_Semicolon",
"ClassDecl : T_Class Y_Identifier Extendsq Implementsq T_LBrace Fieldsq T_RBrace",
"ClassDecl : T_Class Y_TypeIdentifier Extendsq Implementsq T_LBrace Fieldsq T_RBrace",
"Extendsq :",
"Extendsq : T_Extends Y_Identifier",
"Extendsq : T_Extends Y_TypeIdentifier",
"Implementsq :",
"Implementsq : Implements",
"Implements : T_Implements Y_Identifier",
"Implements : Implements T_Comma Y_Identifier",
"Fieldsq :",
"Fieldsq : Fieldsq VariableDecl",
"Fieldsq : Fieldsq FunctionDecl",
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
#line 262 "decaf.y"

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
#line 649 "y.tab.c"

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
case 8:
#line 97 "decaf.y"
	{ yyval = new ParseTree("interface", yystack.l_mark[-2]); }
break;
case 10:
#line 100 "decaf.y"
	{ yyval = yystack.l_mark[-1]; }
break;
case 11:
#line 102 "decaf.y"
	{ yyval = new ParseTree("interface", yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 12:
#line 103 "decaf.y"
	{ yystack.l_mark[-1] -> addChild(yystack.l_mark[0]); }
break;
case 13:
#line 105 "decaf.y"
	{ yyval = new ParseTree("prototype", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-2]); }
break;
case 14:
#line 106 "decaf.y"
	{ yyval = new ParseTree("prototype", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-2]); }
break;
case 15:
#line 109 "decaf.y"
	{ yyval = new ParseTree("class", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 16:
#line 110 "decaf.y"
	{ yyval = new ParseTree("class", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 18:
#line 112 "decaf.y"
	{ yyval = new ParseTree("extends", yystack.l_mark[0]); }
break;
case 19:
#line 113 "decaf.y"
	{ yyval = new ParseTree("extends", yystack.l_mark[0]); }
break;
case 22:
#line 116 "decaf.y"
	{ yyval = new ParseTree("implements", yystack.l_mark[0]); }
break;
case 23:
#line 117 "decaf.y"
	{ yystack.l_mark[-2]->addChild(yystack.l_mark[0]); }
break;
case 24:
#line 118 "decaf.y"
	{ yyval = new ParseTree("fields"); }
break;
case 25:
#line 119 "decaf.y"
	{ yystack.l_mark[-1] -> addChild(yystack.l_mark[0]); }
break;
case 26:
#line 120 "decaf.y"
	{ yystack.l_mark[-1] -> addChild(yystack.l_mark[0]); }
break;
case 28:
#line 125 "decaf.y"
	{ yyval = new ParseTree("variable", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 29:
#line 128 "decaf.y"
	{ yyval = new ParseTree("functiondecl", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 30:
#line 129 "decaf.y"
	{ yyval = new ParseTree("functiondecl", yystack.l_mark[-5], yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 31:
#line 130 "decaf.y"
	{ yyval = new ParseTree("formals"); }
break;
case 33:
#line 132 "decaf.y"
	{ yyval = new ParseTree("formals", yystack.l_mark[0]); }
break;
case 34:
#line 133 "decaf.y"
	{ yystack.l_mark[-2]->addChild(yystack.l_mark[0]); }
break;
case 35:
#line 136 "decaf.y"
	{ yyval = new ParseTree("stmtblock", yystack.l_mark[-2], yystack.l_mark[-1]); }
break;
case 36:
#line 137 "decaf.y"
	{ yyval = new ParseTree("vardecls"); }
break;
case 38:
#line 139 "decaf.y"
	{ yyval = new ParseTree("vardecls", yystack.l_mark[0]); }
break;
case 39:
#line 140 "decaf.y"
	{ yystack.l_mark[-1]->addChild(yystack.l_mark[0]); }
break;
case 40:
#line 141 "decaf.y"
	{ yyval = new ParseTree("stmts"); }
break;
case 42:
#line 143 "decaf.y"
	{ yyval = new ParseTree("stmts", yystack.l_mark[0]); }
break;
case 43:
#line 144 "decaf.y"
	{ yystack.l_mark[-1]->addChild(yystack.l_mark[0]); }
break;
case 54:
#line 151 "decaf.y"
	{ yyval = new ParseTree("if", yystack.l_mark[-3], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 55:
#line 152 "decaf.y"
	{ yyval = new ParseTree("if", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 56:
#line 154 "decaf.y"
	{ yyval = new ParseTree("while", yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 57:
#line 157 "decaf.y"
	{ yyval = new ParseTree("for", yystack.l_mark[-6], yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 60:
#line 162 "decaf.y"
	{ yyval = new ParseTree("break", yystack.l_mark[-1]); }
break;
case 61:
#line 164 "decaf.y"
	{ yyval = new ParseTree("return", yystack.l_mark[-1]); }
break;
case 62:
#line 165 "decaf.y"
	{ yyval = new ParseTree("return", yystack.l_mark[-2], yystack.l_mark[-1]); }
break;
case 63:
#line 167 "decaf.y"
	{ yyval = new ParseTree("print", yystack.l_mark[-4], yystack.l_mark[-2]); }
break;
case 64:
#line 170 "decaf.y"
	{ yyval = new ParseTree("nullstmt"); }
break;
case 66:
#line 172 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 68:
#line 174 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 70:
#line 176 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 72:
#line 178 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 73:
#line 179 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 75:
#line 181 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 76:
#line 182 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 77:
#line 183 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 78:
#line 184 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 80:
#line 186 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 81:
#line 187 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 83:
#line 189 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 84:
#line 190 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 85:
#line 191 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 87:
#line 193 "decaf.y"
	{ yyval = new ParseTree("uop", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 88:
#line 194 "decaf.y"
	{ yyval = new ParseTree("uop", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 94:
#line 198 "decaf.y"
	{ yyval = yystack.l_mark[-1]; }
break;
case 95:
#line 199 "decaf.y"
	{ yyval = new ParseTree("readinteger"); }
break;
case 96:
#line 200 "decaf.y"
	{ yyval = new ParseTree("readline"); }
break;
case 97:
#line 201 "decaf.y"
	{ yyval = new ParseTree("new", yystack.l_mark[-1]); }
break;
case 98:
#line 202 "decaf.y"
	{ yyval = new ParseTree("newarray", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 107:
#line 207 "decaf.y"
	{ yyval = new ParseTree("field_access", yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 108:
#line 208 "decaf.y"
	{ yyval = new ParseTree("aref", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 109:
#line 209 "decaf.y"
	{ yyval = new ParseTree("call", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 110:
#line 210 "decaf.y"
	{ yyval = new ParseTree("call", yystack.l_mark[-3], yystack.l_mark[-1]); }
break;
case 111:
#line 211 "decaf.y"
	{ yyval = new ParseTree("actuals"); }
break;
case 113:
#line 213 "decaf.y"
	{ yyval = new ParseTree("actuals", yystack.l_mark[0]); }
break;
case 114:
#line 214 "decaf.y"
	{ yystack.l_mark[-2]->addChild(yystack.l_mark[0]); }
break;
case 116:
#line 217 "decaf.y"
	{ yyval = new ParseTree("usertype", yystack.l_mark[0]); }
break;
case 117:
#line 218 "decaf.y"
	{ yyval = new ParseTree("primtype", yystack.l_mark[0]); }
break;
case 118:
#line 219 "decaf.y"
	{ yyval = new ParseTree("usertype", yystack.l_mark[0]); }
break;
case 119:
#line 220 "decaf.y"
	{ yyval = new ParseTree("arraytype", yystack.l_mark[0]); }
break;
case 126:
#line 227 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 127:
#line 228 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 128:
#line 229 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 129:
#line 230 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 130:
#line 231 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 131:
#line 232 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 132:
#line 233 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 133:
#line 234 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 134:
#line 235 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 135:
#line 236 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 136:
#line 237 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 137:
#line 238 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 138:
#line 239 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 139:
#line 240 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 140:
#line 241 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 141:
#line 242 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 142:
#line 245 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 143:
#line 246 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 144:
#line 247 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 145:
#line 248 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 146:
#line 249 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 147:
#line 250 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 148:
#line 251 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 149:
#line 252 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 150:
#line 253 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 151:
#line 254 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 152:
#line 255 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 153:
#line 256 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 154:
#line 257 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 155:
#line 258 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 156:
#line 259 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
#line 1263 "y.tab.c"
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
