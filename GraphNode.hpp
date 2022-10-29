#pragma once

#include<iostream>
#include<string>
#include<vector>
#include "systemInterface.hpp"

class GraphNode {
public:
    GraphNode( std::string name );
    std::string getName();
    void setName( std::string name );
    void setTimestamp(int ts);
    int getTimestamp();
    std::vector<GraphNode *> *dependentNodes();
    void setCommand(std::string cmnd);
    std::string getCommand();
    void runCommand();  // execute the command associated with this node. Only for target nodes.
    void addDependentNode(GraphNode *child);
    bool onPath();
    void onPath(bool v);
    bool wasMade();
    void wasMade(bool v);
    bool isATarget();
    void isATarget(bool v);
    int numDependentNodes();
    bool find(std::string);

private:
    bool findhelper(std::string, std::vector<GraphNode*>*);

    std::string _name, _command;
    int _timestamp;
    std::vector<GraphNode *> *_listOfDependentNodes;

    bool _onPath, _isATarget, _wasMade;
};
