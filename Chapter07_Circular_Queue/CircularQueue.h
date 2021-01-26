#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE		1
#define FALSE		0

#define QUE_LEN		100			// 100명을 수용할 수 있는 대기실
typedef int Data;

typedef struct _cQueue {
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);

int QIsEmpty(Queue * pq);

void Enqueue(Queue* pq, Data data);

Data Dequeue(Queue * pq);

Data QPeek(Queue * pq);

#endif // !__CIRCULAR_QUEUE_H__
