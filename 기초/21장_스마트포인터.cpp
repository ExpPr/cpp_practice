#include <iostream>
#include <string>
#include <memory> //스마트 포인터는 memory에 담김.
using namespace std;

// new로 받은 동적 할당은 반드시 delete로 해제해야함 c++에서
//그러나 스마트 포인터는 포인터 처럼 사용하는 클래스 템플릿 이므로, 사용이 끝난 메모리를 자동으로 해제함

