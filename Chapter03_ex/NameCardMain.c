
// 문제 03-2 [리스트의 활용]

#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "../c3_배열_리스트_ArrayList/ArrayList.h"

int main(void) {
	List list;
	ListInit(&list);
	NameCard* pcard;

	// 1. 총 3명의 전화번호 정보를, 앞서 우리가 구현한 리스트에 저장한다.
	pcard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("조수진", "010-3333-7777");
	LInsert(&list, pcard);

	// 2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
	// 한지영
	printf("한지영 님의 정보를 출력합니다.\n");
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "한지영"))
			ShowNameCardInfo(pcard);
		else {
			while (LNext(&list, &pcard)) 
				if (!NameCompare(pcard, "한지영")) {
					ShowNameCardInfo(pcard);
					break;
				}
		}
	}

	// 3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다.
	// 이진수
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "이진수"))
			ChangePhoneNum(pcard, "010-9999-9999");
		else {
			while (LNext(&list, &pcard))
				if (!NameCompare(pcard, "이진수")) {
					ChangePhoneNum(pcard, "010-9999-9999");					break;
				}
		}
	}

	// 4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.
	// 조수진
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "조수진")) {
			pcard = LRemove(&list);
			free(pcard);
		}

		else {
			while (LNext(&list, &pcard))
				if (!NameCompare(pcard, "조수진")) {
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
		}
	}

	// 5. 끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}