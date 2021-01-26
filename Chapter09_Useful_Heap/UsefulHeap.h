#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

// typedef char HData;
// typedef char* HData;		// ���� 09-1
typedef int HData;			// 10-2: �� ����

typedef int (*PriorityComp)(HData d1, HData d2);			
// typedef int PriorityComp(HData d1, HData d2);			

typedef struct _heap {
	PriorityComp comp;					// �̴� �Լ� ������ �����̴�.
//	PriorityComp * comp;				// �� ���� �����͸� ������� �켱������ ���� ������ �Ǵ��ϴ� �Լ��� ����ϱ� ���� ������ �����̴�.
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);		// �켱���� ������ ���� �������� �ʱ� ������ �Լ�ȣ�� ���� ����
HData HDelete(Heap* ph);

#endif // !__SIMPLE_HEAP_H__

