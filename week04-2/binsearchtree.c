#include "binsearchtree.h"

BinSearchTree* createBinSearchTree()
{
	BinSearchTree *pBinSearchTree;

	pBinSearchTree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (!pBinSearchTree)
		return (NULL);
	pBinSearchTree->pRootNode = NULL;
	return (pBinSearchTree);
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{

}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{

}

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{

}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{

}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{

}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{

}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
{

}
