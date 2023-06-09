// ��������

/*
���� wordlistout.txt �������� � ���� 1000 ������� ����.��� ��� ���������� �� course.sgu ����� ������ 1 ����,
�� ����� ���� ��������� � � ���� ����������� �������� ���������� ����� ����� wordlistout.txt.
*/

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

#include <iostream>   //����������� ���������
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
#include <fstream>

#include <clocale>
#include <cstdlib>
#include <windows.h>
#include <sstream>
using namespace std;

int main() { 
	setlocale(LC_ALL, "RUS");       // ����������� �������� ����� 
	system("chcp 1251 >> null");    // ����������� �������� �����
	SetConsoleCP(1251);             // ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);       // ��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_CTYPE, "Russian"); // ����������� �������� �����

	ifstream fin("wordlistout.txt"); //��������� ��������� ���� �� �������
	vector <string> words;

	if (!fin.is_open())
		cout << "���� �� ����� ���� ������!" << endl;

	else {
		string line;
		string::size_type k;
		while (getline(fin, line)) {;
			words.push_back(line);      //��������� ������ ���� ����� �������
		}
	}

	vector <char> alphabet = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
		'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'}; //�������
	sort(alphabet.begin(), alphabet.end());

	string word;
	
	int score = 0;
	int wins = 0;
	int loses = 0;

	char c = 'Y';
	do {
		cout << endl;

		srand((unsigned int)time(0));
		int i = rand() % (words.size() - 1);  //�������� ��������� �����

		word = words[i];

		int k_try;
		
		cout << "�������� ������� ��������� (������� �����): " << endl << "1. �����" << endl << "2. ���������" << endl << "3. ������" << endl << "4. ����� ������" << endl << "5. ��� ������" << endl;
		string level;
		cout << "������ ���������: ";
		cin >> level;
		if (level == "1")
			k_try = 12;
		else if (level == "2")
			k_try = 8;
		else if (level == "3")
			k_try = 6;
		else if (level == "4")
			k_try = 4;
		else if (level == "5")
			k_try = 1;
		else {
			cout << "����������� ����� ������� ���������. ������ ����� ������ ��������� �� ���������." << endl;
			k_try = 12;
		}
		
		cout << "���������� �������: " << k_try << endl;

		cout << "�������� �� �������� - ���� ��������!" << endl;

		string unknownword;
		unknownword.insert(0, word.size(), '_');   //����� ����������� �����, ��� ����� �������� �� ������� ������� �� ������ _
		cout << unknownword << endl;
		cout << endl;

		string::size_type k = count(unknownword.begin(), unknownword.end(), '_'); //������� ������� ������ ��� ������������ �����

		vector <char> copyalphabet(alphabet);     //����� ��������

		while (k_try != 0) {       //���� �� ��������� ����(�������)

			cout << "�������:" << endl;
			for (auto ch : copyalphabet) { //����� ��������
				cout << ch << ' ';
			}
			cout << endl;

			char a;
			cout << "������� �����,��������� ���� ��� ����� �������: " << endl;
			cin >> a;
			a = tolower(a);    //��������� ����� �� ������ ��������
			string::size_type k, kalphabet;

			for (int i = 0; i < copyalphabet.size(); i++) {      //����������� ����� �� ��������
				if (copyalphabet[i] == a) {
					copyalphabet[i] = '-';
					break;
				}
			}

			if (word.find(a) != string::npos) {       //��� ������, ���� �������� ����� ����������� 0, 1 ��� ��������� ���
				cout << "����� " << a << " �������:" << endl; 
				k = word.find(a);    //������� ��������� ����� � �����

				while (k != string::npos) {
					unknownword.replace(k, 1, 1, a);     // � ����� ����������� �����, ������� ������� �� "_", �� ������ "_" �� ��������� �����
					k = word.find(a, k + 1);
				}
				cout << unknownword << endl; 
				cout << endl;
			}

			else if (k_try > 1) {     //���� �������� ������ 1 ����(�������)
				k_try--;
				cout << "�� ������ � ������, �������� �������: " << k_try << endl;
				cout << unknownword << endl;
				cout << endl;
			}

			else if (k_try <= 1) { //���� �������� ��������� �������
				k_try--;
				loses++;
				cout << "�� ��������!" << endl;
				cout << "���������� �����: " << word << endl;
				cout << endl;
				break;
			}

			if (count(unknownword.begin(), unknownword.end(), '_') == 0) {    //���� �� �������� ����� (��� ����������� ����� ����� ��������)
				cout << "�� �������!" << endl;
				wins++;
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

		if (c == 'Y') {   //��� ����� ���� ������ �����
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		}
		else if (c == 'N') {   //����� ����, ���� �������� N, � ����� ���������� ����� � ���������
			cout << endl << "�� ������ ��������� ����." << endl;
			cout << "���� ����������: " << endl;
			cout << "�����: " << wins << endl;
			cout << "���������: " << loses << endl;
			cout << "������� ����� ���������� " << wins * 1.0 / (wins + loses) * 100 << "%" << endl;
			cout << endl << "������� �� ����!" << endl << endl;
		}
	} while (c != 'N');


	system("pause"); // ����� � ����� ���������
	return 0;
}



/* ������ ������� ���� ��� ���� ����; ���������� � ����� wordlistout.txt
���
�������
�����
����
�����
����
����
������
�����
�����
������
����
����
������
����
�������
���
������
�������
������
�������
���
�����
���������
�����
�����
�������
��������
�����
�������
������
������
�����
���
�����
����
�������
����
����
�����
�����������
��������
���������
�����
���
�����
�������
�����
�����
��������
������
����
�������
�������
�����
����
���
������
�������
������
�����������
����
��������
�����
���
���������
�����
����
�����������
��������
��������
������
��������
��������
������������
�����
����
������
����
������
������
������
�����
�������
����
���������
���
������
�����
�����
�����
�������������
�����
�����������
������
����
�����
����
����
�����
���������
������
����������
�����
��������
������������
��������
����
����
������
�����
����
����
�������
�����
���
������
���������
�������
���������
���
����
����������
�����
����
�����
�����
��������
�������
���
����
������
����
�����
����
������
�����
��������
������
�������
��������
��������
������
�����
�����
��������
������
����
�������
�������
������
������
����
��������
����
���
�����
��������
�����
����
�������
�������
�������
���������
����������
�������
��������
��������
������
���������
�������
������
�����������
������
������
���
������������
�������
������
�����
������
���
�����
��������
�����
����
�������������
������
�������������
���
����
�������
����������
����
������
�����
�����
���������
����
���������
�����
���
���������
�����������
��������
�����
�����������
�������
�����
�������
�������
���������
�����
������
�������
�����
�������
������
�����
�������
����
���������
����
����
�������
�����
�����
������
����
������
����������
���
�������
������������
�����
���
������
������
������
����
������
������
�������
������
������
�����
�������
�������
����������
��������
�����
������
���������
�����
�������
�����
������
�������
�������
�������
�������
�����
��������
�������
����
������
�������
����������
��������
����
���������
�����������
������
����������
��������
��������
������
����
������������
������
��������
����
��
����
����
������
������
�������
�������������
����������
������������
���
��������
������
�������
������
�����
�����
�����
������
�������
������������
�������
������
����
�����������
�������
����
�����
�����
�������
��������
������
�������������
�������
�������
��������
����
�������
�������
������������
����
�����
����
���������
���������
�������
�������
����������
��������
����������
�����
��������
������
�����
���������
������
����
����
����
�����
�����
���
�����
���
����������
�������
���
����������
�������������
������
����
������
������
�������
������
����
���
�������
�������
��������
�������
�������
����������
���
�����
��������
����
�������
�������
�����������
�����
�����������
��������������
��������
����������
����
������
����
����������
������
�����
����
����
������
�����
��������
������
�������
���������
���������������
������
��������
�����
���
������
�������
�������
������
�����
��������
����������
����
������
���������
�����������
����
�������
�����
���
�����
������
�����
�����
��������
����
���������
�������
�������
�����
���������
����
�����
�������
����
�����������
�����
�����
������
������������
������
����
��������
�������
������
��
�����
���������
����
�������
���
����
����
������������
�����
����
���������
����
�������
����
�����
������
�����
���
���������
����
��������
��������
�������������
�������
�������
������
������
����
������
�����
��������
���������
��������
��������
���������
�������
������
�����
�����
���������
�������
����
�����������
�������
���������
����������
���������
���������
���������
����������
�����������
����
�������
�������
�������
�������
������������
���������
����
�������������
�������
������
�����������
���������
�����
����
��������
�������
������
���
��������
����
�������
������
������
�������
������
�����
������
��������
������
������
������
�������
����
�������
��������
��������
����
�������
����������������
�������������
�������
�����
�����
������
��������
������
������������
�����������
�����
�������
��������
������
��������
�����������
��������
����
���������
�����
������
��������
������
������
�����
������
���������
�����
�������
�������
������
�����
�����
���������
�������
����
�������
������
����
�������
�������
������
��������
�����
��������
���������
����
������
�������
������������
����
������
�����
��������
�����
����������
�����
���������
�����
�������
������������
�������
������
����
��������
����������
��������
��������
�����
�����
����
������
�����
�����
���������
����
��������������
�����
�����
���������
���������
�������
���������
���������
�����
��������
�������
��������
�����������
�����
��������
����
�����
������
�����������
�������
�������������
�����
����������
�������
��������������
�����������
���
�����
���������
����������
�������
�����
������
����
���
��������
������
����������
����������
�����
����������
����
����������
�����
������
����
����
�����
�����
�����
�������
��������
���������
������
�����������
������
��������
�������
����
�������
������
��������
��������
����
���������
����������
���������
�����������
����������
������
����
��������
����������
����
������������
����������
����
�����������
���
����
������
�����������
��������
��������������
�����
����
���
����������
������
��������
�������
����������
�������
���������
�����������
����
��������
����
��������
����������
�������
����������
������
��������������
������
�����
�������
����
�������
�������
������
��������
������
����������
������
����
�����
������
�������
������
�������
������
�������
���������
�����
�����
����
���������
����������
������
��������
���������
��������
�����������
�������
�����������
�����
�������
������������
��������
�����
����
�������
��������
�����
������
����
������
��������
�����
�������
���
���
�����
��������
���
����
�����
�����
��������
���������
������
���������
�������
������
�����
�������
���������
������
����������
��������
��������
������
�������
�����������
���������
���������
���
��������
���������
�����
�����
������
�������������
��������
�������
�����������
������������
��������
�����
���������
������
�����
��������������
����
���������
���������
�������
��������
����������
����
������
������
����
�������
�����
������
���
����
����������
��������
�������
�����
�����������
��������
���������
����������
����������
�����������
�����
�����
��������
������
����
�����
����
������
�����
�����
�������
����������
�������������
������
����
����
������
����
������
�������
������
������
����
��������
������
���������
�������
���������
�����������
����
����
�������
��������
����������
�����
�����
������
������
��������
������
�����
�����������
�������
����
�����
��������
�����
����
�����
������
�����
�����
������
�����
���������
���
������
�����
�����
��������
�����
���
�������������
�������
����
������
����
�����
�����
������
������
���������
������
�������
������
���
�����
�������
�������
����������
������
�������������
����������
�����
�����������
����
������
���������
���������
������
��������
��������
��������
����
��������
�����
�������
�����������
�����
������������
�����
�����
���������
������
�������
���������������
���������
�����
��������
����������
��������
����
���������
����
����������
�����
�����������
�����������
������
������
���
������
������
�����
��������
��������
����������
�������
�������
�����������
����������
�����
�����
�������
�������
�������
�����
������
�������������
�����
���������
�����������
��������
�����������
�������
���
��������
����������������
�������
���������
�����
����������
��������������
����������
�������������
�����������
�������
������
������
�������
��������
�������
������
�������
����
����������
�������������
����
���������
�������
��������
���������
�����
������
�����
���������
������������
����
����������
*/