#ifndef __CLL_BASE_STACK_H__
#define __CLL_BASE_STACK_H__

#include "../../Chapter05_����_����Ʈ_3/c5_����_����_����Ʈ/CLinkedList.h"

typedef struct _listStack {
	List* plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);


#endif // !__CLL_BASE_STACK_H__
