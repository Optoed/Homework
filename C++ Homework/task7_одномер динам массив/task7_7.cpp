// ������� � �������� ��������� � ���������� ������� - ����� 7

#include <iostream>    //����������� ��������� �����-������
#include <cmath>       //����������� ��������� �������������� �������    
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");        //������������� ������� ����������
	int n, k = 0, count = 0, mx;
	cout << "n = ";
	cin >> n;           //���� ����� n
	int* a = new int[n];        //�������� �������
	for (int i = 0; i < n; i++) {
		cin >> a[i];          //���������� �������
	}
	if (n > 0)
		mx = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] >= mx)          //����� ���������
			mx = a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == mx) {            //���� a[i] = max
			for (int j = i + 1; j < n; j++) {
				a[j - 1] = a[j];          //������� �������� (��������)
			}
			k += 1;
			i -= 1;

			// ��������

			//for (int c = 0; c < n; c++) cout << a[c] << " "
			//cout << "k = " << k << endl;
			//cout << endl;

		}
		count += 1;
		if (count == n) {
			n -= k;
			break;
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";    //����� ���������� ���������
	}
	cout << endl;
	system("pause");     //���������� ���������
	return 0;
}