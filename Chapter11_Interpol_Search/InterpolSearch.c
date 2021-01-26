
// ���� Ž��

#include <stdio.h>

int ISearch(int arr[], int first, int last, int target) {
	int mid;

//	if (first > last)
	if (target < arr[first] || arr[last] < target)
		return -1;

// ���� Ž�������� �߰��� ã��
//	mid = (first + last) / 2;

	// ���� Ž������ �������� �ݿ��� ���� (���⼭�� mid�� �߰����� �ǹ��ϴ� ���� �ƴ�)
	mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return ISearch(arr, first, mid - 1, target);
	else
		return ISearch(arr, mid + 1, last, target);
}


int main(void) {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		puts("Ž�� ����!");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		puts("Ž�� ����!");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	return 0;
}

