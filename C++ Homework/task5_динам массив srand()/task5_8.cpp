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
	cout << "n = ";                           //����������� �������
	cin >> n;
	int** a = new int* [n];

	for (int i = 0; i < n; i++) {          //�������� �������
		a[i] = new int[n];
	}

	srand((unsigned int)time(NULL)); //��������� ����� ���������
	cout << endl;

	cout << "������" << endl;
	for (int i = 0; i < n; i++, cout << endl) {        //���������� �������
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";             //����� ���������� �������
		}
	}
	cout << endl;

	int mn = INT_MAX;
	int mx = INT_MIN;
	int imn = 0, imx = 0;

	for (int i = 0; i < n; i++) {               //����� ������� ��������
		for (int j = 0; j < n; j++) {
			if (a[i][j] < mn) {
				mn = a[i][j];
				imn = i;                     //����� ������, ���������� ������ min
			}
		}
	}
	cout <<"������ min = " << mn << "; ����� ���������� ������ min ������ (���� ���������� � 0) ����� " << imn << endl;


	for (int i = 0; i < n; i++) {               //����� ���������� ���������
		for (int j = 0; j < n; j++) {
			if (a[i][j] >= mx) {
				mx = a[i][j];
				imx = i;                       //����� ������, ���������� ��������� max
			}
		}
	}
	cout << "��������� max = " << mx << "; ����� ���������� ��������� max ������ (���� ���������� � 0) ����� " << imx << endl;

	//������ ������ �������
	swap(a[imn], a[imx]);
	cout << endl;

	//����� ������ �������
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}

	cout << endl;
	system("pause");           //����� � ���������� ���������
	return 0;
}