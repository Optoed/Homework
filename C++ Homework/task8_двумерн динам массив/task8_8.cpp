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

int** CreateX(int N) {    //создание и заполнение столбца X
	cout << endl;
	int** X = new int* [N];
	for (int i = 0; i < N; i++) {
		X[i] = new int[1];
	}
	for (int i = 0; i < N; i++) {             //заполняем массив
		X[i][0] = 0;
	}
	return X;
}

void Print(int** X, int N) {
	cout << "Вывод X:" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		cout << X[i][0] << " ";       //вывод X
	}
	cout << endl;
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

	int N, n, Y;
	cout << "N = ";     //ввод N - количества строк
	cin >> N;
	cout << "n = ";
	cin >> n;            //Ввод n - количества столбцов
	cout << "Y = ";      //Y 
	cin >> Y;

	int** X = CreateX(N);      //вызов столбца X
	Print(X, N); //вывод X
	int** a = Create(N, n);  //вызов функции создания и заполнения двумерного массива

	cout << endl;
	Print(a, N, n); //вывод массива

	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += a[i][j];
		}
		if (sum % Y == 0) {
			n = n + 1;
			for (int i = 0; i < N; i++) {
				for (int jnew = n - 1; jnew >= j; jnew--) {
					a[i][jnew] = a[i][jnew - 1];         //процесс сдвига
				}
				a[i][j] = X[i][0];
			}
			j += 1;
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