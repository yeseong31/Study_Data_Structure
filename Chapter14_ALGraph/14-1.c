/*
	14-1 그래프의 이해와 종류

	정점(Vertex):	연결의 대상이 되는 개체 또는 위치를 의미
	간선(Edge):		이들 사이의 연결을 의미

	'무방향 그래프'와 '방향' 그래프'는 간선의 연결형태에 따라 '완전 그래프(complete graph)'고 구분이 된다.
	완전 그래프란 '각각의 정점에서 다른 모든 정점을 연결한 그래프'를 말한다.
	방향 그래프의 간선의 수는 무방향 그래프의 간선의 수에 두 배가 된다.

	<그래프 자료구조의 ADT>

	Operations:

		void GraphInit(UALGraph *pg, int nv);
		- 그래프의 초기화를 진행한다.
		- 두 번째 인자로 정점의 수를 전달한다.

		void GraphDestroy(UALGraph *pg);
		- 그래프 초기화 과정에서 할당한 리소스를 반환한다.

		void ShowGraphEdgeInfo(UALGraph * pg);
		- 그래프의 간선정보를 출력한다.


	그래프를 구현하는 방법은 두 가지가 있다.
		- 인접 행렬(adjacent matrix) 기반 그래프		정방 행렬을 활용
		- 인접 리스트(adjacent) 기반 그래프			연결 리스트를 활용
*/