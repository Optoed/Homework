#include<iostream>
using namespace std;

int factII(int n, int p, int k) {
	if (k == n) {
		cout << k << " " << p << " " << n << endl; //вывод текущих данных
		return p; //результат

	}

	else if (k < n) {
		cout << k << " " << p << " " << n << endl; //вывод текущих данных
		return factII(n, p * (p + 2), k + 2);
	}

}

int main() {
	setlocale(LC_ALL, "RUS");

	int n, p, k = 1; //ввод чисел
	cout << "n = ";
	cin >> n;

	if (n % 2 == 0) {
		p = 2;
		k = 2;
	}
	else if (n % 2 == 1)
		p = 1;

	cout << endl;
	cout << "n!! = " << factII(n, p, k) << endl; //вызов функции
	return 0;
}