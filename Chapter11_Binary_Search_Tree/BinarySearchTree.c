
#include "BinarySearchTree.h"
#include <stdio.h>


void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;			// parent node
	BTreeNode* cNode = *pRoot;			// current node
	BTreeNode* nNode = NULL;			// new node

	// ���ο� ��尡(�� �����Ͱ� ��� ��尡) �߰��� ��ġ�� ã�´�.
	while (cNode != NULL) {
		if (data == GetData(cNode))
			return;						// ������(Ű) �ߺ��� ������� ����

										// while���� ���������� cNode���� �� ��尡(�� �����Ͱ� ����� ��尡) ����� ��ġ������ ����.
		pNode = cNode;					// �׷��� �� ��ġ�� ��带 �����ϱ� ���� �ʿ��� ����, �� ��ġ�� �ڽ����� �ϴ� �θ� ����� �ּ� ���̴�.
										// (�θ� ��忡 �ڽ� ����� �ּ� ���� ����ǹǷ�) pNode�� ���� �θ� ����� �ּ� ���� �����ϴ� ���̴�.
								
		if (data < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode();			// �� ����� ����
	SetData(nNode, data);				// �� ��忡 ������ ����

	// pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL) {
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	// �� ��尡 ��Ʈ �����
	else
		*pRoot = nNode;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cNode = bst;				// current node
	BSTData cd;							// current data

	while (cNode != NULL) {
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;						// Ž�� ����� ����Ǿ� ���� ����
}
