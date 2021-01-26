
/*

	01-2 [알고리즘의 성능분석 방법]

	시간 복잡도		얼마나 더 빠르냐?				CPU			** 더 중요함
	공간 복잡도		메모리 효울이 뛰어나냐?		MeMory

	일반적으로 알고리즘을 평가할 때는 메모리의 사용량보다 실행속도에 초점을 둔다.



	<알고리즘의 수행속도 평가>
		데이터의 수 n에 대한 연산횟수의 함수 T(n)을 구성한다.

		- 데이터의 수가 적은 경우의 수행속도는 큰 의미가 없다. (최악의 경우를 생각하므로)
		- 데이터의 수에 따른 수행속도의 변화 정도를 기준삼음.



	<순차 탐색 알고리즘과 시간 복잡도 분석의 핵심요소>
		순차 탐색 알고리즘은 맨 앞에서부터 순서대로 탐색을 진행하는 알고리즘이다.
		'01-2 프로젝트 내 LinearSearch.c'의 경우, 값의 동등을 비교하는 == 연산을 적게 수행하는 탐색 알고리즘이 좋은 탐색 알고리즘이다.
		
		주변 연산자의 연산 횟수는 줌심 연산자의 연산 횟수에 의존적이다.

		일반적인 알고리즘의 평가에서는 '최악의 경우'를 기준으로 성능을 평가한다.



	<이진 탐색 알고리즘>
		이진 탐색 알고리즘은 정렬된 데이터가 아니면 적용이 불가능하다(정렬의 기준 및 방식과는 관계없다).

		순서
			1. 배열 인덱스의 시작과 끝을 찾는다.
			2. 시작 인덱스의 값과 끝 인덱스의 값을 합하고 그 결과를 2로 나눈다.
			3. 2로 나눠서 얻은 결과를 기준 인덱스 값으로 하여 타겟 값을 비교한다.

		이진 탐색의 매 과정마다 탐색의 대상을 반씩 줄여나가므로 순차 탐색보다 좋은 성능을 보인다.

		** 'First <= Last' 가 반복의 조건!



	<빅-오 표기법>
		즉 '데이터 수의 증가에 따른 연산횟수의 증가 형태(패턴)'을 나타내는 표기법이다.
		"T(n)이 다항식으로 표현이 된 경우, 최고차항의 차수가 빅-오가 된다."

		O(l)  <  O(log n)  <  O(n)  <  O(n log n)  <  O(n^2)  <  O(2^n)
		상수형	  로그형	      선형	   선형로그형			     지수형



*/


