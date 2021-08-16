#include <iostream>
using namespace std;

//조건식
//1. if -else

int main(void) {

	int a = 1;

	if (a > 5) {
		cout << "Big" << endl;
	}
	else if (a == 5) {
		cout << "same" << endl;
	}
	else {
		cout << "small" << endl;
	}
	//삼향 연산자를 좀 극한으로 사용하는 방식.
	(a > 5) ? (cout << "Big" << endl) : (a == 5) ? (cout << "same" << endl) : (cout << "small" << endl);


	//switch

	//c에서는 오직 정수만 가능했지만. c++에서는 char / short / int / 열거체 등등 다 사용이 가능

	switch (a) {
	case 1:
		cout << "1a" << endl;
		break;
	case 2:
		cout << "2a" << endl;
		break;
	case 3:
		cout << "3a" << endl;
		break;
	case 4:
		cout << "4a" << endl;
		break;
	default:
		cout << "1~4 이외숫자임" << endl;
	}
	char ch = 'a';
	switch (ch) {
	case 'a':
	case 'A':
		cout << "이 학생 학점은 A" << endl;
		break;
	default:
		cout << "머저리" << endl;
	}

	//------------------------------------------------------ 반복문

	//while

	int i = 0, num = 5;

	while (i < num) {
		cout << "현재 " << ++i << "번째 반복중" << endl;
	}
	i = 0, num = 5;
	do {
		cout << "현재 " << ++i << "번째 반복중" << endl;
	} while (i < num);//do-while꼴은 끝에 세미클론 필수다.. 조심!

	//for

	//for (초기식;조건식;증감식) {} 방식
	cout << "===================================================================" << endl;
	for (i = 0; i < 5; i++) {
		cout << "현재 " << i+1 << "번째 반복중" << endl;
	}
	//주의 for문 안 증감을 담당할 초기회된 변수가 for문밖에 이미 존재하는 변수가 아닌경우, 초기식 안 변수는 오로지 for문안에서만 사용가능

	//for문 경우 배열과 결합이 가능
	int arr[5] = { 1,2,3,4,5 };
	for (int ele : arr) {
		cout << ele << " for (:)구문" << endl;
	}

	//break 와 continue, goto는 스킵

	return 0;
}