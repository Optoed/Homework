// task6_8

#include <iostream>    //����������� ���������
#include <cmath>
using namespace std;


int* createA(int n) {         //������� �������� � ���������� P(x)
	int* a = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		int koefa;
		cin >> koefa;
		a[i] = koefa;
	}
	return a;
}

int* createAnew(int* a, int n) {           //������� �������� P`(x)
	int* anew = new int[n];
	return anew;
}

void printA(int* a, int n) {                       //������� ������ P(x)
	cout << endl;
	cout << "������������ ������ ���������� P(x)" << endl;
	for (int i = 0; i < n + 1; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

void printAnew(int* anew, int n) {            //������� ������ P`(x)
	cout << endl;
	cout << "������������ ������ ���������� P'(x)" << endl;
	for (int i = 0; i < n; i++) {
		cout << anew[i] << ' ';
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");   //������������� ������� ����������

	int n;
	cout << "n = ";
	cin >> n;           //���� n
	cout << endl;

	int* a = createA(n);
	printA(a, n);

	int* anew = createAnew(a, n);

	cout << endl;
	for (int i = 0; i < n; i++) {
		anew[i] = a[i] * (n - i);           //���������� P`(x)
	}
	printAnew(anew, n);

	cout << endl;
	int* aanew = new int[n+n-1];            //������������ ���������� ������������� ����� n + (n-1)
	cout << "����: ������������ ���������� P(x) * P`(x)" << endl;
	for (int i = 0; i < n + n; i++) {
		int sum = 0;
		for (int j = 0; j < n + 1; j++) { 
			for (int k = 0; k < n; k++) {
				if ((j + k) == i) {              
					sum += a[j] * anew[k];
				}
			}
		}
		aanew[n+n-1-i-1] = sum;                   //��������� � �����
		cout << aanew[n+n-1-i-1] << ' ';
	}

	cout << endl;
	cout << endl;
	system("pause");           //����� � ���������� ���������
	return 0;
}
