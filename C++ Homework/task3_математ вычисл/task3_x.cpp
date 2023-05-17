#include <iostream> // подключение библиотек ввода-вывода
#include <cmath>       //использование математических функций
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");       //использование русской клавиатуры

	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= i; j-=1) {
			cout << j << endl;
		}
	}

	system("pause");    //пауза
	return 0;    //завершение программы
}