
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

//Дан неориентированный граф. Выяснить, является ли граф связным.

/* СОДЕРЖАНИЕ input4.txt файла
13 13
0 1
0 2
0 5
0 6
3 5
4 3
5 4
6 4
7 8
10 9
9 11
9 12
12 11
*/

#include <iostream>   //подключение библиотек
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Динамические структуры данных\\Graphs\\Графы - Часть 2\\input4.txt");

vector<vector<int>> Gr;			//Cписок смежности
vector<int> used;				//Список посещенных вершин
vector<int> path;				//Список вершин составляющих путь


void go_in_depth(int x) {		//Функция обхода в глубину
	used.resize(100);
	used[x] = 1;
	path.push_back(x);

	for (int i = 0; i < Gr[x].size(); i++) {
		if (used[Gr[x][i]] == 0) {
			go_in_depth(Gr[x][i]);
		}
	}
}


void componet_svyaz(int x) {	//Функция поиска компонентов связности
	replace_if(used.begin(), used.end(), [](int x) {return x == 1; }, 0);
	used.clear();

	while (used.empty()) {
		path.clear();
		go_in_depth(x);
		for (auto it = path.begin(); it != path.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
}


int main() {
	setlocale(LC_ALL, "RUS");	

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
		
		if (x > n || y > n) {

		}
		//ne orient
		else {
			Gr[x].push_back(y);		//Граф неориентированный, поэтому в список смежности x добавляем y
			Gr[y].push_back(x);		//Граф неориентированный, поэтому в список смежности y добавляем x
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

	int count_svyaz = 0;
	cout << endl << "Компоненты связности:\n";
	componet_svyaz(0);			//Первая компонента связности
	count_svyaz += 1;
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			componet_svyaz(i);
			count_svyaz += 1;
		}
	}
	
	if (count_svyaz == 1) {
		cout << "\nОтвет: Граф является СВЯЗНЫМ (так как только одна компонента связности)\n\n";
	}
	else if (count_svyaz > 1) {
		cout << "\nОтвет: Граф является НЕ СВЯЗНЫМ (так как больше одной компоненты связности)\n\n";
	}
	else {
		cout << "\nОтвет: count_svyaz == 0, а значит где-то есть ошибка\n\n";
	}

	system("pause");
	return 0;
}