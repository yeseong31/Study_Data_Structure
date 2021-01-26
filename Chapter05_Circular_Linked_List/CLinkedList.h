#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE		1
#define FALSE		0

/*
#include "../문제_05-1/employee.h"
typedef Employee* Data;
*/

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
} Node;

typedef struct _CLL {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);			// 꼬리에 노드를 추가
void LInsertFront(List* plist, Data data);		// 머리에 노드를 추가

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);			// 계속해서 호출이 가능하고, 리스트를 순환하면서 저장된 값을 반환하도록 구현한다.
Data LRemove(List* plist);
int LCount(List* plist);


#endif // !__C_LINKED_LIST_H__
