
#include "employee.h"
#include "../c5_원형_연결_리스트/CLinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Employee* WhoIsNightDuty(List * plist, char * name, int day) {
	Employee* ret;
	int i = 0;

	LFirst(plist, &ret);
	if (strcmp(ret->name, name) != 0) {
		for (i = 0; i < LCount(plist) - 1; i++) {
			LNext(plist, &ret);

			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i >= LCount(plist) - 1)
			return NULL;
	}
		
	for (int i = 0; i < day; i++)
		LNext(plist, &ret);
	return ret;
}

void ShowEmp(Employee * emp) {
	printf("사번: %d\n", emp->empNum);
	printf("이름: %s\n", emp->name);
}

int main(void) {
	List list;
	ListInit(&list);
	Employee* pemp;

	// 4명의 정보를 입력
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1111;
	strcpy_s(pemp->name, NAME_LEN, "Terry");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2222;
	strcpy_s(pemp->name, NAME_LEN, "Joker");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3333;
	strcpy_s(pemp->name, NAME_LEN, "Byleth");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4444;
	strcpy_s(pemp->name, NAME_LEN, "Banjo");
	LInsert(&list, pemp);

	// Terry 뒤로 3일 뒤의 당직자는?
	pemp = WhoIsNightDuty(&list, "Terry", 3);
	ShowEmp(pemp);

	// Byleth 뒤로 15일 뒤의 당직자는?
	pemp = WhoIsNightDuty(&list, "Byleth", 3);
	ShowEmp(pemp);

	// 할당된 메모리의 전체 소멸
	if (LFirst(&list, &pemp)) {
		free(pemp);

		for (int i = 0; i < LCount(&list) - 1; i++)
			if (LNext(&list, &pemp))
				free(pemp);
	}

	return 0;
}



