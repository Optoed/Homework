//������ �� ������������� ����������� ������� - 6 - ������ ��� ��������

#include<iostream>           //����������� ��������� �����-������
using namespace std;

int H(int x, int n) {        
	int H0 = 1;
	int H1 = 2 * x;
	int H2;
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2 * x;
	}
	else {
		for (int i = 2; i <= n; i++) {
			H2 = 2 * x * H1 - 2 * n * H0;
			H0 = H1;
			H1 = H2;
		}
		return H2;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");       //������� ����������

	int x, n; //���� �����
	cout << "n = ";
	cin >> n;              //���� n
	cout << "x = ";
	cin >> x;       //���� x

	cout << endl;
	cout << "�����: " << H(x, n) << endl; //����� �������
	return 0;
}