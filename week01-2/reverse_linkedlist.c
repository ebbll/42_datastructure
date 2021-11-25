# include "../week01-1/linkedlist.h"
#include <stddef.h>
#include <unistd.h>

void	reverseLinkedList(LinkedList *plist)
{
	ListNode *head;
	ListNode *to_be_tail;
	ListNode *prev, *curr, *next;

	if (plist->currentElementCount == 0 || plist->currentElementCount == 1)
		return ;
	head = plist->headerNode; //dummy
	to_be_tail = plist->headerNode->pLink;
	prev = head;
	curr = head->pLink;
	next = head->pLink->pLink;

	while (curr)
	{
		curr->pLink = prev;
		prev = curr;
		curr = next;
		if (curr)
			next = curr->pLink;
	}
	to_be_tail->pLink = NULL;
	head->pLink = prev;
}