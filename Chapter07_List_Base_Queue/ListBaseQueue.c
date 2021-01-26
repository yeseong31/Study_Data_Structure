
#include "ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (QIsEmpty(pq))
		pq->front = newNode;
	else
		pq->rear->next = newNode;

	pq->rear = newNode;
}

Data Dequeue(Queue* pq) {
	Node* delNode;
	Data rdata;

	if (QIsEmpty(pq)) {
		puts("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	rdata = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return rdata;
}

Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		puts("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}

