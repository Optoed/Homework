#include <iostream> // подключение библиотек ввода-вывода
#include <cmath>       //использование математических функций
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");       //использование русской клавиатуры

	int a, b, h;
	cin >> a >> b >> h;        //ввод a,b,h

	for (a; a <= b; a += h) {
		if (a >= -1 && a <= 1) {
			cout << "при x = " << a << " Логарифм из неположительного числа" << endl;
		}
		else if (a == 2) {
			cout << "при x = " << a << " Деление на 0" << endl;
		}
		else {
			cout << "x = " << a << " функция равна " << log(a * a - 1) / sqrt(a * a - 4 * a + 4) << endl;
		}
	}

	system("pause");    //пауза
	return 0;    //завершение программы
}