//2. Дана последовательность целых чисел. Удалить все минимальные элементы.

//подключение библиотек
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

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

	//вывод элементов вектора до удаление минимумов
	cout << "Вывод элементов вектора до удаление минимумов:" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl << endl;


	//поиск минимума
	vector<int>::iterator iter = min_element(v.begin(), v.end()); //поиск итератора минимального числа
	int Min = *iter; //минимальное число
	
	//удаление минимумов
	vector<int>::iterator it = remove(v.begin(), v.end(), Min);
	v.erase(it, v.end());

	//вывод элементов вектора после удаление минимумов
	cout << "Вывод элементов вектора после удаление минимумов:" << endl;
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	
	//конец программы
	return 0;
}