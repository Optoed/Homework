//������ �� ������������� ����������� ������� - 17

#include<iostream>
#include<cmath>
using namespace std;

void printINT(int n, int a) { //������ n �������� a
	for (int i = 0; i < n; i++)
		cout << a;
}
void printCHAR(int n, char a) { //������ n �������� a
	for (int i = 0; i < n; i++)
		cout << a;
}

void F(int p, int n, int N) { // p - �����, n - ��������
	if (n > 0 && p <= N) {
		printINT(p, p); //������ ����
		printCHAR(n, '-'); //������ �������
		printINT(p, p); //������ ����
		cout << endl; //������� �� ��������� ������
		F(p + 1, n - 2, N); //����� ������� ��� ��������� ������
		printINT(p, p);
		printCHAR(n, '-'); //������ �����
		printINT(p, p);
		cout << endl;
	}

	else if (n == 0 && p <= N) {
		printINT(8, p); //������ ����
		cout << endl; //������� �� ��������� ������
		F(p + 1, n, N); //����� ������� ��� ��������� ������
		printINT(8, p); //������ ����
		cout << endl;
	}
}

int main() {
	bool flag = 0;
	int N;
	cout << "N = ";
	cin >> N;
	cout << endl;
	int n = 6;
	int count = 1;
	int p = 1;
	F(1, n, N); //����� �������
	return 0;
}
