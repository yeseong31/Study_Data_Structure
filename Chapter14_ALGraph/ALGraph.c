#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph* pg, int nv) {
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);	// 간선 정보를 저장할 리스트 생성
	pg->numV = nv;		// 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;		// 초기의 간선의 수 0개

	// 정점의 수만큼 생성된 리스트들을 초기화한다.
	for (i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);	// 리스트의 정렬기준을 설정(알파벳 순으로의 출력 유도)
	}
}

// 그래프 리소스의 해제
void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);		// 동적으로 할당된 연결 리스트의 소멸
}

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV) {		// (무방향 그래프)
	LInsert(&(pg->adjList[fromV]), toV);	// 정점 fromB의 연결 리스트에 정점 toV의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);	// 정점 toV의 연결 리스트에 정점 fromV의 정보 추가
	pg->numE++;
}

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c와 연결된 정점: ", i + 65);

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

