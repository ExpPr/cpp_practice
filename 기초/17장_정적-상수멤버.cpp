#include <iostream>
#include <string>

using namespace std;

//정적 멤버 변수 : 클래스 영역에서 선언. , 객체 별로 할당되지 않고 클래스의 모든 객체가 공유하는 멤버를 의미합니다.
// 정적 멤버라 해도 클래스 멤버의 접근 제한 규칙이 적용
//클래스의 멤버 함수나 프렌드만이 접근가능하나, 외부에도 접근 가능하게 만들려면 그것을 public에서 선언하면 됨.

//함수에도 static 적용가능. 이 경우, 객체이름이 아니라 클래스 이름만으로 호출

// 선언은 클래스 내부에서 하지만 초기화는 생성자 등 클래스 내부에서 진행할 수 없고 파일 영역에서 진행한다
// 이유는 전역변수와 같이 프로그램 시작 시 생성되고 프로그램 종료 시 변수가 사라지므로 객체가 생성될 때 초기화할 수 없기 때문에 파일 영역에서 초기화해야 한다.

class Person
{
private:
	string name_;
	int age_;
public:
	static int person_count_;	// 정적 멤버 변수의 선언 
    static int person_count();           // 정적 멤버 함수의 선언
	Person(const string& name, int age) {
        this->name_=name;
        age_=age;
        person_count_++;
    }	// 생성자 
	~Person() { person_count_--; }			// 소멸자 
	void ShowPersonInfo();
};

int Person::person_count_=0;//정적 멤버 변수 정의 및 초기화.


int Person::person_count()     // 정적 멤버 함수의 정의
{
    return person_count_;
}

//주의 : static 멤버 함수는 static 멤버 변수만 사용 가능
// static 멤버 함수에서 non static 멤버 변수를 사용하려고 하면 비정적 멤버는 참조가 불가능하다고 에러가 발생

//상수멤버 : 상수 멤버 변수란 한 번 초기화하면, 그 값을 변경할 수 없는 멤버 변수


class Student {
    private:
        const int m_Num;//상수 멤버 변수
        const int testnum;
        string name;
        int m_Score;

    public:
        Student();
        Student(const string& sp,int Score );
        void PrintStudent() const;
        void PrintStudent(); //참고로 위에것과 다른 함수 취급.
        Student& operator=(Student& st);
};

//상수 멤버 한번 초기화 방법 : 생성자에서 결정. 한번 결정되면 변경 불가능.
//방식 : 생성자 : 상수멤버(초기화할값) -> 멤버 이니셜라이즈
//상수 멤버가 존재하는 한 생성자에 무조건 입력 필수 

//상수 멤버 함수 : 반환타입 함수명(매개변수) const 
//상수 멤버 함수는 그 자신 함수내부에서 멤버변수들 값을 변경하지 못하도록 자체적 락기능을 검.

//만약 어떠한 객체를 const와 함께 호출햇을 경우. 그 객체는 일반 멤버 함수를 사용하지 못함.
//다만 상수객체가 아닌 객체는 상수 함수는 호출이 가능함.

Student::Student() : m_Num(10),testnum(20) {
    name="";
    m_Score=0;
}

Student::Student(const string& sp,int Score) : m_Num(10),testnum(20) {
    name=sp;
    m_Score=Score;
}

void Student::PrintStudent() const {
        cout<<"학생 번호 : "<<m_Num<<endl;
        cout<<"학생 이름 : "<<name<<endl;
        cout<<"점수 : "<<m_Score<<endl;
} // 함수 정의할 때 원형 뒤에 const 붙여야함.

void Student::PrintStudent() {
       cout<<"학생 번호 : "<<m_Num<<endl;
        cout<<"학생 이름 : "<<name<<endl;
        cout<<"점수 : "<<m_Score<<endl;
}


//주의 상수멤버변수가 선언시 일반적으로 stu1=stu2방식이 안됨. 오버로딩 연산자를 해야함!

Student& Student::operator=(Student& st) {
    name=st.name;
    m_Score=st.m_Score;
    return *this;
}


int main(void) {
    Person p1("John",20);
    Person p2("Kim",32);
    cout<<Person::person_count_<<" 번쨰사람"<<endl;

    int p=Person::person_count();//2저장.

    cout<<"-------------------------------------"<<endl;

    const Student stu1("홍길동",100);
    Student stu2("콩콩이",100);

    stu1.PrintStudent();
    stu2.PrintStudent();

    //상수함수와 일반함수가 이름이 같은경우. 상수객체이서는 상수함수를, 일반객체에선 일반 함수를 호출.
    //단 일반객체에서 일반 함수가 없으면 상수함수를 호출


    return 0;
}