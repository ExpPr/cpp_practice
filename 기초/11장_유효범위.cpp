#include <iostream>
using namespace std;

static int b;//내부 연결 가지는 정적변수선언

void Local(void);
//자동변수 : C언어에서의 지역변수 와 일맥상통. 블록에 선언된 변수를 의미하며, 오로지 그 블록 안에서만 사용가능
//사용완료시 자동으로 메모리에서 삭제됨.

void StaticVar(void) {
	static int static_count = 1;//static 이라는 예약어 사용시, 프로그램 종료가 되어야지 메모리에서 제거됨. 즉 계속해서 저 변수는 메모리에서 살아잇음.
	//또한 이 경우 단 한번만 초기화됨. 여러번 호출한다해서 계속 초기화되진않음
	cout << "StaticVar() 증가 : " << static_count << " 번쨰 호출됨\n";
	static_count++;
}
int main(void)
{
	int i = 5;

	cout << "변수 b 초기값 : " << b << endl;
	int b = 10;
	cout << "변수 b main()에서 값  : " << b << endl;
	//만약 다른 파일에서 이 파일에있는   변수 사용할려면 external int i 라고 선언을 해야함.
	int var = 10;
	cout << "main() 함수 내의 자동 변수 var의 값은 " << var << "입니다.\n" << endl;

	if (i < 10)
	{
		Local();
		int var = 30;
		cout << "if 문 내의 자동 변수 var의 값은 " << var << "입니다." << endl;
		
	}
	cout << "현재 자동 변수 var의 값은 " << var << "입니다." << endl;
	cout << "변수 b 값 : " << b << endl;//메인함수에서 정적변수 b접근불가.
	StaticVar();
	StaticVar();
	StaticVar();

	return 0;


}

void Local(void)
{
	int var = 20;
	b = 30;
	cout << "Local() 함수 내의 자동 변수 var의 값은 " << var << "입니다." << endl;
	cout << "loca함수 내에서 접근한 정적변수 b값  : " << b << endl;
}

/*출력
변수 b 초기값 : 0
변수 b main()에서 값  : 10
main() 함수 내의 자동 변수 var의 값은 10입니다.

Local() 함수 내의 자동 변수 var의 값은 20입니다.
loca함수 내에서 접근한 정적변수 b값  : 30
if 문 내의 자동 변수 var의 값은 30입니다.
현재 자동 변수 var의 값은 10입니다.
변수 b 값 : 10
StaticVar() 증가 : 1 번쨰 호출됨
StaticVar() 증가 : 2 번쨰 호출됨
StaticVar() 증가 : 3 번쨰 호출됨
*/