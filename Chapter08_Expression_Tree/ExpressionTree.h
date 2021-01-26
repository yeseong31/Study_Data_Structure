#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "../c8_��ȸ/BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]);				// ���� Ʈ�� ���� (���� ǥ��� ���� -> ���� Ʈ��)
int EvaluateExpTree(BTreeNode* bt);				// ���� Ʈ�� ���

void ShowPrefixTypeExp(BTreeNode* bt);			// ���� ǥ��� ��� ���
void ShowInfixTypeExp(BTreeNode* bt);			// ���� ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode* bt);			// ���� ǥ��� ��� ���


#endif // !__EXPRESSION_TREE_H__
