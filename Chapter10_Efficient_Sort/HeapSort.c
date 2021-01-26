
#include <stdio.h>
#include "../../Chapter09_우선순위_큐와_힙/c9_힙의_변경_UsefulHeap/UsefulHeap.h"

int PriComp(int n1, int n2) {		// 우선순위 기준 함수
	return n2 - n1;			// 오름차순 정렬
//	return n1 - n2;			// 내림차순 정렬
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	HeapInit(&heap, pc);
	int i;

	// 정렬대상을 가지고 힙을 구성한다.
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬을 완성한다. ('우선순위 큐'를 구현했으므로 꺼내는 족족 정렬됨)
	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}


int main(void) {
	int arr[4] = { 3, 4, 2, 1 };
	int i;
	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
