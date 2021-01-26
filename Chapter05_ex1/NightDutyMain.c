
#include "employee.h"
#include "../c5_����_����_����Ʈ/CLinkedList.h"
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
	printf("���: %d\n", emp->empNum);
	printf("�̸�: %s\n", emp->name);
}

int main(void) {
	List list;
	ListInit(&list);
	Employee* pemp;

	// 4���� ������ �Է�
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

	// Terry �ڷ� 3�� ���� �����ڴ�?
	pemp = WhoIsNightDuty(&list, "Terry", 3);
	ShowEmp(pemp);

	// Byleth �ڷ� 15�� ���� �����ڴ�?
	pemp = WhoIsNightDuty(&list, "Byleth", 3);
	ShowEmp(pemp);

	// �Ҵ�� �޸��� ��ü �Ҹ�
	if (LFirst(&list, &pemp)) {
		free(pemp);

		for (int i = 0; i < LCount(&list) - 1; i++)
			if (LNext(&list, &pemp))
				free(pemp);
	}

	return 0;
}



