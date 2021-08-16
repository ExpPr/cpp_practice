#include <iostream>;
#include <string>;//스트링 이용시 필수
#include <stdio.h>;

using std::cout;
using std::cin;
using std::endl;
//이 세개는 std중 오직 cout, cin, endl에서만 적용한드는 의미 나머지는 std::식 필요.

int main(void) {
	//string 선언방법. char[] 방식과 다르게 문자열 크기 실시간 변경 가능. 자바나 파이썬과 비슷함.

	std::string st1("Hello");
	std::string st2 = "Hi";

	cout << st1 << " " << st2 << endl;

	std::string st3 = st2;//string 복사방법

	// 메소드 총집합 
	//length() , size() : 문자열 길이 / capacity(): 객체가 메모리에서 실제로 사용하는 크기.
	cout << "st1 길이 " << st1.length() << "/ st2 길이 ㅣ " << st2.size();
	cout << "st1 객체 메모리 사용 : " << st1.capacity() << endl;

	//append

	st1 = "Welcome";
	st2 = "";
	st3 = "";

	st1.append(" C++ Programming");//기본형. 맨끝에 괄호안 문자열을 이어적음
	st2.append("C++ Programming", 4, 7);//가할 문자열의 시작 위치부터 개수만큼만 맨 끝에 추가함.
	st3.append(4, 'X');//추가할 문자를 개수만큼 맨 끝에 추가함

	//다만 append 기능만 사용할 것이면 이런 방식도 가능
	st3 += "ccc";
	std::string st4 = st3 + st2;


	cout << "\n" << st1 << "\n" << st2 << "\n" << st3 << endl;

	/*
	 st1 : Welcome C++ Programming
	 st2 : Program
	 st3 : XXXX
	*/

	cout << st1.find("Pro") << endl;//인덱스 0부터 찾을 문자[열]을 찾아, 그 시작 위치를 반환함. 
	//여러개일경우 그중 가장 가까운 것을 찾음.
	cout << st2.find('r', 3) << endl;

	//find() 메소드는 해당 문자열에서 찾을 문자열을 찾지 못하면, string::size_type의 string::npos라는 상수를 반환
	if (st1.find("Pro", 15) == std::string::npos) {
		cout << "해당 문자열을 찾지 못하였습니다" << endl;
		//string::npos == -1
	}


	//compare
	//비교대상.compare(기준). 기준보다 비교대상이 사전편찬순으로 앞이면 음수, 뒤면 양수, 완전 같으면 0
	int comp=st1.compare(st2);// 값 : 1 이 저장됨.

	//다만 c++에선 단순히 < == >으로 연산자만으로 사용이가능

	std::string str1 = "abcde";
	std::string str2 = "abcde";
	std::string str3 = "abcff";
	cout << (str1 == str2) << " " << (str1 == str3) << endl;

	//insert()
	std::string str = "012345";

	str.insert(2, "bbb"); // index가 2인 위치에 있는 문자 앞에 삽입함.
	cout << str << endl; // "01bbb2345"

	//replace()
	str = "012345";

	str.replace(2, 3, "bbb"); // index가 2인 위치에 있는 문자부터 ~ 3개의 문자를 "bbb"로 대체함
	cout << str << endl;    // "01bbb5"
	//erase()
	str = "012345";

	str.erase(1, 4);       // index 1 ~ 4 인 부분을 부분적으로 지움

	cout << str << endl;   // "05"

	//clear()
	str = "012345";

	str.clear();           // 저장되어 있는 문자열을 모두 지움

	cout << str << endl;   // ""

	//substr()
	str = "012345";

	cout << str.substr(2) << endl;    // "2345"  index 2의 위치부터 ~ 끝까지의 문자를 반환함
	cout << str.substr(2, 3) << endl;  // "234"   index 2의 위치부터 3개의 문자를 반환함
	// [] 혹은 at()
	char c = str[1];
	cout << c << endl;

	c = str.at(1); // 위와 동일한 표현
	cout << c << endl;

	//stoi() , to_string()
	//stoi() : string 인자를 받아 int로 변환 (단 받을때 문자열도 전부 숫자로만 구성)
	//to_string() : 숫자를 string으로 변환.

	str = "2000";
	int p = std::stoi(str);

	st1 = std::to_string(p);

	// toupper() tolower() : 소문자를 전부 대문자로 // 대문자를 전부 소문자로. string return 됨
	
	//isdight(), isalpha() :  문자가 숫자인지 / 영어인지 아닌지 판별해줌
	//empty()
	// 
	//swap : 두 문자열 고체
	str1 = "aaa";
	str2 = "ccc";

	str1.swap(str2);

	cout << str1 << endl; // "ccc"
	cout << str2 << endl; // "aaa"


	//맨 뒤의 문자를 pop하거나, 맨 뒤에 push 함.
	str = "abc";

	str.pop_back();
	cout << str << endl; // "ab"

	str.push_back('c');
	cout << str << endl; // "abc"


	// front() 또는 back()
	//- 맨 뒤의 문자를 반환하거나, 맨 뒤의 문자를 반환함.

	 str = "abc";

	cout << str.front() << endl; // "a"
	cout << str.back() << endl;  // "e"


	str.clear();
	// 띄어쓰기가 포함된 채로 STRING 받기
	std::getline(cin, str);
	cout << str << endl;


	return 0;
}