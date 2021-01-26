#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode {			// ���� Ʈ���� ǥ���� ����ü
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;
	
BTreeNode* MakeBTreeNode(void);					// ����� ����
BTData GetData(BTreeNode* bt);					// ��忡 ����� �����͸� ��ȯ
void SetData(BTreeNode* bt, BTData data);		// ��忡 �����͸� ����

// ���� Ʈ�� �ּ� �� ��ȯ
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

// ���� Ʈ���� ������ ���
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif // !__BINARY_TREE_H__
