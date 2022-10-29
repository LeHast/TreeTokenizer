
#include "DepGraph.hpp"

DepGraph::DepGraph(std::string name) : tokenizer{name} {
    _tree = new MakeTree(); 
    firstTarget = nullptr;
}


/*  Prints all the graph. if the graph has cycles it will stop. 
*   It use a helper function.
*/
void DepGraph::print(){
    //_tree->print();

    if (this->isCyclic()) {
        std::cerr << "Input graph has cycles.\n";
        exit(44);
    }
    GraphNode* temp = _tree->getRoot()->graphNode();

    printHelper(temp);
}

/*  Print helper function.
*/
void DepGraph::printHelper(GraphNode* temp){
    std::cout << temp->getName() << std::endl;

    for (int i = 0; i < temp->numDependentNodes(); i++) {
        printHelper(temp->dependentNodes()->at(i));
    }
}

/*  Reads the file and makes the graph and the tree. 
*/
void DepGraph::parseDepGraph(){

    while (!token.isEOF()) {
        //std::cout << "--------- Target--------" << std::endl;
        nextToken();
        if (token.isEOF())
            break;
        while (token.isEndLine()) {
            nextToken();
        }
        firstTarget = new GraphNode(token.getString());
        if (_tree->find(firstTarget->getName()) != nullptr) {
            firstTarget = _tree->find(firstTarget->getName());
        }
        firstTarget->isATarget(true);
        _tree->insert(firstTarget);

        //std::cout << "--------- : --------" << std::endl;
        nextToken();
        if (token.getCharacter() != ':') {
            std::cout << "Not target file found........" << std::endl;
            break;
        }
        //std::cout << "--------- Depenecies --------" << std::endl;
        nextToken();
        while (!token.isEndLine()) {
            GraphNode* depenGn = new GraphNode(token.getString());
            makeGraph(depenGn);
            nextToken();
        }
        //std::cout << "--------- Command --------" << std::endl;
        setCommandG();

        // Add to tree.
        for (int i = 0; i < firstTarget->numDependentNodes(); i++) {
            _tree->insert(firstTarget->dependentNodes()->at(i));
        }
        rootGraph = _tree->getRoot()->graphNode();

    }

    rootGraph = _tree->getRoot()->graphNode();

}


/*  It makes the node grapj
* 
*   @param node: root of the tree-node.
*/
void DepGraph::makeGraph(GraphNode* node) {
    if (_tree->find(node->getName()) != nullptr) {
        node = _tree->find(node->getName());
        firstTarget->addDependentNode(node);
        _tree->insert(node);
    }
    else {
        firstTarget->addDependentNode(node);
        _tree->insert(node);
    }
}


/*  Update every timestamp and run the commands for nodes on the path. If the graph
*   has a cycle it will stop. it uses a helper function. 
*/
void DepGraph::runMake() {
    if (this->isCyclic()) {
        std::cerr << "Input graph has cycles.\n";
        exit(44);
    }
    GraphNode* temp = _tree->getRoot()->graphNode();

    runMakeHelper(temp);
}

/*  runMake helper function.
*/
void DepGraph::runMakeHelper(GraphNode* temp){
    if (temp == nullptr)
        return;
    for (int i = 0; i < temp->numDependentNodes(); i++) {
        runMakeHelper(temp->dependentNodes()->at(i));
    }

    long time = 0;
    if (!timestamp(temp->getName().c_str(), &time)) {
        exit(45);
    }

    temp->setTimestamp(time);
    for (int i = 0; i < temp->numDependentNodes(); i++) {
        if (!timestamp(temp->dependentNodes()->at(i)->getName().c_str(), &time)) {
            exit(45);
        }
        temp->dependentNodes()->at(i)->setTimestamp(time);
    }

    for (int i = 0; i < temp->numDependentNodes(); i++) {
        if (temp->getTimestamp() < temp->dependentNodes()->at(i)->getTimestamp() && !temp->wasMade()) {
            temp->runCommand();
            temp->wasMade(true);
        }
    }
}


/* @return If the graph has cycles it will return true. It uses a helper function.
*/
bool DepGraph::isCyclic(){
    bool cyccli = isCyclic(rootGraph);
    //setonPath(rootGraph);
	return cyccli;
}

/* isCyclic Helper function.
*/
bool DepGraph::isCyclic(GraphNode* target) {
    if (target->onPath())
        return true;


    if (target->numDependentNodes() == 0) {
        target->onPath(false);
        return false;
    }
    else
        target->onPath(true);


    for (int i = 0; i < target->numDependentNodes(); i++) {
        bool cyclic = isCyclic(target->dependentNodes()->at(i));
        if (cyclic)
            return cyclic;
    }
    target->onPath(false);
    return false;
}


/* Gets the next token.
*/
void DepGraph::nextToken(){
    token = tokenizer.getToken();
    //token.print();
}


/* Sets the command of the node.
*/
void DepGraph::setCommandG(){
    // Command
    std::string command;
    nextToken();


    while (!token.isEndLine() && !token.isEOF() && !token.isSpace()) {
        command += token.getString();
        command += " ";
        nextToken();
        if (token.isEndLine()) {
            break;
        }
    }
    firstTarget->setCommand(command);
    _tree->insert(firstTarget);
}

