#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"
#include "Bintreetraversalrec.h"

//��� ���� ��ȸ
void preoderTraversalRecursiveBinTree(BinTree *pBinTree){
	if (pBinTree != NULL) {
		preoderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
	}
}

void preoderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode){
	if (pRootNode != NULL) {
		printf("%c ", pRootNode->data);
		preoderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
		preoderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
	}
}

//��� ���� ��ȸ
void inoderTraversalRecursiveBinTree(BinTree *pBinTree){
	if (pBinTree != NULL) {
		inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
	}
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode){
	if (pRootNode != NULL) {
		inorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
		printf("%c ", pRootNode->data);
		inorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
	}
}

//��� ���� ��ȸ
void postoderTraversalRecursiveBinTree(BinTree *pBinTree){
	if (pBinTree != NULL) {
		postoderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
	}
}

void postoderTraversalRecursiveBinTreeNode(BinTreeNode * pRootNode){
	if (pRootNode != NULL) {
		postoderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
		postoderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
		printf("%c ", pRootNode->data);
	}
}




