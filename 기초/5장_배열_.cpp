#include <iostream>
using namespace std;

int main(void) {
	// 배열 . 형식 : <type> 배열이름[배열길이]
	//type는 모든 것들이 가능. char double long_long 뿐만아니라 구조체도 가능함.

	int arr[4] = { 12,43,53 }; //바로 초기화도 가능, 단 이때 선언크기보다 작은값 선언시 초기화안된 칸은 전부 기본값으로 초기화됨.
	for (int p : arr) {
		cout << "arr[] : " << p << endl;
	}
	arr[2] = 76;

	int arr2[]={ 23,43,54,64,64 };//배열크기 선언 안하고 초기화 가능. 초기화할때 자동으로 크기지정되며 고정.
	//C++11이상 부터는 초기화 식 넣을때 '=' 입력 안해도됨. 즉 int arr2[] { 23,43,54,64,64 }; 도 가능


	int size = sizeof(arr) / sizeof(int);//배열크기;

	//c에서와 위 방식은 한번 배열크기 결정나면 두번다시 바꿀수 없음.
	//c++에선 다만 동적할당이 가능. 이는 다음장에..

	//다중 배열 초기화방식

	int app[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };//일자로 [0][0],[0][1],[0][2],.. 식으로나감
	int app2[2][2] = { {1,2},{3,4} };
	//일부만 초기화하면 나머지 부분은 전부 기본값으로 초기화됨. int인 경우 0
	//2차 배열 만들때 행(앞에꺼)는 생략가능 하나 뒤에 열은 반드시 입력해야함


	int ape[2][4] = { {0,4},{1,3,2,4} };

	return 0;
}