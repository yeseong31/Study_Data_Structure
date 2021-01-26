
#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "../../Chapter08_Ʈ��/c8_��ȸ/BinaryTree2.h"

typedef BTData BSTData;

// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst);

// BST�� ������� ������ ����
void BSTInsert(BTreeNode** pRoot, BSTData data);

// BST�� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);


#endif // !__BINARY_SEARCH_TREE_H__



