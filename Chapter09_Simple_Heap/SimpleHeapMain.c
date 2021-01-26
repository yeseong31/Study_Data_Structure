
#include "SimpleHeap.h"
#include <stdio.h>

int main(void) {
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c\n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c\n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c\n", HDelete(&heap));
	printf("\n");

	return 0;
}

// 데이터를 저장할 때 우선순위 정보를 별도로 전달하는 것은 그다지 선호되지 않는 편이다.
// 일반적으로 데이터의 우선순위는 데이터를 근거로 판단이 이뤄지기 때문이다.

