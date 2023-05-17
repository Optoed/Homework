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
	int imn = 0, imx = 0, jmx = 0, jmn = 0;

	for (int i = 0; i < n; i++) {               //поиск первого max в заштрихованной области
		for (int j = 0; j < n; j++) {             
			if (j <= n - i - 1) {                //выше побочной диагонали и включая её
				if (a[i][j] > mx) {
					mx = a[i][j];
					imx = i;                     //номер строки, содержащей первый max
					jmx = j;                    //номер столбца, содержащего первый max
				}
			}
		}
	}
	cout << "первый max (в заштрихованной области) = " << mx << "; позиция первого max (нумерация с 0): "<< imx << " " << jmx << endl;


	for (int i = 0; i < n; i++) {               //поиск первого минимального вне заштрихованной области
		for (int j = 0; j < n; j++) {
			if (j > n - i - 1) {
				if (a[i][j] < mn) {
					mn = a[i][j];
					imn = i;                       //номер строки, содержащей последний max
					jmn = j;
				}
			}
		}
	}
	cout << "первый min (вне этой области) = " << mn << "; позиция первого min (нумерация с 0): " << imn << " " << jmn << endl;
	cout << endl;

	//Вывод нового массива
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			if (i == imx && j == jmx) {
				a[i][j] = mn;
			}
			if (i == imn && j == jmn) {
				a[i][j] = mx;
			}
			cout << a[i][j] << " ";
		}
	}

	cout << endl;
	system("pause");           //пауза и завершение программы
	return 0;
}