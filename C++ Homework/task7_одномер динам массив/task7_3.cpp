#include <iostream>    //����������� ��������� �����-������
#include <cmath>       //����������� ��������� �������������� �������    
using namespace std;

int main() { 
	setlocale(LC_ALL, "RUS");        //������������� ������� ����������
	int n, k = 0, count = 0;
	cout << "n = ";
	cin >> n;           //���� ����� n
	int* a = new int[n];        //�������� �������
	for (int i = 0; i < n; i++) {          
		cin >> a[i];          //���������� �������
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {            //���� a[i] - ������, ������� ���
			for (int j = i + 1; j < n; j++) {
				a[j - 1] = a[j];          //������� �������� (��������)
			}
			a[n - k] = -99999;       
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

	system("pause");     //���������� ���������
	return 0;
}