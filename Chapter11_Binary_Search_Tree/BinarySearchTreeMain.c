
#include <stdio.h>
#include "BinarySearchTree.h"

int main(void) {
	BTreeNode* bstRoot;				// bstRoot�� BST�� ��Ʈ ��带 ����Ų��.
	BTreeNode* sNode;

	// BinarySearchTree�� ���� �� �ʱ�ȭ
	// �̶����� bstRoot�� ������ ���� Ž�� Ʈ���� ��Ī�ϴ� �̸��� �ȴ�.
	BSTMakeAndInit(&bstRoot);		

	BSTInsert(&bstRoot, 9);			// bstRoot�� 9 ����
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	// Ž��! 1�� ����� ��带 ã�Ƽ�!
	sNode = BSTSearch(bstRoot, 1);

	if (sNode == NULL)
		printf("Ž�� ����!\n");
	else
		printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));

	// Ž��! 4�� ����� ��带 ã�Ƽ�!
	sNode = BSTSearch(bstRoot, 4);
	

	if (sNode == NULL)
		printf("Ž�� ����!\n");
	else
		printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));

	// Ž��! 6�� ����� ��带 ã�Ƽ�!
	sNode = BSTSearch(bstRoot, 6);

	if (sNode == NULL)
		printf("Ž�� ����!\n");
	else
		printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));

	// Ž��! 7�� ����� ��带 ã�Ƽ�!
	sNode = BSTSearch(bstRoot, 7);

	if (sNode == NULL)
		printf("Ž�� ����!\n");
	else
		printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));

	return 0;

}



