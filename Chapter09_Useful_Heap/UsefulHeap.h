#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

// typedef char HData;
// typedef char* HData;		// 문제 09-1
typedef int HData;			// 10-2: 힙 정렬

typedef int (*PriorityComp)(HData d1, HData d2);			
// typedef int PriorityComp(HData d1, HData d2);			

typedef struct _heap {
	PriorityComp comp;					// 이는 함수 포인터 변수이다.
//	PriorityComp * comp;				// 두 개의 데이터를 대상으로 우선순위의 높고 낮음을 판단하는 함수를 등록하기 위한 포인터 변수이다.
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);		// 우선순위 정보를 직접 전달하지 않기 때문에 함수호출 원형 변경
HData HDelete(Heap* ph);

#endif // !__SIMPLE_HEAP_H__

