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
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";             //вывод начального массива
		}
	}
	cout << endl;

	int mn = INT_MAX;
	int mx = INT_MIN;
	int imn = 0, imx = 0;

	for (int i = 0; i < n; i++) {               //поиск первого минимума
		for (int j = 0; j < n; j++) {
			if (a[i][j] < mn) {
				mn = a[i][j];
				imn = i;                     //номер строки, содержащей первый min
			}
		}
	}
	cout <<"первый min = " << mn << "; номер содержащей первый min строки (счёт начинается с 0) равен " << imn << endl;


	for (int i = 0; i < n; i++) {               //поиск последнего максимума
		for (int j = 0; j < n; j++) {
			if (a[i][j] >= mx) {
				mx = a[i][j];
				imx = i;                       //номер строки, содержащей последний max
			}
		}
	}
	cout << "последний max = " << mx << "; номер содержащей последний max строки (счёт начинается с 0) равен " << imx << endl;

	//Меняем строки местами
	swap(a[imn], a[imx]);
	cout << endl;

	//Вывод нового массива
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}

	cout << endl;
	system("pause");           //пауза и завершение программы
	return 0;
}