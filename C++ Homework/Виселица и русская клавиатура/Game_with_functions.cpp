// ��������

/* DONE - 1) ���������� ������ ���� "��������":
 * DONE - 2) ������� ���������, ���������� �������, � ������������, ����������� �� ������ �����.
 * DONE - 3) ������������ �����, ������� ����� ��������������, � ������������ � ������������ �����.
 * DONE - 4) ���� ����� �������, �������� �� �� ������ �����.
 * DONE - 5) � ����� ������ ������������ ����� ������� ��� ����� ������� (������ ���� ������������� ����� �����������).
 * DONE - 6) ������ ���� ������� �����(�������) � ���������� ������������ ����� �����(�������).
 * DONE - 7) ���� ����� �� ������� �� ������������ ����� ����� - ��������� ��������� � ���������, ���� ������� - � ������.
 * DONE - 8) ���������� ������� ������� � ����������� ��� ��������� �����.
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

	vector <string> words = { "�����", "����", "����", "�������", "���", "����", "�����" };
	string word;

	char c = 'Y';
	do {
		cout << endl;

		srand((unsigned int)time(0));

		int i = rand() % (words.size() - 1);
		word = words[i];

		int k_try;
		cout << "�������� ������� ��������� (������� ����� ��� �����): " << endl << "1. �����" << endl << "2. ���������" << endl << "3. ������" << endl << "4. ����� ������" << endl << "5. ��� ������" << endl;
		string level;
		cout << "������ ���������: ";
		getline(cin, level);
		if (level == "1" || level == "�����")
			k_try = 8;
		else if (level == "2" || level == "���������")
			k_try = 6;
		else if (level == "3" || level == "������")
			k_try = 4;
		else if (level == "4" || level == "����� ������")
			k_try = 2;
		else if (level == "5" || level == "��� ������")
			k_try = 1;
		else {
			cout << "����������� ����� ������� ���������. ������ ����� ������ ��������� �� ���������." << endl;
			k_try = 8;
		}

		cout << "���������� �������: " << k_try << endl;

		cout << "�������� �� �������� - ���� ��������!" << endl;

		string unknownword;
		unknownword.insert(0, word.size(), '_');
		cout << unknownword << endl;
		cout << endl;

		string::size_type k = count(unknownword.begin(), unknownword.end(), '_');

		vector <char> copyalphabet(alphabet);

		while (k_try != 0) {

			cout << "�������:" << endl;
			for (auto ch : copyalphabet) {
				cout << ch << ' ';
			}
			cout << endl;

			char a;
			cout << "������� ����� ��� �����: " << endl;
			cin >> a;
			string::size_type k, kalphabet;

			//�������� �������� a � ������ ������� �����

			if (word.find(a) != string::npos) {
				cout << "����� " << a << " �������:" << endl;
				k = word.find(a);

				for (int i = 0; i < copyalphabet.size(); i++) {
					if (copyalphabet[i] == a) {
						copyalphabet[i] = '-';
						break;
					}
				}

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

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	} while (c != 'N');


	system("pause");
	return 0;
}