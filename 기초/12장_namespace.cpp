#include <iostream>;
using namespace std;

//네임스페이스 선언 방식 . 보통 .h로 끝나는 헤더파일에 저장.
namespace kg {
	void Display() {
		cout << "HI" << endl;
	}//함수정의
}

namespace kd {
	void Dp2() {} //함수원형.
	int count;//변수 선언
}

int main(void) {
	kg::Display();

	return 0;
}