#include <iostream>
#include <string>

using namespace std;

//상속 : 기존 클래스 모든 멤버 변수와 멤버 함수를 물려 받아 새로운 클래스를 작성하는 것
//기존 클래스 : 부모 클래스 , 상속받은 클래스 : 자식 클래스
//장점 - 재활용 및 중복제거

//문법 : class 파생클래스이름 : 접근제어지시자 기초클래스이름 [접근제어지시자 기초클래스 이름]...

//
//접근제한자 지정을 private이면 부모 클래스의 모든 멤버 를 상속함
//접근제한자 지정을 protected 이면 부모 클래스의 protected, public 의 멤버만 상속함
//public이면 public만 상속함 

//파생 클래스엔 반드시 자신만의 생성자가 필수임
//파생 클래스에는 기초 클래스의 접근할 수 있는 모든 멤버 변수들이 저장(private는 접근불가)
//파생 클래스는 기초 클래스의 접근할 수 있는 모든 멤버 함수를 사용할 수 있습니다. (private 접근불가)
//파생 클래스에는 필요한 만큼 멤버를 추가할 수 있습니다.

//person 클래스 : 부모, student : 자식

class Person {
    private:
        string name_;
        int age_;
    public:
        Person(const string& name, int age) {
            name_ = name;
            age_ = age;
        }
        virtual void ShowPersonInfo();
};

void Person::ShowPersonInfo() {
    cout << name_ << "의 나이는" << age_ << "입니다." << endl;
}

class Student : public Person {
    private:
        int student_id_;
    public:
        Student(int sid, const string& name, int age);
        void ShowPersonInfo();
};

//파생클래스 생성자 지정시 끝에 :부모클래스이름(생성자에 쓰이는 파라미터들) 을 추가해야함
Student::Student(int sid, const string& name, int age):Person(name, age) {

    student_id_ = sid;
}

//파생 클래스 객세 생성 순서
/*
1. 파생 클래스의 객체를 생성하면, 프로그램은 제일 먼저 기초 클래스의 생성자를 호출합니다
    이때 기초 클래스 생성자는 상속받은 멤버 변수의 초기화를 진행합니다.
2. 그리고서 파생 클래스의 생성자가 호출됩니다.
3. 반대로 파생 클래스의 수명이 다하면, 먼저 파생 클래스의 소멸자가 호출되고, 그 후에 기초 클래스의 소멸자가 호출됩니다.
*/

//오버라이딩 : 오버라이딩이란 멤버 함수의 동작만을 재정의하는 것이므로, 함수의 원형은 기존 멤버 함수의 원형과 같아야 합니다.

//파생 클래스에서 오버라이딩 첫번째방법. 
// ->문제점 : 포인터 변수를 이용할 경우, 파생클래스에 관한 데이터가 아닌 부모 클래스 데이터가 나옴
// 이유 : 부모 객체를 가리키는 포인터 변수는 부모클래스 객체 멤버 함수만 호출할 수 있으므로.
void Student::ShowPersonInfo() {
    cout<< "이 학생의 학번은"<<student_id_<<"입니다."<<endl;
}


//파생 클래스에서 두번째 방법 : virtual 
//부모 클래스에서 상속할 멤버함수를 virtual 입력하여 가상 함수를 만들어서 , 

class Student2 : public Person {
    private:
        int student_id_;
    public:
        Student2 (int sid, const string& name, int age) : Person(name,age) {
            student_id_=sid;
        };
        virtual void ShowPersonInfo();
};

void Student2::ShowPersonInfo() {
    cout<< "이 학생의 학번은"<<student_id_<<"입니다."<<endl;
}

int main(void) {
    Student hong(12345678, "길동",12);
    hong.ShowPersonInfo();
    hong.Person::ShowPersonInfo();

    /* 출력문
    이 학생의 학번은 123456789입니다.
    길동의 나이는 35살입니다.
    */

   Person *ptr_person;
   Person lee("순신",35);

    cout<<"----"<<endl;
   ptr_person = &lee;
   ptr_person->ShowPersonInfo();
   ptr_person=&hong;
   ptr_person->ShowPersonInfo();

   Student2 kim(87654321,"의지",32);

    /* 출력문
    순신의 나이는 35살입니다.
    길동의 나이는 29살입니다. -> 단 이건 부모 클래스에 virtual 선언 안한 경우
    */
   //-> 버추얼 선언시 부모클래스에, "이 학생의 학번은 123456789입니다." 로 나옴"

   ptr_person=&kim;
    ptr_person->ShowPersonInfo();
    //이 학생의 학번은 87654321 입니다.



    return 0;
}