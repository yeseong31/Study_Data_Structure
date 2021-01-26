
#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;		// d1이 정렬 순서상 앞선다.
	else
		return 1;		// d2가 정렬 순서상 앞서거나 같다.

		// 정렬의 기준인 WhoIsPrecede 함수는
		// 정렬의 기준을 프로그래머가 직접 부여하도록 했기 때문에
		// main 함수가 정의된 소스파일에 지목을 하였다.
}


int main(void) {
	// ArrayList의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);			// 정렬의 기준을 등록한다!

		// 함수가 정의되면 이를 연결 리스트의 정렬 기준으로 등록하기 위해
		// SetSortRule 함수를 호출하여 WhoIsPrecede 함수를 인자로 전달한다.

	// 5개의 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {	
		printf("%d ", data);
								
		while (LNext(&list, &data))
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

