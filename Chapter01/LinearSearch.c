
// ���� Ž�� �˰���

/* ----------------------------------------------------------------------------------------

#include <stdio.h>

int LSearch(int arr[], int len, int target) {			// ���� Ž�� �˰��� ����� �Լ�
	int i;
	for (i = 0; i < len; i++) {
		if (arr[i] == target)							// �߽��� �Ǵ� == ������
			return i;			// ã�� ����� �ε��� �� ��ȯ
	}
	return -1;					// ã�� �������� �ǹ��ϴ� �� ��ȯ
}


int main(void) {
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		puts("Ž�� ����!");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);	
	
	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		puts("Ž�� ����!");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);	

	return 0;

}


---------------------------------------------------------------------------------------- */


