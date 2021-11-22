#include "linkedstack.h"
#include <stdlib.h>

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
	pStack->pTopElement->data = 0;
	pStack->pTopElement->pLLink = NULL;
	pStack->pTopElement->pRLink = NULL;
	return (pStack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *head;
	StackNode *new;

	if (pStack == NULL)
		return (FALSE);
	new = (StackNode *)malloc(sizeof(StackNode));
	if (new == NULL)
		return (FALSE);
	head = pStack->pTopElement->pRLink;
	new->pLLink = NULL;
	new->pRLink = head;
	head->pLLink = new;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	//pop 결과는 탑 포인터인데, 그럼 프리는 언제 해??
	StackNode *ret;
	StackNode *next;

	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	ret = pStack->pTopElement->pRLink;
	next = ret->pRLink;
	ret->pRLink->pLLink = NULL;
	ret->pLLink = NULL;
	ret->pRLink = NULL;
	pStack->pTopElement = next;
	pStack->currentElementCount--;
	return (ret);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	return (pStack->pTopElement->pRLink);
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
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack == NULL)
		return (FALSE);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

int checkBracketMatching(char *pSource)
{
	LinkedStack *pStack;
	StackNode *new;
	StackNode *pop;
	int ret;

	pStack = createLinkedStack();
	if (pStack == NULL)
		return (FALSE);
	while (*pSource != '\0')
	{
		if (*pSource == '{' || *pSource == '[' || *pSource == '(' || *pSource == '<')
		{
			new = createLinkedNode((int)*pSource);
			pushLS(pStack, *new);
		}
		else if (*pSource == '}')
		{
			pop = popLS(pStack);
			if (pop->data != '{')
			{
				free(pop);
				deleteLinkedStack(pStack);
				return (FALSE);
			}
		}
		else if (*pSource == ']')
		{
			pop = popLS(pStack);
			if (pop->data != '[')
			{
				free(pop);
				deleteLinkedStack(pStack);
				return (FALSE);
			}
		}
		else if (*pSource == ')')
		{
			pop = popLS(pStack);
			if (pop->data != '(')
			{
				free(pop);
				deleteLinkedStack(pStack);
				return (FALSE);
			}
		}
		else if (*pSource == '>')
		{
			pop = popLS(pStack);
			if (pop->data != '<')
			{
				free(pop);
				deleteLinkedStack(pStack);
				return (FALSE);
			}
		}
		pSource++;
	}
	if (pStack->currentElementCount == 0)
		ret = TRUE;
	else
		ret = FALSE;
	deleteLinkedStack(pStack);
	return (ret);
}

StackNode	*createLinkedNode(int data)
{
	StackNode *new;

	new = (StackNode *)malloc(sizeof(StackNode));
	new->data = data;
	new->pLLink = NULL;
	new->pRLink = NULL;
	return (new);
}
