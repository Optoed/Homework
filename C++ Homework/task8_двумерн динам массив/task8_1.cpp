#include <iostream>    //подключение библиотек ввода-вывода
#include <cmath>       //подключение библиотек математических функций    
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
using namespace std;

int** Create(int N, int n) {    //создание и заполнение двумерного массива
	cout << endl;
	cout << "Введите элементы двумерного массива:" << endl;;
	int** a = new int* [N];
	for (int i = 0; i < N; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < N; i++) {             //заполняем массив
		for (int j = 0; j < n; j++) {
			int b;
			cin >> b;
			a[i][j] = b;
		}
	}
	return a;
}

void Print(int** a, int N, int n) {
	cout << "Вывод массива:" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";       //вывод массива
		}
	}
	cout << endl;
}


int main() {
	setlocale(LC_ALL, "RUS");        //использование русской клавиатуры

	int N, n;
	cout << "N = ";     //ввод N - количества строк
	cin >> N;
	cout << "n = ";
	cin >> n;            //Ввод n - количества столбцов

	cout << endl;
	cout << "Строка X = ";
	int* X = new int[n];
	for (int i = 0; i < n; i++) {
		X[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cout << X[i] << " ";
	}
	cout << endl;
	int** a = Create(N, n);  //вызов функции создания и заполнения двумерного массива
	cout << endl;

	Print(a, N, n);

	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] > 0) {
				count += 1;
			}
		}
		if (count == n) {
			N = N + 1;
			for (int inew = N - 1; inew > i; inew--) {
				a[inew] = a[inew - 1];         //процесс смещения (вставка)
			}
			a[i + 1] = X;
		}
	}
	cout << "Вывод массива, после вставки X" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";       //вывод массива
		}
	}
	cout << endl;

	system("pause");     //завершение программы
	return 0;
}