#include "GraphNode.hpp"

/*	Sets the node's name
* 
*	@param name: Name of the node.
*/
GraphNode::GraphNode(std::string name){
	_listOfDependentNodes = new std::vector<GraphNode*>;
	_name = name;
}


/*	@return Returns the name of the node.
*/
std::string GraphNode::getName(){
	return _name;
}


/*	Sets the node's name
*
*	@param name: Name of the node.
*/
void GraphNode::setName(std::string name){
	_name = name;
}


/*	Sets the node's Time Stamp.
*
*	@param ts: Time stamp of the node.
*/
void GraphNode::setTimestamp(int ts){
	_timestamp = ts;
}
 

/*	@return Returns the time stamp of the node.
*/
int GraphNode::getTimestamp()
{
	return _timestamp;
}


/*	@return Returns the dependent nodes.
*/
std::vector<GraphNode*>* GraphNode::dependentNodes(){
	return _listOfDependentNodes;
}


/*	Sets the node's command.
*
*	@param cmnd: command to be set.
*/
void GraphNode::setCommand(std::string cmnd){
	_command = cmnd;
}


/*	@return Returns the node's command.
*/
std::string GraphNode::getCommand(){
	return _command;
}


/*	It executes the command.
*/
void GraphNode::runCommand(){
	executeCommand(getCommand().c_str());
}


/*	Adds a child to this node.
*
*	@param child: child to be added.
*/
void GraphNode::addDependentNode(GraphNode* child){
	_listOfDependentNodes->push_back(child);	
}


/*	@return Returns if the node is on the path.
*/
bool GraphNode::onPath(){
	return _onPath;
}


/*	Set the node to true or false for the path.
*
*	@param v: true or false bool for the path.
*/
void GraphNode::onPath(bool v){
	_onPath = v;
}


/*	@return Returns if the node was made.
*/
bool GraphNode::wasMade(){
	return _wasMade;
}


/*	Set the node to true or false for was made.
*
*	@param v: true or false bool for was made.
*/
void GraphNode::wasMade(bool v){
	_wasMade = v;
}


/*	@return Returns if the node is a target.
*/
bool GraphNode::isATarget(){
	return _isATarget;
}


/*	Set the node to true or false for target.
*
*	@param v: true or false bool for target.
*/
void GraphNode::isATarget(bool v){
	_isATarget = v;
}


/*	@return Returns the number of dependent nodes.
*/
int GraphNode::numDependentNodes(){
	return _listOfDependentNodes->size();
}


/*	Finds a node in the graph. Uses a helper function.
*	@return Returns if a node is in the graph.
* 
*	@param name: Name of the node that the user wants to find.
*/
bool GraphNode::find(std::string name){
	return findhelper(name, _listOfDependentNodes);
}

/*	find helper function.
*/
bool GraphNode::findhelper(std::string name, std::vector<GraphNode*>* list){
	if (list->size() == 0)
		return false;

	for (int i = 0; i < numDependentNodes(); i++) {
		if (list->at(i)->getName() == name) {
			return true;
		}
		return findhelper(name, list->at(i)->dependentNodes());
	}

	return false;
}
