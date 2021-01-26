
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	// 데이터를 입력 받는 과정
	while (1) {
		printf("자연수 입력: "); scanf_s("%d", &readData);
		if (readData < 1)
			break;

		// 노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
/*
// LinkedRead.c
		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
*/
		// 문제 04-1
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}

	}
	printf("\n");

	// 입력 받은 데이터의 출력과정
	printf("입력 받은 데이터의 전체출력!\n");
	if (head == NULL)
		puts("저장된 자연수가 존재하지 않습니다.");
	else {
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 메모리의 해제과정
	if (head == NULL)
		return 0;
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다.\n", head->data);
		free(delNode);

		while (delNextNode != NULL) {				// 더미 노드에 대해 배우게 되면 이 과정을 좀 더 간략화시킬 수 있다.
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}

// 동적 할당된 메모리에 어떻게 순차적으로 접근하는가에 대해 생각해 보고 그림으로 이해해야 한다.