#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *pBinTree;
	BinTreeNode *new;

	pBinTree = (BinTree *)malloc(sizeof(BinTree));
	if (!pBinTree)
		return (NULL);
	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
	{
		free(pBinTree);
		return (NULL);
	}
	new->data = rootNode.data;
	new->visited = FALSE;
	new->pLeftChild = NULL;
	new->pRightChild = NULL;
	pBinTree->pRootNode = new;
	return (pBinTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree || !pBinTree->pRootNode)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new;

	if (!pParentNode || pParentNode->pLeftChild)
		return (NULL);
	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
		return (NULL);
	new->data = element.data;
	new->visited = FALSE;
	new->pLeftChild = NULL;
	new->pRightChild = NULL;
	pParentNode->pLeftChild = new;
	return (new);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new;

	if (!pParentNode || pParentNode->pRightChild)
		return (NULL);
	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
		return (NULL);
	new->data = element.data;
	new->visited = FALSE;
	new->pLeftChild = NULL;
	new->pRightChild = NULL;
	pParentNode->pRightChild = new;
	return (new);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode || !pNode->pLeftChild)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode || !pNode->pRightChild)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree)
		return ;
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}

void preorderTraversalBinTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	printf("%c\n", pNode->data);
	preorderTraversalBinTree(pNode->pLeftChild);
	preorderTraversalBinTree(pNode->pRightChild);
}

void inorderTraversalBinTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	inorderTraversalBinTree(pNode->pLeftChild);
	printf("%c\n", pNode->data);
	inorderTraversalBinTree(pNode->pRightChild);
}

void postorderTraversalBinTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	postorderTraversalBinTree(pNode->pLeftChild);
	postorderTraversalBinTree(pNode->pRightChild);
	printf("%c\n", pNode->data);
}

int main(void)
{
	BinTree *pBinTree;
	BinTreeNode new;

	new.data = 'A';
	pBinTree = makeBinTree(new);

	new.data = 'B';
	insertLeftChildNodeBT(pBinTree->pRootNode, new);
	
	new.data = 'C';
	insertRightChildNodeBT(pBinTree->pRootNode, new);

	new.data = 'D';
	insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild, new);

	new.data = 'E';
	insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild, new);

	new.data = 'F';
	insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild, new);

	new.data = 'G';
	insertRightChildNodeBT(pBinTree->pRootNode->pRightChild, new);

	new.data = 'H';
	insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, new);

	new.data = 'I';
	insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, new);

	new.data = 'J';
	insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pRightChild, new);

	new.data = 'K';
	insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pLeftChild, new);

	new.data = 'L';
	insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, new);

	new.data = 'M';
	insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, new);

	printf("PREORDER\n");
	preorderTraversalBinTree(pBinTree->pRootNode);
	printf("\n");

	printf("INORDER\n");
	inorderTraversalBinTree(pBinTree->pRootNode);
	printf("\n");

	printf("POSTORDER\n");
	postorderTraversalBinTree(pBinTree->pRootNode);

	deleteBinTree(pBinTree);
}
