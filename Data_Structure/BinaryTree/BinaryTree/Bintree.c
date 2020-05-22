#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"

//Ʈ�� ����
BinTree *makeBinTree(BinTreeNode rootNode){
	BinTree *pReturn = NULL;

	pReturn = (BinTree*)malloc(sizeof(BinTree));
	if (pReturn != NULL) {
		pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		if (pReturn->pRootNode != NULL) {
			*(pReturn->pRootNode) = rootNode;
			pReturn->pRootNode->pLeftChild = NULL;
			pReturn->pRootNode->pRightChild = NULL;
		}
		else {
			printf("����, �޸� �Ҵ�(2), makeBinTree()\n");
			free(pReturn);

			pReturn = NULL;
		}
	}
	else {
		printf("����, �޸� �Ҵ�(1), makeBinTree()\n");
	}

	return pReturn;
}

//�ڽ� ��� �߰�(Left)
BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element){
	BinTreeNode* pReturn = NULL;

	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == NULL) {
			pParentNode->pLeftChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));

			if (pParentNode->pLeftChild != NULL) {
				*(pParentNode->pLeftChild) = element;
				pParentNode->pLeftChild->pLeftChild = NULL;
				pParentNode->pLeftChild->pRightChild = NULL;
				pReturn = pParentNode->pLeftChild;
			}
			else {
				printf("����, �޸� �Ҵ�, insertLeftChildNodeBT()\n");
			}
		}
		else {
			printf("����, �̹� ��尡 �����մϴ�. insertLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

//�ڽ� ��� �߰�(Right)
BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element){
	BinTreeNode* pReturn = NULL;

	if (pParentNode != NULL) {
		if (pParentNode->pRightChild == NULL) {
			pParentNode->pRightChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));

			if (pParentNode->pRightChild != NULL) {
				*(pParentNode->pRightChild) = element;
				pParentNode->pRightChild->pRightChild = NULL;
				pParentNode->pRightChild->pLeftChild = NULL;
				pReturn = pParentNode->pRightChild;
			}
			else {
				printf("����, �޸� �Ҵ�, insertLeftChildNodeBT()\n");
			}
		}
		else {
			printf("����, �̹� ��尡 �����մϴ�. insertLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

//��Ʈ ��� ��ȯ
BinTreeNode *getRootNodeBT(BinTree *pBinTree){
	BinTreeNode* pReturn = NULL;

	if (pBinTree != NULL) {
		pReturn = pBinTree->pRootNode;
	}

	return pReturn;
}

//Left ��� ��ȯ
BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode){
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pLeftChild;
	}

	return pReturn;
}

//Right ��� ��ȯ
BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode){
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pRightChild;
	}

	return pReturn;
}

//Ʈ�� ����
void deleteBinTree(BinTree *pBinTree){
	if (pBinTree != NULL) {
		deletBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

//Ʈ�� ��� ����
void deletBinTreeNode(BinTreeNode *pNode){
	if (pNode != NULL) {
		deletBinTreeNode(pNode->pLeftChild);
		deletBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}













