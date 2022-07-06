#include <iostream>
#include <string>
using namespace std;

//가상함수
/*
 기본 클래스 내에서 선언되어, 파생 클래스에 의해 재정의 되는 멤버 함수

 pointer 나 , reference 를 사용하여, 파생 클래스의 객채를 참조시
 해당 각체에 대해 가상 함수를 호출 -> 파생 클래스의 함수를 실행. (18장 참고)

 보통 코드 호출시 고정된 메모리 주소를 변환되나 (static)
 이 가상함수는 컴파일 타임에 해당 객체를 특정 할 수 없어서, 런 타임때 올바른 함수가 실행되도록 만들어야함. (동적 - dynamic binding)


 규칙
 1. public에 선언할 것
 2. static 일 수 없으며, friend 함수도 될 수 없음
 3. 접근시, "기본 클래스" 의 포인터나 참조를 통해 접근을 해야함
 4. 가상 함수의 프로토타입(반환형과 매개변수)은 기본 클래스와 파생 클래스에서 동일합니다.
 5. 가상 소멸자는 가능하지만, 가상 생성자는 불가능
*/

//추상 클래스 사용시, 반드시 소멸자는 virtual로 선언하는 것이 좋음


class A {
    public:
        virtual void Print() {
            cout << "A class 함수"<< endl;
        }
};

class B : public A {
    public:
        virtual void Print() {
            cout<< "B class 함수"<< endl;
        }
};

class Person {
    private:
        string name_;
        int age_;
    public:
        Person(const string& name, int age) {
            name_ = name;
            age_ = age;
        }
        virtual ~Person() {
            cout<<"~A"<<endl;
        }//가상 소멸자 -> 추상클래스 이용시 선언하면 좋음
        virtual void ShowPersonInfo();
};

void Person::ShowPersonInfo() {
    cout << name_ << "의 나이는" << age_ << "입니다." << endl;
}

class Student : public Person {
    private:
        int student_id_;
    public:
        Student(int sid, const string& name, int age) : Person(name,age) {
            student_id_= sid;
        }
        virtual void ShowPersonInfo();
        
        ~Student() {
            cout<<"~B"<<endl;
        }
};

void Student::ShowPersonInfo() {
    cout<<"학번 : "<<student_id_<<endl;
    }

/*
    순수 가상 함수 -> 보통 가상함수는 파생 클래스에서 재정의 될 것으로 기대되는 멤버 함수를 의미함.
    따라서 가상 함수는 반드시 재정의해야만 하는 함수를 의미하지 않음.
    순수 가상 함수는 "반드시 파생 클래스에서 재정의" 해야 한다는 의미를 가진 멤버 함수를 의미함

    일반적으로 순수 가상 함수는 본체에 함수 동작 정의를 정의하지 않음 -> 파생 클래스에서 재정의 해야만 사용이 가능함

    방식 : virtual 멤버함수원형=0;
*/

/*
    하나 이상 순수 가상 함수를 가진 클래스를 추상 클래스라 지칭함.
    다형성 가진 함수 집합 정의 가능

    추상 클래스는 인스턴스 생성불가. 따라서 파생 클래스에서 모두 오버라이딩하여야 비로소 파생 클래스 인스턴스 생성가능.
    단 추상 클래스의 타입의 포인터나 참조는 바로 사용 가능.
*/


class Animal {
    public:
        virtual ~Animal() {};
        virtual void Cry()=0;//순수 가상 함수
};

class Dog : public Animal {
    public :
        virtual void Cry() {
            cout<<"왈왈"<<endl;
        }
};

class Cat : public Animal {
    public :
        virtual void Cry() {
            cout<<"야옹" << endl;
        }
};


int main() {
    A* ptr;
    A obj_a;
    B obj_b;

    ptr=&obj_a;
    ptr->Print();
    ptr=&obj_b;
    ptr->Print();

    //A class 함수
    //B class 함수

    cout<<"-------------------------------------"<<endl;

    Person *hong = new Student(232132,"hi",32);
    delete hong;

    /* 출력문
    ~B
    ~A
    */

   cout<<"-------------------------------------"<<endl;

   Dog my_dog;
   my_dog.Cry();
   Cat my_cat;
   my_cat.Cry();

    /* 출력문
    왈왈
    야옹
    */


    return 0;
}