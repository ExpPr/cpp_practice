#include <iostream>;
using namespace std;


int add(int x, int y) {
	return x + y;
}

int main(void) {
	//���� ��������: int , unsigned int , long , unsigned long, long long , float , double , long double ,short, unsigned short

	int temp1, temp2;

	int b= 10;
	//���ͷ� ���
	cout << oct;//���� ����� ���ڸ� 10������ �ƴ� 8������ ǥ����

	cout << "10�� 8���� " << b << endl;
	cout << hex;
	cout << "10�� 16���� : " << b << endl;
	cout << dec;
	cout << b << endl;//std::hex, std::dec, std::oct

	float exd = 3.12F;//���̻� . ���̻� �ȴ޸� �⺻������ ���. ������ int, �Ǽ��� double�� �⺻.
	float ecx = 3.2;
	double pi = 314e-2;//3.14ǥ���� 

	//���ڱ��� : ��������ǥ�� �̿��� ���а���. �����Ͽ� �������.
	long long i = 24'847'458'121;
	cout << i << endl;

	//������ ���ͷ�
	//nullptr : null�� ǥ���ϴ� ��, c���� 0�� �Է��޾�� ����.
	int* ptr = nullptr;

	int* a = 0;  //������

	//������� : ������
 // a�� int ���� 0���� ������ Ÿ������ �򰥸� �� ����.
	if (a == 0)
	{
		cout << "a == 0" << endl;
	}

	// a�� ������ Ÿ������ �� �� ����.
	if (a == nullptr)
	{
		cout << "a == nullptr" << endl;
	}

	//auto
	//auto�� �ʱ�ȭ���� ���ؼ� �ش� ������ ������ ������ �߷���.
	//�ʱ�ȭ ���� auto ��� �Ұ���. �׸��� auto�� �Ű������� ���Ұ���.
	auto d = 5.0;// d �� double
	auto n = 2 + 3;//n�� int
	auto sum = add(2, 21);//sum�� add�Լ� return�� int�� int�� ����

	//c++14���� auto sum(int x , int y)���� �Լ������� ��밡���ϵ��� Ȯ���.


	//�ɺ��� ���
	//����� ���ÿ� �ʱ�ȭ�� �ؾ��ϴ°��� ����. ��ũ�� �̿��ϰų� const Ű�����̿�
	
	const int ages = 20;

	//--------------------- ������
	
	char inp = 'c';//char��
	bool result = true;//bool��
	//----------------------- type ��ȯ
	// �ڵ� Ÿ�� ��ȯ : �����Ϸ��� �ڵ����� type��ȯ��.

	int num1 = 3.14;
	int num2 = 8.3E12;
	double num3 = 5;

	cout << "num 1 " << num1 << endl;

	cout << "num 2 " << num2 << endl;

	cout << "num 3 " << num3 << endl;

	//���� Ÿ�� ��ȯ
	//��� : (��ȯ��Ÿ��) ��ȯ�� ������  Ȥ��  ��ȯ�� Ÿ��(��ȯȰ ������) 
	//���ڴ� c c++ �Ѵ� ������. ���ڴ� c++�� ������.

	num1 = 1;
	num2 = 4;

	double re1 = num1 / num2;//0��µ�. �������� int�̹Ƿ�
	double re2 = (double)num1 / num2;//0.25 ���
	double re3 = double(num1 / num2);//0.25���


	return 0;
}