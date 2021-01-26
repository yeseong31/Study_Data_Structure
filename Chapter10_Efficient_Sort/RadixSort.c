
#include <stdio.h>
#include "../../Chapter07_ť/c7_����_����Ʈ_���_ť/ListBaseQueue.h"		// ��Ŷ�� �� ������ ť�� �ش���

#define BUCKET_NUM		10			// 10���� ������ ������ ���� ��Ŷ�� ���� 10���� ����

void RadixSort(int arr[], int num, int maxLen) {
	// �Ű����� maxLen���� ���Ĵ�� �� ���� �� �������� ���� ������ ���޵�

	Queue buckets[BUCKET_NUM];
	int bi;					// ��Ŷ ��ȣ
	int pos;				// �ݺ���: maxlen���� �ݺ�
	int di;					// �ݺ���: �������� ������ŭ �ݺ�
	int divfac = 1;			// �ڸ��� �˻縦 ���� ����
	int radix;				// N��° �ڸ��� ���� ������ ���� ����

	
	for (bi = 0; bi < BUCKET_NUM; bi++)				// �� 10���� ��Ŷ �ʱ�ȭ
		QueueInit(&buckets[bi]);

	for (pos = 0; pos < maxLen; pos++) {			// ���� �� �������� ���̸�ŭ �ݺ�

		for (di = 0; di < num; di++) {				// ���Ĵ���� ����ŭ �ݺ�		
			radix = (arr[di] / divfac) % 10;		// N��° �ڸ��� ���� ����		// NUM���κ��� n��° �ڸ� ���� ����		NUM / n(������) % 10
																				
			Enqueue(&buckets[radix], arr[di]);		// ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����
		}

		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {	// ��Ŷ ����ŭ �ݺ�
			while (!QIsEmpty(&buckets[bi]))				// ��Ŷ�� ����� �� ������� �� ������ �ٽ� arr�� ����
				arr[di++] = Dequeue(&buckets[bi]);
		}

		divfac *= 10;								// N��° �ڸ��� ���� ������ ���� �������� ����
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


