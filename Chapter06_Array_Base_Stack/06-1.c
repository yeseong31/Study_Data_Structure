
/*

	06-1 [스택의 이해와 ADT 정의]

	"먼저 들어간 것이 나중에 나온다!"
	스택은 나중에 들어간 것이 먼저 나오는 구조이다 보니 '후입선출 방식의 자료구조'라고 불린다.


	<스택 ADT 정의>

		스택을 대표하는 넣고, 꺼내고, 들여다 보는 연산을 가리켜 각각 push, pop, peek이라 한다.


		Operations:

			void StackInit(Stack * pstack);
				// 스택의 초기화를 진행한다.
				// 스택 생성 후 제일 먼저 호출되어야 하는 함수이다.

			int SIsEmpty(Stack * pstack);
				// 스택이 빈 경우 TRUE(1), 그렇지 않은 경우 FALSE(0)을 반환.

			void SPush(Stack * pstack, Data data);
				// 스택에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.

			Data SPop(Stack * pstack);
				// 마지막에 저장된 요소를 삭제한다.
				// 삭제된 데이터는 반환이 된다.
				// 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다. (SIsEmpty 함수 호출 이후에 SPop 함수를 호출해야 한다.)

			Data SPeek(Stack * pstack);
				// 마지막에 저장된 요소를 반환하되 삭제하지 않는다.
				// 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
			
			
*/




