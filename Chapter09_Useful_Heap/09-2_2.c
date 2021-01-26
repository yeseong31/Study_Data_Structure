
/*

	09-2_2 [제법 쓸만한 수준의 힙 구현]

	"프로그래머가 우선순위의 판단 기준을 힙에 설정할 수 있어야 한다."

	--------------------------------------------------------------------------------------------------

	<함수 포인터: typedef 선언>

		- typedef int PriorityComp(HData d1, HData d2);
				=> PriorityComp 형 포인터 변수 선언 시 * 표시 필수!
						예)PriorityComp * comp;

		- typedef int (*PriorityComp)(HData d1, HData d2);
				=> PriorityComp 형 포인터 변수 선언 시 * 표시 가 필요하지 않음
						예)PriorityComp comp;

		단, 매개변수 선언 시에는 예외적으로 * 표시를 쓰지 않음

	--------------------------------------------------------------------------------------------------

	<우선순위 큐 자료구조의 ADT>

		Operations:

			void PQueueInit(PQueue * ppq, PriorityComp pc);
				// 우선순위 큐의 초기화를 진행한다.
				// 우선순위 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.

			int PQIsEmpty(PQueue * ppq);
				// 우선순위 큐가 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.

			void PEnqueue(PQueue * ppq, PQData data);
				// 우선순위 큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.

			PQData PDequeue(PQueue * ppq);
				// 우선순위가 가장 높은 데이터를 삭제한다.
				// 삭제된 데이터는 반환된다.
				// 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

*/


