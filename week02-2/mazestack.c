#include "../week02-1/linkedstack.h"
#include "mazestack.h"



void findPath(int maze[8][8], int entry[2], int out[2], LinkedStack *pStack)
{
	StackNode node;
	int x, y;

	node.data = entry[0] * 8 + entry[1];
	maze[entry[0]][entry[1]] = 2;
	pushLS(pStack, node);

}

void printSolution(int maze[8][8], LinkedStack *pStack)
{
	int copy[8][8];
	StackNode *node = pStack->pTopElement->pLink;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			copy[i][j] = maze[i][j];
		}
	}
	for (int i = 0; i < pStack->currentElementCount; i++)
	{
		copy[node->data / 8][node->data % 8] = 4;
		node = node->pLink;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (copy[i][j] == EMPTY)
				printf(" ");
			else if (copy[i][j] == WALL)
				printf("■");
			else // copy[i][j] == WAY
				printf("*");
		}
		printf("\n");
	}
}

int main(void)
{
	LinkedStack *pStack;
	int maze[8][8] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}
	};
	int entry[2] = {0, 0};
	int out[2] = {7, 7};

	pStack = createLinkedStack();

	findPath(maze, entry, out, pStack);
	printSolution(maze, pStack);

	deleteLinkedStack(pStack);
}