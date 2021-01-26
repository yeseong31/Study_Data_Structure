
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// 중간 값을 갖는 요소의 인덱스 값 반환
int MedianOfThree(int arr[], int left, int right) {
	int samples[3] = { left, (left + right) / 2, right };	// 인덱스 값으로 배열을 구성
	
	// 버블 정렬
	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);
	if (arr[samples[1]] > arr[samples[2]])
		Swap(samples, 1, 2);
	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	return samples[1];			// 중간 값 반환
}


// QuickSort 함수의 Helper 함수
int Partition(int arr[], int left, int right) {
	int pIdx = MedianOfThree(arr, left, right);
	int pivot = arr[pIdx];
//	int pivot = arr[left];		// pivot의 위치는 가장 왼쪽!

	int low = left + 1;
	int high = right;

	Swap(arr, left, pIdx);		// pivot을 가장 왼쪽으로 이동
	printf("pivot: %d\n", pivot);		// pivot의 확인을 위한 문장

	while (low <= high) {									// 교차되지 않을 때까지 반복

//		while (pivot > arr[low])							//		** 중요 **
//			low++;											//		배열이 int arr[3] = { 3, 3, 3 }; 으로 선언이 된다면
//															//		'pivot == arr[low] == arr[right]' 이 항상 성립되므로
//		while (pivot < arr[high])							//		외부 while문의 조건이 항상 '거짓'이 되어 내부 while문이 실행이 되지 못해 무한루프 문제 발생.
//			high--;											//		때문에 이 부분은 아래와 같이 변경되어야 함.

		while (pivot >= arr[low] && low <= right)			// pivot보다 큰 값을 찾는 과정	// 우선 >, < 연산자를 각각 >=, <= 연산자로 바꾸어 
			low++;											// low를 오른쪽으로 이동			// 3이 3개 저장된 상황에서도 low와 high가 각각 증감의 기회를 얻음.
		while (pivot <= arr[high] && high >= (left + 1))	// pivot보다 작은 값을 찾는 과정	// 또한 경계검사를 위한 연산을 && 연산자 뒤에 추가하여
			high--;											// high를 왼쪽으로 이동			// low와 high가 배열의 정렬 범위를 넘어서지 않게 함.

		if (low <= high)									// 교차되지 않은 상태라면 swap
			Swap(arr, low, high);
	}

	Swap(arr, left, high);									// pivot과 high가 가리키는 대상 교환
	return high;											// 옮겨진 피벗의 위치정보 반환
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {									// left와 right가 점점 가까워지므로
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);					// 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);					// 오른쪽 영역을 정렬
	}
}

int main(void) {
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
//	int arr[3] = { 3, 3, 3 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}