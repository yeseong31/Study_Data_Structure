
#include "../c8_��ȸ/BinaryTree2.h"
#include "../../Chapter06_����/c6_����_����Ʈ_���_ListBaseStack/ListBaseStack.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


BTreeNode* MakeExpTree(char exp[]) {
	Stack stack;
	StackInit(&stack);
	BTreeNode* pnode;

	int explen = strlen(exp);
	int i;
	
	for (i = 0; i < explen; i++) {
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
			SetData(pnode, exp[i] - '0');		// ���ڸ� ���ڷ� ����
		else {
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		
		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt) {
	int op1, op2;

	// ���޵� ����, ���� Ʈ���� �߰��� �޷� ���� ���� �ܸ� ����� �ּ� ���̶��, �� �ܸ� ��忡 ����� �ǿ����ڸ� ��ȯ�Ѵ�.
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}


void ShowNodeData(int data) {			// ����� �湮 ���� ����
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt) {
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)		// ��ȸ�� �������� �Ұ�ȣ�� ����ؾ� �ϱ� ������, ���� ��ȸ�ϴ� �ڵ带 �����ؾ� �Ѵ�.
		printf("( ");

	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(") ");
}

void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}



