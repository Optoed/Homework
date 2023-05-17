//Дан неориентированный граф.Выяснить, является ли граф связным.

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

vector<vector<int>> Gr;			//Cписок смежности
vector<int> used;				//Список посещенных вершин
vector<int> path;				//Список вершин составляющих путь


void go_in_depth(int x) {
	//used.resize(x);
	used[x] = 1;
	cout << '3';
	path.push_back(x);

	for (int i = 0; i < Gr[x].size(); i++) {
		if (used[Gr[x][i]] == 0) {
			go_in_depth(Gr[x][i]);
		}
	}
}


void componet_svyaz(int x) {
	cout << "1";
	//replace_if(used.begin(), used.end(), [](int x) {return x == 1; }, 0);
	used.clear();
	cout << "1";
	while (used.empty()) {
		cout << "1";
		path.clear();
		cout << '1';
		go_in_depth(x);
		cout << '2';
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
		//orient
		if (x > n || y > n) {

		}
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

	for (int i = 0; i < n; i++) {
		componet_svyaz(i);
		cout << endl;
	}
	


	system("pause");
	return 0;
}