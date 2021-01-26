
#include "ArrayBaseStack.h"


void StackInit(Stack* pstack) {
	pstack->topIndex = -1;			// topIndex�� -1�� �� ���¸� �ǹ���.
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	pstack->stackArr[++pstack->topIndex] = data;	// ������ �߰��� ���� �ε��� �� ����
}

Data SPop(Stack* pstack) {
	int rIdx;

	if (SIsEmpty(pstack)) {
		puts("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	(pstack->topIndex)--;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)){
		puts("Stack Memory Error!");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}

