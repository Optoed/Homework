//������ �� ������������� ����� - 2 (������ �� ��������� � ������ ���������� - ��� ������� � ���������)
//���� �����������, ���������� ����� ����������. ����� ���� ����, ������������ � ������ �����, ��������� ���������.
// ispunct(ch)

#include <iostream>      //����������� ��������� �����-������
#include <string>       //����������� ��������� �����
#include <cstring>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");         //������� ���������

	string s;
	getline(cin, s);     //���� ������ s       
	string punct = ".,;:!?- ";

	string chr;
	getline(cin, chr);
	if (chr.size() == 1 && isalpha(chr[0])) cout << "����� ������� �����";
	else cout << "����� ������� �������" << endl;

	string::size_type k = 0, i = 0;
	cout << endl;
	k = s.find_first_of(chr);

	s += '.';

	while (k != string::npos) {       //���� ����� ����� s.find_first_of(punct) 
		if (k == 0) {
			i = s.find_first_of(punct);
			s.insert(i, 1, ':');
			k = s.find_first_of(chr, i);
			cout << i << " " << s << " " << k << endl;
		}
		else if (s.find_first_of(punct, k - 1) == (k - 1) ) {
			i = s.find_first_of(punct, k);
			if (k - i != 0) {
				s.insert(i, 1, ':');
			}
			k = s.find_first_of(chr, i);
			cout << i << " " << s  << " " << k << endl;
		}
		else {
			cout << "can not research " << s << endl;
			k += 1;
		}
	}

	s = s.substr(0, s.size() - 1);

	cout << "����� ������ ����� ��������������: " << s << endl;  //����� ������
	return 0;     //�����
}