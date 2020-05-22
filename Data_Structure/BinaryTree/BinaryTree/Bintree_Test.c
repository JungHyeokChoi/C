#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"
#include "Bintreetraversal.h"
#include "Bintreeop.h"

BinTree* createExampleBinTree();

int main(int argc, char *argv[]) {
	int compareResult = FALSE;
	int count = 0;

	BinTree *pBinTree = NULL, *pCopyBinTree;
	
	
	pBinTree = createExampleBinTree();
	printf("이진 트리 원본 : \n");
	displayBinTree(pBinTree);

	pCopyBinTree = copyBinTree(pBinTree);
	printf("이진 트리 복사본 : \n");
	displayBinTree(pCopyBinTree);

	compareResult = equalBinTree(pBinTree, pCopyBinTree);
	printf("\n이진 트리 비교 결과 : %d\n", compareResult);

	count = getNodeCountBT(pBinTree);
	printf("\n이진 트리 노드 개수 : %d\n", count);

	count = getNodeCountHaveChildNodeBT(pBinTree);
	printf("\n이진 트리 자식 노드 1개 이상 있는 노드 개수 : %d\n", count);

	count = getLeafNodeCountBT(pBinTree);
	printf("\n이진 트리 단말 노드 개수 : %d\n", count);

	count = getHeightBT(pBinTree);
	printf("\n이진 트리의 높이 : %d\n\n", count);

	increaseKeyBT(pBinTree);
	printf("\n이진 트리 Key 2 증가\n\n");
	displayBinTree(pBinTree);
	printf("\n\n");

	deleteBinTree(pBinTree);
	deleteBinTree(pCopyBinTree);

	return 0;
}

BinTree* createExampleBinTree() {
	BinTree *pReturn = NULL;
	BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
	BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
	BinTreeNode *pNodeG = NULL, *pNodeH = NULL, *pNodeI = NULL;
	BinTreeNode *pNodeJ = NULL, *pNodeK = NULL, *pNodeL = NULL, *pNodeM = NULL;
	BinTreeNode node = { 0, };

	node.data = 'A';
	pReturn = makeBinTree(node);
	if (pReturn != NULL) {
		//Level 1
		pNodeA = getRootNodeBT(pReturn);

		//Level 2
		node.data = 'B';
		pNodeB = insertLeftChildNodeBT(pNodeA, node);
		node.data = 'C';
		pNodeC = insertRightChildNodeBT(pNodeA, node);

		//Level 3
		node.data = 'D';
		pNodeD = insertLeftChildNodeBT(pNodeB, node);
		node.data = 'E';
		pNodeE = insertRightChildNodeBT(pNodeB, node);
		node.data = 'F';
		pNodeF = insertLeftChildNodeBT(pNodeC, node);
		node.data = 'G';
		pNodeG = insertRightChildNodeBT(pNodeC, node);

		//Level 4
		node.data = 'H';
		pNodeH = insertLeftChildNodeBT(pNodeD, node);
		node.data = 'I';
		pNodeI = insertRightChildNodeBT(pNodeD, node);
		node.data = 'J';
		pNodeJ = insertLeftChildNodeBT(pNodeE, node);
		node.data = 'K';
		pNodeK = insertRightChildNodeBT(pNodeF, node);
		node.data = 'L';
		pNodeL = insertLeftChildNodeBT(pNodeG, node);
		node.data = 'M';
		pNodeM = insertRightChildNodeBT(pNodeG, node);
	}

	return pReturn;
}