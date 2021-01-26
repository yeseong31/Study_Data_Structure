#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

typedef char HData;
typedef int Priority;

typedef struct _heapElem {
	Priority pr;				// ���� �������� ���� �켱���� (�켱���� ������ ������ �����Ͽ� �켱���� ť�� ������ ��������� ������)
	HData data;
} HeapElem;
	
typedef struct _heap {			// ���� ����(�켱���� ť)�� ���� �������
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);

#endif // !__SIMPLE_HEAP_H__

// ��� ���� ��������� ������ ���� ������ ���� ��������� �ƴ�,
// �켱���� ť�� ������ ���ο� �ΰ� ������ ��������̴�.

/*

	- ���� ���� ���� Ʈ���̴�.
	- ���� ������ �迭�� ������� �ϸ� �ε����� 0�� ��Ҵ� ����д�.
	- ���� ���� ����� ����� ������ ������ ����� ������ȣ�� ��ġ�Ѵ�.
	- ����� ������ȣ�� ��尡 ����Ǵ� �迭�� �ε��� ���� �ȴ�.
	- �켱������ ��Ÿ���� ���� ���� �������� ���� �켱������ ��Ÿ���ٰ� �����Ѵ�.


*/
