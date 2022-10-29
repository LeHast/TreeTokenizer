#ifndef _Graph_hpp
#define _Graph_hpp

#include<iostream>
#include<cstring>

#include "MakeTree.hpp"
#include "Tokenizer.hpp"
#include "systemInterface.hpp"

class DepGraph {
public:
    DepGraph( std::string name );
    void print();
    void parseDepGraph();
    void runMake();
    bool isCyclic();

private:
    bool isCyclic(GraphNode *);
    void makeGraph(GraphNode*);
    void nextToken();

    void setCommandG();
    void printHelper(GraphNode*);
    void runMakeHelper(GraphNode*);
private:
    std::string _fileToMake, _targetToMake;
    GraphNode *firstTarget, *rootGraph;
    MakeTree *_tree;  // MakeTree implements a binary-search tree similar to BinSearchTree

    Tokenizer tokenizer;
    Token token;


};

#endif
