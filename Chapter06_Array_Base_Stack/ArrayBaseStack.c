
#include "ArrayBaseStack.h"


void StackInit(Stack* pstack) {
	pstack->topIndex = -1;			// topIndex의 -1은 빈 상태를 의미함.
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	pstack->stackArr[++pstack->topIndex] = data;	// 데이터 추가를 위해 인덱스 값 증가
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

