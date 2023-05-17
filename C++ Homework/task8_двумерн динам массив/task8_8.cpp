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

int** CreateX(int N) {    //�������� � ���������� ������� X
	cout << endl;
	int** X = new int* [N];
	for (int i = 0; i < N; i++) {
		X[i] = new int[1];
	}
	for (int i = 0; i < N; i++) {             //��������� ������
		X[i][0] = 0;
	}
	return X;
}

void Print(int** X, int N) {
	cout << "����� X:" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		cout << X[i][0] << " ";       //����� X
	}
	cout << endl;
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

	int N, n, Y;
	cout << "N = ";     //���� N - ���������� �����
	cin >> N;
	cout << "n = ";
	cin >> n;            //���� n - ���������� ��������
	cout << "Y = ";      //Y 
	cin >> Y;

	int** X = CreateX(N);      //����� ������� X
	Print(X, N); //����� X
	int** a = Create(N, n);  //����� ������� �������� � ���������� ���������� �������

	cout << endl;
	Print(a, N, n); //����� �������

	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += a[i][j];
		}
		if (sum % Y == 0) {
			n = n + 1;
			for (int i = 0; i < N; i++) {
				for (int jnew = n - 1; jnew >= j; jnew--) {
					a[i][jnew] = a[i][jnew - 1];         //������� ������
				}
				a[i][j] = X[i][0];
			}
			j += 1;
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