
/*

	문제 03-2 [리스트의 활용]

	다음 헤더파일에 정의된 구조체를 기반으로 리스트를 활용하는 예제를 작성해보기로 한다.


	// 이하 헤더파일 NameCard.h의 내용이다.
		#define NAME_LEN		30
		#define PHONE_LEN		30

		typedef struct __namecard {
			char name[NAME_LEN];
			char phone[PHONE_LEN];
		} NameCard;

		// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
		NameCard * MakeNameCard(char * name, char * phone);

		// NameCard 구조체 변수의 정보 출력
		void ShowNameCardInfo(NameCard * pcard);

		// 이름이 같으면 0, 다르면 0이 아닌 값 반환
		int NameCompare(NameCard * pcard, char * name);

		// 전화번호 정보를 변경
		void ChangePhoneNum(NameCard * pcard, char * phone);


	위의 헤더파일에 대응하는 소스파일 NameCard.c를 작성하자!
	그리고 아래에 나열된 순서대로 일을 진행하도록 main 함수를 정의하자.
	물론 이를 위해서 앞서 구현한 리스트를 활용해야 한다.

		1. 총 3명의 전화번호 정보를, 앞서 우리가 구현한 리스트에 저장한다.
		2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
		3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다.
		4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.
		5. 끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.

	더불어 저장의 형태는 NameCard 구조체 변수의 주소 값이어야 하며,
	위에서 언급하는 특정 이름은 임의로 지정하되 서로 다른 이름으로 지정하기로 하자.

*/


