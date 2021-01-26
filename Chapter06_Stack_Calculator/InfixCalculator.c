
#include "InfixCalculator.h"
#include "InfixToPostfix.h"
#include "PostCalculator.h"
#include <string.h>
#include <stdlib.h>

int EvalInfixExp(char exp[]) {
	int explen = strlen(exp);
	int ret;					// ���� �����

	char* expcpy = (char*)malloc(explen + 1);				// ���� �Ѽ� ���� ����
	strcpy_s(expcpy, explen + 1, exp);

	ConvToRPNExp(expcpy);									// ���� ǥ��� -> ���� ǥ��� ��ȯ
	ret = EvalRPNExp(expcpy);								// ���� ǥ������� ��ȯ�� ���� ���

	free(expcpy);
	return ret;
}


