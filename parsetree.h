#ifndef PARSE_TREE
#define PARSE_TREE

/* parsetree.h
   Alistair Campbell
   2015--2019

   Modified Fall 2019: separate into .h and .cc files
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "tokentype.h"
#include "semantics.h"

  /* prototype for yyerror, needed on my linux laptop */
int yyerror(const char * s);

using namespace std;

struct ParseTree {
  string description;
  Token * token;                 // nullptr for nonterminal trees
  semantics * sem;
  Symtab *symtab;                // new:  attach a symbol table to a parse tree.
  vector<ParseTree *> children;  // empty for terminal trees
  S_type * type;

  ParseTree(string description, ParseTree* c1);

  ParseTree(string description, ParseTree* c1, ParseTree* c2);

  ParseTree(string description, ParseTree* c1, ParseTree* c2, ParseTree *c3);

  ParseTree(string description, ParseTree* c1, ParseTree* c2, ParseTree *c3,
	    ParseTree *c4);

  ParseTree(string description);

  ParseTree(Token * tokp);

  void addChild(ParseTree * tree);

  void addChild(ParseTree * tree1, ParseTree * tree2);


  string toString() const;

};

string base26(int x);

string seq2str(int seq, int depth);

void traverseTree(ParseTree * tree, int depth, int seq);

#endif
