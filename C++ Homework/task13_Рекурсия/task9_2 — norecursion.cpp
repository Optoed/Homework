//Задание на рекурсию - номер 2 - доп условие: способ бе

#include<iostream>
using namespace std;

int factII(int n) {
	int p = 1;
	int next = 1;
	if (n % 2 == 0) next = 2;
	for (int k = 1; k <= n; k += 2) {
		p = p * next;
		cout << k << " " << next << " " << p << endl;
		next = next + 2;
		
	}
	return p;
}

int main() {
	setlocale(LC_ALL, "RUS");

	int n; //ввод чисел
	cout << "n = ";
	cin >> n;

	cout << endl;
	cout << "n!! = " << factII(n) << endl; //вызов функции
	return 0;
}