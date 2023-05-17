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

	int** a = Create(N, n);  //вызов функции создания и заполнения двумерного массива

	cout << endl;
	Print(a, N, n); //вывод массива

	int count = 0;
	int* pusto = new int[n];     //создаём пустую строку
	for (int i = 0; i < n; i++) {
		pusto[i] = -999;
	}
	int k = 0;
	for (int i = 0; i < N; i++) {
		bool flag = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] <= 0) {       //проверка на наличие положительных элементов
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (int inew = i + 1; inew < N; inew++) {
				a[inew - 1] = a[inew];        //процесс удаления
			}
			i = i - 1;
			k += 1;
			N = N - 1;
			cout << k << endl;
		}

		//cout << "Вывод массива, после после удаления лишних строк" << endl;
		//for (int i = 0; i < N; i++, cout << endl) {
			//for (int j = 0; j < n; j++) {
				//cout << a[i][j] << " ";       //вывод массива
			//}
		//}
		//cout << endl;
	}

	cout << "ФИНАЛЬНЫЙ Вывод массива, после после удаления лишних строк" << endl;
	for (int i = 0; i < N; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";       //вывод массива
		}
	}
	cout << endl;

	system("pause");     //завершение программы
	return 0;
}