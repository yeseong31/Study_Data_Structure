
#include "SimpleHeap.h"

void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

// Helper �Լ� 1
// �θ� ����� �ε��� �� ��ȯ
int GetParentIDX(int idx) {
	return idx / 2;
}
// Helper �Լ� 2
// ���� �ڽ� ����� �ε��� �� ��ȯ
int GetLChildIDX(int idx) {
	return idx * 2;
}

// Helper �Լ� 3
// ������ �ڽ� ����� �ε��� �� ��ȯ
int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}

// Helper �Լ� 4
// �� ���� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
// ���� ���� Ʈ���� ������� �ۼ��� �Լ�
int GetHiPriChildIDX(Heap* ph, int idx) {

	// 1. �ڽ� ��尡 ���� ��(�ܸ� ���)
	if (GetLChildIDX(idx) > ph->numOfData)							// numOfData�� ������ ����� ������ȣ�̹Ƿ�
		return 0;													// �ڽ� ����� �ε��� ���� �̺��� ũ��
																	// �� ����� �ڽ� ���� ������ ����̴�.
	// 2. �ڽ� ��尡 �ϳ� ���� ��(���� �ڽ� ���)
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	// 3. �ڽ� ��尡 �� �� ���� ��
	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)		// 3-1. ������ �ڽ� ����� �켱������ �� ���� ��
			return GetRChildIDX(idx);
		else																			// 3-2. ���� �ڽ� ����� �켱������ �� ���� ��
			return GetLChildIDX(idx);
	}
}

// ���� ������ ����
void HInsert(Heap* ph, HData data, Priority pr) {					// "���ο� �����ʹ� �켱������ ���� ���ٴ� �����Ͽ��� '������ ��ġ'�� �����Ѵ�.
	int idx = ++(ph->numOfData);									//  �׸���� �켱������ �񱳸� ���ؼ� �ڽ��� ��ġ�� ã�� ������ ���� �ø���."
	HeapElem nelem = { pr, data };
	
	while (idx != 1) {												// �� ��尡 ����� ��ġ�� ��Ʈ ����� ��ġ�� �ƴ϶�� while�� �ݺ�

		// �� ���� �θ� ����� �켱���� ��
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {				// �� ����� �켱������ �� ���ٸ�
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];		// �θ� ��带 �� ���� down [������] (������ �����ϸ� ��)
			idx = GetParentIDX(idx);								// �� ��带 �� ���� up [�ε��� ����]
		}
		else
			break;													// �� ����� �ε��� ���� ������ ä �ڸ� ��ġ�� �Ϸ�� ������ �ڵ� ����!
	}

	ph->heapArr[idx] = nelem;
}

// ������ ������ ����
HData HDelete(Heap* ph) {
	HData rdata = (ph->heapArr[1]).data;							// ��ȯ�� ���ؼ� ������ (��Ʈ �����) ������ ����
	HeapElem lastElem = ph->heapArr[ph->numOfData];					// ���� ������ ��� ����

	// �Ʒ��� ���� parentIdx���� ������ ��尡 ����� ��ġ������ ����.
	int parentIdx = 1;												// ��Ʈ ��尡 ��ġ�ؾ� �� �ε��� �� ����
	int childIdx;													//  -> ������ ��带 ��Ʈ ���� �ű� ��Ȳ���� ������ �� ����.

	// ��Ʈ ����� �켱������ ���� �ڽ� ��带 �������� �ݺ��� ����
	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {			// childIdx�� �켱���� ���� �ڽ� ����� �ε��� �� ����
		if (lastElem.pr <= ph->heapArr[childIdx].pr)				// ������ ����� �켱������ ������ �ݺ��� Ż��!
			break;
		
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];				// ������ ��庸�� �켱������ ������, �񱳴�� ����� ��ġ�� �� ���� up [������]
		parentIdx = childIdx;										// ������ ��尡 ����� ��ġ������ �� ���� down [�ε��� ����]
	}																// �ݺ����� Ż���ϸ� parentIdx���� ������ ����� ��ġ������ �����

	ph->heapArr[parentIdx] = lastElem;								// ������ ��� ���� ����
	(ph->numOfData)--;
	return rdata;
}		

/*
	"�Լ� HDelete������ ������ ��尡 �־�� �� ��ġ�� parentIdx�� ����� �ε��� ���� �����ϸ鼭 ã�ư��� �ִ�."

	"��Ʈ ���� �÷��� ������ ���� �ڽ��� ��ġ�� ã�� ������ �Ʒ��� �̵��ϸ鼭 �ڽ��� ��ġ�� ã�ư���.
	 ������ �̷��� ����� �̵��� �ڵ忡 �״�� ���� �ʿ�� ����.
	 ���� �������� �����Ǹ� �ܹ��� �׸��� �ű�� �ȴ�."
*/