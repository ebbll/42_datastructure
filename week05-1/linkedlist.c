#include "linkedlist.h"
#include <stdlib.h>

LinkedList* createLinkedList()
{
	LinkedList	*list;
	ListNode	*temp;

	if (!(list = malloc(sizeof(LinkedList))))
		return (NULL);
	list->currentElementCount = 0;
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*prev;
	ListNode	*new;

	if (!pList)
		return (FALSE);
	if (pList->currentElementCount < position || position < 0)
		return (FALSE);
	if (!(new = malloc(sizeof(ListNode))))
		return (FALSE);
	new->data = element.data;
	if (position == 0)
		prev = pList->headerNode;
	else
		prev = getLLElement(pList, position - 1);
	new->pLink = prev->pLink;
	prev->pLink = new;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*prev;
	ListNode	*now;

	if (!pList)
		return (FALSE);
	if (pList->currentElementCount <= position || position < 0)
		return (FALSE);
	if (position == 0)
		prev = pList->headerNode;
	else
		prev = getLLElement(pList, position - 1);
	now = getLLElement(pList, position);
	prev->pLink = now->pLink;
	pList->currentElementCount--;
	free(now);
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*ret;

	if (!pList)
		return (NULL);
	if (pList->currentElementCount <= position || position < 0)
		return (NULL);
	ret = pList->headerNode->pLink;
	for (int i = 0; i < position; i++)
		ret = ret->pLink;
	return (ret);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode	*temp;

	if (!pList)
		return ;
	temp = pList->headerNode;
	while (temp)
	{
		temp->data = 0;
		temp = temp->pLink;
	}
}

int getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	ListNode	*prev;

	if (!pList)
		return ;
	curr = pList->headerNode;
	while (curr)
	{
		prev = curr;
		curr = curr->pLink;
		free(prev);
	}
	free(pList);
}