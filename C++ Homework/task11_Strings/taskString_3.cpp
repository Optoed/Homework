//������ �� ������������� ����� - 3 
//���� �����������, ���������� ���������� �������. ������� ������ �� �����,
//������� ����� ���������, ��������� ������� �������. ��������, "����, ����"

#include <iostream>      //����������� ��������� �����-������
#include <string>       //����������� ��������� �����
#include <cstring>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");         //������� ���������

	string s;
	getline(cin, s);     //���� ������ s       
	string punct = "., ";         //�������������� ����� ����� �������

	string rus = "ABCEKMOPTX";       //�����, ������� ���� � � ������� �����
	string words;
	string::size_type k = 0, i = 0;
	cout << endl;
	k = s.find_first_of(rus);          //����� ������� ������ ���������� �����

	s += '.';

	while (k != string::npos) {       //���� ����� ����� s.find_first_of(punct) 
		if (k == 0) {
			i = s.find_first_of(punct);         //������� �������, ������� ��� �����, �� ���� ����� �����
			words = s.substr(k, i-k);         //��� �����
			int count = 0;
			for (int p = 0; p < words.size(); p++) {
				if (words.find_first_of(rus, p) == p) {    //��������, ��� �� ����� � ����� - ����������
					count += 1;
				}
			}
			if (count == words.size()) {     //��������, ��� �� ����� � ����� - ����������
				cout << words << endl;
			}

			k = s.find_first_of(rus, i);         //����� ������� ������ ���������� ����� ����� i
		}
		else if (s.find_first_of(punct, k - 1) == (k - 1)) {
			i = s.find_first_of(punct, k);
			words = s.substr(k, i-k);
			int count = 0;
			for (int p = 0; p < words.size(); p++) {
				if (words.find_first_of(rus, p) == p) {          //��������, ��� �� ����� � ����� - ����������
					count += 1;
				}
			}
			if (count == words.size()) {
				cout << words << endl;             //��������, ��� �� ����� � ����� - ����������
			}
			 
			k = s.find_first_of(rus, i);            //����� ������� ������ ���������� ����� ����� i
		}
		else {
			cout << "can not research " << endl;
			k += 1;
		}
	}

	return 0;     //�����
}