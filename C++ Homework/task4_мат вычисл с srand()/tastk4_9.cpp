#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "n = ";
	cin >> n; // ����� ��������� �������
	int* s = new int[n];

	srand((unsigned int)time(NULL)); // ��������� ����� ���������
	for (int i = 0; i < n; i++) {
		s[i] = rand() % 10; //��������������� ����� (< 10)
		cout << s[i] << " ";
	}

	cout << endl;
	cout << endl;

	bool flag = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] % 3 != 0 && s[i] != 0 && s[i] % 2 == 0) {
			cout << "i = " << i << " (s[i] = " << s[i] << ")" << endl;
			flag = 1;
		}
	}

	if (flag == 0) {
		cout << endl;
		cout << "����� ��������� ���" << endl;
	}
	
	cout << endl;

	system("pause");
	return 0;
}