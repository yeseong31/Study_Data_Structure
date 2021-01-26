
// O(log n)�� ���� Ž�� �˰����� ������� �񱳿����� Ƚ���� Ȯ��

/* -----------------------------------------------------------------------------

#include <stdio.h>

int BSearch(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid])
			return mid;
		else if (target < arr[mid])
			last = mid - 1;
		else
			first = mid + 1;
		opCount++;								// �񱳿����� Ƚ�� 1 ����
	}	
	printf("�񱳿���Ƚ��: %d\n", opCount);		// Ž������ �� ����Ƚ�� ���
	return -1;
}

int main(void) {
	int arr1[500] = { 0, };				// ��� ��Ҹ� 1���� �ʱ�ȭ
	int arr2[5000] = { 0, };				// ��� ��Ҹ� 1���� �ʱ�ȭ
	int arr3[50000] = { 0, };				// ��� ��Ҹ� 1���� �ʱ�ȭ
	int idx;

	// �迭 arr1�� �������, ������� ���� ���� 1�� ã����� ���
	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
		puts("Ž�� ����!");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	printf("\n");
	
	// �迭 arr2�� �������, ������� ���� ���� 2�� ã����� ���
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 2);
	if (idx == -1)
		puts("Ž�� ����!");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	printf("\n");
	
	// �迭 arr3�� �������, ������� ���� ���� 3�� ã����� ���
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);
	if (idx == -1)
		puts("Ž�� ����!");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	printf("\n");

	return 0;
}

---------------------------------------------------------------------------- */

// ���� �������� �ٰŷ�
// ���� Ž�� �˰��򺸴� ���� Ž�� �˰�����,
// �׸��� O(n) �˰��򺸴� O(log n)�� �˰����� ������ ������ ����.
