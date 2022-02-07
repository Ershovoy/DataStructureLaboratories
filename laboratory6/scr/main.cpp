#include "AVLTree.h"
#include "RBTree.h"
#include "IOTrees.h"

int main()
{
	//TODO: new tree
	AVLTree* avlTree = new AVLTree;
	RBTree* rbTree = new RBTree;

	TreesMenu(avlTree, rbTree);

	delete avlTree;
	delete rbTree;

	return 0;
}