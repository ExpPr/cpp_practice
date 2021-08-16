#include <iostream>
using namespace std;

//���ǽ�
//1. if -else

int main(void) {

	int a = 1;

	if (a > 5) {
		cout << "Big" << endl;
	}
	else if (a == 5) {
		cout << "same" << endl;
	}
	else {
		cout << "small" << endl;
	}
	//���� �����ڸ� �� �������� ����ϴ� ���.
	(a > 5) ? (cout << "Big" << endl) : (a == 5) ? (cout << "same" << endl) : (cout << "small" << endl);


	//switch

	//c������ ���� ������ ����������. c++������ char / short / int / ����ü ��� �� ����� ����

	switch (a) {
	case 1:
		cout << "1a" << endl;
		break;
	case 2:
		cout << "2a" << endl;
		break;
	case 3:
		cout << "3a" << endl;
		break;
	case 4:
		cout << "4a" << endl;
		break;
	default:
		cout << "1~4 �ܼ̿�����" << endl;
	}
	char ch = 'a';
	switch (ch) {
	case 'a':
	case 'A':
		cout << "�� �л� ������ A" << endl;
		break;
	default:
		cout << "������" << endl;
	}

	//------------------------------------------------------ �ݺ���

	//while

	int i = 0, num = 5;

	while (i < num) {
		cout << "���� " << ++i << "��° �ݺ���" << endl;
	}
	i = 0, num = 5;
	do {
		cout << "���� " << ++i << "��° �ݺ���" << endl;
	} while (i < num);//do-while���� ���� ����Ŭ�� �ʼ���.. ����!

	//for

	//for (�ʱ��;���ǽ�;������) {} ���
	cout << "===================================================================" << endl;
	for (i = 0; i < 5; i++) {
		cout << "���� " << i+1 << "��° �ݺ���" << endl;
	}
	//���� for�� �� ������ ����� �ʱ�ȸ�� ������ for���ۿ� �̹� �����ϴ� ������ �ƴѰ��, �ʱ�� �� ������ ������ for���ȿ����� ��밡��

	//for�� ��� �迭�� ������ ����
	int arr[5] = { 1,2,3,4,5 };
	for (int ele : arr) {
		cout << ele << " for (:)����" << endl;
	}

	//break �� continue, goto�� ��ŵ

	return 0;
}