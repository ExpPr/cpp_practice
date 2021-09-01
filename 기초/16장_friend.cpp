#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//friend. 객체의 private 멤버 접근하기 위한 새로운 방법 (또 public에 함수 쓰는 방식아님)
//방식 1 : friend 클래스이름 함수이름 (매개변수목록). 주의점. 반드시 클래스 내부에서 선언되어야함.

//단 외부 클래스 함수인 경우 friend 반환타입혹은클래스(보통 속한 클래스) 외부클래스::함수이름(매개변수)

//즉 함수 원형에만 선언가능.
//friend는 private, public protected등등 어느곳이든 선언가능.


class Rect {
    private:
        double height_;
        double width_;
    public:
        Rect(double height,double width) {
            height_=height;
            width_=width;
        }
        void Displaysize();
        Rect operator*(double mul) const;//이경우는 오직 rect * 2 꼴만 가능, 2 * rect 는 불가능.
        friend Rect operator*(double mul,const Rect &origin);//이는 2 * rect를 구현하는 식

        friend class Display;// 프렌드 클래스

        void height() const {
            cout << "이 사각형의 높이는 " << this->height_ << "입니다." << endl;
        }
        void width() const {
            cout << "이 사각형의 너비는 " << this->width_ << "입니다." << endl;
        }

        
};

void Rect::Displaysize() {
    cout<<"사각형 높이 : "<<this->height_<<" / 사각형 너비 : "<<this->width_<<endl;
}

Rect Rect::operator*(double mul) const {
    return Rect(height_*mul,width_*mul);
}

Rect operator*(double mul,const Rect &origin) {
    return origin*mul;
}

//friend 방식 2 . 프렌드 클래스.
//두 클래스가 기능상 서로 밀접하면서, 상대 클래스의 private 접근해야하면 클래스 자체를 프렌드로 선언가능.
//해당 클래스의 모든 멤버 함수가 특정 클래스의 프렌드인 클래스

//선언방식 : friend class 클래스이름. 
/*
class A {
    friend class B
} -> 이 경우 B 클래스의 모든 메소드들은 전부 클래스 A의 모든 멤버 접근가능. 반대는 불가능.
*/

//주의 : 친구의 자식클래스 마찬가지로 friend 키워드 선언하지 않을 시 관계형성 안됨.

class Display {
    public:
        void ShowSize(const Rect &target) {
        target.height();
        target.width();
           }
        void ShowDiagonal(const Rect &target);
};

//Display는 Rect 클래스를 참조하게 됨.

void Display::ShowDiagonal(const Rect &target) {
    double diagonal=sqrt(pow(target.height_,2)+pow(target.width_,2));
    cout << "이 사각형의 대각선의 길이는 " << diagonal << "입니다." << endl;
}

class Rect1;

class Display1
{
public:
	void ShowSize(const Rect1& target);
	void ShowDiagonal(const Rect1& target);
};

//순환참조 예시 클래스 
class Rect1
{
private:
	double height_;
	double width_;
public:
	Rect1(double height, double width);	// 생성자 
	void height() const;
	void width() const;
	friend void Display1::ShowDiagonal(const Rect1& target);	// 프렌드 멤버 함수 선언 
};

Rect1::Rect1(double height, double width)
{
	height_ = height;
	width_ = width;
}

void Rect1::height() const
{
	cout << "이 사각형의 높이는 " << this->height_ << "입니다." << endl;
}

void Rect1::width() const
{
	cout << "이 사각형의 너비는 " << this->width_ << "입니다." << endl;
}

void Display1::ShowSize(const Rect1& target)
{
	target.height();
	target.width();
}

void Display1::ShowDiagonal(const Rect1& target)
{
	double diagonal;
	diagonal = sqrt(pow(target.height_, 2) + pow(target.width_, 2));
	
	cout << "이 사각형의 대각선의 길이는 " << diagonal << "입니다." << endl;
}


int main(void) {
    Rect origin_Rect(10,20);
    Rect rect1=origin_Rect*3;
    Rect rect2=2*origin_Rect;

    rect1.Displaysize();
    rect2.Displaysize();

    cout<<"\n"<<endl;

    Display show;//<-default 생성자 호출
    show.ShowSize(origin_Rect);
    show.ShowDiagonal(origin_Rect);

    cout<<"============================"<<endl;
    Rect1 r1(10,20);
    Display1 rd;

    rd.ShowSize(r1);
    rd.ShowDiagonal(r1);
    return 0;
}

//위에 전방 선언이 있음.

//순서를 Display1; Rect1{}; Display1{};으로하면 에러.
//Rect1 클래스 내에서 ShowDiagonal() 함수가 프렌드로 선언된 것을 처리하기 전에, 컴파일러는 이미 ShowDiagonal() 함수의 선언을 알고 있어야만 함
