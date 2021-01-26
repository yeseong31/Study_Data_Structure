
/*

	문제 07-1 [덱을 기반으로 큐를 구현하기]

	다음 두 파일을 만들어서 덱을 기반으로 하여 큐를 구현해보자.

		- 큐의 구현을 위한 헤더파일		DequeBaseQueue.h
		- 큐를 구현하고 있는 헤더파일		DequeBaseQueue.c

	큐의 구현에 사용되는 덱의 헤더파일과 소스파일은 다음과 같다.
	이 둘은 앞서 우리가 만든 것들이다.

		- 큐의 구현을 위한 헤더파일		Deque.h
		- 큐를 구현하고 있는 헤더파일		Deque.c

	그리고 큐의 헤더파일에는 다음 함수들이 선언되어야 한다.

		void QueueInit(Queue * pq);
		int QIsEmpty(Queue * pq);
		void Enqueue(Queue * pq, Data data);
		Data Dequeue(Queue * pq);
		Data QPeek(Queue * pq);
		
		
	*/



