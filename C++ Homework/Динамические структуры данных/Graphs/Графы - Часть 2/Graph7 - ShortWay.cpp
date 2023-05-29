
//Дан невзвешенный, неориентированный граф. Найти кратчайшее расстояние от заданной вершины до всех остальных вершин. Вывести не только длину пути, но и сам этот путь.

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
#include <queue>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Динамические структуры данных\\Graphs\\Графы - Часть 2\\input4.txt");


bool BFS(int &a, int &b, int &n, vector<int>&used, vector<int>&path, queue<int>&buf, vector<vector<int>>&Gr) {	//Обход графа в ширину, который начинается с вершины a
	used.resize(n, 0);
	path.resize(n);
	used[a] = 1;
	path.push_back(a);
	buf.push(a);

	bool check = 0;

	while (!buf.empty()) {
		int y = buf.front();
		buf.pop();
		
		for (int i = 0; i < Gr[y].size(); i++) {	//Проходимся по списку смежности
			if (used[Gr[y][i]] == 0) {			//Мы ещё не посещали данную вершину
				buf.push(Gr[y][i]);
				path[Gr[y][i]] = y;				//позиции = каждому эл-ту списка смежности, на эту позицию записываем предка данной вершины Gr[y][i] (предок = y)
				used[Gr[y][i]] = 1;				//Отмечаем вершину как посещенную
				if (Gr[y][i] == b) {
					check = 1;
				}
			}
		}
	}

	return check;
}



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

	int a, b;			//Вводим вершины a и b
	cout << "\n\na = ";
	cin >> a;
	
	for (b = 0; b < n; b++) {
		if (a == b) {}

		else {
			vector<int> used;				//Список посещенных вершин
			vector<int> path;				//Список вершин составляющих общий путь в обходе в ширину
			vector<int> short_path;			//Кратчайший путь от a до b
			queue<int> buf;					//Список стартовых позиций для обхода в ширину

			bool check = BFS(a, b, n, used, path, buf, Gr);		//Вызом модифицированной функии обхода в глубину
			if (check == 0) {
				cout << "\nМежду a = " << a << " и b = " << b << " пути нет(находятся в разных компонентах смежности)\n\n";
			}

			else {
				int copy_b = b;				//Сделал копию b, если вдруг придется с b ещё работать
				while (copy_b != a) {		//В short_path добавляем сам путь (Добавляем предок вершины и теперь вершина является своим предком и так пока b != a, то есть идём с конца в начало)
					short_path.push_back(copy_b);
					//cout << "copy_b = " << copy_b << ",  предок copy_b (path[copy_b]) = " << path[copy_b] << endl;    //Для наглядности
					copy_b = path[copy_b];		//b теперь равен предку b, таким образом когда-нибудь предком b окажется a, что проверяется в следующем if(), и на этом цикл закончится
					if (copy_b == a) {
						//cout << "copy_b = " << copy_b << ",  предок copy_b (path[copy_b]) = " << path[copy_b] << endl;    //Для наглядности
						short_path.push_back(copy_b);
					}
				}

				reverse(short_path.begin(), short_path.end());

				cout << "\n\nКратчайший путь от a = " << a << " до b = " << b << " равен:\n";				//Вывод ответа
				for (auto elem : short_path) {
					cout << elem << ' ';
				}
				cout << "\nДлина пути от a = " << a << " до b = " << b << " равна " << short_path.size() - 1 << endl << endl;

				path.clear();
				short_path.clear();
			}
		}
	}

	
	system("pause");
	return 0;
}