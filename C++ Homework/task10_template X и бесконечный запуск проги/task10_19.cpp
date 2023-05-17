//Задачи на использование шаблонов функций - задание 5

#include <iostream>      //подключение библиотек
#include <limits.h>
#include <cmath>
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
	bool flag = 0;
	int ifirstnechet = 0, ilastchet = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(a[i][j]) % 2 != 0 && flag == 0) {       
				flag = 1;
				ifirstnechet = i;
			}
			if (abs(a[i][j]) % 2 == 0) {
				ilastchet = i;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == ifirstnechet) {
			swap(a[i], a[ilastchet]);
		}
	}

	return a;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "Input dimension\n";
	cin >> n >> m;          //ввод количества строк и столбцов
	char c; 
	do {
		cout << "Введите тип:\n1 - int\n2 - char\n";
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
			char c2 = '1';
			char** a2 = create(c2, n, m);
				
			cout << "CHAR:\n";
			print(a2, n, m);
			a2 = change(a2, n, m);
			cout << "New:\n";
			print(a2, n, m);
			break;
			}
		
		default: cout << "Неправильно введены данные\n";

		}
		cout << "Еще раз? Y - да, N - нет\n";
		cin >> c; // повторяем запуск программы пока не введем N

	} while (c != 'N');
	return 0;
}	