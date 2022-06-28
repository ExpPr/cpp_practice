#include <iostream>;
using namespace std;

//연산자는 c랑 동일함

int main(void) {
	int i = 3 + 4 * 2 - 16 / 4;//
	cout << i << endl;//7로 출력

	// 우선순위가 있으니 표를 참고하자!. 햇깔리면 괄호가 최고 1 순위이니 참고하기

	i += 21;//-= , *= ,/= %= 도 있음. 빼기 , 곱하기 , 몫만 , 나머지만 순
	cout << i << endl;//28로 출력
	i /= 7;//4가 남음

	i++; //i는 4->5가됨

	int result1 = ++i;//먼저 i값을 하나 올린 뒤 result1 대입.
	int result2 = i++;//먼저 i값을 result에 대입뒤 i증가.

	cout << "result 1 : " << result1 << " / reuslt 2 : " << result2 <<"/ i : "<<i<< endl;
	//result 1 : 6 / reuslt 2 : 6/ i : 7


	//비교연산자 : == (같음) , != (다름) , > , < . >= , <= 가 있음. 이건 뭐... 딱히 예시없어도

	//논리연산자 : && (AND) , || (OR) , ! (NOT)

	bool re3 = (3 < 0) && (3 < 5);//거짓
	bool re4 = (3 < 0) || (3 < 5);//참
	bool re5 = !false; //참

	cout << re3 << "  /  " << re4 << endl;
	
	//비트연산자 . bit 단위로 논리 연산.

	// & (AND) , | (OR) , ^ (XOR) , ~ (보수, NOT) , <<숫자 (지정한 숫자만큼 비트 전부 왼쪽으로 이동), >>숫자 (지정한 숫자만큼 비트 전부 오른쪽이동)

	int num3 = 15, num2 = 7;

	cout << "~연산 결과 " << (~num3) << endl;//-16
	cout << "<<연산결과 " << (num2 << 2) << endl; //28
	cout << ">>연산결과 " << (num2 >> 2) << endl;//1

	//삼향 연산자

	// 조건식 ? 반환값1(참결과) : 반환값 2(거짓결과) 

	int a = 10, b = 20;
	int result4 = (a > b) ? a : b;
	cout << "둘중 더 큰놈은 : " << result4 << "이다" << endl;

	//sizeof , 단향 연산자이면서, 이것의 피연산자는 type뿐만이 아닌 변수나 상수도 가능함
	//이 값은 컴퓨터 os 및 cpu마다 다름
	cout << "\nlong long 형 데이터에 할당되는 메모리 크기는 " << sizeof(long long) << "바이트 입니다" << endl;


	//포인터 연산자 및 범위지정 연산자는 다음에..
	return 0;
}