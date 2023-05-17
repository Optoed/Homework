

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
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_CTYPE, "Russian"); // ѕодключение русского €зыка

	ifstream fin("wordlist.txt");
	ofstream fout("wordlistout.txt");
	vector<string> wordlist;
	string wordbook = "йцукенгшщзхъфывапролджэ€чсмитьбю";

	if (!fin.is_open())
		cout << "‘айл не может быть открыт!" << endl;

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