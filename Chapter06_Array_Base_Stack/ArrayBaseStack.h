#ifndef __ARRAY_BASE_STACK_H__
#define __ARRAY_BASE_STACK_H__

#define TRUE		1
#define FALSE		0
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;


void StackInit(Stack* pstack);
// ������ �ʱ�ȭ�� �����Ѵ�.
// ���� ���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ��̴�.

int SIsEmpty(Stack* pstack);
// ������ �� ��� TRUE(1), �׷��� ���� ��� FALSE(0)�� ��ȯ.

void SPush(Stack* pstack, Data data);
// ���ÿ� �����͸� �����Ѵ�. �Ű����� data�� ���޵� ���� �����Ѵ�.

Data SPop(Stack* pstack);
// �������� ����� ��Ҹ� �����Ѵ�.
// ������ �����ʹ� ��ȯ�� �ȴ�.
// �� �Լ��� ȣ���� ���ؼ��� �����Ͱ� �ϳ� �̻� �������� ����Ǿ�� �Ѵ�. (SIsEmpty �Լ� ȣ�� ���Ŀ� SPop �Լ��� ȣ���ؾ� �Ѵ�.)

Data SPeek(Stack* pstack);
// �������� ����� ��Ҹ� ��ȯ�ϵ� �������� �ʴ´�.
// �� �Լ��� ȣ���� ���ؼ��� �����Ͱ� �ϳ� �̻� �������� ����Ǿ�� �Ѵ�.

#endif // !__ARRAY_BASE_STACK_H__
