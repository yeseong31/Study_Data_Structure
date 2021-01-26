
#include "NameCard.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(newCard->name, NAME_LEN, name);
	strcpy_s(newCard->phone, PHONE_LEN, phone);
	return newCard;
}

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard) {
	printf("[�̸�: %s]\n", pcard->name);
	printf("[��ȭ��ȣ: %s]\n\n", pcard->phone);
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
}

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard* pcard, char* phone) {
	strcpy_s(pcard->phone, PHONE_LEN, phone);
}





