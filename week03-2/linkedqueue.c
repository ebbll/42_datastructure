#include "simdef.h"

/*
	QUEUE FUNCTIONS
*/
LinkedQueue* createLinkedQueue()
{
	LinkedQueue *pQueue;

	pQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (!pQueue)
		return (NULL);
	pQueue->currentElementCount = 0;
	pQueue->pFrontNode = NULL;
	pQueue->pRearNode = NULL;
	return (pQueue);
}

int enqueueLQ(LinkedQueue* pQueue, QueueNode *node)
{
	node->pLLink = pQueue->pRearNode;
	node->pRLink = NULL;
	if (pQueue->pRearNode)
	{
		pQueue->pRearNode->pRLink = node;
	}
	else
	{
		pQueue->pFrontNode = node;
	}
	pQueue->pRearNode = node;
	pQueue->currentElementCount++;
	return (TRUE);
}

QueueNode* dequeueLQ(LinkedQueue* pQueue)
{
	QueueNode *ret;

	if (!pQueue)
		return (FALSE);
	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	ret = pQueue->pFrontNode;
	if (pQueue->pFrontNode->pRLink)
	{
		pQueue->pFrontNode->pRLink->pLLink = NULL;
	}
	else // 남은 노드가 없는 경우
	{
		pQueue->pRearNode = NULL;
	}
	pQueue->pFrontNode = pQueue->pFrontNode->pRLink;
	pQueue->currentElementCount--;
	return (ret);
}

QueueNode* peekFrontLQ(LinkedQueue* pQueue)
{
	if (!pQueue || isLinkedDequeEmpty(pQueue))
		return (NULL);
	return (pQueue->pFrontNode);
}

QueueNode* peekRearLQ(LinkedQueue* pQueue)
{
	if (!pQueue || isLinkedDequeEmpty(pQueue))
		return (NULL);
	return (pQueue->pRearNode);
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
	if (!pQueue)
		return ;
	while (pQueue->pFrontNode)
	{
		free(dequeueLQ(pQueue));
	}
	free(pQueue);
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	if (!pQueue)
		return (ERROR);
	return ((pQueue->currentElementCount == 0) ? TRUE : FALSE);
}

void displayLinkedQueue(LinkedQueue *pQueue)
{
	QueueNode *node;
	int i;

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
	node = peekFrontLQ(pQueue);
	i = 0;
	while (node)
	{
		printf("[%d] : %d\n", i, node->info.endTime);
		node = node->pRLink;
		i++;
	}
	printf("===============\n\n");
}

/*
	SIMULATION FUNCTIONS
*/
void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pArrivalQueue)
{
	QueueNode *node;
	if (!pArrivalQueue)
		return ;
	node = (QueueNode *)malloc(sizeof(QueueNode));
	if (!node)
		return ;
	node->info.arrivalTime = arrivalTime;
	node->info.serviceTime = serviceTime;
	node->info.status = ARRIVAL;
	enqueueLQ(pArrivalQueue, node);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	QueueNode *node;

	node = peekFrontLQ(pArrivalQueue);
	if (node && node->info.arrivalTime == currentTime)
		enqueueAQ(pWaitQueue, dequeueLQ(pArrivalQueue));
}

QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode *node;

	node = peekFrontLQ(pWaitQueue);
	if (node && node->info.status == ARRIVAL)
	{
		node->info.startTime = currentTime;
		node->info.status = START;
	}
	return (node);
}

QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	QueueNode *node;

	node = peekFrontLQ();
	*pServiceUserCount++;
	*pTotalWaitTime = pServiceNode->info.startTime - pServiceNode->info.arrivalTime;
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{

}

void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{

}
