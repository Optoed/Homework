//Задачи на использование шаблонов функций - задание 5

#include <iostream>  //подключение библиотек
#include <limits.h>
using namespace std;

template < typename X>
X** create(X c, int n, int m) {//создание
	X** a = new X * [n]; //выделение памяти
	for (int i = 0; i < n; i++)
		a[i] = new X[m];
	for (int i = 0; i < n; i++) //ввод массива
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	return a;
}

template < typename X>
void print(X** a, int n, int m) { //печать
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
}

template < typename X>
X** change(X** a, int n, int m) {//замена
	int mx = INT_MIN;
	int mn = INT_MAX;
	int imn = 0, imx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < mn) {
				mn = a[i][j];
				imn = i;
			}
			if (a[i][j] > mx) {
				mx = a[i][j];
				imx = i;
			}
		}
	}
	cout << "max элемент равен " << mx << " и он лежит в строке с номером (от 0 считаем) " << imx << endl;
	cout << "min элемент равен " << mn << " и он лежит в строке с номером (от 0 считаем) " << imn << endl;
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		if (i == imx) {
			swap(a[i], a[imn]);
		}
	}

	return a;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "Enter count of rows and count of columns\n";
	cin >> n >> m;
	char c;
	do {
		cout << "Введите тип:\n1 - int\n2 - double\n3 - char\n4 - float\n";
		int k;
		cin >> k;
		switch (k) {//вызываем различные типы
		case 1:
		{
			int c = 1;
			int** a = create(c, n, m);
			cout << "INT:\n";
			print(a, n, m);
			a = change(a, n, m);
			cout << "New:\n";
			print(a, n, m);
			break;
		}
		case 2:
		{
			double c1 = 1;
			double** a1 = create(c1, n, m);
			cout << "DOUBLE:\n";
			print(a1, n, m);
			a1 = change(a1, n, m);
			cout << "New:\n";
			print(a1, n, m);
			break;
		}
		case 3:
		{
			char c2 = '1';
			char** a2 = create(c2, n, m);

			cout << "CHAR:\n";
			print(a2, n, m);
			a2 = change(a2, n, m);
			cout << "New:\n";
			print(a2, n, m);
			break;
		}
		case 4:
		{
			float c3 = 1;
			float** a3 = create(c3, n, m);
			cout << "FLOAT:\n";
			print(a3, n, m);
			a3 = change(a3, n, m);
			cout << "New:\n";
			print(a3, n, m);
			break;
		}
		default: cout << "Неправильно введены данные\n";

		}
		cout << "Еще раз? Y - да, N - нет\n";
		cin >> c; // повторяем запуск программы пока не введем N

	} while (c != 'N');
	return 0;
}