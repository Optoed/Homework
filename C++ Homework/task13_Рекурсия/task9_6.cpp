//������ �� ������������� ����������� ������� - 6

#include<iostream>           //����������� ��������� �����-������
using namespace std;

int H(int x, int n) {
	if (n == 0) {
		return 1; 
	}
	if (n == 1) {
		return 2*x; 
	}
	else {
		return 2*x*H(x,n-1)-2* (n-1) * H(x, n - 2);
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