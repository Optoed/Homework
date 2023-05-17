//6. Дан текст, состоящий из предложений, разделенных знаками препинания из набора «. ? !».
//Предложения в свою очередь состоят из слов, отделенных друг от друга пробелами.
//Найти слова(без учета регистра) и их количество, которые встречаются только в повествовательных предложениях.

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;
	
int main() {
	setlocale(LC_ALL, "RUS");

	string str;
	getline(cin, str);
	
	map<string, string> words;
	map<string, string> pov;
	map<string, string> vosk;
	map<string, string> vopr;
	map<string, string> nepov;

	string razd = "!?.";

	string::size_type pos = 0;
	string::size_type k = str.find_first_of(razd, pos);

	while (k != string::npos) {

		char tmp = str[k];
		string temp = str.substr(pos, k - pos);
		temp += ' ';
		string::size_type pos1 = 0;
		string::size_type k1 = temp.find(' ', pos1);

		while (k1 != string::npos) {

			string word = temp.substr(pos1, k1 - pos1);
			transform(word.begin(), word.end(), word.begin(), tolower);

			if (tmp == '.') {
				words.insert(make_pair(word, "pov"));
				pov.insert(make_pair(word, "pov"));
			}
			else if (tmp == '!') {
				words.insert(make_pair(word, "vosk"));
				vosk.insert(make_pair(word, "vosk"));
				nepov.insert(make_pair(word, "vosk"));
			}
			else if (tmp == '?') {
				words.insert(make_pair(word, "vopr"));
				vopr.insert(make_pair(word, "vopr"));
				nepov.insert(make_pair(word, "vopr"));
			}
			pos1 = k1 + 1;

			k1 = temp.find(' ', pos1);

		}
		k1 = 0;
		pos1 = 0;
		pos = k + 2;  //+2, вместо +1 так как после предложения новое начинается лишь только после пробела
		k = str.find_first_of(razd, pos);
	}

	cout << endl;
	cout << "Все слова: " << endl;

	for (map<string, string>::iterator it = words.begin(); it != words.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}
	cout << endl;

	cout << "Все 'повествовательные' слова" << endl;
	for (map<string, string>::iterator it = pov.begin(); it != pov.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}
	cout << endl;

	cout << "Все 'неповествовательные' слова" << endl;
	for (map<string, string>::iterator it = nepov.begin(); it != nepov.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}
	cout << endl;

	cout << "Ответ: " << endl;
	for (map<string, string>::iterator it = pov.begin(); it != pov.end(); it++) {
		auto x = it->first;
		if (nepov.count(x) == 0) {
			cout << x << endl;
		}
	}
	cout << endl;

	return 0;
}

