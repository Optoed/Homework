#include <iostream> // ����������� ��������� �����-������
#include <cmath>       //������������� �������������� �������
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");       //������������� ������� ����������

	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= i; j-=1) {
			cout << j << endl;
		}
	}

	system("pause");    //�����
	return 0;    //���������� ���������
}