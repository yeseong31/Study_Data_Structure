
#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;		// 새 노드가 최근에 추가된 노드를 가리킴.

	pstack->head = newNode;
}

Data SPop(Stack* pstack) {
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {
		puts("Stack Memory Error!");
		exit(-1);
	}

	rnode = pstack->head;
	rdata = rnode->data;

	pstack->head = pstack->head->next;		// 삭제할 노드의 다음 노드를 head가 가리킴.
	free(rnode);
	return rdata;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		puts("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}
