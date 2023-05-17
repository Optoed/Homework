//Дан ориентированный граф. Вывести количество вершин, смежных с данной.

#include <iostream>   //подключение библиотек
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

/*
#include <stdlib.h>
#include <stdio.h>
#include <clocale>
#include <cstdlib>
#include <windows.h>
#include <sstream>
#include <cstring>
#include <time.h>
#include <numeric>
#include <cmath>
#include <iterator>
#include <iomanip>
*/

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\Пётр\\Desktop\\С++ Homework\\Графы - Часть 2\\input1.txt");

int main() {
	setlocale(LC_ALL, "RUS");	

	vector<vector<int>> Gr;			//Cписок смежности
	int n, m;

	cout << "Введите количество вершин = n = ";
	in >> n;
	cout << n << endl;

	cout << "Введите количество ребер = m = ";
	in >> m;
	cout << m << endl;

	Gr.resize(n);					//Задаем список смежности
	
	while (in.peek() != EOF) {		//Проходимся по текстовому файлу "in" и считываем все числа попарно в виде x, y
		int x, y;
		in >> x >> y;
		//orient
		if (x > n || y > n) {

		}
		else {
			Gr[x].push_back(y);		//Граф ориентированный, поэтому только в список смежности x добавляем y
		}
	}
	
	for (int i = 0; i < n; i++) {	//Удаляем повторяющиеся значения если они есть
		sort(Gr[i].begin(), Gr[i].end());
		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
	}

	cout << "\nСписок смежности:\n";
	for (int i = 0; i < n; i++) {	//Вывод содержимого списка смежности
		cout << "x = " << i << ": ";
		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	cout << "\nВершина x = ";
	int x;
	cin >> x;

	cout << "\nОтвет: Количество вершин, смежных с данной: " << Gr[x].size() << "\n\n";	//Ответ

	system("pause");
	return 0;
}