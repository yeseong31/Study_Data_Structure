
#include <stdio.h>

void BubbleSort(int arr[], int n) {
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < (n - i) - 1; j++) {
			if (arr[j] > arr[j + 1]) {			// 오름차순
				// swap
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*

	[버블 정렬(Bubble Sort)]

	버블 정렬은 인접한 두 개의 데이터를 비료해가면서 정렬을 진행하는 방식이다.
	두 데이터를 비교하여 정렬순서상 위치가 바뀌어야 하는 경우에 두 데이터의 위치를 바꿔나간다.
	앞에서부터 순서대로 비교하고 교환하는 일련의 과정이 거품이 일어나는 모습에 비유되어 버블 정렬이라고 부른다.
	
	"정렬의 우선순위가 가장 낮은, 제일 큰 값을 맨 뒤로 보내기!"

		비교 데이터 개수			(오름차순)										비교횟수
			  4				4 2 3 1  ->  2 4 3 1  ->  2 3 4 1  ->  2 3 1 4			3		
		  	  3				2 3 1 4  ->  2 3 1 4  ->  2 1 3 4						2		
			  2				2 1 3 4  ->  1 2 3 4									1	
												swap!!
			|																		|
			V																		V

		for (int i = 0; i < n - 1; i++)				for (int j = 0; j < (n - 1) - i; j++)
																	-----------
																		^ 헷갈릴 수 있으니 주의

	정렬이 완료된, 배열의 끝에 위치한 데이터를 제외하고 나머지를 대상으로 비교와 교환을 진행한다.

	-----------------------------------------------------------------------------------------------------

	<성능평가>


				for(int i = 0; i < n-1; i++) {
					for (j = 0; j = (n-i)-1; j++) {

						if (arr[j] > arr[j + 1) { ... }			// 비교연산이 발생하는 장소

					}
				}

		
		버블 정렬에서 데이터의 수가 n개일 때 진행이 되는 비교의 횟수는 다음과 같다.

				(n-1) + (n-2) + ... + 3 + 2 + 1

				n-1
				 Σ  i   =   (n(n-1)) / 2   =   (n^2 - n) / 2
				i=1

		따라서 버블 정렬의 비교연산에 대한 빅-오는 최악의 경우와 최선의 경우 구분 없이 다음과 같다.

				O(n^2)

	-----------------------------------------------------------------------------------------------------

	결론: '버블 정렬'은 O(n^2)의 성능을 보이는 알고리즘이다.

*/
