/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 59 "decaf.y" /* yacc.c:339  */

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

 

#line 94 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Void = 1,
    T_Int = 2,
    T_Double = 3,
    T_Bool = 4,
    T_String = 5,
    T_Class = 6,
    T_Interface = 7,
    T_Null = 8,
    T_This = 9,
    T_Extends = 10,
    T_Implements = 11,
    T_For = 12,
    T_While = 13,
    T_If = 14,
    T_Else = 15,
    T_Return = 16,
    T_Break = 17,
    T_New = 18,
    T_NewArray = 19,
    T_Print = 20,
    T_ReadInteger = 21,
    T_ReadLine = 22,
    T_Identifier = 23,
    T_TypeIdentifier = 24,
    T_IntConstant = 25,
    T_BoolConstant = 26,
    T_DoubleConstant = 27,
    T_StringConstant = 28,
    T_Plus = 29,
    T_Minus = 30,
    T_Times = 31,
    T_Div = 32,
    T_Mod = 33,
    T_Less = 34,
    T_LessEqual = 35,
    T_Greater = 36,
    T_GreaterEqual = 37,
    T_Assign = 38,
    T_Equal = 39,
    T_NotEqual = 40,
    T_And = 41,
    T_Or = 42,
    T_Not = 43,
    T_Semicolon = 44,
    T_Comma = 45,
    T_Dot = 46,
    T_LBracket = 47,
    T_RBracket = 48,
    T_LParen = 49,
    T_RParen = 50,
    T_LBrace = 51,
    T_RBrace = 52
  };
