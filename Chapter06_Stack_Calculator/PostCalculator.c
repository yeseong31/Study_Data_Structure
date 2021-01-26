
#include "PostCalculator.h"
#include "../c6_����_����Ʈ_���_ListBaseStack/ListBaseStack.h"
#include <string.h>
#include <ctype.h>


int EvalRPNExp(char exp[]) {
	Stack stack;
	StackInit(&stack);

	int explen = strlen(exp);
	
	int i;
	char tok, op1, op2;

	for (i = 0; i < explen; i++) {
		tok = exp[i];

		if (isdigit(tok))
			SPush(&stack, tok - '0');			// �����̸� ���ڷ� ��ȯ �� ���ÿ� PUSH!

		else {
			op2 = SPop(&stack);
			op1 = SPop(&stack);

			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}

	return SPop(&stack);
}

