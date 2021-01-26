
#include "CLLBaseStack.h"
#include "../../Chapter05_연결_리스트_3/c5_원형_연결_리스트/CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>


void StackInit(Stack* pstack) {
	pstack->plist = (Node*)malloc(sizeof(Node));
	ListInit(pstack->plist);
}

int SIsEmpty(Stack* pstack) {
	if (LCount(pstack->plist) == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	LInsert(pstack->plist, data);
}

Data SPop(Stack* pstack) {
	Data data;
	LFirst(pstack->plist, &data);
	LRemove(pstack->plist);
	return data;
}

Data SPeek(Stack* pstack) {
	Data data;
	LFirst(pstack->plist, &data);
	return data;
}
