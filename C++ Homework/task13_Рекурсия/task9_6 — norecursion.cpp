//Задачи на использование рекурсивных функций - 6 - способ без рекурсии

#include<iostream>           //подключение библиотек ввода-вывода
using namespace std;

int H(int x, int n) {        
	int H0 = 1;
	int H1 = 2 * x;
	int H2;
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2 * x;
	}
	else {
		for (int i = 2; i <= n; i++) {
			H2 = 2 * x * H1 - 2 * n * H0;
			H0 = H1;
			H1 = H2;
		}
		return H2;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");       //русская клавиатура

	int x, n; //ввод чисел
	cout << "n = ";
	cin >> n;              //ввод n
	cout << "x = ";
	cin >> x;       //ввод x

	cout << endl;
	cout << "Ответ: " << H(x, n) << endl; //вызов функции
	return 0;
}