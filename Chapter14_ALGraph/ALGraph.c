#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv) {
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);	// ���� ������ ������ ����Ʈ ����
	pg->numV = nv;		// ������ ���� nv�� ����� ������ ����
	pg->numE = 0;		// �ʱ��� ������ �� 0��

	// ������ ����ŭ ������ ����Ʈ���� �ʱ�ȭ�Ѵ�.
	for (i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);	// ����Ʈ�� ���ı����� ����(���ĺ� �������� ��� ����)
	}
}

// �׷��� ���ҽ��� ����
void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);		// �������� �Ҵ�� ���� ����Ʈ�� �Ҹ�
}

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV) {		// (������ �׷���)
	LInsert(&(pg->adjList[fromV]), toV);	// ���� fromB�� ���� ����Ʈ�� ���� toV�� ���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);	// ���� toV�� ���� ����Ʈ�� ���� fromV�� ���� �߰�
	pg->numE++;
}

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx)) {
			printf("%c ", vx+65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

