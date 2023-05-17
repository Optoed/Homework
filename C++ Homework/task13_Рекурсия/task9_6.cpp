//Задачи на использование рекурсивных функций - 6

#include<iostream>           //подключение библиотек ввода-вывода
using namespace std;

int H(int x, int n) {
	if (n == 0) {
		return 1; 
	}
	if (n == 1) {
		return 2*x; 
	}
	else {
		return 2*x*H(x,n-1)-2* (n-1) * H(x, n - 2);
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