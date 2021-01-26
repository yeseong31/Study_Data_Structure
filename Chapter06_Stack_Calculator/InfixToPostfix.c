
#include "../c6_����_����Ʈ_���_ListBaseStack/ListBaseStack.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ConvToRPNExp �Լ��� Helper �Լ� 1
int GetOpPrec(char op) {			// �������� ���� �켱���� ������ ��ȯ�Ѵ�.
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':						// "( �����ڴ� ) �����ڰ� ������ ������ ��� ���� �����־�� �ϱ� ������ �켱������ ���� ����."
		return 1;
	}

	return -1;
}

// ConvToRPNExp �Լ��� Helper �Լ� 2
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)			// op1�� �켱������ �� ���ٸ�
		return 1;
	else if (op1Prec < op2Prec)		// op2�� �켱������ �� ���ٸ�
		return -1;
	else							// op1�� op2�� �켱������ ���ٸ�
		return 0;
}

void ConvToRPNExp(char exp[]) {		// ���� ǥ����� �������� ��ȯ
	Stack stack;
	StackInit(&stack);

	int i, idx = 0;					// idx	: convExp �ε��� ��ȣ
	char tok, popOp;				// tok	: exp���� �� ���ھ� ���� ��
									// popOp: ���ÿ��� ������ ������
	int explen = strlen(exp);

	char* convExp = (char*)malloc(explen + 1);					// ��ȯ�� ������ ���� ����
	memset(convExp, 0, sizeof(char) * explen + 1);				// �Ҵ�� �迭�� 0���� �ʱ�ȭ

	for (i = 0; i < explen; i++) {
		tok = exp[i];

		if (isdigit(tok))					// tok�� ����� ���ڰ� ���ڰ� �´ٸ� �迭 convExp�� �׳� ����
			convExp[idx++] = tok;
		else {								// ���ڰ� �ƴ϶��
			switch(tok)
			{
			case '(':								// ( �����ڶ�� ���ÿ� �״´�.
				SPush(&stack, tok);
				break;

			case ')':								// ) �����ڶ�� �ݺ��ؼ�,
				while (1) {
					popOp = SPop(&stack);			// ���ÿ��� �����ڸ� ������, ( �����ڸ� ���� ������ �迭 convExp�� ����. 
					if (popOp == '(')				
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)		// ������ ��� ���� -> �׳� ����
					convExp[idx++] = SPop(&stack);									// ������ ��� ���� ����	-> ������ ��
				SPush(&stack, tok);													//		tok > SPeek		-> �׳� ����
				break;																//		tok <= SPeek	-> SPop ���� ����
			}
		}
	}
	
	while (!SIsEmpty(&stack))						// ���ÿ� �����ִ� ��� �����ڸ� �迭 convExp�� �̵�
		convExp[idx++] = SPop(&stack);

	strcpy_s(exp, explen + 1, convExp);
	free(convExp);
}



