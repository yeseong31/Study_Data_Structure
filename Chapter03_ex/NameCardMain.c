
// ���� 03-2 [����Ʈ�� Ȱ��]

#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "../c3_�迭_����Ʈ_ArrayList/ArrayList.h"

int main(void) {
	List list;
	ListInit(&list);
	NameCard* pcard;

	// 1. �� 3���� ��ȭ��ȣ ������, �ռ� �츮�� ������ ����Ʈ�� �����Ѵ�.
	pcard = MakeNameCard("������", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("������", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("������", "010-3333-7777");
	LInsert(&list, pcard);

	// 2. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����Ѵ�.
	// ������
	printf("������ ���� ������ ����մϴ�.\n");
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������"))
			ShowNameCardInfo(pcard);
		else {
			while (LNext(&list, &pcard)) 
				if (!NameCompare(pcard, "������")) {
					ShowNameCardInfo(pcard);
					break;
				}
		}
	}

	// 3. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ��ȭ��ȣ ������ �����Ѵ�.
	// ������
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������"))
			ChangePhoneNum(pcard, "010-9999-9999");
		else {
			while (LNext(&list, &pcard))
				if (!NameCompare(pcard, "������")) {
					ChangePhoneNum(pcard, "010-9999-9999");					break;
				}
		}
	}

	// 4. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ �����Ѵ�.
	// ������
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������")) {
			pcard = LRemove(&list);
			free(pcard);
		}

		else {
			while (LNext(&list, &pcard))
				if (!NameCompare(pcard, "������")) {
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
		}
	}

	// 5. ������ �����ִ� ��� ����� ��ȭ��ȣ ������ ����Ѵ�.
	printf("���� �������� ��: %d\n", LCount(&list));

	if (LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}