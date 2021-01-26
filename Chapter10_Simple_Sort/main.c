
#include <stdio.h>


int main(void) {
	int arr1[4] = { 3, 4, 2, 1 };
	int arr2[4] = { 3, 4, 2, 1 };
	int arr3[4] = { 3, 4, 2, 1 };
	int i;

	BubbleSort(arr1, sizeof(arr1) / sizeof(int));
	for (i = 0; i < 4; i++)
		printf("%d ", arr1[i]);
	printf("\n");

	SelectSort(arr2, sizeof(arr2) / sizeof(int));
	for (i = 0; i < 4; i++)
		printf("%d ", arr2[i]);
	printf("\n");

	InsertSort(arr3, sizeof(arr3) / sizeof(int));
	for (i = 0; i < 4; i++)
		printf("%d ", arr3[i]);
	printf("\n");

	return 0;
}


