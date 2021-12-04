#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *pDeque;

	pDeque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (!pDeque)
		return (NULL);
	pDeque->currentElementCount = 0;
	pDeque->pFrontNode = NULL;
	pDeque->pRearNode = NULL;
	return (pDeque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *node;

	if (!pDeque)
		return (FALSE);
	node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!node)
		return (FALSE);
	node->data = element.data;
	node->pLLink = NULL;
	node->pRLink = pDeque->pFrontNode;
	if (pDeque->pFrontNode)
	{
		pDeque->pFrontNode->pLLink = node;
	}
	else
	{
		pDeque->pRearNode = node;
	}
	pDeque->pFrontNode = node;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *node;

	if (!pDeque)
		return (FALSE);
	node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!node)
		return (FALSE);
	node->data = element.data;
	node->pLLink = pDeque->pRearNode;
	node->pRLink = NULL;
	if (pDeque->pRearNode)
	{
		pDeque->pRearNode->pRLink = node;
	}
	else
	{
		pDeque->pFrontNode = node;
	}
	pDeque->pRearNode = node;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *ret;

	if (!pDeque)
		return (FALSE);
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	ret = pDeque->pFrontNode;
	if (pDeque->pFrontNode->pRLink)
	{
		pDeque->pFrontNode->pRLink->pLLink = NULL;
	}
	else
	{
		pDeque->pRearNode = NULL;
	}
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	pDeque->currentElementCount--;
	return (ret);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *ret;

	if (!pDeque)
		return (FALSE);
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	ret = pDeque->pRearNode;
	if (pDeque->pRearNode->pLLink)
	{
		pDeque->pRearNode->pLLink->pRLink = NULL;
	}
	else
	{
		pDeque->pFrontNode = NULL;
	}
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	pDeque->currentElementCount--;
	return (ret);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	if (!pDeque)
		return ;
	while (pDeque->pFrontNode)
	{
		free(deleteFrontLD(pDeque));
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (ERROR);
	return ((pDeque->currentElementCount == 0) ? TRUE : FALSE);
}

void displayLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode *node;
	int i;

	if (pDeque == NULL)
	{
		printf("Deque pointer doesn't exist\n\n");
		return ;
	}
	if (pDeque->currentElementCount == 0)
	{
		printf("No elements in deque\n\n");
		return ;
	}
	printf("=====DEQUE=====\n");
	printf("Deque size : %d\n", pDeque->currentElementCount);
	node = peekFrontLD(pDeque);
	i = 0;
	while (node)
	{
		printf("[%d] : %c\n", i, (char)node->data);
		node = node->pRLink;
		i++;
	}
	printf("===============\n\n");
}

void displayReverseLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode *node;
	int i;

	if (pDeque == NULL)
	{
		printf("Deque pointer doesn't exist\n\n");
		return ;
	}
	if (pDeque->currentElementCount == 0)
	{
		printf("No elements in deque\n\n");
		return ;
	}
	printf("===REV_DEQUE===\n");
	printf("Deque size : %d\n", pDeque->currentElementCount);
	node = peekRearLD(pDeque);
	i = pDeque->currentElementCount - 1;
	while (node)
	{
		printf("[%d] : %c\n", i, (char)node->data);
		node = node->pLLink;
		i--;
	}
	printf("===============\n\n");
}

int main(void)
{
	LinkedDeque *pDeque;
	DequeNode new;
	DequeNode *temp;

	pDeque = createLinkedDeque();
	printf("EMPTY? : %d\n\n", isLinkedDequeEmpty(pDeque));

	new.data = 'A';
	insertFrontLD(pDeque, new);
	new.data = 'B';
	insertFrontLD(pDeque, new);
	new.data = 'C';
	insertRearLD(pDeque, new);
	new.data = 'D';
	insertRearLD(pDeque, new);
	displayLinkedDeque(pDeque);
	displayReverseLinkedDeque(pDeque);

	temp = deleteRearLD(pDeque);
	printf("Delete rear : %c\n", (char)temp->data);
	free(temp);
	temp = deleteFrontLD(pDeque);
	printf("Delete front : %c\n", (char)temp->data);
	free(temp);
	displayLinkedDeque(pDeque);
	displayReverseLinkedDeque(pDeque);

	deleteFrontLD(pDeque);
	deleteFrontLD(pDeque);
	displayLinkedDeque(pDeque);
	displayReverseLinkedDeque(pDeque);

	printf("EMPTY? : %d\n\n", isLinkedDequeEmpty(pDeque));

	deleteFrontLD(pDeque);

	deleteLinkedDeque(pDeque);

	return (0);
}