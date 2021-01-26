

/*

	08-2 [이진 트리의 구현]

	O 이진 트리의 구현 방법: 배열 기반 or 연결 리스트 기반
		
		- 배열 기반의 이진 트리			- 노드에 번호를 부여하고 그 번호에 해당하는 값을 배열의 인덱스 값으로 활용
										- 편의상 배열의 첫 번째 요소는 사용하지 않음(worst case 고려)

		- 연결 리스트 기반의 이진 트리		양방향 연결 리스트의 구성으로 트리의 구성 형태를 만들 수 있지만
										완전 이진 트리의 구조를 갖는 '힙'이라는 자료구조는 배열을 기반으로 하기 때문에
										배열로 트리를 구성하는 것이 훨씬 용이하다.


	O 이진 트리 자료구조의 ADT

		Operations:

			BTreeNode* MakeBTreeNode(void);
				// 이진 트리 노드를 생성하여 그 주소 값을 반환한다.

			BTData GetData(BTreeNode* bt);	
				// 노드에 저장된 데이터를 반환한다.

			void SetData(BTreeNode* bt, BTData data);
				// 노드에 데이터를 저장한다. data로 전달된 값을 저장한다.

			BTreeNode* GetLeftSubTree(BTreeNode* bt);
				// 왼쪽 서브 트리의 주소 값을 반환한다.

			BTreeNode* GetRightSubTree(BTreeNode* bt);
				// 오른쪽 서브 트리의 주소 값을 반환한다.

			void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
				// 왼쪽 서브 트리를 연결한다.

			void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
				// 오른쪽 서브 트리를 연결한다.

*/

