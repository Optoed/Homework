

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
#include <fstream>

#include <clocale>
#include <cstdlib>
#include <windows.h>

#include <sstream>
using namespace std;

int main() {

	system("chcp 1251 >> null");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_CTYPE, "Russian"); // ����������� �������� �����

	ifstream fin("wordlist.txt");
	ofstream fout("wordlistout.txt");
	vector<string> wordlist;
	string wordbook = "��������������������������������";

	if (!fin.is_open())
		cout << "���� �� ����� ���� ������!" << endl;

	else {
		string line;
		string::size_type k;
		while (getline(fin, line)) {
			k = line.find_first_of(wordbook);
			string word = line.substr(k);
			wordlist.push_back(word);
			fout << word;
			fout << endl;
		}

	}
	fout.close();
	return 0;
}