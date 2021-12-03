#include "arrayqueue.h"
#include <stdlib.h>
#include <stdio.h>

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *pQueue;

	if (maxElementCount <= 0)
		return (NULL);
	pQueue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (pQueue == NULL)
		return (NULL);
	pQueue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (pQueue->pElement == NULL)
	{
		free(pQueue);
		return (NULL);
	}
	pQueue->maxElementCount = maxElementCount;
	pQueue->currentElementCount = 0;
	pQueue->front = 0;
	pQueue->rear = pQueue->maxElementCount - 1;
	return (pQueue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue || isArrayQueueFull(pQueue))
		return (FALSE);
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear].data = element.data;
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	if (!pQueue || isArrayQueueEmpty(pQueue))
		return (NULL);
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (&(pQueue->pElement[pQueue->front - 1]));
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	if (!pQueue || isArrayQueueEmpty(pQueue))
		return (NULL);
	return (&(pQueue->pElement[pQueue->front]));
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (-1);
	return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (-1);
	return (pQueue->currentElementCount == 0);
}

void displayArrayQueue(ArrayQueue *pQueue)
{
	int end;

	if (pQueue == NULL)
	{
		printf("Queue pointer doesn't exist\n\n");
		return ;
	}
	if (pQueue->currentElementCount == 0)
	{
		printf("No elements in queue\n\n");
		return ;
	}
	printf("=====QUEUE=====\n");
	printf("Queue size : %d\n", pQueue->currentElementCount);
	if (pQueue->front <= pQueue->rear)
		end = pQueue->rear;
	else
		end = pQueue->rear + pQueue->maxElementCount;
	for (int start = pQueue->front; start <= end; start++)
	{
		printf("[%d] : %c\n", start % pQueue->maxElementCount, pQueue->pElement[start % pQueue->maxElementCount].data);
	}
	printf("===============\n\n");
}

int	main(void)
{
	ArrayQueue *pQueue;
	ArrayQueueNode new;
	ArrayQueueNode *temp;

	pQueue = createArrayQueue(4);

	printf("EMPTY? : %d\n\n", isArrayQueueEmpty(pQueue));

	new.data = 'A';
	enqueueAQ(pQueue, new);
	new.data = 'B';
	enqueueAQ(pQueue, new);
	new.data = 'C';
	enqueueAQ(pQueue, new);
	new.data = 'D';
	enqueueAQ(pQueue, new);
	displayArrayQueue(pQueue);

	printf("FULL? : %d\n\n", isArrayQueueFull(pQueue));


	temp = dequeueAQ(pQueue);
	printf("DEQUEUE : %c\n", (int)temp->data);
	temp = peekAQ(pQueue);
	printf("PEEK : %c\n", (int)temp->data);
	displayArrayQueue(pQueue);

	new.data = 'E';
	enqueueAQ(pQueue, new);
	displayArrayQueue(pQueue);

	dequeueAQ(pQueue);
	dequeueAQ(pQueue);
	dequeueAQ(pQueue);
	dequeueAQ(pQueue);
	displayArrayQueue(pQueue);

	printf("EMPTY? : %d\n\n", isArrayQueueEmpty(pQueue));

	dequeueAQ(pQueue);

	deleteArrayQueue(pQueue);
	pQueue = NULL;

	return (0);
}