


#include "PriorityQueue.h"
#include <stdio.h>

int DataPriorityComp(char ch1, char ch2) {	
	return ch2 - ch1;							
}

int main(void) {
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c\n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c\n", PDequeue(&pq));

	while (!PQIsEmpty(&pq))
		printf("%c\n", PDequeue(&pq));
	printf("\n");

	return 0;
}

