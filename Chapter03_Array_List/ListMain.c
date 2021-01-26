
#include <stdio.h>
#include "ArrayList.h"

int main(void) {
	// ArrayList의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 5개의 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {							// LFirst 함수의 호출을 요구하는 이유는
		printf("%d ", data);							// 리스트 내에서 '데이터의 참조위치'를 기록하기 때문이다.
														// 따라서 처음부터 참조를 새롭게 시작하기 위해서는 바로 이 정보를 초기화해야 한다.
		while (LNext(&list, &data))						// 이를 목적으로 LFirst 함수의 호출을 요구하는 것이다.
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22를 탐색하여 모두 삭제
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data == 22)
				LRemove(&list);
	}
	printf("\n\n");

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}
