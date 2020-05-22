#include <stdio.h>
#include <stdlib.h>
#include "Binsearchtree.h"

BinSearchTree* createExampleBinTree();


int main() {
	BinSearchTree *pBinSearchTree = NULL;
	BinSearchTreeNode *pNode = NULL;

	int ret = FALSE;

	pBinSearchTree = createExampleBinTree();

	displayBinSearchTree(pBinSearchTree);
	
	ret = deleteElementBST(pBinSearchTree, 40);
	printf("\nDeleteElementBST() : %d\n\n", ret);
	
	displayBinSearchTree(pBinSearchTree);
	deleteBinSearchTree(pBinSearchTree);

	return 0;
}

BinSearchTree* createExampleBinTree() {
	BinSearchTree *pReturn = NULL;
	BinSearchTreeNode node = { 0, };

	
	pReturn = createBinSearchTree();
	if (pReturn != NULL) {
		node.key = 50;
		insertElementBST(pReturn, node);
		node.key = 40;
		insertElementBST(pReturn, node);
		node.key = 60;
		insertElementBST(pReturn, node);
		node.key = 30;
		insertElementBST(pReturn, node);
		node.key = 45;
		insertElementBST(pReturn, node);
		/*
		node.key = 29;
		insertElementBST(pReturn, node);
		node.key = 33;
		insertElementBST(pReturn, node);
		node.key = 43;
		insertElementBST(pReturn, node);
		node.key = 47;
		insertElementBST(pReturn, node);
		*/
		
	}
	return pReturn;
}
