/*
	[12-1 균형 잡힌 이진 탐색 트리: AVL 트리의 이해]

	이진 탐색 트리는 균형이 맞지 않을수록 시간 복잡도가 O(log2 n)에서 O(n)에 가까워진다.
	이러한 이진 탐색 트리의 단점을 해결한 트리를 가리켜 '균형 잡힌 이진 트리'라 하며,
	그 중 AVL 트리는 '이진 탐색 트리'가 자동으로 균형을 잡을 수 있도록 개선해준다.

	<AVL 트리>
	AVL 트리는 노드가 추가될 때, 그리고 삭제될 때 트리의 균형상태를 파악해서 스스로 그 구조를 변경하여 균형을 잡는 트리이다.
	균형의 정도를 표현하기 위해 '균형 인수'를 사용한다.

		균형 인수 = (왼쪽 서브 트리의 높이) - (오른쪽 서브 트리의 높이)

	균형 인수의 절댓값이 크면 클수록 그만큼 트리의 균형이 무너진 상태이다.
	따라서 AVL 트리는 균형 인수의 절댓값이 2 이상인 경우에 균형을 잡기 위한 트리의 재조정을 진행한다.(리밸런싱)
*/

/*
	<리밸런싱이 필요한 첫 번째 상태와 LL회전>

			5	+2						"자식 노드 두 개가 왼쪽으로 연이어 연결되어서 균형 인수 +2가 연출되었다."
		   /							즉 균형 인수 +2가 연출된 이 상태를 'LL상태'라고 하며
		  3		+1		>>>		3		LL회전이란, LL상태에서 균형을 잡기 위해 필요한 회전을 의미한다.
		 /					   / \
		1		0			  1   5


	pNode   5					
		   / \
	cNode 3   T4					 3	cNode		ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
		 / \			LL		   /   \			ChangeRightSubTree(cNode, pNode);
		1	T3			>>>		  1     5	pNode
	   / \						 / \   / \
	  T1 T2						T1 T2 T3 T4
*/

/*
	<리밸런싱이 필요한 두 번째 상태와 RR회전>
	LL상태와 RR상태, 그리고 RR회전과 LL회전의 유일한 차이점은 방향이다.

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);
*/

/*
	<리밸런싱이 필요한 세 번째 상태와 LR회전>
	"LL상태는 자식 노드가 왼쪽으로 연이어 두 개 달린 상태를 뜻하는 것이고,
	LR상태는 자식 노드가 왼쪽으로 하나, 그리고 이어서 오른쪽으로 하나 달린 상태를 말하는 것이다."
	
	LR상태는 RR회전을 통해 LL상태로 전환할 수 있다.	 즉 LR회전 = RR회전 + LL회전.

	pNode   5														   5
		   / \														  / \				
	cNode 1   T4	일부를 떼어서		   RR회전		 다시 붙인다		 3	 T4		LL회전		 3
		 / \					1				  3					/ \					   /   \
		T1	3			>>>		 \		>>>	     /		>>>		   1   T3		>>>		  1     5
		   / \					  3			    1				  / \					 / \   / \
		  T2 T3													 T1	T2					T1 T2 T3 T4
*/

/*
	<리밸런싱이 필요한 네 번째 상태와 RL회전>
	LR상태와 RL상태는 방향의 차이만 있기 때문에, RL회전 = LL회전 + RR회전.
*/