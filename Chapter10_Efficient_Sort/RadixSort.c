
#include <stdio.h>
#include "../../Chapter07_큐/c7_연결_리스트_기반_큐/ListBaseQueue.h"		// 버킷은 그 구조가 큐에 해당함

#define BUCKET_NUM		10			// 10진수 정수의 정렬을 위해 버킷의 수를 10개로 지정

void RadixSort(int arr[], int num, int maxLen) {
	// 매개변수 maxLen에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달됨

	Queue buckets[BUCKET_NUM];
	int bi;					// 버킷 번호
	int pos;				// 반복문: maxlen까지 반복
	int di;					// 반복문: 데이터의 개수만큼 반복
	int divfac = 1;			// 자릿수 검사를 위한 변수
	int radix;				// N번째 자리의 숫자 추출을 위한 변수

	
	for (bi = 0; bi < BUCKET_NUM; bi++)				// 총 10개의 버킷 초기화
		QueueInit(&buckets[bi]);

	for (pos = 0; pos < maxLen; pos++) {			// 가장 긴 데이터의 길이만큼 반복

		for (di = 0; di < num; di++) {				// 정렬대상의 수만큼 반복		
			radix = (arr[di] / divfac) % 10;		// N번째 자리의 숫자 추출		// NUM으로부터 n번째 자리 숫자 추출		NUM / n(피제수) % 10
																				
			Enqueue(&buckets[radix], arr[di]);		// 추출한 숫자를 근거로 버킷에 데이터 저장
		}

		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {	// 버킷 수만큼 반복
			while (!QIsEmpty(&buckets[bi]))				// 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
				arr[di++] = Dequeue(&buckets[bi]);
		}

		divfac *= 10;								// N번째 자리의 숫자 추출을 위한 피제수의 증가
	}
}

int main(void) {
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}


