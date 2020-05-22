#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"

//트리 생성
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
			printf("오류, 메모리 할당(2), makeBinTree()\n");
			free(pReturn);

			pReturn = NULL;
		}
	}
	else {
		printf("오류, 메모리 할당(1), makeBinTree()\n");
	}

	return pReturn;
}

//자식 노드 추가(Left)
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
				printf("오류, 메모리 할당, insertLeftChildNodeBT()\n");
			}
		}
		else {
			printf("오류, 이미 노드가 존재합니다. insertLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

//자식 노드 추가(Right)
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
				printf("오류, 메모리 할당, insertLeftChildNodeBT()\n");
			}
		}
		else {
			printf("오류, 이미 노드가 존재합니다. insertLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

//루트 노드 반환
BinTreeNode *getRootNodeBT(BinTree *pBinTree){
	BinTreeNode* pReturn = NULL;

	if (pBinTree != NULL) {
		pReturn = pBinTree->pRootNode;
	}

	return pReturn;
}

//Left 노드 반환
BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode){
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pLeftChild;
	}

	return pReturn;
}

//Right 노드 반환
BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode){
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pRightChild;
	}

	return pReturn;
}

//트리 삭제
void deleteBinTree(BinTree *pBinTree){
	if (pBinTree != NULL) {
		deletBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

//트리 노드 삭제
void deletBinTreeNode(BinTreeNode *pNode){
	if (pNode != NULL) {
		deletBinTreeNode(pNode->pLeftChild);
		deletBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}













