#include <iostream>;
using namespace std;

//사용자 지정 리터럴은 c++11부터 이용가능.
//이는 숫자 뒤에 m, km등을 붙여 거리를 표현하게 한다던지, h, min등을 붙여 시간을 표현하게 하는 것처럼 특정 접미사를 만들 수 있는 것
//산자 오버로딩의 방식으로 구현
//보통 이는 class와 같이 사용함.
//단 이렇게 만든 리터럴은 언더바 "_"가 필수이다. 없이는 사용못함.. 

//클래스
class Distance {
private:
	int _value;
public :
	Distance(int value) {//생성자.
		_value = value;
	}
	void m() {
		cout << "meter : " << _value << "m" << endl;
	}
	void km() {
		cout << "kilometer : " << _value * 0.001 << endl;
	}
};

//사용지지정 리터럴 형식
// <클래스명> operator"" <원하는 접미사. 언더바 필수>(실수형 or 정수형 or 문자형)
// 정수형은 오직 unsigned long long 실수형은 long double 만가능

Distance operator"" _m(unsigned long long value) {
	return Distance(value);
}

Distance operator"" _m(long double value) {
	return Distance(value);
}

Distance operator"" _km(unsigned long long value) {
	return Distance(value*1000.0L);
}

Distance operator"" _km(long double value) {
	return Distance(value * 1000.0L);
}

int dfefc(void) {
	Distance n1 = 13_m;//원래같앗으면 Distance n1(13) 혹은 Distance n1=Distance(13) 같은 식이나 이런식으로 간단하게가능
	Distance n2 = 130_km;

	n1.m();
	n2.km();
	
	
	return 0;
}