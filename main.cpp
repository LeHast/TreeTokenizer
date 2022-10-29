
#include<iostream>
#include<cstdlib>
#include "DepGraph.hpp"
#include "Tokenizer.hpp"
#include "Token.hpp"
#include "GraphNode.hpp"
#include "TreeNode.hpp"


namespace debug {
template <class T>
void print(T var) {
    std::cout << var << std::endl;
}

}

int main(int argc, const char *argv[] ) {

    if( argc != 2 ) {
        std::cout << "usage: " << argv[0] << " name-of-a-makefile\n";
        exit(1);
    }
    // creates a Reader and build the dependency graph using the tokens that it returns.
    DepGraph *make = new DepGraph(argv[1]); 
    make->parseDepGraph();
    if( make->isCyclic() )  {
        std::cerr << "Input graph has cycles.\n";
        exit(2);
    }
    make->runMake();
    return 0;
}

// exit 1 - needs 2 files.
// exit 2 - cycles main.cpp.
// exit 44 - cycles DepGraph.cpp.
// exit 45 - file does not exit DepGraph.cpp.
// 

