#include <iostream>;
#include <string>;
using namespace std;
//함수 

//형식 : <반환 자료형> 함수이름 (매게변수 [들] )

int small(int x, int y) {
	return (x < y) ? x : y;
}
int big(int, int); //함수정의는 main 이후로도 가능하나, main 앞에 미리 이런 함수도 있다든걸
//알려줘야함. 이때 앞에꺼 선언 함수는 세미클론 필수

//값에 의한 전달 : 함수 내에서 매개변수 조작은 인수로 전달되는 변수에 아무런 영향 x
//즉 인수로 전달된 변수의 값을 복사하고 그 복사본을 옮기는 식
void Local(int x) {
	x += 100;
}

//참조에 의한 전달 : 복사본을 옮기는게아니라 원본 자체를 건드리는방식
//매게변수에 &를 입력, 이떄 &는 주소 연산자가 아니라 참조자로 작동. 아눈 다른 변수나 상수를 가리키는 방법으로 또 다른 방식을 제공


void Local2(int& x) {
	x += 10;
}

//주소에 의한 전달 : 포인터를 이용함. 주소를 전달함.
void swap(int *x,int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

//재귀함수 :
int RecursiveSum(int i) {
	if (i == 1) {
		return 1;
	}
	else {
		return i + RecursiveSum(i - 1);
	}
}

//함수 포인터 
//함수의 이름은 메모리에 올라간 함수의 시작 주소를 가리키는 포인터 상수(constant pointer)가 됨
//함수의 시작 주소를 가리키는 포인터 상수를 함수 포인터(function pointer)
//포인터 상수(constant pointer)란 포인터 변수가 가리키고 있는 주소 값을 변경할 수 없는 포인터를 의미하며,
//상수 포인터(pointer to constant)란 상수를 가르키는 포인터를 의미

double Add(double num1, double num2) { return num1 + num2; }

double Sub(double num1, double num2) { return num1 - num2; }

double Mul(double num1, double num2) { return num1 * num2; }

double Div(double num1, double num2) { return num1 / num2; }

double Calculator(double num1, double num2, double (*func)(double, double)) { return func(num1, num2); }//함수 포인터 활용

typedef double (*Airth) (double, double);//typedef 를 이용하면 복잡한 타입을 간단하게 만들수 있음.
//typedef 사용방식 : typedef 타입 이름 (매개변수) -> 매개변수는 잇을수도잇고 없을수도있고.
//typedef 정의에 매개변수를 쓰면, 변수 선언시 사용자가 지정한 typedef만 쓰고 매개변수 입력 스킵이 가능할 수 잇다. (주로함수선언?)

//double Calculator(double num1, double num2, Arith func) { return func(num1, num2); } -> typedef 적용되면

int main(void) {
	cout << small(3, 6) << endl;
	cout << big(10, 100) << endl;

	int xk = 130;
	int* x = &xk;
	Local(xk);

	cout << to_string(xk) << endl;//x=130;
	Local2(xk);
	cout << to_string(xk) << endl;//x=140;

	int a = 10, b = 20;
	swap(&a, &b);
	cout << "a :" << a << "/ b : " << b << endl;


	cout << "1부터 10까지합 : " << RecursiveSum(10) << endl;

	double (*calc)(double, double) = NULL; // 함수 포인터 선언
	Airth calc2 = NULL;//typedef 이용
	double num1 = 3, num2 = 4, result = 0;
	char oper = '*';

	switch (oper) {
	case '+':
		calc = Add;
		calc2 = Add;
		break;
	case '-':
		calc = Sub;
		calc2 = Sub;
		break;
	case '*':
		calc = Mul;
		calc2 = Mul;
		break;
	case '/':
		calc = Div;
		calc2 = Div;
		break;
	default:
		cout << "사칙연산(+, -, *, /)만을 지원합니다." << endl;
		break;
	}

	result = Calculator(3, 4, calc);

	cout << "사칙 연산의 결과는 " << result << "입니다." << endl;
	cout << "함수 포인터를 + typedef 이용하여 만듬 / 사칙 연산의 결과는 " << result << "입니다.";

	return 0;
}

int big(int x, int y) {
	return (x > y) ? x : y;
}