
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../c7_원형_큐/CircularQueue.h"

#define CUS_COME_TERM		15		// 고객의 주문 간격: 초 단위

#define CHE_BUR		0				// 치즈버거 상수
#define BUL_BUR		1				// 불고기버거 상수
#define DUB_BUR		2				// 더블버거 상수
				
#define CHE_TERM	12				// 치즈버거 제작 시간: 초 단위
#define BUL_TERM	15				// 불고기버거 제작 시간: 초 단위
#define DUB_TERM	24				// 더블버거 제작 시간: 초 단위

int main(void) {
	int makeProc = 0;				// 햄버거 제작 진행상황
	int cheOrder = 0;
	int bulOrder = 0;
	int dubOrder = 0; 
	int sec;
	
	Queue q;

	QueueInit(&q);
	srand(time(NULL));

	// 아래 for문의 1회 회전은 1초의 시간이 흐름을 의미
	for (sec = 0; sec < 3600; sec++) {					
		if (sec % CUS_COME_TERM == 0) {					// 15초에 한 번식 TRUE가 된다.
			switch (rand() % 3)							// 치즈, 블고기, 더블 중 랜덤으로 하나를 선택
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

		if (makeProc <= 0 && !QIsEmpty(&q))				// enqueue	: 대기실 이동
			makeProc = Dequeue(&q);						// dequeue	: 대기실에서 나와서 대기

		makeProc--;
	}

	puts("Simulation Report!");
	printf(" - Cheese Burger: %d \n", cheOrder);
	printf(" - Bulgogi Burger: %d \n", bulOrder);
	printf(" - Dubble Burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUE_LEN);
	return 0;
}
