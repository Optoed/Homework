// Виселица

/* DONE - 1) Реализуйте аналог игры "Виселица":
 * DONE - 2) Создать контейнер, содержащий алфавит, и определяющий, угадывалась ли данная буква.
 * DONE - 3) Сгенерируйте слово, заменив буквы подчеркиванием, и запрашивайте у пользователя букву.
 * DONE - 4) Если буква угадана, выводите ее на нужном месте.
 * DONE - 5) В любой момент пользователь может набрать все слово целиком (должна быть предоставлена такая возможность).
 * 6) Должен быть счетчик ходов и определено максимальное число ходов.
 * 7) Если слово не угадано за максимальное число ходов - выводится сообщение о проигрыше, если угадано - о победе.
 * 8) Желательно вывести алфавит и зачеркивать уже выбранные буквы.
 * 9) Можно попробовать вместо максимального числа ходов нарисовать виселицу(это необязательно)
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

	vector <char> alphabet = { 'й', 'ц', 'у', 'к', 'е', 'н', 'г', 'ш', 'щ', 'з', 'х', 'ъ', 'ф', 'ы', 'в',
		'а', 'п', 'р', 'о', 'л', 'д', 'ж', 'э', 'я', 'ч', 'с', 'м', 'и', 'т', 'ь', 'б', 'ю' };
	sort(alphabet.begin(), alphabet.end());

	vector <string> words = { "ксюша", "петя", "саша", "санечка", "юра", "егор", "данил", "ксюшасамаялучшая" };
	string word;

	char c = 'Y';
	do {
		cout << endl;
		cout << "СПАСАЙСЯ ОТ ВИСЕЛИЦЫ - ИГРА НАЧАЛАСЬ!" << endl;

		srand((unsigned int)time(0));

		int i = rand() % (words.size() - 1);
		word = words[i];
		//cout << word << endl;

		int k_try = 7;
		//cout << "Выберете уровень сложности (введите цифру или слово): " << endl << "1. Легко" << endl << "2. Нормально" << endl << "3. Сложно" << endl << "4. Без шансов" << endl;
		cout << "Количество попыток = " << k_try << endl;

		string unknownword;
		unknownword.insert(0, word.size(), '_');
		cout << unknownword << endl;
		cout << endl;

		string::size_type k = count(unknownword.begin(), unknownword.end(), '_');


		while (k_try != 0) {

			char a;
			cout << "Введите букву: " << endl;
			cin >> a;
			string::size_type k;
			
			//добавить проверку a в начале каждого цикла

			if (word.find(a) != string::npos) {
				cout << "Буква " << a << " найдена" << endl;
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
				cout << "Ты ошибся с буквой, осталось попыток: " << k_try << endl;
				cout << endl;
			}

			else if (k_try <= 1) {
				k_try--;
				cout << "Ты проиграл!" << endl;
				cout << "Загаданное слово: " << word << endl;
				cout << endl;
				break;
			}

			if (count(unknownword.begin(), unknownword.end(), '_') == 0) {
				cout << "Ты победил!" << endl;
				cout << "Загаданное слово: " << word << endl;
				cout << endl;
				break;
			}
			

		}


		cout << "Введите Y - если хотите сыграть ещё раз или N - если нет: " << endl;
		cin >> c;

		while (c != 'Y' && c != 'N') {
			cin >> c;
		}

		cout << endl << endl << endl << endl << endl << endl << endl << endl;

	} while (c != 'N');


	system("pause");
	return 0;
}