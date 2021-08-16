#include <iostream>;
using namespace std;

//����� ���� ���ͷ��� c++11���� �̿밡��.
//�̴� ���� �ڿ� m, km���� �ٿ� �Ÿ��� ǥ���ϰ� �Ѵٴ���, h, min���� �ٿ� �ð��� ǥ���ϰ� �ϴ� ��ó�� Ư�� ���̻縦 ���� �� �ִ� ��
//���� �����ε��� ������� ����
//���� �̴� class�� ���� �����.
//�� �̷��� ���� ���ͷ��� ����� "_"�� �ʼ��̴�. ���̴� ������.. 

//Ŭ����
class Distance {
private:
	int _value;
public :
	Distance(int value) {//������.
		_value = value;
	}
	void m() {
		cout << "meter : " << _value << "m" << endl;
	}
	void km() {
		cout << "kilometer : " << _value * 0.001 << endl;
	}
};

//��������� ���ͷ� ����
// <Ŭ������> operator"" <���ϴ� ���̻�. ����� �ʼ�>(�Ǽ��� or ������ or ������)
// �������� ���� unsigned long long �Ǽ����� long double ������

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
	Distance n1 = 13_m;//������������ Distance n1(13) Ȥ�� Distance n1=Distance(13) ���� ���̳� �̷������� �����ϰ԰���
	Distance n2 = 130_km;

	n1.m();
	n2.km();
	
	
	return 0;
}