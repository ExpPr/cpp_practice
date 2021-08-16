#include <iostream>
using namespace std;

//포인터 : 어떤 데이터의 메모리 주소를 저장함. 정확히는 그 데이터가 시작되는 주소값을 저장.
//선언 : <type> *변수이름=&원하는변수이름, 혹은 &주소값 /  이때 &는 주소값을 의미함.
// * 는 참조 연산자로 지칭됨.

int main(void) {
	int p = 100;
	int* ptr = &p;//포인터 선언
	int** pptr = &ptr;//포인터 참조

	//포인터 끼리의 덧셈 곰셈 나눗셈은 의미없음. 단 뺄샘은 두 포인터의 상대적 거리
	//포인터에 정수를 더하거나 뺄순 잇어도. 실수와의 연산은 무조건 안됨
	//포인터끼리 대입하거나 비교가능

	int arr[3] = { 10,20,30 };
	int* ptr_arr = arr;//포인터에 배열 이름 대입

	//2차원 배열에서 포인터 관계 p[j][i]=*(*(p+j)+i)

	cout << *ptr_arr << "  /  " << *(ptr_arr)+2 << "  /  " << *(ptr_arr + 2) << endl;
	//출력 : 10, 12 ,30

	cout << ptr_arr[1] << "  /  " << ptr_arr[2] << "/" << endl;//이런식으로 사용도 가능

	//=========================================================================
	cout << "---------------------------------------------------------------" << endl;
	//메모리 동적 할당
	//c에서는 malloc(sizeof(struct..)*10)이런 식으로 사용했겟지만c++에서는 new / delete로 모든게 해결!
	//단 c++에도 malloc , calloc 등을 이용가능은 함.
	

	//new 연산자는 일종의 객체를 생성한다고 생각하면됨.

	//형식 : 타입* 포인터이름= new 타입

	int* ptr_n = new int;
	*ptr_n = 123.4;
	cout << "ptr_n 주소 : " << ptr_n << "/ 값 : " << *ptr_n << endl;
	delete ptr_n;//free() 함수역활함 

	//이것으로 동적 배열을 만들수 있다.

	cout << "동적 배열 출력 부분 " << endl;

	int size;
	cout << "input size : ";
	cin >> size;
	int* dy = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> dy[i];
	}


	int* now = dy;
	int* begin = dy, * end = dy + size;//포인터로 처음과 끝부분 지정

	while (now != end) {
		cout << *(now);
		now++;
	}

	delete[] dy; //다음과 같이 동적 배열 사용후 delete가 아니라 delete[] 로입력할것
	cout << "\n\n" << endl;
	//C++11 부터는 동적 배열을 초기화 리스트 통해 사용이 가능.
	int* arrays = new int[5]{ 9,7,6,5,2 };
	cout << arrays[3] << endl;

	delete[] arrays;

	return 0;
}