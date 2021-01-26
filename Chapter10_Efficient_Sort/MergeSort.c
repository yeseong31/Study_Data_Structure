
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));		// ���� ����� ���� �޸� ���� �Ҵ�
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {			// ������ �� ������ �����͸� ���� �迭 sortArr�� ��´�.
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx++] = arr[fIdx++];
		else
			sortArr[sIdx++] = arr[rIdx++];
	}

	if (fIdx > mid)									// �迭�� �պκ��� ��� sortArr�� �Ű����ٸ�,
		for (i = rIdx; i <= right; i++, sIdx++)		// �迭�� �޺κп� ���� �����͵��� sortArr�� �״�� �ű��.
			sortArr[sIdx] = arr[i];

	else											// �迭�� �޺κ��� ��� sortArr�� �Ű����ٸ�,
		for (i = fIdx; i <= mid; i++, sIdx++)		// �迭�� �պκп� ���� �����͵��� sortArr�� �״�� �ű��.
			sortArr[sIdx] = arr[i];

	for (i = left; i <= right; i++)					// ���� �Ҵ�� �迭�� �����͸� �迭 arr�� �Ű� ��´�.
		arr[i] = sortArr[i];

	free(sortArr);
}


void MergeSort(int arr[], int left, int right) {		// left, right:	���Ĵ���� ��������
	int mid;

	if (left < right) {						// �����Ͱ� 1�� ������ ��� left == right�� �ǹǷ� �Լ�ȣ�� ����(��ȯ)
		mid = (left + right) / 2;			// MergeSort �Լ��� �ѷ� ���� �� ���� ����� ��������� ȣ���

		// �ѷ� ����� ������ �����Ѵ�.
		MergeSort(arr, left, mid);			// left ~ mid�� ��ġ�� ������ ����
		MergeSort(arr, mid + 1, right);		// mid+1 ~ right�� ��ġ�� ������ ���� 

		// ���ĵ� �� �迭�� '����'�Ѵ�.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void) {
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// �迭 arr�� ��ü ���� ����
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}


