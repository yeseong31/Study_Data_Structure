
/*
	- PriotityComp�� typedef ������ ������ ����.

		typedef int (*PriorityComp)(HData d1, HData d2);

	- ù ��° ������ �켱������ ���ٸ�, 0���� ū ���� ��ȯ�ǵ��� �����Ѵ�.
	- �� ��° ������ �켱������ ���ٸ�, 0���� ���� ���� ��ȯ�ǵ��� �����Ѵ�.
	- ù ��°, �� ��° ������ �켱������ �����ϴٸ�, 0�� ��ȯ�ǵ��� �����Ѵ�.


	�� ������ �ٰŷ�, �����Ͱ� �켱������ �񱳿� ���� �Լ��� �����ؼ� ���� ����ؾ� �Ѵ�.
*/

/*

#include "UsefulHeap.h"
#include <stdio.h>

int DataPriorityComp(char ch1, char ch2) {			// �켱���� ���Լ�
	return ch2 - ch1;								// �ƽ�Ű �ڵ� ���� ���� ������ �켱������ �� ����
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