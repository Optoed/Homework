// task6_3
// � ������� 3 ������ ���� ��������, ��� ����� P`(x) + P(x) ����������� ������� ����� (��� ������� = n) �� ���������,
// � ���������� � ������� ������� ����� ��� � �������� �������!


#include <iostream>    //����������� ���������
#include <cmath>
using namespace std;


int* createA(int n) {           //������� �������� � ���������� ������� ��� P(x)
	int* a = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		int koefa;
		cin >> koefa;
		a[i] = koefa;
	}
	return a;
}

int* createAnew(int* a, int n) {              //������� �������� ������� ��� P`(x)
	int* anew = new int[n + 1];
	anew[0] = 0;
	return anew;
}

void printA(int* a, int n) {           //������� ������ P(x)
	cout << endl;
	cout << "������������ ������ ���������� P(x)" << endl;
	for (int i = 0; i < n + 1; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

void printAnew(int*anew, int n) {                //������� ������ P`(x)
	cout << endl;
	cout << "������������ ������ ���������� P'(x)" << endl;
	for (int i = 0; i < n + 1; i++) {
		cout << anew[i] << ' ';
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");   //������������� ������� ����������

	int n;
	cout << "n = ";
	cin >> n;          //���� n
	cout << endl;

	int* a = createA(n);
	printA(a, n);

	int* anew = createAnew(a, n);

	cout << endl;
	for (int i = 0; i < n; i++) {
		anew[i+1] = a[i] * (n - i);               //���������� ������������� � P`(x)
	}
	printAnew(anew, n);

	cout << endl;
	int* aanew = new int[n + 1];
	cout << "����: ������������ ���������� P(x) + P`(x)" << endl;
	for (int i = 0; i < n + 1; i++) {
		aanew[i] = a[i] + anew[i];                         //����� ������������� P(x) + P`(x)
		cout << aanew[i] << ' ';
	}

	cout << endl;
	cout << endl;
	system("pause");           //����� � ���������� ���������
	return 0;
}
