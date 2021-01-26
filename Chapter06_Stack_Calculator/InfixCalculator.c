
#include "InfixCalculator.h"
#include "InfixToPostfix.h"
#include "PostCalculator.h"
#include <string.h>
#include <stdlib.h>

int EvalInfixExp(char exp[]) {
	int explen = strlen(exp);
	int ret;					// 최종 계산결과

	char* expcpy = (char*)malloc(explen + 1);				// 원본 훼손 방지 차원
	strcpy_s(expcpy, explen + 1, exp);

	ConvToRPNExp(expcpy);									// 중위 표기법 -> 후위 표기법 변환
	ret = EvalRPNExp(expcpy);								// 후위 표기법으로 변환된 수식 계산

	free(expcpy);
	return ret;
}


