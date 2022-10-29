
#include "MakeTree.hpp"

MakeTree::MakeTree(){
}

/*	Insert the GraphNode into the tree.
*	It uses a helper function.	
* 
*	@param nNnode: GraphNode to be add it.
*/
void MakeTree::insert(GraphNode* nNode){
	_root = insert(_root, nNode);
}

/*	Insert helper. Recursive.
*
*	@param tNode: Root of the tree.
*	@param nNode: Node to be insert.
*	@return Returns the treeNode.
*/
TreeNode* MakeTree::insert(TreeNode* tNode, GraphNode* nNode){
	if (tNode == nullptr) {
		return new TreeNode(nNode);
	}
	if (tNode->graphNode()->getName() == nNode->getName())
		return tNode;
	if (tNode->graphNode()->getName() < nNode->getName()) {
		tNode->right(insert(tNode->right(), nNode));
	}
	else {
		tNode->left(insert(tNode->left(), nNode));
	}
	
	return tNode;
}

/*	Find the node with the name need it. It uses a helper function
*	for recursive search.
*
*	@param name: Name to find.
*	@return Returns the node with that name if there is not a node with that
*	name it will return nullptr.
*/
GraphNode* MakeTree::find(std::string name){
	return find(name, _root);
}
/*	Find Helper. Recursive.
*
*	@param name: Name to find.
*	@param root: root of the tree.
*	@return Returns the node with that name if there is not a node with that
*	name it will return nullptr.
*/
GraphNode* MakeTree::find(std::string name, TreeNode* root){
	if (root == nullptr) {
		return nullptr;
	}
	
	if (root->graphNode()->getName() == name) {
		return root->graphNode();
	}

	GraphNode* gra = find(name, root->left());
	if (gra != nullptr)
		return gra;
	gra = find(name, root->right());

	return gra;
}

/*	Print all the tree in-order order.
*	
*	@param root: root of the tree.
*/
void MakeTree::print(TreeNode* root){
	if (root == nullptr) {
		return;
	}

	print(root->left());
	root->print();
	print(root->right());
}
