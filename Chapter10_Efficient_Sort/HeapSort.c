
#include <stdio.h>
#include "../../Chapter09_�켱����_ť��_��/c9_����_����_UsefulHeap/UsefulHeap.h"

int PriComp(int n1, int n2) {		// �켱���� ���� �Լ�
	return n2 - n1;			// �������� ����
//	return n1 - n2;			// �������� ����
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	HeapInit(&heap, pc);
	int i;

	// ���Ĵ���� ������ ���� �����Ѵ�.
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	// ������� �ϳ��� ������ ������ �ϼ��Ѵ�. ('�켱���� ť'�� ���������Ƿ� ������ ���� ���ĵ�)
	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}


int main(void) {
	int arr[4] = { 3, 4, 2, 1 };
	int i;
	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
