
// 이진 탐색 알고리즘을 재귀함수로 재구현


#include <stdio.h>

int BSearch(int arr[], int first, int last, int target) {
	int mid;
	
	if (first > last)
		return -1;

	mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return BSearch(arr, first, mid - 1, target);
	else
		return BSearch(arr, mid + 1, last, target);
}


int main(void) {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		puts("탐색 실패!");
	else
		printf("타겟 저장 인덱스: %d\n", idx);
	
	idx = BSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		puts("탐색 실패!");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	return 0;
}

