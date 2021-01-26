
/*

#include "PriorityQueue.h"
#include <string.h>
#include <stdio.h>

int DataPriorityComp(char* str1, char* str2) {
	return strlen(str2) - strlen(str1);
}

int main(void) {
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Good Morning");
	PEnqueue(&pq, "I have a pen");
	PEnqueue(&pq, "Priority Queue");
	PEnqueue(&pq, "Do you like coffee");
	PEnqueue(&pq, "I am so happy");

	while (!PQIsEmpty(&pq))
		printf("%s\n", PDequeue(&pq));
	printf("\n");
}

*/