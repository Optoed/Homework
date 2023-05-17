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
	cout << "n = ";
	cin >> n;                //число эпементов массива
	int* s = new int[n];

	srand((unsigned int)time(NULL)); //начальная точка генерации
	for (int i = 0; i < n; i++) {
		s[i] = rand() % 10; //псевдослучайное число (< 10)
		cout << s[i] << " ";
	}

	cout << endl;
	cout << endl;

	int mx = INT_MIN;
	int mn = INT_MAX;
	bool flagmx = 0;
	bool flagmn = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] > mx && s[i] % 2 == 0) {
			mx = s[i];
			flagmx = 1;        //проверка на наличие чётного элемента в массиве
		}
		if (s[i] < mn && s[i] % 2 != 0) {
			mn = s[i];
			flagmn = 1;       //проверка на наличие нечётного элемента в массиве
		}
	}

	cout << "Максимальный чётный элемент равен " << mx << endl;
	cout << "Минимальный нечётный элемент равен " << mn << endl;
	cout << endl;
	int a, b, ai, bi;

	for (int i = 0; i < n; i++) {
		if (flagmx == 1) {                  //проверка на наличие максимального чётного элемента в массиве
			if (s[i] == mx) {
				a = s[i];
				ai = i;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (flagmx == 1) {                  //проверка на наличие минимального нечётного элемента в массиве
			if (s[i] == mn) {
				b = s[i];
				bi = i;
			}
		}
	}

	if (flagmx == 1 && flagmn == 1) {            //очередная проверка                       //меняем местами
		for (int i = 0; i < n; i++) {
			if (i == ai) {
				s[i] = b;
			}
			else if (i == bi) {
				s[i] = a;
			}
			cout << s[i] << " ";
		}
	}
	else {
		cout << "таких элементов нет" << endl;
	}
	cout << endl;
	cout << endl;

	system("pause");
	return 0;

}