
//Дан ориентированный граф. Реализовать топологическую сортировку
//(P.s. с неорентированным графом топологическая сортировка будет, вероятно, нерабочей)

/* СОДЕРЖАНИЕ input4.txt файла
9 14
0 1
0 2
1 2
1 3
1 4
2 4
2 5
3 6
4 6
5 4
5 7
6 7
6 8
7 8
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

ifstream in("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Динамические структуры данных\\Graphs\\Графы - Часть 2\\inputTopologicalSort.txt");

vector<vector<int>> Gr;			//Cписок смежности
vector<int> used;				//Список посещенных вершин
vector<int> order;				//Список вершин составляющих путь


void TopologicalSort(int x, int &n) {		//Функция Топологической сортировки (основана на TopologicalSort)
	used.resize(n);
	used[x] = 1;

	for (int i = 0; i < Gr[x].size(); i++) {
		if (used[Gr[x][i]] == 0) {
			TopologicalSort(Gr[x][i], n);
		}
	}

	order.push_back(x);
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
		//orient
		else {
			Gr[x].push_back(y);		//Граф ориентированный, поэтому в список смежности x добавляем y
			//Gr[y].push_back(x);		//Граф неориентированный, поэтому в список смежности y добавляем x
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

	TopologicalSort(0, n);

	reverse(order.begin(), order.end());

	cout << "\nРезультат топологической сортировки: ";
	for (auto i : order) {
		cout << i << ' ';
	}
	cout << "\n\n";

	system("pause");
	return 0;
}