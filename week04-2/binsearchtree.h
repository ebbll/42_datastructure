#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

#include <stdlib.h>
#include <stdio.h>

typedef struct BinSearchTreeNodeType
{
	int key;
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType
{
	BinSearchTreeNode *pRootNode;
} BinSearchTree;

BinSearchTree *createBinSearchTree();
BinSearchTreeNode *insertElementBST(BinSearchTreeNode* pNode, BinSearchTreeNode element);
BinSearchTreeNode *deleteElementBST(BinSearchTreeNode* pRoot, int key);

BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key);
BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key);
BinSearchTreeNode *searchBST(BinSearchTreeNode *pRoot, int key);

void inorderTraversalBST(BinSearchTreeNode *pNode);

void deleteBinSearchTreeNode(BinSearchTreeNode *pRoot);
void deleteBinSearchTree(BinSearchTree *pBinSearchTree);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif