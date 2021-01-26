
#include "../c6_연결_리스트_기반_ListBaseStack/ListBaseStack.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ConvToRPNExp 함수의 Helper 함수 1
int GetOpPrec(char op) {			// 연산자의 연산 우선순위 정보를 반환한다.
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':						// "( 연산자는 ) 연산자가 등장할 때까지 쟁반 위에 남아있어야 하기 때문에 우선순위가 가장 낮다."
		return 1;
	}

	return -1;
}

// ConvToRPNExp 함수의 Helper 함수 2
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)			// op1의 우선순위가 더 높다면
		return 1;
	else if (op1Prec < op2Prec)		// op2의 우선순위가 더 높다면
		return -1;
	else							// op1과 op2의 우선순위가 같다면
		return 0;
}

void ConvToRPNExp(char exp[]) {		// 후위 표기법의 수식으로 변환
	Stack stack;
	StackInit(&stack);

	int i, idx = 0;					// idx	: convExp 인덱스 번호
	char tok, popOp;				// tok	: exp에서 한 글자씩 떼어 옴
									// popOp: 스택에서 꺼내온 연산자
	int explen = strlen(exp);

	char* convExp = (char*)malloc(explen + 1);					// 변환된 수식을 담을 공간
	memset(convExp, 0, sizeof(char) * explen + 1);				// 할당된 배열을 0으로 초기화

	for (i = 0; i < explen; i++) {
		tok = exp[i];

		if (isdigit(tok))					// tok에 저장된 문자가 숫자가 맞다면 배열 convExp에 그냥 저장
			convExp[idx++] = tok;
		else {								// 숫자가 아니라면
			switch(tok)
			{
			case '(':								// ( 연산자라면 스택에 쌓는다.
				SPush(&stack, tok);
				break;

			case ')':								// ) 연산자라면 반복해서,
				while (1) {
					popOp = SPop(&stack);			// 스택에서 연산자를 꺼내어, ( 연산자를 만날 때까지 배열 convExp에 저장. 
					if (popOp == '(')				
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)		// 스택이 비어 있음 -> 그냥 쌓음
					convExp[idx++] = SPop(&stack);									// 스택이 비어 있지 않음	-> 연산자 비교
				SPush(&stack, tok);													//		tok > SPeek		-> 그냥 쌓음
				break;																//		tok <= SPeek	-> SPop 이후 쌓음
			}
		}
	}
	
	while (!SIsEmpty(&stack))						// 스택에 남아있는 모든 연산자를 배열 convExp로 이동
		convExp[idx++] = SPop(&stack);

	strcpy_s(exp, explen + 1, convExp);
	free(convExp);
}



