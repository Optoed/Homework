#include <iostream>   //подключение библиотек
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <time.h>
#include <numeric>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <string>
#include <cstring>

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <clocale>
#include <cstdlib>
#include <windows.h>
#include <sstream>

using namespace std;

ifstream fin("C:\\Users\\Пётр\\Desktop\\Список слов без пробелов.txt");
ofstream fout_eng("C:\\Users\\Пётр\\Desktop\\Список англ слов.txt");
ofstream fout_rus("C:\\Users\\Пётр\\Desktop\\Список рус слов.txt");
ofstream fout_gloss("C:\\Users\\Пётр\\Desktop\\Глоссарий для латеха.txt");

int main() {
	setlocale(LC_ALL, "RUS");       // Подключение русского языка 
	system("chcp 1251 >> null");    // Подключение русского языка
	SetConsoleCP(1251);             // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);       // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_CTYPE, "Russian"); // Подключение русского языка

	set<string> english;
	set<string> rus;
	set<char> eng_section;
	set<char> rus_section;

	set<string> words;
	set<char> section;

	string word;

	while (getline(fin, word)) {
		if ((word[0] <= 'Я' && word[0] >= 'А') || (word[0] <= 'я' && word[0] >= 'а') || (word[0] <= '9' && word[0] >= '0')) {
			rus.insert(word);
			rus_section.insert(word[0]);
		}
		if ((word[0] <= 'Z' && word[0] >= 'A') || (word[0] <= 'z' && word[0] >= 'a')) {
			english.insert(word);
			eng_section.insert(word[0]);
		}
		words.insert(word);
		section.insert(word[0]);
	}

	int i = 1;
	for (auto it = english.begin(); it != english.end(); it++) {
		fout_eng << i << ". " << "\\" << "textbf{" << *it << "} (\\" << "textit{}) ~--- " << endl << endl;
		i++;
	}

	for (auto it = rus.begin(); it != rus.end(); it++) {
		fout_rus << i << ". " << "\\" << "textbf{" << *it << "} (\\" << "textit{}) ~--- " << endl << endl;
		i++;
	}

	for (auto it = english.begin(); it != english.end(); it++) {
		fout_eng << *it << endl;
		i++;
	}

	for (auto it = rus.begin(); it != rus.end(); it++) {
		fout_rus << *it << endl;
		i++;
	}

	int count = 1;
	for (auto it1 = section.begin(); it1 != section.end(); it1++) {
		fout_gloss << "\\section*{" << *it1 << "}" << endl << endl;
		for (auto it2 = words.begin(); it2 != words.end(); it2++) {
			auto word = *it2;
			if (*it1 == word[0]) {
				fout_gloss << count << ". " << "\\" << "textbf{" << *it2 << "} (\\" << "textit{}) ~--- " << endl << endl;
				count++;
			}
			
		}
	}

	return 0;
}