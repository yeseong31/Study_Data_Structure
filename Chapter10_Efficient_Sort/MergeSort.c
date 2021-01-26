
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));		// 병합 결과를 담을 메모리 공간 할당
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {			// 병합할 두 영역의 데이터를 비교해 배열 sortArr에 담는다.
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx++] = arr[fIdx++];
		else
			sortArr[sIdx++] = arr[rIdx++];
	}

	if (fIdx > mid)									// 배열의 앞부분이 모두 sortArr에 옮겨졌다면,
		for (i = rIdx; i <= right; i++, sIdx++)		// 배열의 뒷부분에 남은 데이터들을 sortArr에 그대로 옮긴다.
			sortArr[sIdx] = arr[i];

	else											// 배열의 뒷부분이 모두 sortArr에 옮겨졌다면,
		for (i = fIdx; i <= mid; i++, sIdx++)		// 배열의 앞부분에 남은 데이터들을 sortArr에 그대로 옮긴다.
			sortArr[sIdx] = arr[i];

	for (i = left; i <= right; i++)					// 동적 할당된 배열의 데이터를 배열 arr에 옮겨 담는다.
		arr[i] = sortArr[i];

	free(sortArr);
}


void MergeSort(int arr[], int left, int right) {		// left, right:	정렬대상의 범위정보
	int mid;

	if (left < right) {						// 데이터가 1개 남았을 경우 left == right가 되므로 함수호출 종료(반환)
		mid = (left + right) / 2;			// MergeSort 함수는 둘로 나눌 수 없을 대까지 재귀적으로 호출됨

		// 둘로 나누어서 각각을 정렬한다.
		MergeSort(arr, left, mid);			// left ~ mid에 위치한 데이터 정렬
		MergeSort(arr, mid + 1, right);		// mid+1 ~ right에 위치한 데이터 정렬 

		// 정렬된 두 배열을 '병합'한다.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void) {
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// 배열 arr의 전체 영역 정렬
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}


