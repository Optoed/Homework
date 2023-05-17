//2. Дана последовательность целых чисел. Найти все такие цифры, которые встречаются в двузначных числах, но не встречаются в трехзначных

//подключение библиотек
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>

using namespace std;

//двузначные числа
bool digit2(int x) {
	return (x >= 10 && x <= 99) == 0; 
}

//трёхзначные числа
bool digit3(int x) {
	return (x >= 100 && x <= 999) == 0;
}

int main() { //главная функция
	//подключение русской клавиатуры
	setlocale(LC_ALL, "RUS");

	int n;
	cout << "Введите количество чисел в последовательности:" << endl;
	cin >> n; //количество чисел в последовательности
	cout << endl;

	set <int> s; 
	
	//заполнение set
	for (int i = 0; i < n; i++) {
		int x;
		cout << "s[" << i << "] = ";
		cin >> x;
		s.insert(x);
	}
	cout << endl;

	//вывод set
	cout << "Вывод введённых чисел: " << endl;
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//создание двух векторов, эквивалентных set s
	vector <int> dg2(s.begin(), s.end());
	vector <int> dg3(s.begin(), s.end());

	//заполняем вектор dg2 двузначными числами, принадлежащими set s
	vector<int>::iterator iter2 = remove_if(dg2.begin(), dg2.end(), digit2);
	dg2.erase(iter2, dg2.end());

	//заполняем вектор dg3 трёхзначными числами, принадлежащими set s
	vector<int>::iterator iter3 = remove_if(dg3.begin(), dg3.end(), digit3);
	dg3.erase(iter3, dg3.end());

	//вывод содержимого dg2 для наглядности
	cout << "Вывод содержимого dg2:" << endl;
	cout << endl;
	for (auto it = dg2.begin(); it != dg2.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//вывод содержимого dg3 для наглядности
	cout << "Вывод содержимого dg3:" << endl;
	cout << endl;
	for (auto it = dg3.begin(); it != dg3.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//два set для цифр чисел, принадлежащих dg2 и dg3 соответственно
	set<int>nums2dg;
	set<int>nums3dg;

	//заполняем set nums2dg
	for (auto it = dg2.begin(); it != dg2.end(); it++) {
		auto nm1 = *it / 10;
		auto nm2 = *it % 10;
		nums2dg.insert(nm1);
		nums2dg.insert(nm2);
	}

	//заполняем set nums3dg
	for (auto it = dg3.begin(); it != dg3.end(); it++) {
		auto nm1 = *it / 100;
		auto nm2 = (*it / 10) % 10;
		auto nm3 = *it % 10;
		nums3dg.insert(nm1);
		nums3dg.insert(nm2);
		nums3dg.insert(nm3);
	}

	//вывод set nums2dg
	cout << "Вывод содержимого nums2dg:" << endl;
	cout << endl;
	for (auto it = nums2dg.begin(); it != nums2dg.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//вывод set nums3dg
	cout << "Вывод содержимого nums3dg:" << endl;
	cout << endl;
	for (auto it = nums3dg.begin(); it != nums3dg.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//Вставляем в новый set numsdg все элементы nums2dg, которые не содержатся в nums3dg
	set<int>numsdg;

	for (auto it = nums2dg.begin(); it != nums2dg.end(); it++) {
		auto x = *it;
		if (nums3dg.find(x) == nums3dg.end()) {
			numsdg.insert(x);
		}
	}
	cout << endl;

	//выводим ответ
	cout << "Ответ: " << endl;
	for (auto it = numsdg.begin(); it != numsdg.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//конец программы
	return 0;
}