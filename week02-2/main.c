#include "linkedstack.h"
#include <stdio.h>

#define EMPTY 0
#define WALL 1
#define VISITED 2

int MAZE[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 1 ,1 ,1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0}
};

int ANSWER[HEIGHT][WIDTH] = {
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
	node = pStack->pTopElement->pLink;
	printf("=====STACK=====\n");
	printf("Stack size : %d\n", pStack->currentElementCount);
	while (node != NULL)
	{
		printf("(%d, %d)\n", node->data.x, node->data.y);
		node = node->pLink;
	}
	printf("===============\n\n");
}

void displayAnswer(LinkedStack *pStack)
{
	StackNode *node;

	node = pStack->pTopElement->pLink;
	while (node != NULL)
	{
		ANSWER[node->data.y][node->data.x] = VISITED;
		node = node->pLink;
	}
	printf("===MAP===\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (ANSWER[i][j] == 2)
				printf("→ ");
			else if (ANSWER[i][j] == 0)
				printf("  ");
			else
				printf("■ ");
		}
		printf("\n");
	}
}

int main(void)
{
	LinkedStack *pStack = createLinkedStack();
	t_pos startPos = {0, 0};
	t_pos endPos = {7, 7};

	findPath(startPos, endPos, pStack);
	displayLinkedStack(pStack);
	displayAnswer(pStack);
	deleteLinkedStack(pStack);
	return (0);
}