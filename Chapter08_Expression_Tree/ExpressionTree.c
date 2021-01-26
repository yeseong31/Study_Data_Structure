
#include "../c8_순회/BinaryTree2.h"
#include "../../Chapter06_스택/c6_연결_리스트_기반_ListBaseStack/ListBaseStack.h"
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
			SetData(pnode, exp[i] - '0');		// 문자를 숫자로 저장
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

	// 전달된 것이, 서브 트리가 추가로 달려 있지 않은 단말 노드의 주소 값이라면, 그 단말 노드에 저장된 피연산자를 반환한다.
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


void ShowNodeData(int data) {			// 노드의 방문 목적 형성
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

	if (bt->left != NULL || bt->right != NULL)		// 순회의 과정에서 소괄호를 출력해야 하기 때문에, 직접 순회하는 코드를 삽입해야 한다.
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



