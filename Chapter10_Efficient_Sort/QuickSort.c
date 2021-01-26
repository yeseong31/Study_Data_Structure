
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// �߰� ���� ���� ����� �ε��� �� ��ȯ
int MedianOfThree(int arr[], int left, int right) {
	int samples[3] = { left, (left + right) / 2, right };	// �ε��� ������ �迭�� ����
	
	// ���� ����
	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);
	if (arr[samples[1]] > arr[samples[2]])
		Swap(samples, 1, 2);
	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	return samples[1];			// �߰� �� ��ȯ
}


// QuickSort �Լ��� Helper �Լ�
int Partition(int arr[], int left, int right) {
	int pIdx = MedianOfThree(arr, left, right);
	int pivot = arr[pIdx];
//	int pivot = arr[left];		// pivot�� ��ġ�� ���� ����!

	int low = left + 1;
	int high = right;

	Swap(arr, left, pIdx);		// pivot�� ���� �������� �̵�
	printf("pivot: %d\n", pivot);		// pivot�� Ȯ���� ���� ����

	while (low <= high) {									// �������� ���� ������ �ݺ�

//		while (pivot > arr[low])							//		** �߿� **
//			low++;											//		�迭�� int arr[3] = { 3, 3, 3 }; ���� ������ �ȴٸ�
//															//		'pivot == arr[low] == arr[right]' �� �׻� �����ǹǷ�
//		while (pivot < arr[high])							//		�ܺ� while���� ������ �׻� '����'�� �Ǿ� ���� while���� ������ ���� ���� ���ѷ��� ���� �߻�.
//			high--;											//		������ �� �κ��� �Ʒ��� ���� ����Ǿ�� ��.

		while (pivot >= arr[low] && low <= right)			// pivot���� ū ���� ã�� ����	// �켱 >, < �����ڸ� ���� >=, <= �����ڷ� �ٲپ� 
			low++;											// low�� ���������� �̵�			// 3�� 3�� ����� ��Ȳ������ low�� high�� ���� ������ ��ȸ�� ����.
		while (pivot <= arr[high] && high >= (left + 1))	// pivot���� ���� ���� ã�� ����	// ���� ���˻縦 ���� ������ && ������ �ڿ� �߰��Ͽ�
			high--;											// high�� �������� �̵�			// low�� high�� �迭�� ���� ������ �Ѿ�� �ʰ� ��.

		if (low <= high)									// �������� ���� ���¶�� swap
			Swap(arr, low, high);
	}

	Swap(arr, left, high);									// pivot�� high�� ����Ű�� ��� ��ȯ
	return high;											// �Ű��� �ǹ��� ��ġ���� ��ȯ
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {									// left�� right�� ���� ��������Ƿ�
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);					// ���� ������ ����
		QuickSort(arr, pivot + 1, right);					// ������ ������ ����
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