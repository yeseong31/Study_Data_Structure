
/*

	문제 05-2 [더미 노드 기반의 양방향 연결 리스트의 구현]

	앞서 구현한 양방향 연결 리스트를 모델로 하여 조금만 수정하고 조금만 보태면
	완전한 형태의 양방향 연결 리스트를 구현할 수 있다.
	구현하고자 하는 연결 리스트의 특징은 다음과 같다.

		- 양방향 연결 리스트이다.
		- 더미 노드가 리스트의 앞과 뒤에 각각 존재한다.
		- 포인터 변수 head와 tail이 있어서 리스트의 앞과 뒤를 각각 가리킨다.

	이 경우에는 꼬리에도 더미 노드가 존재함에 유의하자.
	그리고 구현범위를 제한한다는 의미에서 헤더파일의 일부를 제공한다.
	즉 아래에서 보이는 구조체와 함수를 기반으로 양방향 연결 리스트를 구현하면 된다.

	
		// 헤더파일의 일부로 다음 구조체의 정의와 함수의 선언을 담고 있어야 한다.
		typedef struct _node {
			Data data;
			struct _node * next;
			struct _node * prev;
		} Node;

		typedef struct _dbLinkedList {
			Node * head;
			Node * tail;
			Node * cur;
			int numOfData;
		} DBLinkedList;

		typedef DBLinkedList List;

		void ListInit(List * plist);
		void LInsert(List * plist, Data data);		// 꼬리에 노드를 추가한다.

		int LFirst(List * plist, Data * pdata);
		int LNext(List * plist, Data * pdata);

		Data LRemove(List * plist);					// 앞서 참조가 이뤄진 노드를 삭제한다.
		int LCount(List * plist);
			
	
	앞서 구현한 양방향 연결 리스트에서는 새 노드를 머리에 추가하였다.
	따라서 이번에는 새 노드를 꼬리에 추가하는 방식으로 LInsert 함수를 구현하기로 하겠다.
	그리고 LRemove 함수의 선언이 추가되었는데, 이 함수의 기능은 앞서 수차례 경험한 것을 토대로 작성하면 된다.
	그리고 프로그램을 완성한 다음에는 머리에 있는 더미 노드와 꼬리에 있는 더미 노드에 각각 어떠한 의미가 있는지 생각해보기 바란다.

*/



