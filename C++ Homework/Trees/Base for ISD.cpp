
//Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.

/*
Условие:


Пример для ввода:
n = 10
	

*/

#include<iostream>									//Подключение библиотеки ввода-вывода
#include<fstream>
#include<cmath>															
#include<queue>										//Подключение библиотеки очередей

#define watch(x) cout << #x << " = " << x << endl   //Макрос для быстрого вывода значения переменной

using namespace std;

ifstream fin("inputforIBT.txt");

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
		fin >> x;
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


int right_h(tree* tr) {			//Высота правой ветки
	int count = 0;
	tree* y = tr;
	while (y) {
		count++;
		y = y->right;
	}
	return count - 1;
}


void add(tree*& tr, int x) {			//функция добавления в ИСД
	tree* n = node(x);
	tree* y = tr;

	if (left_h(tr) == right_h(tr)) {
		do {
			y = y->left;
		} while (y->left);

		if (!y->left) {
			y->left = n;
		}

		else {
			y->right = n;
		}
	}

	else {
		do {
			y = y->right;
		} while (y->right);

		if (!y->left) {
			y->left = n;
		}

		else {
			y->right = n;
		}
	}
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


void del_n(tree * tr, int val) {
	tree * y;
	find(tr, val, y);

	if (y) {
		if (left_h(tr) == 0) {
			tr = NULL;
		}

		else if (left_h(tr) != right_h(tr)) {
			tree * x = tr->left;

			do {
				x = x->left;
			}
			while (x->left->left);

			if (x->right) {
				if (x->right->inf == val) {
					x->right = NULL;
				}

				else {
					y->inf = x->right->inf;
					x->right = NULL;
				}

				delete x->right;
			}

			else {
				if (x->left->inf == val) {
					x->left = NULL;	
				}

				else {
					y->inf = x->left->inf;
					x->left = NULL;
				}

				delete x->left;
			}
		}

		else {
			tree* x = tr->right;

			do {
				x = x->right;
			}
			while (x->right->right);

			if (x-> right) {
				if (x-> right-> inf == val) {
					x-> right = NULL;
				}

				else {
					y-> inf = x-> right-> inf;
					x-> right = NULL;
				}
				delete x-> right;
				
			}

			else {
				if (x-> left-> inf == val) {
					x-> left = NULL;
					
				}

				else {
					y-> inf = x-> left-> inf;
					x->left = NULL;
				}

				delete x-> left;
			}
		}
	}
}


void print(tree* tr, int k) {
	if (!tr) {
		cout << "Empty tree\n";
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


int main() {
	setlocale(LC_ALL, "RUS");

	int n, x;
	cout << "n = ";
	cin >> n;

	tree* tr = NULL;
	create(tr, n);
	cout << endl;

	int k = int(log((float)n) / log((float)2.0));
	print(tr, k);
	cout << endl;

	cout << endl;
	//cout << left_h(tr) << " " << right_h(tr);
	cout << endl;

	cout << "x = ";
	cin >> x;
	add(tr, x);
	n++;

	k = int(log((float)n) / log((float)2.0));
	cout << endl;
	print(tr, k);
	cout << endl;
	cout << endl;

	cout << " del node: ";
	cin >> x;
	del_n(tr, x);

	n--;
	k = int(log((float)n) / log((float)2.0));
	cout << endl;
	print(tr, k);

	cout << "--------------------------------------------" << endl;
	system("pause");					//Пауза
	return 0;							//Конец программы
}