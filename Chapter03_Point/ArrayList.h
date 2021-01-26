#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE		1
#define FALSE		0

#define LIST_LEN	100

#include "Point.h"

typedef Point* LData;					// LData�� ���� typedef ����							// typedef ������ �����Ͽ� ����ü ������ �����ϴ� ����Ʈ��,
																						// ����ü ������ �ּ� ���� �����ϴ� ����Ʈ�� ������ �� �ִ�.
typedef struct __ArrayList {		// �迭��� ����Ʈ�� ������ ����ü
	LData arr[LIST_LEN];			// ����Ʈ�� ������� �迭
	int numOfData;					// ����� �������� ��
	int curPosition;				// ������ ������ġ�� ���
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist);
	// �ʱ�ȭ�� ����Ʈ�� �ּ� ���� ���ڷ� �����Ѵ�.
	// ����Ʈ ���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ��̴�.

void LInsert(List* plist, LData data);
	// ����Ʈ�� �����͸� �����Ѵ�.�Ű����� data�� ���޵� ���� �����Ѵ�.

int LFirst(List* plist, LData* pdata);
	// ù ��° �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�.
	// �������� ������ ���� �ʱ�ȭ�� ����ȴ�.
	// ���� ���� �� TRUE(1), ���� �� FALSE(0) ��ȯ.

int LNext(List* plist, LData* pdata);
	// ������ �������� ���� �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�.
	// �������� ������ ���ؼ� �ݺ� ȣ���� �����ϴ�.
	// ������ ���� �����Ϸ��� ���� LFirst �Լ��� ȣ���ؾ� �Ѵ�.
	// ���� ���� �� TRUE(1), ���� �� FALSE(0) ��ȯ.

LData LRemove(List* plist);
	// LFirst �Ǵ� LNext �Լ��� ������ ��ȯ �����͸� �����Ѵ�.
	// ������ �����ʹ� ��ȯ�ȴ�.
	// ������ ��ȯ �����͸� �����ϹǷ� ���̴� �ݺ� ȣ���� ������� �ʴ´�.

int LCount(List* plist);
	// ����Ʈ�� ����Ǿ� �ִ� �������� ���� ��ȯ�Ѵ�.

#endif // !__ARRAY_LIST_H__
