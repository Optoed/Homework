//9. Дана последовательность целых чисел. Удалить все минимальные элементы.

//подключение библиотек
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;


int main() { //главная функция
	//подключение русской клавиатуры
	setlocale(LC_ALL, "RUS");

	int n;
	cout << "Введите количество чисел в последовательности:" << endl;
	cin >> n; //количество чисел в последовательности
	vector <int> v; //вектор

	//заполнение вектора
	cout << "Заполните вектор:" << endl;
	for (int i = 0; i < n; i++) {
		int x;
		cout << i+1 << ") ";
		cin >> x;
		v.push_back(x);
	}
	cout << endl;

	//вывод элементов вектора
	cout << "Вывод элементов вектора до удаление максимумов:" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl << endl;

	//поиск максимума
	vector<int>::iterator iter = max_element(v.begin(), v.end()); //поиск итератора минимального числа
	int Max = *iter; //минимальное число
	
	//удаление максимумов
	vector<int>::iterator it = remove(v.begin(), v.end(), Max);
	v.erase(it, v.end());

	//вывод элементов вектора после удаление максимумов
	cout << "Вывод элементов вектора после удаление максимумов:" << endl;
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl << endl;

	//после всех чётных элементов вставить новый элемент
	int Y;
	cout << "Вставьте новый элемент: ";
	cin >> Y;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			v.insert(v.begin() + i + 1, Y);
			i++;
		}
	}
	cout << endl;
	
	//вывод элементов вектора после вставки элемента после каждого чётного элемента
	cout << "Вывод элементов вектора после вставки:" << endl;
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl << endl;

	//Сортировка последовательности
	sort(v.begin(), v.end());

	//вывод элементов вектора после сортировки
	cout << "Вывод элементов вектора после сортировки:" << endl;
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl << endl;

	//удаление дубликатов
	vector<int>::iterator iter3 = unique(v.begin(), v.end());
	v.erase(iter3, v.end());

	//Вывод элементов вектора после удаления дубликатов
	cout << "Вывод элементов вектора после удаления дубликатов:" << endl;
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl << endl;
	cout << "Конец программы";
	
	//конец программы
	return 0;
}