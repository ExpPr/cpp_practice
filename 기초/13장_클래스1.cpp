#include <iostream>
#include <string>
using namespace std;

//클래스 선언

class Book{
	private://<-private 제어 지시자는 생략가능. 범위는 오로지 그 클래스만
		int current_page_;//멤버 변수=필드
		void set_percent() {
			percent_=(double) current_page_/total_page_*100;
		}//멤버 함수=메소드
	public://나머지 제어 지시자 생략 불가능
		Book(const string &title="웹 프로그래밍",int total_page=100){//생성자 + default 인수
			title_=title;
			total_page_=total_page;
			current_page_=0;
			set_percent();

		}
		//생성자를 이렇게 직접 제시하지 않으면. 컴파일러가 자동으로 디폴트 생성자를 생성함 . 원형 Book() {}
		//단 사용자가 직접 만들수도 있음

		//Book(const string &title="웹 프로그래밍",int total_page=100); default 생성자 직접 생성. 그중 default 인수를 이용하는 방법.
		string title_;
		int total_page_;
		double percent_;
		//메소드는 모든 인스턴스가 공유함. 필드만 각 개체마다 다르게 적용.
		const Book& ThickerBook(const Book& comp_book);
		void move(int page);
		void Open();
		void Read();
		Book(const Book& origin);//복사 생성자
		~Book();//소멸자.
		//소멸자 특징 : 인수 안가짐. 반환값 없지만 void형 선언이 아님. 객체 소멸자는 단 한개만 가질수 있음.
		//const volaltile static으로 선언불가. 단 const, volaltile static 등으로 선언된 객체의 소멸은 가능.
};//세미클론 필수

//외부에서 클래스 메소드 지정방법
//반환타입 클래스명::메소드이름(매개변수) {... 명령어}

void Book::move(int page) {
	current_page_=page;
}

const Book& Book::ThickerBook(const Book& comp_book) {
	if (comp_book.total_page_>this->total_page_) {
		return comp_book;
	}
	else
		return *this;//이때는 자기 클래스 자체를 나타내는 this.
		//this는 자기 객체 클래스 그 자체의 포인터임.
}

Book::Book(const Book& origin) {//복사 생성자 설정.
	title_=origin.title_;
	total_page_=origin.total_page_;
	current_page_=origin.current_page_;
	percent_=origin.current_page_;

}
Book::~Book() {
	cout<<"Book 객체 소멸"<<endl;
}

int main(void) {
	//default 생성자 호출방법
	Book web_book1;
	Book web_book2=Book();
	Book *ptr_book3=new Book;

	//복사 생성자 이용
	Book copy_book(web_book1);
	
	cout<<ptr_book3->percent_<<endl;
	return 0;
}

