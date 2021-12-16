#ifndef _HEAP_
#define _HEAP_

#include <stdlib.h>
#include <stdio.h>

typedef struct	heapNodeType
{
	int	data;
} heapNode;

typedef struct  heapType
{
	int		currentElementCount;
	int		maxElementCount;
	struct heapNodeType*	pRootNode;  
} heap;

heap*		createArrayHeap(int maxElementCount);
heapNode*	getRootNodeAH(heap* pArrayHeap);
int			insertChildNodeHP(heap* pArrayHeap, heapNode element);
void		swapNode(heap* pArrayHeap, int child, int parent);
void		deleteHeap(heap* pArrayHeap);
void		deleteHeapNode(heap* pArrayHeap);
void		Inorder(heap *pArrayHeap, int i);

#endif

#define TRUE	1
#define FALSE	0
