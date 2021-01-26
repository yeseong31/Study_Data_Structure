
#include <stdio.h>
#include "BinarySearchTree.h"

int main(void) {
	BTreeNode* bstRoot;				// bstRoot는 BST의 루트 노드를 가리킨다.
	BTreeNode* sNode;

	// BinarySearchTree의 생성 및 초기화
	// 이때부터 bstRoot는 생성된 이진 탐색 트리를 지칭하는 이름이 된다.
	BSTMakeAndInit(&bstRoot);		

	BSTInsert(&bstRoot, 9);			// bstRoot에 9 저장
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	// 탐색! 1이 저장된 노드를 찾아서!
	sNode = BSTSearch(bstRoot, 1);

	if (sNode == NULL)
		printf("탐색 실패!\n");
	else
		printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));

	// 탐색! 4가 저장된 노드를 찾아서!
	sNode = BSTSearch(bstRoot, 4);
	

	if (sNode == NULL)
		printf("탐색 실패!\n");
	else
		printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));

	// 탐색! 6이 저장된 노드를 찾아서!
	sNode = BSTSearch(bstRoot, 6);

	if (sNode == NULL)
		printf("탐색 실패!\n");
	else
		printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));

	// 탐색! 7이 저장된 노드를 찾아서!
	sNode = BSTSearch(bstRoot, 7);

	if (sNode == NULL)
		printf("탐색 실패!\n");
	else
		printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));

	return 0;

}



