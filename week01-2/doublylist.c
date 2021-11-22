#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
	DoublyList *pList;
	DoublyListNode *head;

	pList = (DoublyList *)malloc(sizeof(DoublyList));
	if (pList == NULL)
		return (FALSE);
	head = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (head == NULL)
		return (FALSE);
	head->data = 0;
	head->pLLink = NULL;
	head->pRLink = NULL;
	pList->currentElementCount = 0;
	pList->headerNode = head;
	return (pList);
}

void deleteDoublyList(DoublyList* pList)
{
	DoublyListNode *temp;
	DoublyListNode *next;

	if (pList == NULL)
		return ;
	temp = pList->headerNode;
	while (temp != NULL)
	{
		next = temp->pRLink;
		free(temp);
		temp = next;
	}
	free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *prev;
	DoublyListNode *next;
	DoublyListNode *new;

	if (pList == NULL)
		return (FALSE);
	if (position > pList->currentElementCount || position < 0)
		return (FALSE);
	new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	if (position == 0)
		prev = pList->headerNode;
	else
		prev = getDLElement(pList, position - 1);
	next = prev->pRLink;
	prev->pRLink = new;
	new->pLLink = prev;
	if (next != NULL)
		next->pLLink = new;
	new->pRLink = next;
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *prev;
	DoublyListNode *next;
	DoublyListNode *del;

	if (pList == NULL)
		return (FALSE);
	if (position >= pList->currentElementCount || position < 0)
		return (FALSE);
	if (position == 0)
		prev = pList->headerNode;
	else
		prev = getDLElement(pList, position - 1);
	del = prev->pRLink;
	next = del->pRLink;
	prev->pRLink = next;
	if (next != NULL)
		next->pLLink = NULL;
	free(del);
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode *temp;

	if (pList == NULL)
		return ;
	temp = pList->headerNode->pRLink;
	for (int i = 0; i < getDoublyListLength(pList); i++)
	{
		temp->data = 0;
		temp = temp->pRLink;
	}
}

int getDoublyListLength(DoublyList* pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *temp;

	if (pList == NULL)
		return (NULL);
	if (position >= pList->currentElementCount || position < 0)
		return (NULL);
	temp = pList->headerNode->pRLink;
	for (int i = 0; i < position; i++)
	{
		temp = temp->pRLink;
	}
	return (temp);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *temp;

	printf("Doubly List Length : %d\n\n", pList->currentElementCount);
	temp = pList->headerNode->pRLink;
	for (int i = 0; i < getDoublyListLength(pList); i++)
	{
		printf("%dth element data: %d\n", i, temp->data);
		temp = temp->pRLink;
	}
}
