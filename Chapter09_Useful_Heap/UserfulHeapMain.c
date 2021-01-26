
/*
	- PriotityComp의 typedef 선언은 다음과 같다.

		typedef int (*PriorityComp)(HData d1, HData d2);

	- 첫 번째 인자의 우선순위가 높다면, 0보다 큰 값이 반환되도록 정의한다.
	- 두 번째 인자의 우선순위가 높다면, 0보다 작은 값이 반환되도록 정의한다.
	- 첫 번째, 두 번째 인자의 우선순위가 동일하다면, 0이 반환되도록 정의한다.


	위 내용을 근거로, 데이터간 우선순위의 비교에 사용될 함수를 정의해서 힙에 등록해야 한다.
*/

/*

#include "UsefulHeap.h"
#include <stdio.h>

int DataPriorityComp(char ch1, char ch2) {			// 우선순위 비교함수
	return ch2 - ch1;								// 아스키 코드 값이 작은 문자의 우선순위가 더 높음
//	return ch1 - ch2;								
}

int main(void) {
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c\n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c\n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c\n", HDelete(&heap));
	printf("\n");

	return 0;
}

*/