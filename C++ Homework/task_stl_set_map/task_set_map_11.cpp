//11. Во входном файле задан набор слов и целых чисел, разделенных пробелами.
//Найти все слова, встречающиеся столько же раз, сколько первое число.

//подключение библиотек
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	
	setlocale(LC_ALL, "RUS");

	ifstream fin("input_set_map_11.txt");
	//можно создать файл вывода через ofstream

	if (!fin.is_open())
		cout << "Файл не может быть открыт!" << endl;

	else {
		string line;
		string numbers = "0123456789";
		string notword = numbers + ' ';
		string::size_type numbbegin, numbend, wordbegin, wordend;
		bool flag = 0;
		int countnumb = 0;
		string firstnumb;
		multiset<string> words;
		map<string, int> mapwords;

		while (getline(fin, line)) {
			cout << line << endl;
			line += ' ';
			numbbegin = line.find_first_of(numbers);
			numbend = line.find(' ', numbbegin);
			int pos = 0;
			
			wordbegin = line.find_first_not_of(notword);
			wordend = line.find(' ', wordbegin);

			while (wordbegin != string::npos) {
				string word = line.substr(wordbegin, wordend - wordbegin);
				int thiswordcount = 1;
				if (mapwords.count(word) == 0)
					mapwords.insert(make_pair(word, thiswordcount));
				else
					mapwords[word] += 1;
				wordbegin = line.find_first_not_of(notword, wordend);
				wordend = line.find(' ', wordbegin);
			}

			if (flag == 0) {
				if (numbbegin != string::npos) {
					firstnumb = line.substr(numbbegin, numbend - numbbegin);
					flag = 1;
				}
			}

			if (flag == 1) {
				while (numbbegin != string::npos) {
					if (firstnumb == line.substr(numbbegin, numbend - numbbegin)) {
						countnumb++;
					}
					numbbegin = line.find_first_of(numbers, numbend);
					numbend = line.find(' ', numbbegin);
				}
			}
		}
	
		cout << endl << firstnumb << endl;
		cout << "Таких firstnumb-чисел всего: " << countnumb << endl;

		cout << endl;

		for (map<string, int>::iterator it = mapwords.begin(); it != mapwords.end(); it++) {
			cout << it->first << ' ' << it->second << endl;
		}
		cout << endl;

		cout << "Ответ: " << endl;
		for (map<string, int>::iterator it = mapwords.begin(); it != mapwords.end(); it++) {
			if (it->second == countnumb)
				cout << it->first << endl;
		}
	}


	return 0;
}
