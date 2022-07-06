#include <iostream>
#include <string>
using namespace std;

/*
general programming -> 프로그램 알고리즘에 중점을 둠.

templete :
    매게 변수의 타입에 따라 함수나 클래스를 생성하는 매커니즘.
    타입 마다 별도의 함수나 클래스를 만들지 않고, 여러 타입에서 동작 할 수 있는 단 하나의 함수나 클래스 작성이 가능.
*/

//함수 templete 예시
//함수 templete는 사용할 때 마다 그 인스턴스를 호출함 

//typename 대신 class 사용가능. 동일기능임.
template <typename T>
void Swap(T& a, T& b) {
    T temp;
	temp = a;
	a = b;
	b = temp;	
}

//명시적 특수화 : 특정 타입에 대한 특정 동작을 제공하는 방식
template <> void Swap<double>(double&, double&) {

}


//class template
/* 
클래스 일반화 선언 - 위 함수와 유사하나 함수가 아니라 클래스로 바뀐 것이 전부

형식:
template <typename T>
class 이름 {
    ...
}


*/


template <typename T>
class Data {
    private :
    T data_;
    public :
        Data(T dt);
        T get_data();
};

template <typename T>
Data<T>::Data(T dt) {
    data_ = dt;
}

template <typename T>
T Data<T>::get_data() {
    return data_;
}

//명시적 특수화 - 클래스 버전

template <> class Data<double> {
    private :
    double data_;
    public :
    Data(double dt) {
        data_ = dt;
    }
    double get_data() {
        cout<<"double data 출력"<<endl;
        return data_;
    }
};

//부분 명시적 특수화
/*
    template <typename T1, typename T2>
    class X 일때

    하나만 선언:
    template <typename T1> class X<T1,int> {...}

    다 선언
    template <> class X<int,double> {...}
*/


//중첩 클래스 템플릿 (nested class template)
// 클래스 내에서, 혹은 클래스 template 내에서 또 다른 template 중첩하여 사용 가능
/*
형식
template <typename T>
class X
{
    template <typename U>
    class Y
    {
        ...

    }

    ...

    }

int main(void)
{}

template <typename T>
template <typename U>
X<T>::Y<U>::멤버함수이름()
{
    ...
}
*/


int main(void)
{
	int c = 2, d = 3;
	cout << "c : " << c << ", d : " << d << endl;
	Swap(c, d);
	cout << "c : " << c << ", d : " << d << endl;
	
	double e = 1.234, f = 4.321;
	cout << "e : " << e << ", f : " << f << endl;
	Swap(e, f);
	cout << "e : " << e << ", f : " << f << endl;

    /*
c : 2, d : 3
c : 3, d : 2
e : 1.234, f : 4.321
e : 1.234, f : 4.321
    */

   cout<<"-----------------------------------"<<endl;


    //template 사용한 class 객체 선언시 클래스이름<type명> 식으로 해야함.
    //즉 타입 명시화 필수임 class에는
   Data<string> str_data("c++ class");
   Data<int> int_data(3232);
   Data<double> d_data(3.2345);

   cout<<"str:"<<str_data.get_data()<<endl;
   cout<<"int:"<<int_data.get_data()<<endl;
   cout<<"double:"<<d_data.get_data()<<endl;

   /*
str:c++ class
int:3232
double data 출력
double:3.2345
   */

cout<<"-----------------------------------"<<endl;
	return 0;
}

/* 
class template 특징

1. 하나 잇아 템블리 ㅅ인수를 가지는 클래스 템플릿 가능

ex : template <typename T1, int i> class ...

2. 클래스 템플릿에 디폴트 선언 가능

template <typename T=int> class...

3. 클래스 템플릿을 기초 클래스 하여 상속가능

template <typename T>
class Y : class X<T> {...}
*/