#endif
/* Tokens.  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    89,    90,    91,    91,    91,    91,    94,
     105,   106,   133,   134,   136,   137,   140,   147,   155,   140,
     175,   182,   190,   175,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   223,   224,   239,   249,   239,   260,
     270,   260,   280,   281,   282,   283,   286,   286,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   297,   298,   298,
     298,   298,   299,   299,   300,   300,   300,   303,   304,   305,
     308,   311,   312,   313,   316,   318,   319,   321,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   351,   351,   351,   351,   352,   353,
     354,   355,   356,   359,   359,   359,   359,   359,   360,   360,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   371,
     371,   372,   373,   374,   376,   378,   380,   382,   384,   398,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Int", "T_Double", "T_Bool",
  "T_String", "T_Class", "T_Interface", "T_Null", "T_This", "T_Extends",
  "T_Implements", "T_For", "T_While", "T_If", "T_Else", "T_Return",
  "T_Break", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Identifier", "T_TypeIdentifier", "T_IntConstant",
  "T_BoolConstant", "T_DoubleConstant", "T_StringConstant", "T_Plus",
  "T_Minus", "T_Times", "T_Div", "T_Mod", "T_Less", "T_LessEqual",
  "T_Greater", "T_GreaterEqual", "T_Assign", "T_Equal", "T_NotEqual",
  "T_And", "T_Or", "T_Not", "T_Semicolon", "T_Comma", "T_Dot",
  "T_LBracket", "T_RBracket", "T_LParen", "T_RParen", "T_LBrace",
  "T_RBrace", "$accept", "Program", "Decls", "Decl", "InterfaceDecl",
  "InterfaceDecl2", "InterfaceMiddle", "Prototype", "ClassDecl", "$@1",
  "@2", "$@3", "$@4", "@5", "$@6", "Extendsq", "Implementsq", "Implements",
  "Fieldsq", "VariableDecl", "Variable", "FunctionDecl", "$@7", "$@8",
  "$@9", "$@10", "Formalsq", "Formals", "StmtBlock", "$@11", "StmtVarsq",
  "StmtVars", "Stmtsq", "Stmts", "Stmt", "MatchedStmt", "UnmatchedStmt",
  "MatchedIf", "OpenIf", "WhileStmt", "ForStmt", "ForExprq", "BreakStmt",
  "ReturnStmt", "PrintStmt", "Exprq", "Expr", "Expr2", "Expr3", "Expr4",
  "Expr5", "Expr6", "Expr7", "Expr8", "Expr9", "Constant", "LValue",
  "FieldAccess", "ArrayRef", "Call", "Actualsq", "Actuals", "NewArrayType",
  "Type", "Primtype", "Usertype", "Lsttype", "Y_IntConstant",
  "Y_DoubleConstant", "Y_BoolConstant", "Y_StringConstant", "Y_Int",
  "Y_Double", "Y_Bool", "Y_String", "Y_TypeIdentifier", "Y_Identifier",
  "Y_This", "Y_Null", "Y_Break", "Y_Return", "Y_Print", "Y_Void",
  "Y_Assign", "Y_Or", "Y_Plus", "Y_Minus", "Y_Times", "Y_Div", "Y_Mod",
  "Y_Less", "Y_LessEqual", "Y_Greater", "Y_GreaterEqual", "Y_Equal",
  "Y_NotEqual", "Y_And", "Y_Not", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52
};
# endif

#define YYPACT_NINF -237

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-237)))

#define YYTABLE_NINF -79

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     187,  -237,  -237,  -237,  -237,  -237,    52,   -18,  -237,     9,
     187,  -237,  -237,  -237,  -237,  -237,   -31,  -237,     4,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,   -18,  -237,  -237,
    -237,    14,   -16,  -237,  -237,  -237,    -9,    -4,     3,    49,
      49,  -237,  -237,     4,   -18,    20,  -237,  -237,  -237,    52,
    -237,  -237,    12,    22,  -237,  -237,   104,   104,  -237,  -237,
      69,    69,   104,   104,  -237,  -237,    37,     4,  -237,   -18,
    -237,    39,  -237,    40,    62,    71,   104,  -237,    77,  -237,
      78,   -18,    81,    72,    90,   100,  -237,   100,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,    29,    53,   104,  -237,
    -237,  -237,  -237,  -237,   156,   104,  -237,  -237,   106,   122,
     136,  -237,  -237,   149,   157,  -237,   159,   163,  -237,  -237,
    -237,  -237,  -237,  -237,   237,  -237,   135,   156,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   172,  -237,
     183,   189,    98,   167,    63,    32,  -237,    96,  -237,   202,
     190,  -237,  -237,  -237,  -237,  -237,  -237,   193,  -237,  -237,
     203,    92,   200,   131,   131,  -237,   237,   237,   237,   -18,
     237,   204,   207,   211,  -237,  -237,  -237,  -237,   237,  -237,
     237,  -237,  -237,   237,   237,  -237,  -237,  -237,  -237,   237,
     237,   237,   237,  -237,   237,   237,  -237,  -237,  -237,   237,
     237,   237,   -18,   237,  -237,   237,   237,   237,  -237,  -237,
     209,   237,    96,  -237,    96,   222,  -237,   220,   221,   223,
     206,  -237,  -237,  -237,   189,    98,   167,   167,    63,    63,
      63,    63,    32,    32,  -237,  -237,  -237,  -237,   224,  -237,
    -237,   225,   229,   226,  -237,   -36,   237,   100,   201,  -237,
      65,  -237,  -237,   237,  -237,   233,   234,  -237,  -237,   264,
     231,   235,  -237,  -237,  -237,   237,   201,  -237,   240,  -237,
    -237,   201,  -237
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   155,   144,   145,   146,   147,     0,     0,   148,     0,
       2,     3,     8,    10,     7,     5,     0,     6,     0,   131,
     132,   133,   134,   135,   136,   137,   138,     0,   149,    20,
      16,     0,     0,     1,     4,    34,     0,    35,     0,    24,
      24,    11,    13,     0,     0,     0,   139,    36,    39,     0,
      21,    17,     0,     0,     9,    12,    42,    42,    26,    25,
      27,    27,    42,    42,    44,    37,    43,     0,    40,     0,
      22,    28,    18,     0,     0,     0,     0,    35,     0,    29,
       0,     0,     0,     0,     0,     0,    45,     0,    31,    30,
      31,    14,    15,    46,    38,    41,     0,     0,    48,    23,
      32,    33,    19,    50,    52,    49,   151,   150,     0,     0,
       0,   153,   152,     0,     0,   154,     0,     0,   140,   142,
     141,   143,   159,   170,     0,    59,     0,    53,    54,    56,
      57,    60,    64,    66,    65,    61,    62,    63,     0,    79,
      81,    83,    85,    88,    93,    96,   100,   103,   104,   105,
     119,   120,   107,   113,   114,   115,   116,   118,   106,   117,
       0,     0,     0,     0,     0,    51,    72,     0,     0,     0,
       0,     0,     0,     0,    47,    55,    58,   157,     0,   169,
       0,   167,   168,     0,     0,   163,   164,   165,   166,     0,
       0,     0,     0,   158,     0,     0,   160,   161,   162,     0,
       0,     0,     0,     0,   156,     0,   125,   125,    74,    75,
       0,     0,   102,   105,   101,     0,    73,     0,     0,     0,
       0,   109,   110,   108,    82,    84,    86,    87,    89,    90,
      91,    92,    94,    95,    97,    98,    99,   121,     0,    80,
     127,     0,   126,     0,    76,     0,     0,     0,    78,   111,
       0,   122,   124,     0,   123,     0,     0,    70,    68,    56,
       0,   129,   130,   128,    77,    72,    78,   112,     0,    67,
      69,    78,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -237,  -237,  -237,   276,  -237,  -237,  -237,   244,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,   253,   239,  -237,   205,   138,
      70,    66,  -237,  -237,  -237,  -237,    18,  -237,   -82,  -237,
    -237,  -237,  -237,  -237,  -123,  -236,    28,  -237,  -237,  -237,
    -237,    38,  -237,  -237,  -237,  -237,  -118,  -237,   126,   125,
     -34,    48,   -26,   -95,    35,  -237,   107,  -237,  -237,  -237,
     102,    99,  -237,     0,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,     2,    -5,  -237,  -237,  -237,
    -237,  -237,    -3,  -237,  -237,  -237,  -130,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    31,    42,    14,    40,
      61,    82,    39,    60,    80,    50,    70,    71,    96,    15,
      16,    17,    56,    75,    57,    78,    65,    66,   125,    98,
     104,   105,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   215,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     241,   242,   260,    67,    19,    20,    21,   153,   154,   155,
     156,    22,    23,    24,    25,    26,   157,   158,   159,   160,
     161,   162,    27,   205,   178,   194,   163,   199,   200,   201,
     189,   190,   191,   192,   183,   184,   180,   164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    30,    32,    94,   175,    95,   173,    28,    29,    33,
      18,   253,   259,    37,   195,    35,   255,     1,     2,     3,
       4,     5,    38,     1,     2,     3,     4,     5,    44,    28,
     269,    43,     1,     2,     3,     4,     5,    45,    52,    53,
       8,    46,    44,   210,    59,    43,     8,    47,   216,   217,
     218,    58,   220,    36,    48,     8,     1,     2,     3,     4,
       5,    49,    77,    62,    79,   196,   197,   198,    41,     2,
       3,     4,     5,    63,    54,    68,    89,    28,     8,     8,
      73,    74,    69,    99,    76,   238,    81,   239,   240,   240,
      28,     8,    83,   240,   193,   122,    18,    18,   195,   195,
     195,   195,   106,   107,   234,   235,   236,   102,     2,     3,
       4,     5,   113,   114,    84,   116,   117,    28,    91,   118,
     119,   120,   121,    85,   122,   258,    64,    64,   256,    87,
       8,    88,    64,    64,    90,   263,    92,   123,   209,   181,
     182,   106,   107,   124,   202,   203,    86,   216,   272,   226,
     227,   113,   114,    93,   116,   117,    28,   166,   118,   119,
     120,   121,   101,   101,   219,   257,   106,   107,   232,   233,
     108,   109,   110,   167,   111,   112,   113,   114,   115,   116,
     117,    28,   124,   118,   119,   120,   121,   168,   122,   174,
       1,     2,     3,     4,     5,     6,     7,   237,   212,   214,
     169,   123,   -78,   185,   186,   187,   188,   124,   170,    93,
     171,   106,   107,     8,   172,   108,   109,   110,   176,   111,
     112,   113,   114,   115,   116,   117,    28,   177,   118,   119,
     120,   121,   179,   122,   100,   100,   103,   228,   229,   230,
     231,   206,   204,   165,   207,   262,   123,   106,   107,   208,
     261,   211,   124,   250,    93,   244,   221,   113,   114,   222,
     116,   117,    28,   223,   118,   119,   120,   121,   246,   122,
     213,   213,   247,   248,   251,   249,   253,   252,   254,   264,
     265,   266,   123,   267,    36,   213,    34,   213,   124,    55,
     213,   213,   271,    51,   270,    97,   213,   213,   213,   213,
      72,   213,   213,   268,   224,   225,   213,   213,   213,   243,
     245
};

static const yytype_uint16 yycheck[] =
{
       0,     6,     7,    85,   127,    87,   124,    25,     6,     0,
      10,    47,   248,    18,   144,    46,    52,     3,     4,     5,
       6,     7,    27,     3,     4,     5,     6,     7,    31,    25,
     266,    31,     3,     4,     5,     6,     7,    53,    43,    44,
      26,    50,    45,   161,    49,    45,    26,    51,   166,   167,
     168,    49,   170,    49,    51,    26,     3,     4,     5,     6,
       7,    12,    67,    51,    69,    33,    34,    35,    54,     4,
       5,     6,     7,    51,    54,    57,    81,    25,    26,    26,
      62,    63,    13,    54,    47,   203,    47,   205,   206,   207,
      25,    26,    52,   211,    31,    32,    96,    97,   228,   229,
     230,   231,    10,    11,   199,   200,   201,    54,     4,     5,
       6,     7,    20,    21,    52,    23,    24,    25,    46,    27,
      28,    29,    30,    52,    32,   248,    56,    57,   246,    52,
      26,    53,    62,    63,    53,   253,    46,    45,    46,    41,
      42,    10,    11,    51,    48,    49,    76,   265,   271,   183,
     184,    20,    21,    53,    23,    24,    25,    51,    27,    28,
      29,    30,    96,    97,   169,   247,    10,    11,   194,   195,
      14,    15,    16,    51,    18,    19,    20,    21,    22,    23,
      24,    25,    51,    27,    28,    29,    30,    51,    32,    54,
       3,     4,     5,     6,     7,     8,     9,   202,   163,   164,
      51,    45,    46,    36,    37,    38,    39,    51,    51,    53,
      51,    10,    11,    26,    51,    14,    15,    16,    46,    18,
      19,    20,    21,    22,    23,    24,    25,    44,    27,    28,
      29,    30,    43,    32,    96,    97,    98,   189,   190,   191,
     192,    51,    40,   105,    51,   250,    45,    10,    11,    46,
     250,    51,    51,    47,    53,    46,    52,    20,    21,    52,
      23,    24,    25,    52,    27,    28,    29,    30,    46,    32,
     163,   164,    52,    52,    50,    52,    47,    52,    52,    46,
      46,    17,    45,    52,    49,   178,    10,   180,    51,    45,
     183,   184,    52,    40,   266,    90,   189,   190,   191,   192,
      61,   194,   195,   265,   178,   180,   199,   200,   201,   207,
     211
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    26,    56,
      57,    58,    59,    60,    63,    74,    75,    76,   118,   119,
     120,   121,   126,   127,   128,   129,   130,   137,    25,   130,
     131,    61,   131,     0,    58,    46,    49,   131,   131,    67,
      64,    54,    62,   118,   137,    53,    50,    51,    51,    12,
      70,    70,   131,   131,    54,    62,    77,    79,   130,   131,
      68,    65,    51,    51,    75,    81,    82,   118,    81,    13,
      71,    72,    71,    81,    81,    78,    47,   131,    80,   131,
      69,    47,    66,    52,    52,    52,    75,    52,    53,   131,
      53,    46,    46,    53,    83,    83,    73,    73,    84,    54,
      74,    76,    54,    74,    85,    86,    10,    11,    14,    15,
      16,    18,    19,    20,    21,    22,    23,    24,    27,    28,
      29,    30,    32,    45,    51,    83,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   122,   123,   124,   125,   131,   132,   133,
     134,   135,   136,   141,   152,    74,    51,    51,    51,    51,
      51,    51,    51,   101,    54,    89,    46,    44,   139,    43,
     151,    41,    42,   149,   150,    36,    37,    38,    39,   145,
     146,   147,   148,    31,   140,   141,    33,    34,    35,   142,
     143,   144,    48,    49,    40,   138,    51,    51,    46,    46,
     101,    51,   109,   111,   109,    96,   101,   101,   101,   131,
     101,    52,    52,    52,   103,   104,   105,   105,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   131,   101,   101,
     101,   115,   116,   115,    46,   116,    46,    52,    52,    52,
      47,    50,    52,    47,    52,    52,   101,    83,    89,    90,
     117,   118,   131,   101,    46,    46,    17,    52,    96,    90,
      91,    52,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    61,    61,    62,    62,    64,    65,    66,    63,
      67,    68,    69,    63,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    75,    77,    78,    76,    79,
      80,    76,    81,    81,    82,    82,    84,    83,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    92,    93,    93,
      94,    95,    96,    96,    97,    98,    98,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   105,
     105,   105,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   110,   110,   110,   111,   111,
     111,   112,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   119,   119,   119,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     4,
       1,     3,     3,     2,     6,     6,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     2,     2,     0,     1,     2,
       3,     0,     2,     2,     2,     2,     0,     0,     8,     0,
       0,     8,     0,     1,     1,     3,     0,     5,     0,     1,
       1,     2,     0,     1,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     5,     7,
       5,     9,     0,     1,     2,     2,     3,     5,     0,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     4,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     4,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 89 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("program", (yyvsp[0])); top = (yyval); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("interface", (yyvsp[-2]));
                    Token *tok = (yyvsp[-2])->token;
                    semantics *test = currentScope->local_lookup(tok->text);
                    if (test) semantic_error("Interface redefined", tok->line);
                    currentInterface = new S_interface;
                    currentInterface->name = tok->text;
                    currentInterface->line = tok->line;
                    currentScope->insert(tok->text, currentInterface);
                    all_decls.push_back(currentInterface);
                    (yyval)->sem = currentInterface;
                }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "decaf.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);
                    Token *tok = (yyvsp[-1])->children[0]->token;
                    semantics *test = currentScope->local_lookup(tok->text);
                    if (test) semantic_error("Interface redefined", tok->line);
                    openscope();
                    currentInterface = new S_interface;
                    currentInterface->name = tok->text;
                    currentInterface->line = tok->line;
                    for(ParseTree * child : (yyvsp[-1])->children){
                        if (!(child == (yyvsp[-1])->children[0])){
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
                    (yyval)->symtab = closescope();
                    currentScope->insert(tok->text, currentInterface);
                    all_decls.push_back(currentInterface);
                    (yyval)->sem = currentInterface;
                }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 133 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("interface", (yyvsp[-2]), (yyvsp[0])); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1]) -> addChild((yyvsp[0])); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 136 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("prototype", (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-2])); }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("prototype", (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-2])); }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "decaf.y" /* yacc.c:1646  */
    { Token *tok = (yyvsp[0])->token;
                    string class_name = tok->text;
                    semantics *curr = topScope->local_lookup(tok->text);
                    if (curr) semantic_error("Class redefined", tok->line);
                    S_class * this_class = new S_class(class_name, tok->line);
                    currentClass = this_class;
                    openscope(); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 147 "decaf.y" /* yacc.c:1646  */
    { if ((yyvsp[0])) { Token *tok = (yyvsp[0])->children[0]->token;
                    string class_name = tok->text;
                    S_undefined * temp_parent = new S_undefined;
                    temp_parent -> name = class_name;
                    temp_parent -> line = tok->line;
                    currentClass->parentClass = temp_parent;
                    (yyval)->sem = temp_parent;
                }}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 155 "decaf.y" /* yacc.c:1646  */
    { if ((yyvsp[0])) {
            for(ParseTree *i_tree : (yyvsp[0])->children){
                Token *tok = i_tree->token;
                string interface_name = tok->text;
                S_undefined * temp_interface = new S_undefined;
                temp_interface->name = interface_name;
                temp_interface->line = tok->line;
                currentClass->interfaces.push_back(temp_interface);
            }
        }}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 165 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("class", (yyvsp[-8]), (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]));
                for(ParseTree * child : (yyvsp[-1])->children){
                    currentClass->fields.push_back(child->sem);
                }
                all_decls.push_back(currentClass);
                topScope->insert(currentClass->name, currentClass);
                (yyval)->sem = currentClass;
                currentClass = nullptr;
                (yyval)->symtab = closescope(); }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 175 "decaf.y" /* yacc.c:1646  */
    { Token *tok = (yyvsp[0])->token;
                    string class_name = tok->text;
                    semantics *curr = topScope->local_lookup(tok->text);
                    if (curr) semantic_error("Attempted class override", tok->line);
                    S_class * this_class = new S_class(class_name, tok->line);
                    currentClass = this_class;
                    openscope(); }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "decaf.y" /* yacc.c:1646  */
    { if ((yyvsp[0])) { Token *tok = (yyvsp[0])->children[0]->token;
                        string class_name = tok->text;
                        S_undefined * temp_parent = new S_undefined;
                        temp_parent -> name = class_name;
                        temp_parent -> line = tok->line;
                        currentClass->parentClass = temp_parent;
                        (yyval)->sem = temp_parent;
                    }}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 190 "decaf.y" /* yacc.c:1646  */
    { if ((yyvsp[0])) {
                for(ParseTree *i_tree : (yyvsp[0])->children){
                    Token *tok = i_tree->token;
                    string interface_name = tok->text;
                    S_undefined * temp_interface = new S_undefined;
                    temp_interface->name = interface_name;
                    temp_interface->line = tok->line;
                    currentClass->interfaces.push_back(temp_interface);
                }
            }}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 200 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("class", (yyvsp[-8]), (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]));
                    for(ParseTree * child : (yyvsp[-1])->children){
                        currentClass->fields.push_back(child->sem);
                    }
                    all_decls.push_back(currentClass);
                    topScope->insert(currentClass->name, currentClass);
                    (yyval)->sem = currentClass;
                    currentClass = nullptr;
                    (yyval)->symtab = closescope(); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "decaf.y" /* yacc.c:1646  */
    { (yyval) = nullptr; }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 211 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("extends", (yyvsp[0])); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 212 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("extends", (yyvsp[0])); }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 213 "decaf.y" /* yacc.c:1646  */
    { (yyval) = nullptr; }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 215 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("implements", (yyvsp[0])); }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 216 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-2])->addChild((yyvsp[0])); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 217 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("fields"); }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 218 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1]) -> addChild((yyvsp[0])); }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 219 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1]) -> addChild((yyvsp[0])); }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 224 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("variable", (yyvsp[-1]), (yyvsp[0]));
                        Token *tok = (yyvsp[0])->token;
                        string var_name = tok->text;
                        S_type *var_type = dynamic_cast<S_type *>((yyvsp[-1])->sem);
                        semantics *curr = currentScope->local_lookup(tok->text);
                        if (curr) semantic_error("Variable already defined",tok->line);
                        S_variable *this_var = new S_variable();
                        this_var->type = var_type;
                        this_var->name = var_name;
                        this_var->line = yylineno;
                        currentScope->insert(var_name, this_var);
                        all_decls.push_back(this_var);
                        (yyval)->sem = this_var; }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 239 "decaf.y" /* yacc.c:1646  */
    {
                    currentFunction = new S_function;
                    Token *tok = (yyvsp[-1])->token;
                    string func_name = tok->text;
                    semantics *curr = currentScope->local_lookup(func_name);
                    if (curr) semantic_error("Function already defined",tok->line);
                    S_type *var_type = dynamic_cast<S_type *>((yyvsp[-2])->sem);
                    currentFunction->name = func_name;
                    currentFunction->returnType = var_type;
                }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "decaf.y" /* yacc.c:1646  */
    { for(ParseTree *f_tree : (yyvsp[0])->children){
                        S_variable * this_formal = dynamic_cast<S_variable *>(f_tree->sem);
                        currentFunction->formals.push_back(this_formal);
                    }
                }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 254 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("functiondecl", (yyvsp[-7]), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[0]));
                    currentScope->insert(currentFunction->name, currentFunction);
                    all_decls.push_back(currentFunction);
                    (yyval)->sem = currentFunction;
                    currentFunction = nullptr; }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 260 "decaf.y" /* yacc.c:1646  */
    {
                        currentFunction = new S_function;
                        Token *tok = (yyvsp[-1])->token;
                        string func_name = tok->text;
                        semantics *curr = currentScope->local_lookup(func_name);
                        if (curr) semantic_error("Function already defined",tok->line);
                        //S_type *var_type = dynamic_cast<S_type *>($1->sem);
                        currentFunction->name = func_name;
                        currentFunction->returnType = NULL;
                    }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 270 "decaf.y" /* yacc.c:1646  */
    { for(ParseTree *f_tree : (yyvsp[0])->children){
                            S_variable * this_formal = dynamic_cast<S_variable *>(f_tree->sem);
                            currentFunction->formals.push_back(this_formal);
                        }
                    }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 275 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("functiondecl", (yyvsp[-7]), (yyvsp[-6]), (yyvsp[-3]), (yyvsp[0]));
                        currentScope->insert(currentFunction->name, currentFunction);
                        all_decls.push_back(currentFunction);
                        (yyval)->sem = currentFunction;
                        currentFunction = nullptr; }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 280 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("formals"); }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 282 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("formals", (yyvsp[0])); }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 283 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-2])->addChild((yyvsp[0])); }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 286 "decaf.y" /* yacc.c:1646  */
    { openscope(); }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 287 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("stmtblock", (yyvsp[-2]), (yyvsp[-1]));
                                        (yyval)->symtab = closescope(); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 289 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("vardecls"); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 291 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("vardecls", (yyvsp[0])); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 292 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 293 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("stmts"); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 295 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("stmts", (yyvsp[0])); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 296 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 303 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("if", (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 304 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("if", (yyvsp[-2]), (yyvsp[0])); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 305 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("if", (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 308 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("while", (yyvsp[-2]), (yyvsp[0])); }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 311 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("for", (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 316 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("break", (yyvsp[-1])); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 318 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("return", (yyvsp[-1])); }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 319 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("return", (yyvsp[-2]), (yyvsp[-1])); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 321 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("print", (yyvsp[-4]), (yyvsp[-2])); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 324 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("nullstmt"); }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 326 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 328 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 330 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 332 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 333 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 335 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 336 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 337 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 338 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 340 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 341 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 343 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 344 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 345 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 347 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("uop", (yyvsp[-1]), (yyvsp[0])); }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 348 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("uop", (yyvsp[-1]), (yyvsp[0])); }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 352 "decaf.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 353 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("readinteger"); }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 354 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("readline"); }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 355 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("new", (yyvsp[-1])); }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 356 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("newarray", (yyvsp[-3]), (yyvsp[-1])); }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 361 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("field_access", (yyvsp[-2]), (yyvsp[0])); }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 362 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("aref", (yyvsp[-3]), (yyvsp[-1])); }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 363 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("call", (yyvsp[-3]), (yyvsp[-1])); }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 364 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("call", (yyvsp[-3]), (yyvsp[-1])); }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 365 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("actuals"); }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 367 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("actuals", (yyvsp[0])); }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 368 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-2])->addChild((yyvsp[0])); }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 371 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("usertype", (yyvsp[0])); }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 376 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0]));
                  (yyval)->sem = topScope->lookup("int"); }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 378 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0]));
                     (yyval)->sem = topScope->lookup("double"); }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 380 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0]));
                   (yyval)->sem = topScope->lookup("bool"); }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 382 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0]));
                     (yyval)->sem = topScope->lookup("string"); }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 384 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("usertype", (yyvsp[0]));
            string type_name = (yyvsp[0])->token->text;
            semantics *thing = topScope->lookup(type_name);
        if (thing == nullptr) {
            S_type *undef_type = new S_undefined;
            undef_type->name = type_name;
            undef_type->line = yylineno;
            (yyval)->sem = undef_type;
        }
        else if (dynamic_cast<S_type *>(thing))
            (yyval)->sem = thing;
        else
            semantic_error(type_name + " is not a type",
                 (yyvsp[0])->token->line); }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 398 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("arraytype", (yyvsp[-2]));
            S_arraytype *this_type = new S_arraytype;
            this_type->element_type = dynamic_cast<S_type *>((yyvsp[-2])->children[0]->sem);
            this_type->line = yylineno;
            (yyval)->sem = this_type;
        }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 406 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 407 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 408 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 409 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 410 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 411 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 412 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 413 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 414 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 415 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 416 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 417 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 418 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 419 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 420 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 421 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 424 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 425 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 426 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 427 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 428 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 429 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 430 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 431 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 432 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 433 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 434 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 435 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 436 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 437 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 438 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2437 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 440 "decaf.y" /* yacc.c:1906  */


int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
