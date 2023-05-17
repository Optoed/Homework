//2. Дана последовательность целых чисел. Найти все такие цифры, которые встречаются в двузначных числах, но не встречаются в трехзначных

//подключение библиотек
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <iterator>
using namespace std;

//функция, которая создаёт set и заполняет этот set цифрами данного числа
set <int> set_n(int n) {
	set <int> s;
	while (n) {
		s.insert(n % 10);
		n /= 10;
	}
	return s;
}

int main() {  

	setlocale(LC_ALL, "RUS"); 
	set <int> s1, s0, s, res;
	int n, a;
	cout << "Количество чисел = ";
	cin >> n;
	cout << endl;
	cout << "Введите числа: " << endl;

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a; //ввод числа
		s = set_n(a); //вызов функции
		if (a > 99 && a <= 999)
			s0.insert(s.begin(), s.end());     //если a - трёхзначное, то добавляем его цифры в s0
		else if (a > 9 && a <= 99)
			s1.insert(s.begin(), s.end());     //если a - двузначное, то добавляем его цифры в s1
	}
	cout << endl;

	cout << "Цифры в двузначных числах: " << endl;
	for (auto i : s1) {
		cout << i << ' ';
	}
	cout << endl;
	cout << endl;
	cout << "Цифры в трёхзначных числах: " << endl;
	for (auto i : s0) {
		cout << i << ' ';
	}
	cout << endl;

	set_difference(s1.begin(), s1.end(), s0.begin(), s0.end(), inserter(res, res.begin())); //в set "res" добавляем цифры,
	//которые встречаются в двузначных числах, но не встречаются в трехзначных

	//вывод ответа
	cout << endl << "цифры, которые встречаются в двузначных числах, но не встречаются в трехзначных: " << endl;
	for (auto i : res) {
		cout << i << ' ';
	}
	cout << endl << endl;

	//конец программы
	system("pause");
	return 0;
}