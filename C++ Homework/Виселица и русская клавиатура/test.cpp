// ��������

/* DONE - 1) ���������� ������ ���� "��������":
 * DONE - 2) ������� ���������, ���������� �������, � ������������, ����������� �� ������ �����.
 * DONE - 3) ������������ �����, ������� ����� ��������������, � ������������ � ������������ �����.
 * DONE - 4) ���� ����� �������, �������� �� �� ������ �����.
 * DONE - 5) � ����� ������ ������������ ����� ������� ��� ����� ������� (������ ���� ������������� ����� �����������).
 * 6) ������ ���� ������� ����� � ���������� ������������ ����� �����.
 * 7) ���� ����� �� ������� �� ������������ ����� ����� - ��������� ��������� � ���������, ���� ������� - � ������.
 * 8) ���������� ������� ������� � ����������� ��� ��������� �����.
 * 9) ����� ����������� ������ ������������� ����� ����� ���������� ��������(��� �������������)
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <time.h>
#include <numeric>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>

#include <clocale>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	system("chcp 1251 >> null");

	vector <char> alphabet = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
		'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	sort(alphabet.begin(), alphabet.end());

	vector <string> words = { "�����", "����", "����", "�������", "���", "����", "�����", "����������������" };
	string word;

	char c = 'Y';
	do {
		cout << endl;
		cout << "�������� �� �������� - ���� ��������!" << endl;

		srand((unsigned int)time(0));

		int i = rand() % (words.size() - 1);
		word = words[i];
		//cout << word << endl;

		int k_try = 7;
		//cout << "�������� ������� ��������� (������� ����� ��� �����): " << endl << "1. �����" << endl << "2. ���������" << endl << "3. ������" << endl << "4. ��� ������" << endl;
		cout << "���������� ������� = " << k_try << endl;

		string unknownword;
		unknownword.insert(0, word.size(), '_');
		cout << unknownword << endl;
		cout << endl;

		string::size_type k = count(unknownword.begin(), unknownword.end(), '_');


		while (k_try != 0) {

			char a;
			cout << "������� �����: " << endl;
			cin >> a;
			string::size_type k;
			
			//�������� �������� a � ������ ������� �����

			if (word.find(a) != string::npos) {
				cout << "����� " << a << " �������" << endl;
				k = word.find(a);
				while (k != string::npos) {
					unknownword.replace(k, 1, 1, a);
					k = word.find(a, k + 1);
				}
				cout << unknownword << endl;
				cout << endl;
			}

			else if (k_try > 1) {
				k_try--;
				cout << "�� ������ � ������, �������� �������: " << k_try << endl;
				cout << endl;
			}

			else if (k_try <= 1) {
				k_try--;
				cout << "�� ��������!" << endl;
				cout << "���������� �����: " << word << endl;
				cout << endl;
				break;
			}

			if (count(unknownword.begin(), unknownword.end(), '_') == 0) {
				cout << "�� �������!" << endl;
				cout << "���������� �����: " << word << endl;
				cout << endl;
				break;
			}
			

		}


		cout << "������� Y - ���� ������ ������� ��� ��� ��� N - ���� ���: " << endl;
		cin >> c;

		while (c != 'Y' && c != 'N') {
			cin >> c;
		}

		cout << endl << endl << endl << endl << endl << endl << endl << endl;

	} while (c != 'N');


	system("pause");
	return 0;
}