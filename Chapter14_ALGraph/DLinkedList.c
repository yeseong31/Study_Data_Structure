
#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));		// ���� ��� ����
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;		// �� ��尡 ���� ��带 ����Ŵ
	plist->head->next = newNode;					// ���� ��尡 �� ��带 ����Ŵ

	(plist->numOfData)++;

	// ���� �Լ��� �����ϱ� ���ؼ��� ���� ������ ���� head�� NULL�� �ƴ�, ���� ��带 ����Ű�� �ִٴ� ����� ���� ���ƾ� �Ѵ�.
	// �׸��� ���� �Լ����� if...else ������ ���ٴ� ��ǿ��� �ָ��ؾ� �Ѵ�.
	// �̴� ��� ����� �߰������� �ϰ��ǰ� ���ǵǾ����� ���ϴ� ���̰�
	// �̰��� �ٷ� ���� ��尡 �ִ� �����̱� �����̴�.

}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;			// pred�� ���� ��带 ����Ŵ
	newNode->data = data;

	// �� ��尡 �� ��ġ�� ã�� ���� �ݺ���!

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)	// comp�� 0�� ��ȯ�Ѵٴ� ���� ù ��° ������ data�� ���� ������ �ռ��� ������			
		pred = pred->next;			// ���� ���� �̵�						// head�� �� ��������� �Ѵٴ� �ǹ��̴�.

	newNode->next = pred->next;		// �� ����� �������� ����				// pred->next != NULL	: pred�� ����Ʈ�� ������ ��带 ����Ű���� ���� ���� ����
	pred->next = newNode;			// �� ����� ������ ����					// plist->comp(data, pred->next->data) != 0		: �� �����Ϳ� pred�� ���� ��忡 ����� ��������
	(plist->numOfData)++;													//												  �켱������ ���ϱ� ���� �Լ�ȣ��
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)		// ���� ������ ���õ��� �ʾҴٸ�
		FInsert(plist, data);		// �Ӹ��� ��带 �߰�!
	else
		SInsert(plist, data);		// �׷��� �ʴٸ� ���� ���ش�� ��� �߰�!
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;		// ����� ������ �ʿ���.
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;		// ù ��° ����� �����͸� ����
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

	// ���⼭ �߿��� ����, cur�� ���� �� ��ġ �������� �ʿ�������
	// before�� LFirst �Ǵ� LNext ȣ�� �� �缳���ǹǷ� �������� ������ ���ʿ���
}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	// SetSortRule �Լ��� ����Ʈ�� ��� comp�� �ʱ�ȭ�ϴ� �Լ��̹Ƿ� ����ó�� ������ �����ȴ�.
	plist->comp = comp;
}

