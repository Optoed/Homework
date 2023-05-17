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
	cout << "(*по условию n = 5)\n n = ";                           //размерность массива, по условию n = 5 
	cin >> n;
	int** a = new int* [n];

	for (int i = 0; i < n; i++) {          //создание массива
		a[i] = new int[n];
	}

	int t = 0;


	for (int i = 0; i < n; i++) {      
		if (i % 2 == 0) {
			for (int j = n-1; j > -1; j-=1) {
				a[i][j] = t;
				t += 1;
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				a[i][j] = t;
				t += 1;
			}
		}
	}

	cout << endl;
	cout << "ћассив" << endl; //¬ывод массива

	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}

	cout << endl;
	system("pause");           //пауза и завершение программы
	return 0;
}