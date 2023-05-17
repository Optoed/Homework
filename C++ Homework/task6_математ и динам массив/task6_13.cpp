// task6_13

#include <iostream>       // ввод библиотеки ввода-вывода
using namespace std;

int main() {
	
	setlocale(LC_ALL, "RUS");         // использование русской раскладки

	int rows, k, coef = 1, suma = 0;               
	
	cout << "¬ведите число строк ";
	cin >> rows;                     // вводим число строк (по условию надо больше 10)
	cout << endl;
	cout << "¬ведите число k ";
	cin >> k;             // вводим число k, например 3 или 7
	cout << endl;

	for(int i = 0; i < rows; i++) { 

		for (int space = 1; space <= rows - i; space++)            //добавл€ем пробелы дл€ красоты
			cout << " ";

		for (int j = 0; j <= i; ++j) {
			if (j == 0 || i == 0)               // частный случай
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;            //формула дл€ выводимых чисел

			cout << coef << " ";
			if (k == i) {                 // определение числа 2 в степени k
				suma += coef;         // дл€ этого мы просто складываем все числа в i-строке треугольника ѕаскал€
			}
		}

		cout << endl;

	}

	cout << endl;
	cout << "»спользу€ треугольник ѕаскал€, находим 2 в степени k, оно равно " << suma << endl;          //вывод ответа
	cout << endl;
	system("pause");               //пауза и завершение программы
	return 0;
}
