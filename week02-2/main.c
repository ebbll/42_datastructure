#include "linkedstack.h"
#include <stdio.h>

int g_map[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 1 ,1 ,1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0}
};

void displayLinkedStack(LinkedStack *pStack)
{
	StackNode *node;
	
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
	node = pStack->pTopElement;
	printf("=====STACK=====\n");
	printf("Stack size : %d\n", pStack->currentElementCount);
	while (node != NULL)
	{
		printf("[%d %d]\n", node->data.x, node->data.y);
		node = node->pLink;
	}
	printf("===============\n\n");
}

int main(void)
{
	LinkedStack *p = createLinkedStack();
	t_pos startPos = {0, 0};
	t_pos endPos = {7, 7};

	findPath(startPos, endPos, p);
	printMap();
	displayLinkedStack(p);
	deleteLinkedStack(p);
	return (0);
}