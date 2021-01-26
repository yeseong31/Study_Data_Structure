
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
	newNode->next = pstack->head;		// �� ��尡 �ֱٿ� �߰��� ��带 ����Ŵ.

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

	pstack->head = pstack->head->next;		// ������ ����� ���� ��带 head�� ����Ŵ.
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
