#include <stdio.h>
#include <stdlib.h>
#include "Binsearchtree.h"

//���� Ž�� Ʈ�� ����
BinSearchTree *createBinSearchTree(){
	BinSearchTree *pReturn = NULL;

	pReturn = (BinSearchTree*)malloc(sizeof(BinSearchTree));
	if (pReturn != NULL) {
		pReturn->pRootNode = NULL;
	}
	else {
		printf("����, �޸� �Ҵ�, createBinSearchTree()\n");
	}

	return pReturn;
}

//���� Ž�� Ʈ�� ��� ����
int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element){
	int ret = TRUE;
	BinSearchTreeNode* pParentNode = NULL;
	BinSearchTreeNode* pNewNode = NULL;

	if (pBinSearchTree == NULL) {
		ret = FALSE;
		return ret;
	}

	pParentNode = pBinSearchTree->pRootNode;
	while (pParentNode != NULL) {
		if (element.key == pParentNode->key) {
			printf("����, �ߺ��� Ű - [%d],insertElementBST()\n", element.key);
			ret = FALSE;
			return ret;
		}
		else if (element.key < pParentNode->key) {
			if (pParentNode->pLeftChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pLeftChild;
			}
		}
		else {
			if (pParentNode->pRightChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pRightChild;
			}
		}
	}
	pNewNode = (BinSearchTreeNode*)malloc(sizeof(BinSearchTreeNode));
	if (pNewNode != NULL) {
		*pNewNode = element;
		pNewNode->pLeftChild = NULL;
		pNewNode->pRightChild = NULL;
		if (pParentNode == NULL) {
			pBinSearchTree->pRootNode = pNewNode;
		}
		else {
			if (pNewNode->key < pParentNode->key) {
				pParentNode->pLeftChild = pNewNode;
			}
			else {
				pParentNode->pRightChild = pNewNode;
			}
		}
		ret = TRUE;
	}
	else {
		printf("����, �޸��Ҵ�, insertElementBST()\n");
		ret = FALSE;
	}

	return ret;
}

//���� Ž�� Ʈ�� ��� ����
int deleteElementBST(BinSearchTree *pBinSearchTree, int key){
	int ret = TRUE;
	BinSearchTreeNode *pDelNode = NULL, *pParentNode = NULL;
	BinSearchTreeNode *pPredecessor = NULL, *pSuccessor = NULL;
	BinSearchTreeNode *pChildNode = NULL;

	if (pBinSearchTree == NULL) {
		ret = FALSE;
		return ret;
	}

	//Ű�� �ش��ϴ� ��� ã��
	pParentNode = NULL;
	pDelNode = pBinSearchTree->pRootNode;
	while (pDelNode != NULL) {	
		
		if (key == pDelNode->key) {
			break;
		}
		pParentNode = pDelNode;
		if (key < pDelNode->key) {
			pDelNode = pDelNode->pLeftChild;
		}
		else {
			pDelNode = pDelNode->pRightChild;
		}
		if (pDelNode == NULL) {
			printf("����, �������� �ʴ� Ű - [%d], deleteElementBST()\n",key);
			ret = FALSE;
			return ret;
		}
	}

	//�ش� ��� ����
	if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = NULL;
			}
			else {
				pParentNode->pRightChild = NULL;
			}
		}
		else {
			pBinSearchTree->pRootNode = NULL;
		}
	}
	else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
		pPredecessor = pDelNode;
		pSuccessor = pDelNode->pLeftChild;

		if (pSuccessor->pRightChild != NULL) {
			while (pSuccessor->pRightChild != NULL) {
				pPredecessor = pSuccessor;
				pSuccessor = pSuccessor->pRightChild;
			}

			pPredecessor->pRightChild = pSuccessor->pLeftChild;
			pSuccessor->pLeftChild = pDelNode->pLeftChild;
			pSuccessor->pRightChild = pDelNode->pRightChild;
		}
		else {
			pSuccessor = pDelNode->pRightChild;
			pSuccessor->pLeftChild = pDelNode->pLeftChild;
			pSuccessor->pRightChild = NULL;
		}
		
		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pSuccessor;
			}
			else {
				pParentNode->pRightChild = pSuccessor;
			}
		}
		else {
			pBinSearchTree->pRootNode = pSuccessor;
		}
	}
	else {
		if (pDelNode->pLeftChild != NULL) {
			pChildNode = pDelNode->pLeftChild;
		}
		else {
			pChildNode = pDelNode->pRightChild;
		}
		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pChildNode;
			}
			else {
				pParentNode->pRightChild = pChildNode;
			}
		}
		else {
			pBinSearchTree->pRootNode = pChildNode;
		}
	}

	free(pDelNode);
	return ret;
}

//���� Ž�� Ʈ�� �˻�
BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key){
	BinSearchTreeNode* pReturn = NULL;

	if (pBinSearchTree == NULL) {
		return NULL;
	}

	pReturn = pBinSearchTree->pRootNode;
	while (pReturn != NULL) {
		if (key == pReturn->key) {
			break;
		}
		else if (key < pReturn->key) {
			pReturn = pReturn->pLeftChild;
		}
		else {
			pReturn = pReturn->pRightChild;
		}
	}

	return pReturn;
}

//���� Ž�� Ʈ�� ����
void deleteBinSearchTree(BinSearchTree *pBinSearchTree){
	if (pBinSearchTree != NULL) {
		deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
		free(pBinSearchTree);
	}
}

void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode){
	if (pTreeNode != NULL) {
		deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
		deleteBinSearchTreeInternal(pTreeNode->pRightChild);
		free(pTreeNode);
	}
}

//���� Ž�� Ʈ�� ��ȸ
void displayBinSearchTree(BinSearchTree* pBinSearchTree) {
	if (pBinSearchTree != NULL) {
		displayBinSearchTreeNode(pBinSearchTree->pRootNode, 0, 'R');
	}
	else {
		printf("Ʈ���� NULL�Դϴ�.\n");
	}
}

void displayBinSearchTreeNode(BinSearchTreeNode* pNode, int level, char type) {
	int i = 0;

	for (i = 0; i < level; i++) {
		printf("	");
	}

	if (pNode != NULL) {
		printf("-[%i,%c]%d\n", level, type, pNode->key);

		displayBinSearchTreeNode(pNode->pLeftChild, level + 1, 'L');
		displayBinSearchTreeNode(pNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}