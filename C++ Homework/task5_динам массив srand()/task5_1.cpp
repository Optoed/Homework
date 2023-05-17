#include <iostream>    //подключение библиотек
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");   //использование русской клавиатуры
	int n;
	cout << "n = ";                           //размерность массива
	cin >> n;
	int** a = new int* [n];                 

	for (int i = 0; i < n; i++) {          //создание массива
		a[i] = new int[n];
	}

	srand((unsigned int)time(NULL)); //начальная точка генерации
	cout << endl;

	cout << "Массив" << endl;
	for (int i = 0; i < n; i++, cout << endl) {        //заполнение массива
		for (int j = 0; j < n; j++) {
			a[i][j] = i + 1;
			cout << a[i][j] << " ";             //вывод начального массива
		}
	}

	for (int i = 0; i < n / 2; i++) {               //i идёт до середины (если количество строк нечётное, n/2 округляется в меньшую сторону)
		for (int j = 0; j < n; j++) {
			swap(a[i][j], a[n - i - 1][j]);              //меняем i строку с n-i-1 строкой (первую с последней, вторую с предпоследней и т.д.)
		}
	}
	cout << endl;

	cout << "Результат" << endl;
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";                        //вывод нового массива
		}
	}
	cout << endl;


	cout << endl;
	system("pause");           //пауза и завершение программы
	return 0;
}