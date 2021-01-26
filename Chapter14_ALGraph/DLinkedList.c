
#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));		// 더미 노드 생성
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;		// 새 노드가 나른 노드를 가리킴
	plist->head->next = newNode;					// 더미 노드가 새 노드를 가리킴

	(plist->numOfData)++;

	// 위의 함수를 이해하기 위해서는 현태 포인터 변수 head가 NULL이 아닌, 더미 노드를 가리키고 있다는 사실을 잊지 말아야 한다.
	// 그리고 위의 함수에는 if...else 구문이 없다는 사실에도 주목해야 한다.
	// 이는 모든 노드의 추가과정이 일관되게 정의되었음을 뜻하는 것이고
	// 이것이 바로 더미 노드가 주는 이점이기 때문이다.

}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;			// pred는 더미 노드를 가리킴
	newNode->data = data;

	// 새 노드가 들어갈 위치를 찾기 위한 반복문!

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)	// comp가 0을 반환한다는 것은 첫 번째 인자인 data가 정렬 순서상 앞서기 때문에			
		pred = pred->next;			// 다음 노드로 이동						// head에 더 가까워져야 한다는 의미이다.

	newNode->next = pred->next;		// 새 노드의 오른쪽을 연결				// pred->next != NULL	: pred가 리스트의 마지막 노드를 가리키는지 묻기 위한 연산
	pred->next = newNode;			// 새 노드의 왼족을 연결					// plist->comp(data, pred->next->data) != 0		: 새 데이터와 pred의 다음 노드에 저장된 데이터의
	(plist->numOfData)++;													//												  우선순위를 비교하기 위한 함수호출
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)		// 정렬 기준이 마련되지 않았다면
		FInsert(plist, data);		// 머리에 노드를 추가!
	else
		SInsert(plist, data);		// 그렇지 않다면 정렬 기준대로 노드 추가!
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;		// 노드의 삭제에 필요함.
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;		// 첫 번째 노드의 데이터를 전달
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;

	// 여기서 중요한 것은, cur은 삭제 후 위치 재조정이 필요하지만
	// before은 LFirst 또는 LNext 호출 시 재설정되므로 재조정의 과정이 불필요함
}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	// SetSortRule 함수는 리스트의 멤버 comp를 초기화하는 함수이므로 다음처럼 간단히 정리된다.
	plist->comp = comp;
}

