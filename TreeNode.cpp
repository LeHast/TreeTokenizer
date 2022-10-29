#include "TreeNode.hpp"

TreeNode::TreeNode(GraphNode* nNode) : leftSubtree{ nullptr }, rightSubtree {nullptr}{
	makeNode = nNode;
}

/*	@return Returns the left node.
*
*/
TreeNode* TreeNode::left(){
	return leftSubtree;
}


/*	Sets the left node.
*	
*	@param leftPtr - Left node to be set into the tree.
*/	
void TreeNode::left(TreeNode* leftPtr){
	leftSubtree = leftPtr;
}


/*	@return Returns the right node
*	
*/
TreeNode* TreeNode::right()
{
	return rightSubtree;
}


/*	Sets the right node.
*
*	@param rightPtr - Right node to be set into the tree.
*/
void TreeNode::right(TreeNode* rightPtr){
	rightSubtree = rightPtr;
}

/*	Print the name of the node.
*/
void TreeNode::print(){
	std::cout << makeNode->getName() << std::endl;
}

/*	@return Returns this node.
*/
GraphNode* TreeNode::graphNode(){
	return makeNode;
}
