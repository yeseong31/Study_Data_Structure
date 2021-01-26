
#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue* ppq, PriorityComp pc) {
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue* ppq) {
	HIsEmpty(ppq);
}

void PEnqueue(PQueue* ppq, PQData data) {
	HInsert(ppq, data);
}

PQData PDequeue(PQueue* ppq) {
	return HDelete(ppq);
}

// UsefulHeap.h에 껍데기를 씌운다는 느낌으로 우선순위 큐 구현