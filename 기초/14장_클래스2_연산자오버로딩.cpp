#include <iostream>
#include <string>
using namespace std;

class Position {
    private:
        double x_;
        double y_;
    public:
        Position(int x,int y) {
            x_=x;
            y_=y;
        }
        void Display();
        Position operator -(const Position& other);//연산자 오버로딩 1번째. 맴버변수이용.
        friend Position operator +(const Position& o1,const Position& o2);//연산자 오버로딩 2번째. 이 방식 이용하면 private 접근이 막힘.
        //이때 friend 이용.
        Position operator++();
        Position operator=(const Position& temp) {
            return *this;
        }
};

//형식 : 클래스이름::operator오버로딩할연산자(매개변수)
Position Position::operator-(const Position& other) {
    return Position((x_+other.x_)/2,(y_+other.y_)/2);
}//방법 1 : 클래스 멤버 함수로 정의하는 방법. private 접근가능.


Position Position::operator++(){
    x_++;
    y_++;
}
 
void Position::Display() {
    cout<<"x 좌표 : "<<this->x_<<" / y : "<<this->y_<<endl;
}

int main(void) {
    Position pos1(3.3,12.5);
    Position pos2=Position(-14.4,7.8);
    Position pos3=pos1-pos2;
    ++pos3;
    Position pos4=pos3;

    pos3.Display();
    return 0;
}

/* 사용제약
1. 전혀 새로운 연산자 정의 불가. ex: %%, +++같은거
2. 기본 타입 다루는 연산자 의미 재정의불가. overloading된 피연산자 중 하나는 반드시 사용자정의 타입이어야함.
3. 오버로딩 된 연산자는 기본 타입 다루는 경우에 적요오디는 피연산자의 수, 우선순위 및 그룹화 준수 필요
 -> 예를들면 이항연산자가 단항 연산자로 오버로딩이 불가
 4. 오버로딩된 연산자는 디폴트 인수 사용불가

 5. 오버로딩 불가능한 연산자
 :: / . / .* / ? : / sizeof / typeid / const_cast / dynamic_cast / reinterpret_cast/ static_cast /

 6. 오로지 멤버변수로만 오버로딩이 가능 한 연산자 
 = / () / [] / ->
 */
