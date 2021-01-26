
#include "PostCalculator.h"
#include "../c6_연결_리스트_기반_ListBaseStack/ListBaseStack.h"
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
			SPush(&stack, tok - '0');			// 정수이면 숫자로 변환 후 스택에 PUSH!

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

