//Задачи на использование рекурсивных функций - 17

#include<iostream>
#include<cmath>
using namespace std;

void printINT(int n, int a) { //печать n символов a
	for (int i = 0; i < n; i++)
		cout << a;
}
void printCHAR(int n, char a) { //печать n символов a
	for (int i = 0; i < n; i++)
		cout << a;
}

void F(int p, int n, int N) { // p - чисел, n - символов
	if (n > 0 && p <= N) {
		printINT(p, p); //печать цифр
		printCHAR(n, '-'); //печать дефисов
		printINT(p, p); //печать цифр
		cout << endl; //переход на следующую строку
		F(p + 1, n - 2, N); //вызов функции для следующей строки
		printINT(p, p);
		printCHAR(n, '-'); //нижняя часть
		printINT(p, p);
		cout << endl;
	}

	else if (n == 0 && p <= N) {
		printINT(8, p); //печать цифр
		cout << endl; //переход на следующую строку
		F(p + 1, n, N); //вызов функции для следующей строки
		printINT(8, p); //печать цифр
		cout << endl;
	}
}

int main() {
	bool flag = 0;
	int N;
	cout << "N = ";
	cin >> N;
	cout << endl;
	int n = 6;
	int count = 1;
	int p = 1;
	F(1, n, N); //вызов функции
	return 0;
}
