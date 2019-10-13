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
    0,    1,    1,    2,    2,    3,    5,    4,    8,    8,
   10,   10,    9,   11,   11,   13,   13,   12,   12,   14,
   14,   15,   16,   16,   17,   17,   20,   20,   22,   22,
   24,   24,   24,   26,   26,   26,   26,   26,   29,   29,
   29,   34,   34,   34,   34,   37,   37,   37,   41,   42,
   18,   43,   43,   43,   43,    6,    6,    6,   48,   48,
   48,   48,   49,   50,   44,   45,   46,   47,   51,   52,
   53,   54,   55,    7,   19,   21,   33,   35,   36,   38,
   39,   28,   30,   31,   32,   25,   27,   23,   40,
};
static const short yylen[] = {                            2,
    1,    1,    2,    1,    1,    2,    2,    6,    0,    1,
    1,    3,    4,    0,    1,    1,    2,    0,    1,    1,
    2,    2,    0,    1,    3,    1,    3,    1,    3,    1,
    3,    3,    1,    3,    3,    3,    3,    1,    3,    3,
    1,    3,    3,    3,    1,    2,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
   69,   70,   71,   72,   73,    0,    0,    2,    4,    5,
    0,    0,   56,   57,   58,   59,   60,   61,   62,   63,
    3,    6,   74,    0,    0,   64,    0,   11,    0,    0,
    0,    7,    0,    0,    0,    8,   12,   16,    0,    0,
   65,   67,   66,   68,   78,   89,   51,    0,    0,   20,
    0,   24,    0,    0,    0,    0,    0,    0,    0,    0,
   45,    0,   48,   49,   50,   52,   53,   54,   55,   17,
   13,   21,   22,   75,    0,   76,    0,   88,    0,   86,
   87,    0,    0,   82,   83,   84,   85,    0,    0,    0,
    0,   77,    0,    0,   79,   80,   81,    0,    0,    0,
   47,   46,   25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   42,   43,   44,
};
static const short yydgoto[] = {                          6,
    7,    8,    9,   10,   11,   29,   47,   30,   36,   31,
   39,   48,   40,   49,   50,   51,   52,   53,   75,   54,
   77,   55,   79,   56,   82,   57,   83,   88,   58,   89,
   90,   91,   93,   59,   60,   98,   61,   99,  100,   62,
   63,   64,   65,   66,   67,   68,   69,   13,   14,   15,
   16,   17,   18,   19,   20,
};
static const short yysindex[] = {                        13,
    0,    0,    0,    0,    0,    0,   13,    0,    0,    0,
  -25,  -21,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -13,  -26,    0,   13,    0,  -21,   -6,
   32,    0,   37,   13,   13,    0,    0,    0,   15,   13,
    0,    0,    0,    0,    0,    0,    0,   41,   15,    0,
   54,    0,   -7,   62,   68,   22,  150,   36,   16,  163,
    0,  163,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   15,    0,   29,    0,   29,    0,
    0,   29,   29,    0,    0,    0,    0,   29,   29,   29,
   29,    0,   29,   29,    0,    0,    0,   29,   29,   29,
    0,    0,    0,   68,   22,  150,  150,   36,   36,   36,
   36,   16,   16,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  115,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   76,    0,   81,    0,    0,    0,
   87,    0,    0,    0,  -22,    0,    0,    0,  -20,  -16,
    0,    0,    0,    0,    0,    0,    0,    0,  -19,    0,
    0,    0,    0,   82,   55,  155,  127,   77,   34,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  160,  159,  133,  139,   88,   99,  110,
  121,   50,   66,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  135,   -1,    0,  -14,   60,   17,    0,    0,    0,
    0,    0,    0,    0,  149,    0,   73,    0,    0,    0,
    0,   93,    0,   74,    0,  126,    0,    0,  104,    0,
    0,    0,    0,  117,  -58,    0,  -17,    0,    0,    0,
  145,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 211
static const short yytable[] = {                         94,
   14,   23,   14,   14,   14,   14,   15,   14,   15,   15,
   15,   15,   28,   15,    1,    2,    3,    4,   22,   37,
   14,   14,   27,   23,   23,   24,   15,   15,   25,   14,
   74,   18,   19,   38,   26,   15,    5,   23,   70,   41,
   42,   43,   44,   33,   45,   32,   95,   96,   97,   94,
   94,   94,   94,   41,   42,   43,   44,   46,   45,   12,
   80,   81,   41,   41,   92,   45,   12,   41,   41,   41,
   41,   46,   41,   41,   41,   41,   34,   41,   39,   39,
  114,  115,  116,   39,   39,   39,   39,   35,   39,   39,
   39,   39,   71,   39,   40,   40,   28,   73,   28,   40,
   40,   40,   40,   76,   40,   40,   40,   40,   78,   40,
   38,   38,   38,   38,    1,   38,   38,   38,   38,    7,
   38,   34,   34,   34,   34,   26,   34,   34,   34,   34,
    9,   34,   35,   35,   35,   35,   10,   35,   35,   35,
   35,   21,   35,   36,   36,   36,   36,  103,   36,   36,
   36,   36,  105,   36,   37,   37,   37,   37,    0,   37,
   37,   37,   37,    0,   37,   33,   33,   33,   33,  104,
   33,   31,   31,   31,   31,    0,   31,   32,   32,   32,
   32,    0,   32,   84,   85,   86,   87,   41,   42,   43,
   44,  108,  109,  110,  111,   30,   30,   72,   30,   29,
   29,   27,   29,   27,  101,    0,  102,  106,  107,  112,
  113,
};
static const short yycheck[] = {                         58,
   23,   23,   25,   26,   27,   28,   23,   30,   25,   26,
   27,   28,   27,   30,    2,    3,    4,    5,   44,   34,
   43,   44,   49,   44,   44,   47,   43,   44,   12,   52,
   38,   52,   52,   35,   48,   52,   24,   23,   40,   25,
   26,   27,   28,   50,   30,   29,   31,   32,   33,  108,
  109,  110,  111,   25,   26,   27,   28,   43,   30,    0,
   39,   40,   29,   30,   29,   30,    7,   34,   35,   36,
   37,   43,   39,   40,   41,   42,   45,   44,   29,   30,
   98,   99,  100,   34,   35,   36,   37,   51,   39,   40,
   41,   42,   52,   44,   29,   30,   42,   44,   44,   34,
   35,   36,   37,   42,   39,   40,   41,   42,   41,   44,
   34,   35,   36,   37,    0,   39,   40,   41,   42,   44,
   44,   34,   35,   36,   37,   44,   39,   40,   41,   42,
   50,   44,   34,   35,   36,   37,   50,   39,   40,   41,
   42,    7,   44,   34,   35,   36,   37,   75,   39,   40,
   41,   42,   79,   44,   34,   35,   36,   37,   -1,   39,
   40,   41,   42,   -1,   44,   39,   40,   41,   42,   77,
   44,   39,   40,   41,   42,   -1,   44,   39,   40,   41,
   42,   -1,   44,   34,   35,   36,   37,   25,   26,   27,
   28,   88,   89,   90,   91,   41,   42,   49,   44,   41,
   42,   42,   44,   44,   60,   -1,   62,   82,   83,   93,
   94,
};
#define YYFINAL 6
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
"Expr9 : NoOp",
"NoOp : Constant",
"LValue : Y_Identifier",
"Constant : Y_IntConstant",
"Constant : Y_DoubleConstant",
"Constant : Y_BoolConstant",
"Constant : Y_StringConstant",
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
#line 189 "decaf.y"

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
#line 416 "y.tab.c"

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
	{ yyval = new ParseTree("formals"); }
break;
case 11:
#line 101 "decaf.y"
	{ yyval = new ParseTree("formals", yystack.l_mark[0]); }
break;
case 12:
#line 102 "decaf.y"
	{ yystack.l_mark[-2]->addChild(yystack.l_mark[0]); }
break;
case 13:
#line 105 "decaf.y"
	{ yyval = new ParseTree("stmtblock", yystack.l_mark[-2], yystack.l_mark[-1]); }
break;
case 14:
#line 106 "decaf.y"
	{ yyval = new ParseTree("vardecls"); }
break;
case 16:
#line 108 "decaf.y"
	{ yyval = new ParseTree("vardecls", yystack.l_mark[0]); }
break;
case 17:
#line 109 "decaf.y"
	{ yystack.l_mark[-1]->addChild(yystack.l_mark[0]); }
break;
case 18:
#line 110 "decaf.y"
	{ yyval = new ParseTree("stmts"); }
break;
case 20:
#line 112 "decaf.y"
	{ yyval = new ParseTree("stmts", yystack.l_mark[0]); }
break;
case 21:
#line 113 "decaf.y"
	{ yystack.l_mark[-1]->addChild(yystack.l_mark[0]); }
break;
case 23:
#line 117 "decaf.y"
	{ yyval = new ParseTree("nullstmt"); }
break;
case 25:
#line 119 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 27:
#line 121 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 29:
#line 123 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 31:
#line 125 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 32:
#line 126 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 34:
#line 128 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 35:
#line 129 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 36:
#line 130 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 37:
#line 131 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 39:
#line 133 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 40:
#line 134 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 42:
#line 136 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 43:
#line 137 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 44:
#line 138 "decaf.y"
	{ yyval = new ParseTree("binop", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 46:
#line 140 "decaf.y"
	{ yyval = new ParseTree("uop", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 47:
#line 141 "decaf.y"
	{ yyval = new ParseTree("uop", yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 56:
#line 151 "decaf.y"
	{ yyval = new ParseTree("primtype", yystack.l_mark[0]); }
break;
case 57:
#line 152 "decaf.y"
	{ yyval = new ParseTree("usertype", yystack.l_mark[0]); }
break;
case 58:
#line 153 "decaf.y"
	{ yyval = new ParseTree("arraytype", yystack.l_mark[0]); }
break;
case 65:
#line 160 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 66:
#line 161 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 67:
#line 162 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 68:
#line 163 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 69:
#line 164 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 70:
#line 165 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 71:
#line 166 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 72:
#line 167 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 73:
#line 168 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 74:
#line 169 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 75:
#line 172 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 76:
#line 173 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 77:
#line 174 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 78:
#line 175 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 79:
#line 176 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 80:
#line 177 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 81:
#line 178 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 82:
#line 179 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 83:
#line 180 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 84:
#line 181 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 85:
#line 182 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 86:
#line 183 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 87:
#line 184 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 88:
#line 185 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 89:
#line 186 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
#line 858 "y.tab.c"
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
