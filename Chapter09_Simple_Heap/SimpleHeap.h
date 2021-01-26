#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

typedef char HData;
typedef int Priority;

typedef struct _heapElem {
	Priority pr;				// 값이 작을수록 높은 우선순위 (우선순위 정보를 별도로 정의하여 우선순위 큐의 구현을 고려했음을 보여줌)
	HData data;
} HeapElem;
	
typedef struct _heap {			// 힙의 구현(우선순위 큐)을 위한 헤더파일
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);

#endif // !__SIMPLE_HEAP_H__

// 사실 위의 헤더파일은 순수한 힙의 구현을 위한 헤더파일이 아닌,
// 우선순위 큐의 구현을 염두에 두고 정의한 헤더파일이다.

/*

	- 힙은 완전 이진 트리이다.
	- 힙의 구현은 배열을 기반으로 하며 인덱스가 0인 요소는 비워둔다.
	- 따라서 힙에 저장된 노드의 개수와 마지막 노드의 고유번호는 일치한다.
	- 노드의 고유번호가 노드가 저장되는 배열의 인덱스 값이 된다.
	- 우선순위를 나타내는 정수 값이 작을수록 높은 우선순위를 나타낸다고 가정한다.


*/
