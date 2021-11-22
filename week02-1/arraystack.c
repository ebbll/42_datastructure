#include "arraystack.h"
#include <stdlib.h>

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *pStack;
	StackNode *pNode;

	if (maxElementCount < 0)
	pStack = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (pStack == NULL)
		return (NULL);
	pStack->pTopElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	if (pStack->pTopElement == NULL)
		return (NULL);
	pStack->currentElementCount = 0;
	pStack->maxElementCount = maxElementCount;
	return (pStack);
}

int pushAS(ArrayStack* pStack, StackNode element)
{
	if (pStack == NULL)
		return (FALSE);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (FALSE);
	pStack->pTopElement[pStack->currentElementCount].data = element.data;
	pStack->currentElementCount++;
}

StackNode* popAS(ArrayStack* pStack)
{
	StackNode *ret;

	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	pStack->currentElementCount--;
	return (&pStack->pTopElement[pStack->currentElementCount - 1]);
}

StackNode* peekAS(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	return (&pStack->pTopElement[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack* pStack)
{
	free(pStack->pTopElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (-1);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (-1);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

int checkBracketMatching(char *pSource)
{
	ArrayStack *pStack;
	StackNode *node;
	int ret;

	pStack = createArrayStack(100);
	while (*pSource != '\0')
	{
		if (*pSource == '{' || *pSource == '[' || *pSource == '(' || *pSource == '<')
		{
			node = createArrayStack((int)*pSource);
			pushAS(pStack, *node);
			free(node);
		}
		else if (*pSource == '}')
		{
			if (popAS(pStack)->data != '{')
				return (FALSE);
		}
		else if (*pSource == ']')
		{
			if (popAS(pStack)->data != '[')
				return (FALSE);
		}
		else if (*pSource == ')')
		{
			if (popAS(pStack)->data != '(')
				return (FALSE);
		}
		else if (*pSource == '>')
		{
			if (popAS(pStack)->data != '<')
				return (FALSE);
		}
		pSource++;
	}
	if (isArrayStackEmpty(pStack))
		ret = TRUE;
	else
		ret = FALSE;
	deleteArrayStack(pStack);
	return (ret);
}

StackNode	*createArrayNode(int data)
{
	StackNode *node;

	node = (StackNode *)malloc(sizeof(StackNode));
	node->data = data;
	return (node);
}
