
#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc) {			// 매개변수 선언으로 함수 포인터 변수 사용 시 * 표시를 쓰지 않음
	ph->numOfData = 0;
	ph->comp = pc;									// 우선순위 비교에 사용되는 함수의 등록
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) {
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;		

	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else {
//		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)		// comp에 등록된 함수의 호출결과를 통해 우선순위 판단
			return GetRChildIDX(idx);
		else							
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data) {		// HInsert 함수를 호출하면서 우선순위 정보를 직접 전달하지 않기 때문에 함수호출 원형 변경
	int idx = ++(ph->numOfData);	

	while (idx != 1) {	
//		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {	
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;	
	}

	ph->heapArr[idx] = data;
}

HData HDelete(Heap* ph) {
	HData rdata = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];	

	int parentIdx = 1;	
	int childIdx;		

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {	
//		if (lastElem.pr <= ph->heapArr[childIdx].pr)
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];	
		parentIdx = childIdx;	
	}	

	ph->heapArr[parentIdx] = lastElem;	
	(ph->numOfData)--;
	return rdata;
}


