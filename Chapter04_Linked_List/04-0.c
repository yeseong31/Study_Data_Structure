
/*

	04-0 [메모리의 동적 할당(열혈C 542p)]

	우리는 지역변수와 같이 함수호출 때마다 매번 할당이 이루어지지만
	할당이 되면 전역변수와 같이 함수를 빠져나가도 소멸되지 않는 성격의 변수가 필요하다.

	<힙 영역의 메모리 공간 할당과 해제>
		: malloc 함수, free 함수

		malloc 함수는 인자로 전달된 정수 값에 해당하는 바이트 크기의 메모리 공간을
		힙 영역에 할당한 후 '이 메모리 공간의 주소 값을 반환'한다.


		#include <stdlib.h>

		int * ptr1 = (int*)malloc(sizeof(int));					// malloc 함수의 반환형이 void 포인터이므로
		double * ptr2 = (double*)maloc(sizeof(double));			// 반환된 주소 값의 적절한 형 변환이 필요하다.
	
		free(ptr1);
		free(ptr2);
		
		
*/

