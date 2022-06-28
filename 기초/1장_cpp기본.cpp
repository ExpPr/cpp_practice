#include <iostream>;
using namespace std;//이 코드는 std::cout 같이 범위지정 생략이 가능함 (단 std 관련된 것 한에서만)

int main(void) {
	cout << "Hello world\n" << endl;//endl : 원래는 std::endl, 줄바꿈 + 버퍼비우기 (flush) 기능.
	cout << "First line " << flush;// 버퍼 비우나 줄바꿈은 안함
	cout << "Second line" << endl;

	int age;//변수지정
	cout << "your age :";
	cin >> age;

	cout << "your age is " << age << endl;
}