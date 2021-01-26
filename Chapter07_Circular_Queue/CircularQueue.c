
#include "CircularQueue.h"
#include <stdio.h>

void QueueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

// ���� ť�� �ٽ�
// ť�� ���꿡 ���� F�� R�� �̵��� �� �̵��ؾ� �� ��ġ�� �˷��ִ� �Լ�
int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)		// �迭�� ������ ����� �ε��� ���̶��
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {		// ť�� �� á�ٸ�
		puts("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);		// rear�� �� ĭ �̵�
	pq->queArr[pq->rear] = data;			// rear�� ����Ű�� ���� ������ ����
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		puts("Queue Memory Error!");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];	// F�� ��ġ�� '��ȿ���� ���� ������'�̹Ƿ�
}									// ���ٸ� ���� ������ �ʿ����� ����

Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		puts("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

