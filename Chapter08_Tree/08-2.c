

/*

	08-2 [���� Ʈ���� ����]

	O ���� Ʈ���� ���� ���: �迭 ��� or ���� ����Ʈ ���
		
		- �迭 ����� ���� Ʈ��			- ��忡 ��ȣ�� �ο��ϰ� �� ��ȣ�� �ش��ϴ� ���� �迭�� �ε��� ������ Ȱ��
										- ���ǻ� �迭�� ù ��° ��Ҵ� ������� ����(worst case ���)

		- ���� ����Ʈ ����� ���� Ʈ��		����� ���� ����Ʈ�� �������� Ʈ���� ���� ���¸� ���� �� ������
										���� ���� Ʈ���� ������ ���� '��'�̶�� �ڷᱸ���� �迭�� ������� �ϱ� ������
										�迭�� Ʈ���� �����ϴ� ���� �ξ� �����ϴ�.


	O ���� Ʈ�� �ڷᱸ���� ADT

		Operations:

			BTreeNode* MakeBTreeNode(void);
				// ���� Ʈ�� ��带 �����Ͽ� �� �ּ� ���� ��ȯ�Ѵ�.

			BTData GetData(BTreeNode* bt);	
				// ��忡 ����� �����͸� ��ȯ�Ѵ�.

			void SetData(BTreeNode* bt, BTData data);
				// ��忡 �����͸� �����Ѵ�. data�� ���޵� ���� �����Ѵ�.

			BTreeNode* GetLeftSubTree(BTreeNode* bt);
				// ���� ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.

			BTreeNode* GetRightSubTree(BTreeNode* bt);
				// ������ ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.

			void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
				// ���� ���� Ʈ���� �����Ѵ�.

			void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
				// ������ ���� Ʈ���� �����Ѵ�.

*/

