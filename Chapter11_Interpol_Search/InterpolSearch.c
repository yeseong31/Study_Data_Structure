
// 보간 탐색

#include <stdio.h>

int ISearch(int arr[], int first, int last, int target) {
	int mid;

//	if (first > last)
	if (target < arr[first] || arr[last] < target)
		return -1;

// 이진 탐색에서의 중간값 찾기
//	mid = (first + last) / 2;

	// 이진 탐색과의 차이점을 반영한 문장 (여기서의 mid는 중간값을 의미하는 것이 아님)
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
		puts("탐색 실패!");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		puts("탐색 실패!");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	return 0;
}

