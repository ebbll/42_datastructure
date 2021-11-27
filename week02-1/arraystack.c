#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *pStack;
	ArrayStackNode *pElement;

	if (maxElementCount <= 0)
		return (NULL);
	pStack = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (pStack == NULL)
		return (NULL);
	pStack->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (pStack->pElement == NULL)
		return (NULL);
	pStack->maxElementCount = maxElementCount;
	pStack->currentElementCount = 0;
	return (pStack);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	if (pStack == NULL)
		return (FALSE);
	if (isArrayStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode *ret;

	if (pStack == NULL)
		return (NULL);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	pStack->currentElementCount--;
	return (&pStack->pElement[pStack->currentElementCount]);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (NULL);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack* pStack)
{
	free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (FALSE);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (FALSE);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void displayArrayStack(ArrayStack* pStack)
{
	if (pStack == NULL)
	{
		printf("Stack pointer doesn't exist\n\n");
		return ;
	}
	if (pStack->currentElementCount == 0)
	{
		printf("No elements in stack\n\n");
		return ;
	}
	printf("=====STACK=====\n");
	printf("Stack size : %d\n", pStack->currentElementCount);
	for (int i = pStack->currentElementCount - 1; i >= 0; i--)
	{
		printf("[%d] : %d\n", pStack->currentElementCount - i - 1, pStack->pElement[i].data);
	}
	printf("===============\n\n");
}

int	main(void)
{
	ArrayStack *pStack;
	ArrayStackNode new;
	ArrayStackNode *temp;

	pStack = createArrayStack(3);

	printf("EMPTY? : %d\n\n", isArrayStackEmpty(pStack));

	new.data = 0;
	pushAS(pStack, new);
	new.data = 1;
	pushAS(pStack, new);
	new.data = 2;
	pushAS(pStack, new);
	displayArrayStack(pStack);

	printf("FULL? : %d\n\n", isArrayStackFull(pStack));

	new.data = 3;
	pushAS(pStack, new);
	displayArrayStack(pStack);

	temp = popAS(pStack);
	printf("POP : %d\n", temp->data);
	temp = peekAS(pStack);
	printf("PEEK : %d\n", temp->data);
	displayArrayStack(pStack);

	popAS(pStack);
	popAS(pStack);
	displayArrayStack(pStack);

	printf("EMPTY? : %d\n\n", isArrayStackEmpty(pStack));

	popAS(pStack);
}