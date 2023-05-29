
/*
Дан неориентированный граф.

Выполнить следующие задания:

1) Вывести Эйлеров путь или Эйлеров цикл, если он существует.
*/

/*
Содержимое txt-файла:

6 10
0 1
0 2
0 4
0 5
1 3
1 4
2 3
2 4
3 4
3 5

*/

#include <iostream>   //подключение библиотек
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Динамические структуры данных\\Graphs\\Графы - Часть 2\\inputEulerian.txt");


vector<vector<int>> Gr;			//Cписок смежности



void Eulerian(int& n) {			//Алгоритм поиска Эйлерова пути/цикла
	int v1 = -1, v2 = -1;		//Приравниваем две вершины к -1

	bool checkcycle = 0;
	for (int i = 0; i < n; i++) {
		if (Gr[i].size() % 2 != 0) {		//Степень вершины нечетная
			if (v1 == -1) {
				v1 = i;
			}
			else if (v2 == -1) {
				v2 = i;
			}
			else {
				checkcycle = 1;		//Проверка: "Больше 2-х нечетных степеней"
			}
		}
	}

	if (v1 != -1) {				//Если нечетные степени есть - образуем новое ребро
		Gr[v1].push_back(v2);
		Gr[v2].push_back(v1);
	}

	stack<int> st;
	st.push(v1);			//Добавляем в стек любую вершину, например, v1
	vector<int> res;		//результирующий вектор

	while (!st.empty()) {		//удаляем все ребра и добавляем путь в res
		int v = st.top();
		if (Gr[v].size() != 0) {  
			st.push(Gr[v][0]);
			if (Gr[Gr[v][0]].size() > 0) {
				Gr[Gr[v][0]].erase(find(Gr[Gr[v][0]].begin(), Gr[Gr[v][0]].end(), v));
			}
			Gr[v].erase(Gr[v].begin());
		}
		else {
			res.push_back(v);
			st.pop();
		}
	}

	if (v1 != -1) {   //Удаляем "фиктивное" ребро, которое добавляли ранее
		for (int i = 0; i + 1 < res.size(); i++) {
			if (res[i] == v1 && res[i + 1] == v2 || res[i] == v2 && res[i + 1] == v1) {
				vector<int> res2;
				for (int j = i + 1; j < res.size(); j++) {
					res2.push_back(res[j]);
				}
				for (int j = 1; j <= i; j++) {
					res2.push_back(res[j]);
				}
				res = res2;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {		//Проверяем, остались ли ребра
		if (Gr[i].size()) {
			checkcycle = 1;
			break;
		}
	}

	if (checkcycle == 1) {
		cout << "\nГраф несвязный, Эйлерова цикла нет\n\n";
	}
	else {								//Вывод пути
		cout << "\nВывод пути: ";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << "\n\n";
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
		
		if (x > n || y > n) { //ничего не делаем
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
	cout << endl;
	
	Eulerian(n);	//Вызов функции Эйлерова пути/цикла

	system("pause");
	return 0;
}