#include <iostream>;
using namespace std;//�� �ڵ�� std::cout ���� �������� ������ ������ (�� std ���õ� �� �ѿ�����)

int main(void) {
	cout << "Hello world\n" << endl;//endl : ������ std::endl, �ٹٲ� + ���ۺ��� (flush) ���.
	cout << "First line " << flush;// ���� ��쳪 �ٹٲ��� ����
	cout << "Second line" << endl;

	int age;//��������
	cout << "your age :";
	cin >> age;

	cout << "your age is " << age << endl;
}