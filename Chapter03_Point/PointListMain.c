
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "ArrayList.h"

int main(void) {
	List list;
	Point* ppos;
	Point compPos;			// 데이터 비교를 위한 구조체를 마련함(초기화는 비교하기 직전 수행).

	ListInit(&list);

	// 4개의 데이터 저장
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// 저장된 데이터의 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1) {
			LRemove(&list);
			free(ppos);									// 동적할당된 메모리까지 삭제되지 않으므로 '직접' free 함수의 호출을 통해 삭제를 해줘야 한다.
		}
		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				LRemove(&list);
				free(ppos);
			}
		}
	}

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;

}

