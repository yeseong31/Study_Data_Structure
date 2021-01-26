

/*

	08-3 [이진 트리의 순회]

	O 순회의 세 가지 방법

					C
				  /	  \
				 L	   R

		- 전위 순회			루트 노드를 먼저!					'C' -> L -> R
		- 중위 순회			루트 노드를 중간에!				L -> 'C' -> R
		- 후위 순회			루트 노드를 마지막에!				L -> R -> 'C'



		높이가 2 이상이 되더라도 이진 트리는 그 구조가 재귀적이기 때문에
		"이 세 가지 순회의 방법을 재귀적으로 구현만 하면 문제는 해결이 된다."

		중위, 전위, 후위 순회 함수의 유일한 차이점은 루트 노드를 방문하는 문장이 삽입된 위치이다.

	-----------------------------------------------------------------------------------------------------------------------------------------------
		중위 순회를 기준으로 순회의 순서는 다음과 같다.

			1. 왼쪽 서브 트리의 순회
			2. 루트 노드의 방문
			3. 오른쪽 서브 트리의 순회

						||				+ 재귀의 탈출 조건 정의!
						VV

			// 중위 순회
			void InorderTraverse(BTreeNode * bt) {			// 이진 트리 전체를 중위 순회하는 함수
				if (bt == NULL)								// bt가 NULL이면 재귀 탈출!
					return;

				InorderTraverse(bt->left);					// 1단계:	왼쪽 서브 트리의 순회
				printf("%d\n", bt->data);					// 2단계:	루트 노드의 방문(노드의 방문을 출력 외에도 다른 방법으로도 표현 가능)
				InorderTraverse(bt->right);					// 3단계:	오른쪽 서브 트리의 순회
			}

	-----------------------------------------------------------------------------------------------------------------------------------------------

			// 전위 순회
			void PreorderTraverse(BTreeNode * bt) {
				if (bt == NULL)
					return;

				printf("%d\n", bt->data);
				PreorderTraverse(bt->left);
				PreorderTraverse(bt->right);
			}

			// 후위 순회
			void PostorderTraverse(BTreeNode * bt) {
				if (bt == NULL)
					return;

				PostorderTraverse(bt->left);
				PostorderTraverse(bt->right);
				printf("%d\n", bt->data);
			}

	-----------------------------------------------------------------------------------------------------------------------------------------------

	O 노드의 방문 이유

	'함수 포인터'를 사용할 생각이다!

			typedef void (*VisitFuncPtr)(BTData data);

			void InorderTraverse(BTreeNode * bt, VisitFuncPtr action) {	
				if (bt == NULL)	
					return;

				InorderTraverse(bt->left, action);	
				action(bt->data);					// 노드의 방문:	함수의 주소 값을 매개변수 action을 통해서 전달받도록 변경
				InorderTraverse(bt->right, action);	
			}


*/



