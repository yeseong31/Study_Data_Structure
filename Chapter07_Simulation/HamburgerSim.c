
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../c7_����_ť/CircularQueue.h"

#define CUS_COME_TERM		15		// ���� �ֹ� ����: �� ����

#define CHE_BUR		0				// ġ����� ���
#define BUL_BUR		1				// �Ұ����� ���
#define DUB_BUR		2				// ������� ���
				
#define CHE_TERM	12				// ġ����� ���� �ð�: �� ����
#define BUL_TERM	15				// �Ұ����� ���� �ð�: �� ����
#define DUB_TERM	24				// ������� ���� �ð�: �� ����

int main(void) {
	int makeProc = 0;				// �ܹ��� ���� �����Ȳ
	int cheOrder = 0;
	int bulOrder = 0;
	int dubOrder = 0; 
	int sec;
	
	Queue q;

	QueueInit(&q);
	srand(time(NULL));

	// �Ʒ� for���� 1ȸ ȸ���� 1���� �ð��� �帧�� �ǹ�
	for (sec = 0; sec < 3600; sec++) {					
		if (sec % CUS_COME_TERM == 0) {					// 15�ʿ� �� ���� TRUE�� �ȴ�.
			switch (rand() % 3)							// ġ��, ����, ���� �� �������� �ϳ��� ����
			{
			case CHE_BUR:
				Enqueue(&q, CHE_TERM);
				cheOrder++;
				break;
			case BUL_BUR:
				Enqueue(&q, BUL_TERM);
				bulOrder++;
				break;
			case DUB_BUR:
				Enqueue(&q, DUB_TERM);
				dubOrder++;
				break;
			}
		}

		if (makeProc <= 0 && !QIsEmpty(&q))				// enqueue	: ���� �̵�
			makeProc = Dequeue(&q);						// dequeue	: ���ǿ��� ���ͼ� ���

		makeProc--;
	}

	puts("Simulation Report!");
	printf(" - Cheese Burger: %d \n", cheOrder);
	printf(" - Bulgogi Burger: %d \n", bulOrder);
	printf(" - Dubble Burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUE_LEN);
	return 0;
}
