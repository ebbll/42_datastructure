#include "linkedstack.h"
#include <stdio.h>

static int dx[4] = {1, 0, -1, 0};
static int dy[4] = {0, 1, 0, -1};

extern int g_map[HEIGHT][WIDTH];

void	printMap(void)
{
	printf("================\n");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf("%d ", g_map[i][j]);
		}
		printf("\n");
	}
	printf("===============\n");
}

static	int		poscmp(const t_pos a, const t_pos b)
{
	if (a.x == b.x && a.y == b.y)
		return (TRUE);
	return (FALSE);
}

static	int		pos_in_map(const t_pos pos)
{
	if ((pos.x >= 0 && pos.x < HEIGHT) && (pos.y >= 0 && pos.y < WIDTH))
		return (TRUE);
	return (FALSE);
}

int		findPath(const t_pos currPos, const t_pos endPos, LinkedStack *pStack)
{
	t_pos pos;

	g_map[currPos.y][currPos.x] = 2;
	if (pushLS(pStack, currPos) == FALSE)
		return (FALSE);
	for (int i = 0; i < 4; ++i)
	{
		pos.x = currPos.x + dx[i];
		pos.y = currPos.y + dy[i];
		if (pos_in_map(pos))
		{
			if (g_map[pos.y][pos.x] == 0)
			{
				if (findPath(pos, endPos, pStack))
					return (TRUE);
			}
		}
	}
	if (poscmp(currPos, endPos) == FALSE)
	{
		static int i = 0;
		StackNode *pop;
		pop = popLS(pStack);
		printf("[%d] pop : [%d %d]\n", i, pop->data.x, pop->data.y);
		++i;
		return (FALSE);
	}
	return (TRUE);
}