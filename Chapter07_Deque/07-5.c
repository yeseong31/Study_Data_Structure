
/*

	07-5 [덱(Deque)의 이해와 구현]

	"덱은 앞으로도 뒤로도 넣을 수 있고, 앞으로도 뒤로도 뺄 수 있는 자료구조!"

	덱은 양방향으로 넣고, 양방향으로 뺄 수 있는 자료구조이기에, 스택과 큐의 특성을 모두 갖는,
	혹은 스택과 큐를 조합한 형태의 자료구조로 이해되고 있다.


	<덱 자료구조의 ADT>

		Operations:

		void DequeInit(Deque* pdeq);
			// 덱의 초기화를 진행한다.
			// 덱 생성 후 제일 먼저 호출되어야 하는 함수이다.

		int DQIsEmpty(Deque* pdeq);
			// 덱이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.

		void DQAddFirst(Deque* pdeq, Data data);
			// 덱의 머리에 데이터를 저장한다. data로 전달된 값을 저장한다.

		void DQAddLast(Deque* pdeq, Data data);
			// 덱의 꼬리에 데이터를 저정한다. data로 전달된 값을 저장한다.

		Data DQRemoveFirst(Deque* pdeq);
			// 덱의 머리에 위치한 데이터를 반환 및 소멸한다.

		Data DQRemoveLast(Deque* pdeq);
			// 덱의 꼬리에 위치한 데이터를 반환 및 소멸한다.

		Data DQGetFirst(Deque* pdeq);
			// 덱의 머리에 위치한 데이터를 소멸하지 않고 반환한다. 

		Data DQGetLast(Deque* pdeq);
			// 덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환한다.

*/


