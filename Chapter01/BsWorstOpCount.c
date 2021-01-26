
// O(log n)인 이진 탐색 알고리즘을 대상으로 비교연산의 횟수를 확인

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
		opCount++;								// 비교연산의 횟수 1 증가
	}	
	printf("비교연산횟수: %d\n", opCount);		// 탐색실패 시 연산횟수 출력
	return -1;
}

int main(void) {
	int arr1[500] = { 0, };				// 모든 요소를 1으로 초기화
	int arr2[5000] = { 0, };				// 모든 요소를 1으로 초기화
	int arr3[50000] = { 0, };				// 모든 요소를 1으로 초기화
	int idx;

	// 배열 arr1을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
		puts("탐색 실패!");
	else
		printf("타겟 저장 인덱스: %d \n", idx);
	printf("\n");
	
	// 배열 arr2을 대상으로, 저장되지 않은 정수 2를 찾으라고 명령
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 2);
	if (idx == -1)
		puts("탐색 실패!");
	else
		printf("타겟 저장 인덱스: %d \n", idx);
	printf("\n");
	
	// 배열 arr3을 대상으로, 저장되지 않은 정수 3을 찾으라고 명령
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);
	if (idx == -1)
		puts("탐색 실패!");
	else
		printf("타겟 저장 인덱스: %d \n", idx);
	printf("\n");

	return 0;
}

---------------------------------------------------------------------------- */

// 위의 실행결과를 근거로
// 순차 탐색 알고리즘보다 이진 탐색 알고리즘이,
// 그리고 O(n) 알고리즘보다 O(log n)의 알고리즘이 월등히 성능이 좋다.
