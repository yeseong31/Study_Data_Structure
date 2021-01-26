
#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

BTreeNode* MakeBTreeNode(void) {
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode* bt) {
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL)
		free(main->left);										// 왼쪽에 연결되어 잇던 것이 노드 하나가 아니라 '둘 이상의 노드로 구성된 서브 트리'라면
																// 모든 노드를 대상으로 free 함수를 호출해야 함. (순회)
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}
