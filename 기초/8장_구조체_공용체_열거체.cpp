#include <iostream>;
#include <string>;
using namespace std;

struct book {
	string title;
	char author[30];
	int price;
};
//위 같은 방식으로 struct 구조체이름 {멤버변수들}; 방식

//공용체 : 모든 멤버 변수가 하나의 메모리 공간을 사용함.
//구조체라면 예를들어 int short char 선언시 8byte 사용하나, 공용체는 제일큰 int 인 4byte만 사용하고 그 영역을 공유함.

union sharedata {
	unsigned char a;
	unsigned char b;
	unsigned int c;

};

//열거체

enum Weather { SUNNY = 0, CLOUD, RAIN = 10, SNOW = 20 };
//SUNNY = 0, CLOUD=1, RAIN=10, SNOW=20

int main(void) {
	//구조체 변수 선언 : struct 구조체이름 구조체변수이름
	//초기화는 중괄호 { } 를 통해 함.

	struct book bk1 ={"HTML 과 CSS","홍길동",100000 };//= 생략가능.
	struct book bk2 {};//전부 다 초기화 할 필요x 빈공간이면 전부 기본값으로 됨.
	cout << bk2.price << endl;


	sharedata var;//공용체 선언
	var.c = 0x12345678;

	cout << hex;
	cout << var.a << endl;//x
	cout << var.b << endl;//5678
	cout << var.c << endl;//12345678

	int input;
	Weather wt;//열거체 선언

	cout << "오늘의 날씨를 입력해 주세요 : " << endl;

	cout << "(SUNNY=0, CLOUD=1, RAIN=20, SNOW=30)" << endl;

	cin >> input;

	wt = (Weather)input;



	switch (wt)

	{

	case SUNNY:

		cout << "오늘의 날씨는 아주 맑아요!";

		break;

	case CLOUD:

		cout << "오늘의 날씨는 흐리네요!";

		break;

	case RAIN:

		cout << "오늘의 날씨는 비가 주룩주룩 오네요!";

		break;

	case SNOW:

		cout << "오늘의 날씨는 하얀 눈이 내려요!";

		break;

	default:

		cout << "정확한 상숫값을 입력해 주세요!";

		break;

	}


	return 0;
}