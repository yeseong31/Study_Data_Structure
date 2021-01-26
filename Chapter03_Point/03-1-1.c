

/*

	<리스트에 구조체 변수 저장하기1: 구조체 Point와 관련 함수들의 정의>

			typedef struct _point {
				int xpos;				// x좌표 정보
				int ypos;				// y좌표 정보
			} Point;

		정수가 아닌 다른 데이터를 리스트에 저장한다는데 의미가 있으므로, 구조체는 가급적 간단히 정의하였다.
		이어 위의 구조체와 관련 있는 다음 함수들도 함께 정의하고자 한다.

			void SetPointPos(Point * ppos, int xpos, int ypos);		// 값을 저장

			void ShoePointPos(Point * ppos);						// 정보 출력
				
			int PointComp(Point * pos1, Point * pos2);				// 두 Point 변수의 멤버 xpos만 같으면 1 반환
																	// 두 Point 변수의 멤버 ypos만 같으면 2 반환
																	// 두 Point 변수의 멤버가 모두 같으면 0 반환
																	// 두 Point 변수의 멤버가 모두 다르면 -1 반환
*/


