
#include "DBLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// 첫 번째 노드 추가 시 아래 문장에서 plist->head는 NULL이다!
	newNode->next = plist->head;

	if (plist->head != NULL)
		plist->head->prev = newNode;		// 두 번째 이후의 노드를 추가할 때

	newNode->prev = NULL;
	plist->head = newNode;
	(plist->numOfData)++;
}


int LFirst(List* plist, Data* pdata) {
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

//	Data LRemove(List* plist);

int LCount(List* plist) {
	return plist->numOfData;
}

