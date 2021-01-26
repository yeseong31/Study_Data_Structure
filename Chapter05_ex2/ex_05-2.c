
/*

	���� 05-2 [���� ��� ����� ����� ���� ����Ʈ�� ����]

	�ռ� ������ ����� ���� ����Ʈ�� �𵨷� �Ͽ� ���ݸ� �����ϰ� ���ݸ� ���¸�
	������ ������ ����� ���� ����Ʈ�� ������ �� �ִ�.
	�����ϰ��� �ϴ� ���� ����Ʈ�� Ư¡�� ������ ����.

		- ����� ���� ����Ʈ�̴�.
		- ���� ��尡 ����Ʈ�� �հ� �ڿ� ���� �����Ѵ�.
		- ������ ���� head�� tail�� �־ ����Ʈ�� �հ� �ڸ� ���� ����Ų��.

	�� ��쿡�� �������� ���� ��尡 �����Կ� ��������.
	�׸��� ���������� �����Ѵٴ� �ǹ̿��� ��������� �Ϻθ� �����Ѵ�.
	�� �Ʒ����� ���̴� ����ü�� �Լ��� ������� ����� ���� ����Ʈ�� �����ϸ� �ȴ�.

	
		// ��������� �Ϻη� ���� ����ü�� ���ǿ� �Լ��� ������ ��� �־�� �Ѵ�.
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
		void LInsert(List * plist, Data data);		// ������ ��带 �߰��Ѵ�.

		int LFirst(List * plist, Data * pdata);
		int LNext(List * plist, Data * pdata);

		Data LRemove(List * plist);					// �ռ� ������ �̷��� ��带 �����Ѵ�.
		int LCount(List * plist);
			
	
	�ռ� ������ ����� ���� ����Ʈ������ �� ��带 �Ӹ��� �߰��Ͽ���.
	���� �̹����� �� ��带 ������ �߰��ϴ� ������� LInsert �Լ��� �����ϱ�� �ϰڴ�.
	�׸��� LRemove �Լ��� ������ �߰��Ǿ��µ�, �� �Լ��� ����� �ռ� ������ ������ ���� ���� �ۼ��ϸ� �ȴ�.
	�׸��� ���α׷��� �ϼ��� �������� �Ӹ��� �ִ� ���� ���� ������ �ִ� ���� ��忡 ���� ��� �ǹ̰� �ִ��� �����غ��� �ٶ���.

*/


