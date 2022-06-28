#include <iostream>;
using namespace std;


int add(int x, int y) {
	return x + y;
}

int main(void) {
	//숫자 변수종류: int , unsigned int , long , unsigned long, long long , float , double , long double ,short, unsigned short

	int temp1, temp2;

	int b= 10;
	//리터럴 상수
	cout << oct;//이제 담겨진 숫자를 10진수가 아닌 8진수로 표현함

	cout << "10을 8진수 " << b << endl;
	cout << hex;
	cout << "10을 16진수 : " << b << endl;
	cout << dec;
	cout << b << endl;//std::hex, std::dec, std::oct

	float exd = 3.12F;//접미사 . 접미사 안달면 기본형으로 취급. 정수는 int, 실수는 double이 기본.
	float ecx = 3.2;
	double pi = 314e-2;//3.14표현법 

	//숫자구분 : 작은따움표를 이용해 구분가능. 컴파일에 영향안줌.
	long long i = 24'847'458'121;
	cout << i << endl;

	//포인터 리터럴
	//nullptr : null을 표현하는 값, c에선 0을 입력햇어야 했음.
	int* ptr = nullptr;

	int* a = 0;  //포인터

	//사용이유 : 가독성
 // a가 int 값의 0인지 포인터 타입인지 헷갈릴 수 있음.
	if (a == 0)
	{
		cout << "a == 0" << endl;
	}

	// a가 포인터 타입인지 알 수 있음.
	if (a == nullptr)
	{
		cout << "a == nullptr" << endl;
	}

	//auto
	//auto는 초기화식을 통해서 해당 변수의 형식을 스스로 추론함.
	//초기화 없이 auto 사용 불가능. 그리고 auto는 매개변수에 사용불가능.
	auto d = 5.0;// d 는 double
	auto n = 2 + 3;//n는 int
	auto sum = add(2, 21);//sum은 add함수 return이 int니 int로 정의

	//c++14부턴 auto sum(int x , int y)같이 함수형에도 사용가능하도록 확장됨.


	//심볼릭 상수
	//선언과 동시에 초기화를 해야하는것이 차이. 매크로 이용하거나 const 키워드이용
	
	const int ages = 20;

	//--------------------- 문자형
	
	char inp = 'c';//char형
	bool result = true;//bool형
	//----------------------- type 변환
	// 자동 타입 변환 : 컴파일러가 자동으로 type변환함.

	int num1 = 3.14;
	int num2 = 8.3E12;
	double num3 = 5;

	cout << "num 1 " << num1 << endl;

	cout << "num 2 " << num2 << endl;

	cout << "num 3 " << num3 << endl;

	//강제 타입 변환
	//방식 : (변환할타입) 변환할 데이터  혹은  변환할 타입(변환활 데이터) 
	//전자는 c c++ 둘다 가능함. 후자는 c++만 가능함.

	num1 = 1;
	num2 = 4;

	double re1 = num1 / num2;//0출력됨. 오른쪽이 int이므로
	double re2 = (double)num1 / num2;//0.25 출력
	double re3 = double(num1 / num2);//0.25출력


	return 0;
}