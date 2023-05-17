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

	cout << endl;
	cout << "������ X = ";
	int* X = new int[n];
	for (int i = 0; i < n; i++) {
		X[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cout << X[i] << " ";
	}
	cout << endl;
	int** a = Create(N, n);  //����� ������� �������� � ���������� ���������� �������
	cout << endl;

	Print(a, N, n);

	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] > 0) {
				count += 1;
			}
		}
		if (count == n) {
			N = N + 1;
			for (int inew = N - 1; inew > i; inew--) {
				a[inew] = a[inew - 1];         //������� �������� (�������)
			}
			a[i + 1] = X;
		}
	}
	cout << "����� �������, ����� ������� X" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";       //����� �������
		}
	}
	cout << endl;

	system("pause");     //���������� ���������
	return 0;
}