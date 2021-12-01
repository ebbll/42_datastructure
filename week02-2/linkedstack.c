#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *pStack;

	pStack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (pStack == NULL)
		return (NULL);
	pStack->currentElementCount = 0;
	pStack->pTopElement = (StackNode *)malloc(sizeof(StackNode));
	if (pStack->pTopElement == NULL)
		return (NULL);
	pStack->pTopElement->data.x = 0;
	pStack->pTopElement->data.y = 0;
	pStack->pTopElement->pLink = NULL;
	return (pStack);
}

int pushLS(LinkedStack* pStack, t_pos pos)
{
	StackNode *new;

	if (pStack == NULL)
		return (FALSE);
	new = (StackNode *)malloc(sizeof(StackNode));
	if (new == NULL)
		return (FALSE);
	new->data.x = pos.x;
	new->data.y = pos.y;
	new->pLink = pStack->pTopElement->pLink;
	pStack->pTopElement->pLink = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	//pop 결과는 스택노드의 포인터인데, 그럼 프리는 언제 해??
	StackNode *ret;

	if (pStack == NULL)
		return (NULL);
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	ret = pStack->pTopElement->pLink;
	pStack->pTopElement->pLink = ret->pLink;
	pStack->currentElementCount--;
	return (ret);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (pStack == NULL)
		return (NULL);
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement->pLink);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode *temp;

	if (pStack == NULL)
		return ;
	for (int i = 0; i < pStack->currentElementCount; i++)
	{
		temp = popLS(pStack);
		free(temp);
	}
	free(pStack->pTopElement);
	free(pStack);
}

/*
int isLinkedStackFull(LinkedStack* pStack)
{
	// linkedstack이 full일 수 있나??
}
*/

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack == NULL)
		return (FALSE);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
