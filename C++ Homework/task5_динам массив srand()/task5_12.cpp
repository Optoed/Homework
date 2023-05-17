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
	int imn = 0, imx = 0, jmx = 0, jmn = 0;

	for (int i = 0; i < n; i++) {               //����� ������� max � �������������� �������
		for (int j = 0; j < n; j++) {             
			if (j <= n - i - 1) {                //���� �������� ��������� � ������� �
				if (a[i][j] > mx) {
					mx = a[i][j];
					imx = i;                     //����� ������, ���������� ������ max
					jmx = j;                    //����� �������, ����������� ������ max
				}
			}
		}
	}
	cout << "������ max (� �������������� �������) = " << mx << "; ������� ������� max (��������� � 0): "<< imx << " " << jmx << endl;


	for (int i = 0; i < n; i++) {               //����� ������� ������������ ��� �������������� �������
		for (int j = 0; j < n; j++) {
			if (j > n - i - 1) {
				if (a[i][j] < mn) {
					mn = a[i][j];
					imn = i;                       //����� ������, ���������� ��������� max
					jmn = j;
				}
			}
		}
	}
	cout << "������ min (��� ���� �������) = " << mn << "; ������� ������� min (��������� � 0): " << imn << " " << jmn << endl;
	cout << endl;

	//����� ������ �������
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			if (i == imx && j == jmx) {
				a[i][j] = mn;
			}
			if (i == imn && j == jmn) {
				a[i][j] = mx;
			}
			cout << a[i][j] << " ";
		}
	}

	cout << endl;
	system("pause");           //����� � ���������� ���������
	return 0;
}