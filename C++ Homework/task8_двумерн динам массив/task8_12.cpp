#include <iostream>    //����������� ��������� �����-������
#include <cmath>       //����������� ��������� �������������� �������    
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
using namespace std;

int** Create(int N, int n) {    //�������� � ���������� ���������� �������
	cout << endl;
	cout << "������� �������� ���������� �������:" << endl;;
	int** a = new int* [N];
	for (int i = 0; i < N; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < N; i++) {             //��������� ������
		for (int j = 0; j < n; j++) {
			int b;
			cin >> b;
			a[i][j] = b;
		}
	}
	return a;
}

void Print(int** a, int N, int n) {
	cout << "����� �������:" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";       //����� �������
		}
	}
	cout << endl;
}


int main() {
	setlocale(LC_ALL, "RUS");        //������������� ������� ����������

	int N, n;
	cout << "N = ";     //���� N - ���������� �����
	cin >> N;
	cout << "n = ";
	cin >> n;            //���� n - ���������� ��������

	int** a = Create(N, n);  //����� ������� �������� � ���������� ���������� �������

	cout << endl;
	Print(a, N, n); //����� �������

	int count = 0;
	int* pusto = new int[n];     //������ ������ ������
	for (int i = 0; i < n; i++) {
		pusto[i] = -999;
	}
	int k = 0;
	for (int i = 0; i < N; i++) {
		bool flag = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] <= 0) {       //�������� �� ������� ������������� ���������
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (int inew = i + 1; inew < N; inew++) {
				a[inew - 1] = a[inew];        //������� ��������
			}
			i = i - 1;
			k += 1;
			N = N - 1;
			cout << k << endl;
		}

		//cout << "����� �������, ����� ����� �������� ������ �����" << endl;
		//for (int i = 0; i < N; i++, cout << endl) {
			//for (int j = 0; j < n; j++) {
				//cout << a[i][j] << " ";       //����� �������
			//}
		//}
		//cout << endl;
	}

	cout << "��������� ����� �������, ����� ����� �������� ������ �����" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";       //����� �������
		}
	}
	cout << endl;

	system("pause");     //���������� ���������
	return 0;
}