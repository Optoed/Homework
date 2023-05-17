//������ �� ������������� ����������� ������� - 12

#include <iostream>           //����������� ��������� �����-������
#include <cmath>              //����������� ���������� �������������� �������
#include <cstring>            //����������� ���������� ������
using namespace std;

//����������� ������� �������� ����� �� 2-�� � 10-�� ������� ���������
long Transformation(char str[64], int position, long number, long plus) {       
	if (position < strlen(str)) {
		if (str[strlen(str) - position] == '1') {
			return Transformation(str, position + 1, number+plus, plus*2);
		}
		else if (str[strlen(str) - position] == '0') {
			return Transformation(str, position + 1, number, plus * 2);
		}
		//���� ��� ����� ��������� ����� �������������� ������� ������ 0 � 1
		else if (str[strlen(str) - position] != '0' && str[strlen(str) - position] != '1') { 
			cout << "����� � �������� ������� ��������� ���� �������� �������" << endl;
		}
	}	
	else if (position == strlen(str)) {
		if (str[strlen(str) - position] == '1') {
			cout << "Answer (����� � 10-�� ������� ���������): " << number + plus << endl;
		}
		else if (str[strlen(str) - position] == '0') {
			cout << "Answer ������ � 10-�� ������� ���������): " << number << endl;
		}
		//���� ��� ����� ��������� ����� �������������� ������� ������ 0 � 1
		else if (str[strlen(str) - position] != '0' && str[strlen(str) - position] != '1') { 
			cout << "����� � �������� ������� ��������� ���� �������� �������" << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");       //������� ����������

	long number = 0; //����� � 10-�� ������� ���������
	int position = 1;   //������� (������� ������)
	long plus = 1; //�����, ������� �� ��������� � number
	char str[64]; 
	cout << "������� ����� � �������� ������� ���������:" << endl;
	cin >> str;      //���� ����� � �������� ������� ���������

	cout << endl;
	//����� ������
	Transformation(str, position, number, plus);

	return 0; //���������� ������ ���������
}