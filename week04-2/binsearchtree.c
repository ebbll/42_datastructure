#include "binsearchtree.h"

// 이진 탐색 트리의 조건
// 1. key는 유일한 값이다
// 2. root의 key는 왼쪽 서브트리의 어떠한 key보다도 크다
// 3. root의 key는 오른쪽 서브트리의 어떠한 key보다도 작다
// 4. 왼쪽과 오른쪽 서브트리도 이진 탐색 트리이다
BinSearchTree* createBinSearchTree(BinSearchTreeNode element)
{
	BinSearchTree *pBinSearchTree;

	pBinSearchTree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (!pBinSearchTree)
		return (NULL);
	pBinSearchTree->pRootNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (!pBinSearchTree->pRootNode)
	{
		free(pBinSearchTree);
		return (NULL);
	}
	pBinSearchTree->pRootNode->key = element.key;
	pBinSearchTree->pRootNode->value = element.value;
	pBinSearchTree->pRootNode->pLeftChild = NULL;
	pBinSearchTree->pRootNode->pRightChild = NULL;
	return (pBinSearchTree);
}

BinSearchTreeNode *createNode(BinSearchTreeNode element)
{
	BinSearchTreeNode *pNode;

	pNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (!pNode)
		return (NULL);
	pNode->key = element.key;
	pNode->value = element.value;
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	return (pNode);
}

BinSearchTreeNode *insertElementBST(BinSearchTreeNode* pRoot, BinSearchTreeNode element)
{
	//빈 자리를 찾으면 노드 생성
	if (!pRoot)
		return (createNode(element));

	if (element.key < pRoot->key)
		pRoot->pLeftChild = insertElementBST(pRoot->pLeftChild, element);
	else if (element.key > pRoot->key)
		pRoot->pRightChild = insertElementBST(pRoot->pRightChild, element);
	//같은 값을 가진 경우 삽입하지 않음
	return (pRoot);
}

BinSearchTreeNode *getMinKeyNode(BinSearchTreeNode *pNode)
{
	BinSearchTreeNode *temp;

	temp = pNode;
	while (temp->pLeftChild)
	{
		temp = temp->pLeftChild;
	}
	return (temp);
}

BinSearchTreeNode *deleteElementBST(BinSearchTreeNode* pRoot, int key)
{
	if (!pRoot)
		return (NULL);

	// 지우고자 하는 노드 서치
	if (key < pRoot->key)
		pRoot->pLeftChild = deleteElementBST(pRoot->pLeftChild, key);
	else if (key > pRoot->key)
		pRoot->pRightChild = deleteElementBST(pRoot->pRightChild, key);

	// 노드 찾은 경우
	else
	{
		BinSearchTreeNode *temp;

		// 노드의 child가 없거나 하나일 때
		if (pRoot->pLeftChild == NULL)
		{
			temp = pRoot->pRightChild;
			free(pRoot);
			return (temp);
		}
		else if (pRoot->pRightChild == NULL)
		{
			temp = pRoot->pLeftChild;
			free(pRoot);
			return (temp);
		}
		// 노드에 자식이 둘 있는 경우
		// 오른쪽 서브트리에서 successor 노드를 찾는다.
		temp = getMinKeyNode(pRoot->pRightChild);
		// successor 노드 키와 삭제할 노드 키를 바꾼다.
		pRoot->key = temp->key;
		// 노드를 삭제한다.
		pRoot->pRightChild = deleteElementBST(pRoot->pRightChild, temp->key);
	}
	return (pRoot);
}

/*
BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{

}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{

}
*/

BinSearchTreeNode* searchBST(BinSearchTreeNode* pRoot, int key)
{
	BinSearchTreeNode *ret;

	ret = pRoot;
	while (ret)
	{
		if (ret->key == key)
			break ;
		else if (key < ret->key)
			ret = ret->pLeftChild;
		else
			ret = ret->pRightChild;
	}
	return (ret);
}

void inorderTraversalBST(BinSearchTreeNode *pNode)
{
	if (!pNode)
		return ;
	inorderTraversalBST(pNode->pLeftChild);
	printf("%d\n", pNode->key);
	inorderTraversalBST(pNode->pRightChild);
}

// Postorder로 지워줌
void deleteBinSearchTreeNode(BinSearchTreeNode* pRoot)
{
	if (!pRoot)
		return ;
	deleteBinSearchTreeNode(pRoot->pLeftChild);
	deleteBinSearchTreeNode(pRoot->pRightChild);
	free(pRoot);
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
	if (!pBinSearchTree)
		return ;
	deleteBinSearchTreeNode(pBinSearchTree->pRootNode);
	free(pBinSearchTree);
}

int main(void)
{
	BinSearchTree *pBinSearchTree;
	BinSearchTreeNode new;
	new.value = 0;

	new.key = 30;
	pBinSearchTree = createBinSearchTree(new);

	new.key = 20;
	insertElementBST(pBinSearchTree->pRootNode, new);

	new.key = 40;
	insertElementBST(pBinSearchTree->pRootNode, new);

	new.key = 10;
	insertElementBST(pBinSearchTree->pRootNode, new);

	new.key = 24;
	insertElementBST(pBinSearchTree->pRootNode, new);

	new.key = 34;
	insertElementBST(pBinSearchTree->pRootNode, new);
	
	new.key = 46;
	insertElementBST(pBinSearchTree->pRootNode, new);

	new.key = 6;
	insertElementBST(pBinSearchTree->pRootNode, new);

	new.key = 14;
	insertElementBST(pBinSearchTree->pRootNode, new);

	new.key = 22;
	insertElementBST(pBinSearchTree->pRootNode, new);

	printf("=====SEARCH=====\n");
	if (searchBST(pBinSearchTree->pRootNode, 22))
		printf("EXIST\n\n");
	else
		printf("DOES NOT EXIST\n\n");

	printf("=====SEARCH=====\n");
	if (searchBST(pBinSearchTree->pRootNode, -1))
		printf("EXIST\n\n");
	else
		printf("DOES NOT EXIST\n\n");
	
	printf("=====INORDER=====\n");
	inorderTraversalBST(pBinSearchTree->pRootNode);

	deleteBinSearchTree(pBinSearchTree);

	return (0);
}