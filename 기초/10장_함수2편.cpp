#include <iostream>;
#include <string>;
using namespace std;
#define SQR(X) (X*X);//c언어 define 사용법. 이것이 인라인이랑 비슷하나 인라인이 좀더 수월

inline int Sub(int x, int y) {
	return x - y;
}//인라인 함수 형식 ,함수 원형이나 정의 어느쪽이든 상관x,
//인라인 함수는 코드 내용이 매우 짧을때 사용할 것을 추천.

struct Book {
	string title;
	string author;
	int price;
};

//default 인수
//함수 원형에만 지정가능. 가장 오른쪽부터 시작해야만 함, 가운데에 따로 인수지정불가
void Display(int x, int y, char ch, int z = 4);
void Display(int x, int y, char ch = 'z', int z = 12);

//Display(1,2), Display(3,4,'b'), Display(3,2,'c',2) 가 가능

//c++은 함수 오버로딩 가능 - 오버로딩 조건 : 매개변수가 달라야함 타입 혹은 개수
void shift(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;

	cout << a << "," << b << endl;
}

void shift(int& a, int& b, int& c) {
	int temp;
	temp = a;
	a = b;
	b = c;
	c = temp;
	cout << a << "," << b << ","<<c<<endl;
}

void Display(const Book &);

int main(void) {
	Book web{ "HTML 과 CSS","고길동",30000 };//c++에선 c와 달리 typedef로 안해도 굳이 struct Book ~~ 식으로 안해도됨
	Display(web);

	return 0;
}

void Display(const Book& bk) {//매개변수에서 const : 매개변수에 들어간 변수의 값을 변경하지 못하게 함.
	cout << "책 제목 : " << bk.title << endl;
	cout << "저자 : " << bk.author << endl;
	cout << "가격 : " << bk.price << endl;
}