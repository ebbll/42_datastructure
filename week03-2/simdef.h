#ifndef _SIM_DEF_
#define _SIM_DEF_

#include <stdlib.h>
#include <stdio.h>

typedef enum SimStatusType { ARRIVAL, START, END } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
} SimCustomer;

typedef struct QueueNodeType
{
	SimCustomer info;
	struct QueueNodeType* pRLink;
	struct QueueNodeType* pLLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;
	QueueNode* pFrontNode;
	QueueNode* pRearNode;
} LinkedQueue;

LinkedQueue* createLinkedQueue();
int enqueueLQ(LinkedQueue* pDeque, QueueNode *node);
QueueNode* dequeueLQ(LinkedQueue* pQueue);
QueueNode* peekFrontLQ(LinkedQueue* pQueue);
QueueNode* peekRearLQ(LinkedQueue* pQueue);
void deleteLinkeQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);

void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pArrivalQueue);
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif