  /* definitions */

%{

#include <iostream>

using namespace std;

#include "tokentype.h"

string resultString;
Token* myTok;
size_t addlines;

int error(string msg, int line)
{
  cout << msg << " on line " << line << endl;
  return -1;
}

TokenType makeToken(TokenType type) {
    myTok = new Token(type, yytext, yylineno);
    return type;
}


%}

%x STRING
%x MLC
follow [[:space:]]+[A-Za-z]|[[:space:]]*\[[[:space:]]*\]

%%

  /* keywords */

void/{follow}?  { return makeToken(T_Void); }
int/{follow}?   { return makeToken(T_Int); }
double/{follow}? { return makeToken(T_Double); }
bool/{follow}? { return makeToken(T_Bool); }
string/{follow}? { return makeToken(T_String); }
class/{follow}? { return makeToken(T_Class); }
interface/{follow}? { return makeToken(T_Interface); }
null/{follow}? { return makeToken(T_Null); }
this/{follow}? { return makeToken(T_This); }
extends/{follow}? { return makeToken(T_Extends); }
implements/{follow}? { return makeToken(T_Implements); }
for/{follow}? { return makeToken(T_For); }
while/{follow}? { return makeToken(T_While); }
if/{follow}? { return makeToken(T_If); }
else/{follow}? { return makeToken(T_Else); }
return/{follow}? { return makeToken(T_Return); }
break/{follow}? { return makeToken(T_Break); }
New/{follow}? { return makeToken(T_New); }
NewArray/{follow}? { return makeToken(T_NewArray); }
Print/{follow}? { return makeToken(T_Print); }
ReadInteger/{follow}? { return makeToken(T_ReadInteger); }
ReadLine/{follow}? { return makeToken(T_ReadLine); }


  /* operations */
\+ { return makeToken(T_Plus); }
\- { return makeToken(T_Minus); }
\* { return makeToken(T_Times); }
\/ { return makeToken(T_Div); }
\% { return makeToken(T_Mod); }
\< { return makeToken(T_Less); }
\<\= { return makeToken(T_LessEqual); }
\> { return makeToken(T_Greater); }
\>\= { return makeToken(T_GreaterEqual); }
\= { return makeToken(T_Assign); }
\=\= { return makeToken(T_Equal); }
\!\= { return makeToken(T_NotEqual); }
\&\& { return makeToken(T_And); }
\|\| { return makeToken(T_Or); }
\! { return makeToken(T_Not); }
\; { return makeToken(T_Semicolon); }
\, { return makeToken(T_Comma); }
\. { return makeToken(T_Dot); }
\[ { return makeToken(T_LBracket); }
\] { return makeToken(T_RBracket); }
\( { return makeToken(T_LParen); }
\) { return makeToken(T_RParen); }
\{ { return makeToken(T_LBrace); }
\} { return makeToken(T_RBrace); }

  /* booleans */
true/{follow}? { return makeToken(T_BoolConstant); }
false/{follow}? { return makeToken(T_BoolConstant); }

  /* identifier */
[A-Za-z][A-Za-z0-9_]* { string errmssg;
                        if (strlen(yytext) <= 31) return makeToken(T_Identifier);
                        else{
                            errmssg += "identifier ";
                            errmssg += yytext;
                            errmssg += " too long";
                            return error(errmssg, yylineno);
                        }; }

  /* type identifier */
[A-Za-z][A-Za-z0-9_]*/{follow} { return makeToken(T_TypeIdentifier); }

  /* integer */
([0-9]+|0(x|X)[0-9a-f]+|0(x|X)[0-9A-F]+) { return makeToken(T_IntConstant); }

  /* double literals */
[0-9]+[\.][0-9]*((E|e)(\+|\-)?[0-9]+)? { return makeToken(T_DoubleConstant); }

  /* string */
\" { BEGIN(STRING); resultString = "\""; }
<STRING>[^\n"]* { resultString += yytext; }
<STRING>\n      {return error("missing \" at end of string constant",
		yylineno); }
<STRING><<EOF>>  {return error("missing \" at end of string constant",
		yylineno); }
<STRING>\"     { BEGIN(INITIAL);
	         myTok = new Token(T_StringConstant,resultString + "\"",
                                  yylineno);
		 return T_StringConstant; }

  /* newline consumption */
\n { yylineno += 1; }

  /* whitespace */
[[:space:]] {}

  /* comments */
\/\/.*$

  /* multi line comments */
\/\* { BEGIN(MLC); addlines = 0; }
<MLC>\*\/ { BEGIN(INITIAL); }
<MLC>. {}
<MLC>\n { yylineno += 1; addlines += 1; }
<MLC><<EOF>>  { return error("missing */ for block comment beginning on line", yylineno - addlines); }

.  { string errmsg;
     errmsg += "stray '";
     errmsg += yytext;
     errmsg += "'";
     return error(errmsg, yylineno); }

<<EOF>> { return -1; }

%%

  /* subroutines */

int yywrap(void) {
    return 1;  // makes it stop at EOF.
    /* there's a warning without this */
    if (false)
        yyunput(0, 0);
}
