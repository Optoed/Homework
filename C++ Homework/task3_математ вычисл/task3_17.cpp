#include <iostream> // подключение библиотек ввода-вывода
#include <cmath>       //использование математических функций
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");       //использование русской клавиатуры

	for (int i = 1; i <= 4; ++i) {

		for (int j = i; j <= i && j > 0; j -= 1) {
			cout << j << " ";
		}

		cout << "\n";

		for (int с = i; с <= i && с > 0; с -= 1) {
			cout << с * 2 << " ";
		}

		cout << "\n";
	}

	system("pause");    //пауза
	return 0;    //завершение программы
}