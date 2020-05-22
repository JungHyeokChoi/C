#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"
#include "Bintreeop.h"

//이진 트리 복사(재귀함수)
BinTree *copyBinTree(BinTree *pSource){
	BinTree* pReturn = NULL;

	if (pSource != NULL) {
		pReturn = (BinTree*)malloc(sizeof(BinTree));
		if (pReturn != NULL) {
			pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
		}
		else {
			printf("오류, 메모리할당, copyBinTree()\n");
		}
	}
	return pReturn;
}

BinTreeNode *copyBinTreeNode(BinTreeNode *pSourceNode){
	BinTreeNode* pReturn = NULL;
	
	if (pSourceNode != NULL) {
		pReturn = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		if (pReturn != NULL) {
			*pReturn = *pSourceNode;
			pReturn->pLeftChild = copyBinTreeNode(getLeftChildNodeBT(pSourceNode));
			pReturn->pRightChild = copyBinTreeNode(getRightChildNodeBT(pSourceNode));
		}
		else {
			printf("오류, 메모리할당, copyBinTreeNode()\n");
		}
	}
	return pReturn;
}

//이진 트리 동일성 검사(재귀함수)
int equalBinTree(BinTree *pFirst, BinTree *pSecond){
	int ret = FALSE;

	if (pFirst == NULL && pSecond == NULL) {
		ret = TRUE;
	}else if (pFirst != NULL && pSecond != NULL
		&& equalBinTreeNode(pFirst->pRootNode,pSecond->pRootNode) == TRUE) {

		ret = TRUE;
	}

	return ret;
}

int equalBinTreeNode(BinTreeNode *pFirst, BinTreeNode *pSecond){
	int ret = FALSE;

	if (pFirst == NULL && pSecond == NULL) {
		ret = TRUE;
	}else if(pFirst != NULL && pSecond != NULL 
		&& pFirst->data == pSecond->data 
		&& equalBinTreeNode(pFirst->pLeftChild,pSecond->pLeftChild) == TRUE
		&& equalBinTreeNode(pFirst->pRightChild, pSecond->pRightChild) == TRUE) {

		ret = TRUE;
	}

	return ret;
}

//이진 트리 노드 개수
int getNodeCountBT(BinTree *pSource){
	int ret = 0;

	if (pSource != NULL) {
		ret = getNodeCountBTNode(pSource->pRootNode);
	}
	return ret;
}

int getNodeCountBTNode(BinTreeNode *pSource){
	int ret = 0;

	if (pSource != NULL) {
		ret = getNodeCountBTNode(pSource->pLeftChild) +
			getNodeCountBTNode(pSource->pRightChild) + 1;
	}

	return ret;
}

//이진 트리 자식 노드 1개 이상 있는 노드 개수
int getNodeCountHaveChildNodeBT(BinTree *pSource){
	int ret = 0;

	if (pSource != NULL) {
		ret = getNodeCountHaveChildNodeBTNode(pSource->pRootNode);
		
	}

	return ret;
}

int getNodeCountHaveChildNodeBTNode(BinTreeNode *pSource){
	int ret = 0;

	if (pSource != NULL) {
		if (pSource->pLeftChild != NULL || pSource->pRightChild != NULL) {
			ret = getNodeCountHaveChildNodeBTNode(pSource->pLeftChild)
				+ getNodeCountHaveChildNodeBTNode(pSource->pRightChild) +1 ;
		}
	}

	return ret;
}




//이진 트리 단말 노드 개수
int getLeafNodeCountBT(BinTree *pSource){
	int ret = 0;

	if (pSource != NULL) {
		ret = getLeafNodeCountBTNode(pSource->pRootNode);
	}

	return ret;
}

int getLeafNodeCountBTNode(BinTreeNode *pSource){
	int ret = 0;

	if (pSource != NULL) {
		if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL) {
			ret = 1;
		}
		else {
			ret = getLeafNodeCountBTNode(pSource->pLeftChild) +
				getLeafNodeCountBTNode(pSource->pRightChild);
		}
	}

	return ret;
}

//이진 트리 높이
int getHeightBT(BinTree *pSource){
	int ret = 0;

	if (pSource != NULL) {
		ret = getHeightBTNode(pSource->pRootNode);
	}

	return ret;
}

int getHeightBTNode(BinTreeNode *pSource){
	int ret = 0;

	if (pSource != NULL) {
		if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL) {
			ret = 1;
		}
		else {
			int leftChildHeight = getHeightBTNode(pSource->pLeftChild);
			int rightChildHeight = getHeightBTNode(pSource->pRightChild);

			if (leftChildHeight >= rightChildHeight) {
				ret = 1 + leftChildHeight;
			}
			else {
				ret = 1 + rightChildHeight;
			}
		}
	}

	return ret;
}

//이진 트리 Key 값 증가
void increaseKeyBT(BinTree * pSource){
	if (pSource != NULL) {
		increaseKeyBTNode(pSource->pRootNode);
	}
	else {
		printf("트리가 NULL입니다.\n");
	}
}

void increaseKeyBTNode(BinTreeNode * pSource){
	if (pSource != NULL) {
		pSource->data += 2;

		increaseKeyBTNode(pSource->pLeftChild);
		increaseKeyBTNode(pSource->pRightChild);
	}
	return 0;
}


//이진 트리 구조 및 내용 출력
void displayBinTree(BinTree *pTree){
	if (pTree != NULL) {
		displayBinTreeNode(pTree->pRootNode,0,'O');
	}
	else {
		printf("트리가 NULL입니다.\n");
	}
}

void displayBinTreeNode(BinTreeNode *pNode, int level, char type){
	int i = 0;
	
	for (i = 0; i < level; i++) {
		printf("	");
	}

	if (pNode != NULL) {
		printf("-[%i,%c]%c\n", level, type, pNode->data);

		displayBinTreeNode(pNode->pLeftChild, level + 1, 'L');
		displayBinTreeNode(pNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}




















