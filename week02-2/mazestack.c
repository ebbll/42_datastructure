#include "linkedstack.h"
#include <stdio.h>

#define EMPTY 0
#define WALL 1
#define VISITED 2

int direction[4][2] = {
	{1, 0},
	{0, 1},
	{0, -1},
	{-1, 0}
};

extern int MAZE[HEIGHT][WIDTH];

int check(t_pos current, t_pos end)
{
	return (current.x == end.x && current.y == end.y);
}

int findPath(t_pos currentPos, t_pos endPos, LinkedStack *pStack)
{
	t_pos pos;

	pushLS(pStack, currentPos);
	MAZE[currentPos.y][currentPos.x] = VISITED;
	for (int i = 0; i < 4; i++)
	{
		pos.x = currentPos.x + direction[i][0];
		pos.y = currentPos.y + direction[i][1];
		if ((pos.x >= 0 && pos.x < HEIGHT) && (pos.y >= 0 && pos.y < WIDTH))
		{
			if (MAZE[pos.y][pos.x] == EMPTY)
			{
				if (findPath(pos, endPos, pStack))
					return (TRUE);
			}
		}
	}
	if (check(currentPos, endPos) == FALSE)
	{
		free(popLS(pStack));
		return (FALSE);
	}
	return (TRUE);
}
