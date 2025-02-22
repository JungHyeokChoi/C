#ifndef _BIN_TREE_
#define _BIN_TREE_

typedef struct BinTreeNodeType {
	char data;
	int visited;

	struct BinTreeNodeType *pLeftChild;
	struct BinTreeNodeType *pRightChild;

}BinTreeNode;

typedef struct BinTreeType {
	struct BinTreeNodeType *pRootNode;
}BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deletBinTreeNode(BinTreeNode* pNode);

#endif _BIN_TREE_

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE	1
#define FALSE	0

#endif _COMMON_TREE_DEF_