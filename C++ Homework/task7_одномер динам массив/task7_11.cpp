// ������� � �������� ��������� � ���������� ������� - ����� 11

#include <iostream>    //����������� ��������� �����-������
#include <cmath>       //����������� ��������� �������������� �������    
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");        //������������� ������� ����������
	int n, mn, x;
	cout << "n = ";
	cin >> n;           //���� ����� n
	cout << "x = ";
	cin >> x;
	int* a = new int[n];        //�������� �������

	cout << "������:\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];          //���������� �������
	}
	if (n > 0)
		mn = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] <= mn)          //����� ��������
			mn = a[i];
	}

	cout << "min-������� = " << mn << endl;

	int check = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mn && check == 0) {            //���� a[i] = mn
			n = n + 1;
			for (int j = n - 1; j > i; j--) {
				a[j] = a[j - 1];         //������� �������� (�������)
			}
			a[i + 1] = x;
			check = 1;    // ��������, ���� ����� x � mn - ���� � �� �� �����

			// ��������

			//for (int c = 0; c < n; c++) cout << a[c] << " ";
			//cout << endl;

		}
		else
			check = 0;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";    //����� ���������� ���������
	}
	cout << endl;
	system("pause");     //���������� ���������
	return 0;
}