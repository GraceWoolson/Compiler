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


  /* prototype for yyerror, needed on my linux laptop */
int yyerror(const char * s);

using namespace std;

struct ParseTree {
  string description;
  Token * token;                 // nullptr for nonterminal trees
  vector<ParseTree *> children;  // empty for terminal trees
  ParseTree(string description, ParseTree* c1): description(description),
						token(nullptr)
  {
    addChild(c1);
  }
  
  ParseTree(string description, ParseTree* c1, ParseTree* c2):
    description(description), token(nullptr)
  {
    addChild(c1);
    addChild(c2);
  }
  
  ParseTree(string description, ParseTree* c1, ParseTree* c2, ParseTree *c3):
    description(description), token(nullptr)
  {
    addChild(c1);
    addChild(c2);
    addChild(c3);
  }
  
  ParseTree(string description, ParseTree* c1, ParseTree* c2, ParseTree *c3,
	    ParseTree *c4): 
    description(description), token(nullptr)
  {
    addChild(c1);
    addChild(c2);
    addChild(c3);
    addChild(c4);
  }
  
  ParseTree(string description) : description(description), token(nullptr) {}
  ParseTree(Token * tokp) : token(tokp) {}
  
  void addChild(ParseTree * tree) {
    children.push_back(tree);
  }
  
  void addChild(ParseTree * tree1, ParseTree * tree2) {
    children.push_back(tree1);
    children.push_back(tree2);
  }
  
  string toString() {
    string answer = "";
    if (token)
      answer +=  token->toString();
    else {
      answer += "(" + description;
      for (vector<ParseTree *>::iterator i=children.begin(); 
           i != children.end(); i++) {
        ParseTree *tree = *i;
        if (!tree) answer += " EMPTY";
        else answer += " " + tree->toString();
      }
      answer += ")";
    }
    return answer;
  }
};

string base26(int x);

string seq2str(int seq, int depth);

void traverseTree(ParseTree * tree, int depth, int seq);

#endif
