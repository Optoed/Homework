
//Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.

/*
Условие:
Дано дерево. Определить высоту узла X

Пример для ввода:
n = 10

4 5 3 7 8 6 9 1 2 0
*/

#include<iostream>									//Подключение библиотеки ввода-вывода
#include<cmath>										//Подключение библиотеки математики				
#include<queue>										//Подключение библиотеки очередей

#define watch(x) cout << #x << " = " << x << endl   //Макрос для быстрого вывода значения переменной

using namespace std;

//#include<fstream>
//ifstream fin("inputforIBT.txt");

struct tree {					//Структура дерева
	int inf;
	tree* left;
	tree* right;
};


tree* node(int x) {				//Новый элемент (узел) для дерева
	tree* n = new tree;
	n->inf = x;
	n->left = NULL;
	n->right = NULL;
	return n;
}


void create(tree*& tr, int n) {	//Функция создания дерева (пока ещё пустого)
	int x;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}


void preorder(tree* tr) {		//Прямой обход - К-Л-П
	if (tr) {
		cout << tr->inf << ' ';
		preorder(tr->left);
		preorder(tr->right);
	}
}


int left_h(tree* tr) {			//Высота левой ветки
	int count = 0;
	tree* y = tr;
	while (y) {
		count++;
		y = y->left;
	}
	return count - 1;
}


void find(tree* tr, int x, tree*& res) {				//Функция поиска
	if (tr) {
		if (tr->inf == x) {
			res = tr;
		}

		else {
			find(tr->left, x, res);
			find(tr->right, x, res);
		}
	}
}	  


void print(tree* tr, int k) {				//Вывод дерева
	if (!tr) {
		cout << "Ответ: дерево - пустое\n";
	}

	else {
		queue<tree*> cur, next;
		tree* r = tr;
		cur.push(r);
		int j = 0;

		while (cur.size()) {
			if (j == 0) {
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
					cout << ' ';
			}

			tree* buf = cur.front();
			cur.pop();
			j++;

			if (buf) {
				cout << buf->inf;
				next.push(buf->left);
				next.push(buf->right);
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';
			}

			if (!buf) {
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';

				cout << ' ';

			}

			if (cur.empty()) {
				cout << endl;
				swap(cur, next);
				j = 0;
				k--;
			}
		}
	}
}


int main() {								//Главная функция
	setlocale(LC_ALL, "RUS");				//Русская клавитура

	cout << "Условие:\nДано дерево.Определить высоту узла X" << endl;

	int n, x;
	cout << "n (например, 10) = ";
	cin >> n;


	cout << endl << "Введите числовые данные для дерева (например, 4 5 3 7 8 6 9 1 2 0): " << endl;
	tree* tr = NULL;
	create(tr, n);							//Создаем дерево и заполняем его

	cout << "---------------------------------------" << endl << endl;
	int k = int(log((float)n) / log((float)2.0));
	print(tr, k);							//Выводим содержимое дерева

	if (n > 0) {
		cout << endl << "---------------------------------------" << endl;

		cout << "Узел x = ";
		cin >> x;

		tree* res = NULL;
		find(tr, x, res);

		cout << "---------------------------------------" << endl << endl << endl;

		if (res) {			//То есть если x нашли в дереве
			cout << "Ответ: высота узла x = " << left_h(res) << endl;
		}

		else {
			cout << "Ответ: такого узла x нет в данном дереве" << endl;
		}
	}

	cout << "---------------------------------------" << endl << endl;
	system("pause");					//Пауза
	return 0;							//Конец программы
}