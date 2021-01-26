/*
	[12-2 균형 잡힌 이진 탐색 트리: AVL 트리의 구현]

	AVL 트리도 이진 탐색 트리이므로, 이진 탐색 트리의 구현결과인 다음 파일들을 확장하여 AVL 트리를 구현하고자 한다.

		BinaryTree3의 헤더 파일 및 소스 파일, BinarySearchTree2의 헤더 파일 및 소스 파일

	여기서 BinarySearchTree2.c에 리밸런싱 기능을 추가하여, 파일의 이름을 BinarySearchTree3.c로 변경할 것이다.
	참고로 리밸런싱 기능을 추가하겠다는 것은 리밸런싱에 필요한 함수를 추가로 정의하겠다는 의미가 아니다.
	노드의 추가 및 삭제 시 자동으로 리밸런싱이 진행되도록 그 기능을 확장하겠다는 의미이다.
*/

/*
	<리밸런싱에 필요한 도구들의 정의: 군형을 이루고 있는가?>

	"리밸런싱 불균형 상태"의 판단은 '루트 노드'를 기준으로 "왼쪽 서브 트리의 높이와 오른쪽 서브 트리의 높이"를 확인한 후 결정한다.

		int GetHeight(BTreeNode* bst) {
			int leftH, rightH;

			if (bst == NULL) return 0;
			leftH = GetHeight(GetLeftSubTree(bst));		// 왼쪽 서브 트리 높이 계산
			rightH = GetHeight(GetRightSubTree(bst));	// 오른쪽 서브 트리 높이 계산

			// 큰 값의 높이를 반환
			if (leftH > rightH) return leftH + 1;
			else return rightH + 1;
		}
		
	그리고 균형 인수를 계산해서 반환하는 도구를 만든다.
		
		int GetHeightDiff(BTreeNode* bst) {
			int lsh, rsh;		// left sub tree height, right sub tree height

			if (bst == NULL) return 0;
			lsh = GetHeight(GetLeftSubTree(bst));	// 왼쪽 서브 트리의 높이
			rsh = GetHeight(GetRightSubTree(bst));	// 오른쪽 서브 트리의 높이
			return lsh - rsh;
		}
*/

/*
	<리밸런싱에 필요한 도구들의 정의: LL회전, RR회전>

	BTreeNode* RotateLL(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node
		
		// pNode와 cNode가 LL회전을 위해 적절한 위치를 가리키게 된다.
		pNode = bst;
		cNode = GetLeftSubTree(pNode);

		// 실제 LL회전을 담당하는 두 개의 문장
		ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
		ChangeRightSubTree(cNode, pNode);

		// LL회전으로 인해서 변경된 루트 노드의 주소 값 반환
		return cNode;
	}

	BTreeNode* RotateRR(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node

		// pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 된다.
		pNode = bst;
		cNode = GetRightSubTree(pNode);

		// 실제 RR회전을 담당하는 두 개의 문장
		ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
		ChangeLeftSubTree(cNode, pNode);

		// RR회전으로 인해서 변경된 루트 노드의 주소 값 반환
		return cNode;
	}
*/

/*
	<리밸런싱에 필요한 도구들의 정의: LR회전, RL회전>

		BTreeNode* RotateLR(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node

		// pNode와 cNode가 LR회전을 위해 적절한 위치를 가리키게 된다.
		pNode = bst;
		cNode = GetLeftSubTree(pNode);

		// 실제 LR회전을 담당하는 두 개의 문장
		ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
		return RotateLL(pNode);
	}

	BTreeNode* RotateRR(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node

		// pNode와 cNode가 RL회전을 위해 적절한 위치를 가리키게 된다.
		pNode = bst;
		cNode = GetRightSubTree(pNode);

		// 실제 RL회전을 담당하는 두 개의 문장
		ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
		return RotateRR(pNode);
	}
*/

/*
	<리밸런싱에 필요한 도구들의 정의: Rebalance 함수>

	BTreeNode* Rebalance(BTreeNode** pRoot) {
		int hDiff = GetHeightDiff(*pRoot);	// 균형 인수 계산

		// 균형 인수가 +2이상이면 LL상태 또는 RR 상태이다.
		if (hDiff > 1) {	// 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면,
			if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
				*pRoot = RotateLL(*pRoot);
			else
				*pRoot = RotateLR(*pRoot);
		}

		// 균형 인수가 -2 이사이면 RR상태 또는 RL상태이다.
		if (hDiff < -1) {
			if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) 
				*pRoot = RotateRR(*pRoot);
			else
				*pRoot = RotateRL(*pRoot);
		}

		return *pRoot;
*/