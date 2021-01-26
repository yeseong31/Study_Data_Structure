
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

// 원형 큐의 핵심
// 큐의 연산에 의한 F와 R이 이동할 때 이동해야 할 위치를 알려주는 함수
int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)		// 배열의 마지막 요소의 인덱스 값이라면
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {		// 큐가 꽉 찼다면
		puts("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);		// rear을 한 칸 이동
	pq->queArr[pq->rear] = data;			// rear이 가리키는 곳에 데이터 저장
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		puts("Queue Memory Error!");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];	// F의 위치는 '유효하지 않은 데이터'이므로
}									// 별다른 삭제 과정이 필요하지 않음

Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		puts("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

