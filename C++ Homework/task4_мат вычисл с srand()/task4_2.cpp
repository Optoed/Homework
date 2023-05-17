#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "n = ";
	cin >> n; // число эпементов массива
	int* s = new int[n];

	srand((unsigned int)time(NULL)); // начальная точка генерации
	for (int i = 0; i < n; i++) {
		s[i] = rand() % 10; //псевдослучайное число (< 10)
		cout << s[i] << " ";
	}

	cout << endl;
	int suma = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 != 0 && s[i] % 2 != 0) {
			suma += s[i];
			cout << "i = " << i << "; s[i] = " << s[i] << endl;
			count += 1;

		}
	}

	cout << endl;

	if (count > 0) {
		cout << endl;
		cout << "Ответ: " << suma << endl;
		cout << endl;
	}
	else {
		cout << "таких элементов нет" << endl;
		cout << endl;
	}

	system("pause");
	return 0;
	}