// task6_13

#include <iostream>       // ���� ���������� �����-������
using namespace std;

int main() {
	
	setlocale(LC_ALL, "RUS");         // ������������� ������� ���������

	int rows, k, coef = 1, suma = 0;               
	
	cout << "������� ����� ����� ";
	cin >> rows;                     // ������ ����� ����� (�� ������� ���� ������ 10)
	cout << endl;
	cout << "������� ����� k ";
	cin >> k;             // ������ ����� k, �������� 3 ��� 7
	cout << endl;

	for(int i = 0; i < rows; i++) { 

		for (int space = 1; space <= rows - i; space++)            //��������� ������� ��� �������
			cout << " ";

		for (int j = 0; j <= i; ++j) {
			if (j == 0 || i == 0)               // ������� ������
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;            //������� ��� ��������� �����

			cout << coef << " ";
			if (k == i) {                 // ����������� ����� 2 � ������� k
				suma += coef;         // ��� ����� �� ������ ���������� ��� ����� � i-������ ������������ �������
			}
		}

		cout << endl;

	}

	cout << endl;
	cout << "��������� ����������� �������, ������� 2 � ������� k, ��� ����� " << suma << endl;          //����� ������
	cout << endl;
	system("pause");               //����� � ���������� ���������
	return 0;
}
