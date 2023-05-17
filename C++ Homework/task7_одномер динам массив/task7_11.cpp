// Вставка и удаление элементов в одномерном массиве - номер 11

#include <iostream>    //подключение библиотек ввода-вывода
#include <cmath>       //подключение библиотек математических функций    
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");        //использование русской клавиатуры
	int n, mn, x;
	cout << "n = ";
	cin >> n;           //ввод числа n
	cout << "x = ";
	cin >> x;
	int* a = new int[n];        //создание массива

	cout << "Массив:\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];          //заполнение массива
	}
	if (n > 0)
		mn = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] <= mn)          //поиск минимума
			mn = a[i];
	}

	cout << "min-элемент = " << mn << endl;

	int check = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mn && check == 0) {            //если a[i] = mn
			n = n + 1;
			for (int j = n - 1; j > i; j--) {
				a[j] = a[j - 1];         //процесс смещения (вставки)
			}
			a[i + 1] = x;
			check = 1;    // проверка, если вдруг x и mn - одно и то же число

			// ПРОВЕРКА

			//for (int c = 0; c < n; c++) cout << a[c] << " ";
			//cout << endl;

		}
		else
			check = 0;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";    //вывод оставшихся элементов
	}
	cout << endl;
	system("pause");     //завершение программы
	return 0;
}