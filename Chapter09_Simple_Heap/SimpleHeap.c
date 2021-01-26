
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

// Helper 함수 1
// 부모 노드의 인덱스 값 반환
int GetParentIDX(int idx) {
	return idx / 2;
}
// Helper 함수 2
// 왼쪽 자식 노드의 인덱스 값 반환
int GetLChildIDX(int idx) {
	return idx * 2;
}

// Helper 함수 3
// 오른쪽 자식 노드의 인덱스 값 반환
int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}

// Helper 함수 4
// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
// 완전 이진 트리를 기반으로 작성된 함수
int GetHiPriChildIDX(Heap* ph, int idx) {

	// 1. 자식 노드가 없을 때(단말 노드)
	if (GetLChildIDX(idx) > ph->numOfData)							// numOfData는 마지막 노드의 고유번호이므로
		return 0;													// 자식 노드의 인덱스 값이 이보다 크면
																	// 이 노드의 자식 노드는 공집합 노드이다.
	// 2. 자식 노드가 하나 있을 때(왼쪽 자식 노드)
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	// 3. 자식 노드가 두 개 있을 때
	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)		// 3-1. 오른쪽 자식 노드의 우선순위가 더 높을 때
			return GetRChildIDX(idx);
		else																			// 3-2. 왼쪽 자식 노드의 우선순위가 더 높을 때
			return GetLChildIDX(idx);
	}
}

// 힙에 데이터 저장
void HInsert(Heap* ph, HData data, Priority pr) {					// "새로운 데이터는 우선순위가 제일 낮다는 가정하에서 '마지막 위치'에 저장한다.
	int idx = ++(ph->numOfData);									//  그리고는 우선순위의 비교를 통해서 자신의 위치를 찾을 때까지 위로 올린다."
	HeapElem nelem = { pr, data };
	
	while (idx != 1) {												// 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복

		// 새 노드와 부모 노드의 우선순위 비교
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {				// 새 노드의 우선순위가 더 높다면
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];		// 부모 노드를 한 레벨 down [실제로] (복사라고 생각하면 됨)
			idx = GetParentIDX(idx);								// 새 노드를 한 레벨 up [인덱스 값만]
		}
		else
			break;													// 새 노드의 인덱스 값만 유지한 채 자리 배치가 완료될 때까지 코드 구현!
	}

	ph->heapArr[idx] = nelem;
}

// 힙에서 데이터 삭제
HData HDelete(Heap* ph) {
	HData rdata = (ph->heapArr[1]).data;							// 반환을 위해서 삭제할 (루트 노드의) 데이터 저장
	HeapElem lastElem = ph->heapArr[ph->numOfData];					// 힙의 마지막 노드 저장

	// 아래의 변수 parentIdx에는 마지막 노드가 저장될 위치정보가 담긴다.
	int parentIdx = 1;												// 루트 노드가 위치해야 할 인덱스 값 저장
	int childIdx;													//  -> 마지막 노드를 루트 노드로 옮긴 상황으로 간주할 수 있음.

	// 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {			// childIdx에 우선순위 높은 자식 노드의 인덱스 값 저장
		if (lastElem.pr <= ph->heapArr[childIdx].pr)				// 마지막 노드의 우선순위가 높으면 반복문 탈출!
			break;
		
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];				// 마지막 노드보다 우선순위가 높으니, 비교대상 노드의 위치를 한 레벨 up [실제로]
		parentIdx = childIdx;										// 마지막 노드가 저장될 위치정보를 한 레벨 down [인덱스 값만]
	}																// 반복문을 탈출하면 parentIdx에는 마지막 노드의 위치정보가 저장됨

	ph->heapArr[parentIdx] = lastElem;								// 마지막 노드 최종 저장
	(ph->numOfData)--;
	return rdata;
}		

/*
	"함수 HDelete에서는 마지막 노드가 있어야 할 위치를 parentIdx에 저장된 인덱스 값을 갱신하면서 찾아가고 있다."

	"루트 노드로 올려진 마지막 노드는 자신의 위치를 찾을 때까지 아래로 이동하면서 자신의 위치를 찾아간다.
	 하지만 이러한 빈번한 이동을 코드에 그대로 담을 필요는 없다.
	 최종 목적지가 결정되면 단번에 그리로 옮기면 된다."
*/