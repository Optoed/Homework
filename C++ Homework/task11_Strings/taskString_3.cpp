//Задачи на использование строк - 3 
//Дано предложение, записанное латинскими буквами. Вывести только те слова,
//которые можно прочитать, используя русский алфавит. Например, "МАМА, ОВЕС"

#include <iostream>      //подключение библиотек ввода-вывода
#include <string>       //подключение библиотек строк
#include <cstring>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");         //русская клавиатра

	string s;
	getline(cin, s);     //ввод строки s       
	string punct = "., ";         //разделительные знаки между словами

	string rus = "ABCEKMOPTX";       //буквы, которые есть и в русском языке
	string words;
	string::size_type k = 0, i = 0;
	cout << endl;
	k = s.find_first_of(rus);          //поиск позиции первой подходящей буквы

	s += '.';

	while (k != string::npos) {       //пока можем найти s.find_first_of(punct) 
		if (k == 0) {
			i = s.find_first_of(punct);         //позиция пробела, запятой или точки, то есть конца слова
			words = s.substr(k, i-k);         //это слово
			int count = 0;
			for (int p = 0; p < words.size(); p++) {
				if (words.find_first_of(rus, p) == p) {    //проверка, все ли буквы в слове - подходящие
					count += 1;
				}
			}
			if (count == words.size()) {     //проверка, все ли буквы в слове - подходящие
				cout << words << endl;
			}

			k = s.find_first_of(rus, i);         //поиск позиции первой подходящей буквы после i
		}
		else if (s.find_first_of(punct, k - 1) == (k - 1)) {
			i = s.find_first_of(punct, k);
			words = s.substr(k, i-k);
			int count = 0;
			for (int p = 0; p < words.size(); p++) {
				if (words.find_first_of(rus, p) == p) {          //проверка, все ли буквы в слове - подходящие
					count += 1;
				}
			}
			if (count == words.size()) {
				cout << words << endl;             //проверка, все ли буквы в слове - подходящие
			}
			 
			k = s.find_first_of(rus, i);            //поиск позиции первой подходящей буквы после i
		}
		else {
			cout << "can not research " << endl;
			k += 1;
		}
	}

	return 0;     //конец
}