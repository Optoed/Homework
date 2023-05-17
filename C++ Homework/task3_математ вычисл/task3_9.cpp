#include <iostream> // подключение библиотек ввода-вывода
#include <cmath>       //использование математических функций
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");       //использование русской клавиатуры

	int n;
	cin >> n;       //ввод n

	for (int i = 1; i < sqrt(n); i++) {           //идём от 1 до корня из числа n
		for (int j = i + 1; j < sqrt(n); j++) {      //идём от i+1 до корня из числа n
			if ((i * i + j * j) < n) {                //условие задачи
				cout << i << " " << j << " i * i + j * j = " << i * i + j * j << endl;     //вывод
			}

		}
	}

	system("pause");    //пауза
	return 0;    //завершение программы
}