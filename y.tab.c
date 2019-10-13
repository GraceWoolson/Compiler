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
#define Y_Or 257
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    5,    4,    8,    8,
   10,   10,    9,   11,   11,   13,   13,   12,   12,   14,
   14,   15,   16,   16,   17,   17,   20,   21,   18,   22,
   22,   22,   22,    6,    6,    6,   27,   27,   27,   27,
   28,   29,   23,   24,   25,   26,   30,   31,   32,   33,
   34,    7,   35,   19,
};
static const short yylen[] = {                            2,
    1,    1,    2,    1,    1,    2,    2,    6,    0,    1,
    1,    3,    4,    0,    1,    1,    2,    0,    1,    1,
    2,    2,    0,    1,    3,    1,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
   47,   48,   49,   50,   51,    0,    0,    2,    4,    5,
    0,    0,   34,   35,   36,   37,   38,   39,   40,   41,
    3,    6,   52,    0,    0,   42,    0,   11,    0,    0,
    0,    7,    0,    0,    0,    8,   12,   16,    0,    0,
   43,   45,   44,   46,   29,    0,    0,   20,    0,   24,
    0,   26,    0,   28,   30,   31,   32,   33,   17,   13,
   21,   22,   54,    0,    0,   25,   27,
};
static const short yydgoto[] = {                          6,
    7,    8,    9,   10,   11,   29,   45,   30,   36,   31,
   39,   46,   40,   47,   48,   49,   50,   51,   64,   52,
   53,   54,   55,   56,   57,   58,   13,   14,   15,   16,
   17,   18,   19,   20,    0,
};
static const short yysindex[] = {                        10,
    0,    0,    0,    0,    0,    0,   10,    0,    0,    0,
  -25,  -22,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -16,   -3,    0,   10,    0,  -22,  -19,
  -12,    0,   -4,   10,   10,    0,    0,    0,   13,   10,
    0,    0,    0,    0,    0,   -2,   13,    0,    4,    0,
   11,    0, -206,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   13,   17,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,   52,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    9,    0,    5,    0,    0,    0,
    6,    0,    0,    0,  -23,    0,    0,    0,  -26,  -17,
    0,    0,    0,    0,    0,    0,  -24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,   47,  -18,    0,  -11,   30,   -5,    0,    0,    0,
    0,    0,    0,    0,   12,    0,   -7,    0,    0,   -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 64
static const short yytable[] = {                         14,
   23,   14,   14,   14,   14,   15,   25,   15,   15,   15,
   15,    1,    2,    3,    4,   28,   38,   23,   22,   23,
   14,   59,   37,   32,   24,   18,   15,   19,   14,   12,
   33,   26,   34,    5,   15,   23,   12,   41,   42,   43,
   44,   41,   42,   43,   44,   27,   35,   62,   63,   60,
   65,    1,    7,   21,    9,   10,   66,    0,   61,    0,
    0,    0,    0,   67,
};
static const short yycheck[] = {                         23,
   23,   25,   26,   27,   28,   23,   12,   25,   26,   27,
   28,    2,    3,    4,    5,   27,   35,   44,   44,   44,
   44,   40,   34,   29,   47,   52,   44,   52,   52,    0,
   50,   48,   45,   24,   52,   23,    7,   25,   26,   27,
   28,   25,   26,   27,   28,   49,   51,   44,   38,   52,
  257,    0,   44,    7,   50,   50,   64,   -1,   47,   -1,
   -1,   -1,   -1,   65,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 257
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
"T_RBrace",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"Y_Or",
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
"Expr2 : Expr3 Y_Or Expr2",
"Expr3 : Constants",
"LValue : Y_Identifier",
"Constants : Y_IntConstant",
"Constants : Y_DoubleConstant",
"Constants : Y_BoolConstant",
"Constants : Y_StringConstant",
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
"Y_Minus : T_Minus",
"Y_Assign : T_Assign",

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
#line 154 "decaf.y"

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
#line 332 "y.tab.c"

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
case 34:
#line 129 "decaf.y"
	{ yyval = new ParseTree("primtype", yystack.l_mark[0]); }
break;
case 35:
#line 130 "decaf.y"
	{ yyval = new ParseTree("usertype", yystack.l_mark[0]); }
break;
case 36:
#line 131 "decaf.y"
	{ yyval = new ParseTree("arraytype", yystack.l_mark[0]); }
break;
case 43:
#line 138 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 44:
#line 139 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 45:
#line 140 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 46:
#line 141 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 47:
#line 142 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 48:
#line 143 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 49:
#line 144 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 50:
#line 145 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 51:
#line 146 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 52:
#line 147 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 53:
#line 150 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
case 54:
#line 151 "decaf.y"
	{ yyval = new ParseTree(myTok); }
break;
#line 662 "y.tab.c"
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
