/*
	[12-2 ���� ���� ���� Ž�� Ʈ��: AVL Ʈ���� ����]

	AVL Ʈ���� ���� Ž�� Ʈ���̹Ƿ�, ���� Ž�� Ʈ���� ��������� ���� ���ϵ��� Ȯ���Ͽ� AVL Ʈ���� �����ϰ��� �Ѵ�.

		BinaryTree3�� ��� ���� �� �ҽ� ����, BinarySearchTree2�� ��� ���� �� �ҽ� ����

	���⼭ BinarySearchTree2.c�� ���뷱�� ����� �߰��Ͽ�, ������ �̸��� BinarySearchTree3.c�� ������ ���̴�.
	����� ���뷱�� ����� �߰��ϰڴٴ� ���� ���뷱�̿� �ʿ��� �Լ��� �߰��� �����ϰڴٴ� �ǹ̰� �ƴϴ�.
	����� �߰� �� ���� �� �ڵ����� ���뷱���� ����ǵ��� �� ����� Ȯ���ϰڴٴ� �ǹ��̴�.
*/

/*
	<���뷱�̿� �ʿ��� �������� ����: ������ �̷�� �ִ°�?>

	"���뷱�� �ұ��� ����"�� �Ǵ��� '��Ʈ ���'�� �������� "���� ���� Ʈ���� ���̿� ������ ���� Ʈ���� ����"�� Ȯ���� �� �����Ѵ�.

		int GetHeight(BTreeNode* bst) {
			int leftH, rightH;

			if (bst == NULL) return 0;
			leftH = GetHeight(GetLeftSubTree(bst));		// ���� ���� Ʈ�� ���� ���
			rightH = GetHeight(GetRightSubTree(bst));	// ������ ���� Ʈ�� ���� ���

			// ū ���� ���̸� ��ȯ
			if (leftH > rightH) return leftH + 1;
			else return rightH + 1;
		}
		
	�׸��� ���� �μ��� ����ؼ� ��ȯ�ϴ� ������ �����.
		
		int GetHeightDiff(BTreeNode* bst) {
			int lsh, rsh;		// left sub tree height, right sub tree height

			if (bst == NULL) return 0;
			lsh = GetHeight(GetLeftSubTree(bst));	// ���� ���� Ʈ���� ����
			rsh = GetHeight(GetRightSubTree(bst));	// ������ ���� Ʈ���� ����
			return lsh - rsh;
		}
*/

/*
	<���뷱�̿� �ʿ��� �������� ����: LLȸ��, RRȸ��>

	BTreeNode* RotateLL(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node
		
		// pNode�� cNode�� LLȸ���� ���� ������ ��ġ�� ����Ű�� �ȴ�.
		pNode = bst;
		cNode = GetLeftSubTree(pNode);

		// ���� LLȸ���� ����ϴ� �� ���� ����
		ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
		ChangeRightSubTree(cNode, pNode);

		// LLȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� �� ��ȯ
		return cNode;
	}

	BTreeNode* RotateRR(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node

		// pNode�� cNode�� RRȸ���� ���� ������ ��ġ�� ����Ű�� �ȴ�.
		pNode = bst;
		cNode = GetRightSubTree(pNode);

		// ���� RRȸ���� ����ϴ� �� ���� ����
		ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
		ChangeLeftSubTree(cNode, pNode);

		// RRȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� �� ��ȯ
		return cNode;
	}
*/

/*
	<���뷱�̿� �ʿ��� �������� ����: LRȸ��, RLȸ��>

		BTreeNode* RotateLR(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node

		// pNode�� cNode�� LRȸ���� ���� ������ ��ġ�� ����Ű�� �ȴ�.
		pNode = bst;
		cNode = GetLeftSubTree(pNode);

		// ���� LRȸ���� ����ϴ� �� ���� ����
		ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
		return RotateLL(pNode);
	}

	BTreeNode* RotateRR(BTreeNode* bst) {
		BTreeNode* pNode, cNode;	// parent node, child node

		// pNode�� cNode�� RLȸ���� ���� ������ ��ġ�� ����Ű�� �ȴ�.
		pNode = bst;
		cNode = GetRightSubTree(pNode);

		// ���� RLȸ���� ����ϴ� �� ���� ����
		ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
		return RotateRR(pNode);
	}
*/

/*
	<���뷱�̿� �ʿ��� �������� ����: Rebalance �Լ�>

	BTreeNode* Rebalance(BTreeNode** pRoot) {
		int hDiff = GetHeightDiff(*pRoot);	// ���� �μ� ���

		// ���� �μ��� +2�̻��̸� LL���� �Ǵ� RR �����̴�.
		if (hDiff > 1) {	// ���� ���� Ʈ�� �������� ���̰� 2 �̻� ũ�ٸ�,
			if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
				*pRoot = RotateLL(*pRoot);
			else
				*pRoot = RotateLR(*pRoot);
		}

		// ���� �μ��� -2 �̻��̸� RR���� �Ǵ� RL�����̴�.
		if (hDiff < -1) {
			if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) 
				*pRoot = RotateRR(*pRoot);
			else
				*pRoot = RotateRL(*pRoot);
		}

		return *pRoot;
*/