#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

// deque : double-ended queue
// insert 와 delete가 양 끝(front와 rear)에서 일어남
// 일반적으로 더블 링크드 리스트로 구현됨
// 더블 링크드 리스트로 구현된 덱은 front와 rear의 정보가 있기 때문에 삽입/제거 연산의 시간 복잡도가 O(1)과 같음

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
	if (pDeque->pFrontNode) // 기존에 노드가 존재할 경우
	{
		pDeque->pFrontNode->pLLink = node;
	}
	else // 노드가 없는 경우
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
	if (pDeque->pFrontNode->pRLink) // 노드가 남아있는 경우
	{
		pDeque->pFrontNode->pRLink->pLLink = NULL;
	}
	else // 남은 노드가 없는 경우
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

	// BACD
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

	temp = deleteFrontLD(pDeque);
	printf("Delete front : %c\n", (char)temp->data);
	free(temp);
	temp = deleteFrontLD(pDeque);
	printf("Delete front : %c\n\n", (char)temp->data);
	free(temp);
	displayLinkedDeque(pDeque);
	displayReverseLinkedDeque(pDeque);

	printf("EMPTY? : %d\n\n", isLinkedDequeEmpty(pDeque));

	deleteFrontLD(pDeque);

	deleteLinkedDeque(pDeque);

	return (0);
}
