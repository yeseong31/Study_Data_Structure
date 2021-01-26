
#include <stdio.h>
#include "ArrayList.h"

int main(void) {
	// ArrayList�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// 5���� ������ ����
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� �������� ��ü ���
	printf("���� �������� ��: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {							// LFirst �Լ��� ȣ���� �䱸�ϴ� ������
		printf("%d ", data);							// ����Ʈ ������ '�������� ������ġ'�� ����ϱ� �����̴�.
														// ���� ó������ ������ ���Ӱ� �����ϱ� ���ؼ��� �ٷ� �� ������ �ʱ�ȭ�ؾ� �Ѵ�.
		while (LNext(&list, &data))						// �̸� �������� LFirst �Լ��� ȣ���� �䱸�ϴ� ���̴�.
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� Ž���Ͽ� ��� ����
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data == 22)
				LRemove(&list);
	}
	printf("\n\n");

	// ���� �� ���� ������ ��ü ���
	printf("���� �������� ��: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}
