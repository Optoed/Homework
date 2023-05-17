#include <iostream>    //����������� ���������
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");   //������������� ������� ����������
	int n;
	cout << "n = ";
	cin >> n;                //����� ��������� �������
	int* s = new int[n];       

	srand((unsigned int)time(NULL)); //��������� ����� ���������
	for (int i = 0; i < n; i++) {
		s[i] = rand() % 10; //��������������� ����� (< 10)
		cout << s[i] << " ";
	}

	cout << endl;
	cout << endl;

	int mx = INT_MIN;
	bool flag = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] > mx && s[i] % 2 == 0) {
			mx = s[i];
			flag = 1;        //�������� �� ������� ������� �������� � �������
		}
	}

	cout <<"������������ ������ ������� ����� " << mx << endl;

	for (int i = 0; i < n; i++) {
		if (flag == 1) {                  //�������� �� ������� ������������� ������� �������� � �������
			if (s[i] == mx) {
				s[i] = s[i] * 2;       //�������� ������������� �������
			}
			cout << s[i] << " ";
		}
		else {
			cout << endl;
			cout << "����� ��������� ���" << endl;
			break;
		}
	}

	cout << endl;
	cout << endl;

	system("pause");      
	return 0;
}