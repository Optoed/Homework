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
	bool flag = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] > mx && s[i] % 2 == 0) {
			mx = s[i];
			flag = 1;        //проверка на наличие чётного элемента в массиве
		}
	}

	cout <<"Максимальный чётный элемент равен " << mx << endl;

	for (int i = 0; i < n; i++) {
		if (flag == 1) {                  //проверка на наличие максимального чётного элемента в массиве
			if (s[i] == mx) {
				s[i] = s[i] * 2;       //удвоение максимального чётного
			}
			cout << s[i] << " ";
		}
		else {
			cout << endl;
			cout << "таких элементов нет" << endl;
			break;
		}
	}

	cout << endl;
	cout << endl;

	system("pause");      
	return 0;
}