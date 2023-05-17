
//Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.

/*
Условие:
Дано дерево. Вывести путь от корня до узла X.

Пример для ввода:
n = 10
5 3 7 1 9 4 2 8 6 0
x = 2

Ответ: 5 3 1 2
*/

#include<iostream>									//Подключение библиотеки ввода-вывода
#include<algorithm>									//Подключение библиотеки алгоритмов

#include<iomanip>									//Input / Output manipulation
#include<limits.h>									//Подключение библиотеки для INT_MAX

#include<vector>									//Подключение библиотеки векторов																
#include<stack>										//Подключение библиотеки стеков	
#include<queue>										//Подключение библиотеки очередей

#include<string.h>									//Подключение библиотек для использования строк
#include<string>

#define watch(x) cout << #x << " = " << x << endl   //Макрос для быстрого вывода значения переменной

using namespace std;


struct tree {					//Структура дерева
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};


tree* node(int x) {				//Новый элемент (узел) для дерева
	tree* n = new tree;
	n->inf = x;
	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;
	return n;
}


void inorder(tree* tr) {		//Симметричный - Л-К-П
	if (tr) {
		inorder(tr->left);
		cout << tr->inf << ' ';
		inorder(tr->right);
	}
}


void insert(tree*& tr, int x) {			//функция вставки
	tree* n = node(x);

	if (!tr) {
		tr = n;							//если дерево пустое - корень
	}

	else {
		tree* y = tr;
		
		while (y) {						//ищем куда вставлять
			if (n->inf > y->inf) {		//правая ветка
				if (y->right) {
					y = y->right;
				}

				else {
					n->parent = y;		//узел становится правым ребенком
					y->right = n;
					break;
				}
			}

			else if (n->inf < y->inf) { //левая ветка
				if (y->left) {
					y = y->left;
				}

				else {
					n->parent = y;		//узел становится левым ребенком
					y->left = n;
					break;
				}
			}
		}
	}
}


tree* find(tree* tr, int x) {				//Функция поиска
	if (!tr || x == tr->inf) {				//Если дерево пусто или Если дерево имеет только корень, равный этому элементу x
		return tr;
	}

	if (x > tr->inf) {
		return find(tr->right, x);			//Ищем по правой ветке
	}

	else if (x < tr->inf) {
		return find(tr->left, x);			//Ищем по левой ветке
	}
}


void PrintWay(tree* tr, int x) {			//Функция вывода пути
	if (!tr) {								//Если дерево пусто
		cout << "Дерево пустое" << endl;
	}

	else if (x == tr->inf) {				//Если дерево имеет только корень, равный этому элементу x
		cout << tr->inf << ' ';
	}

	else if (x > tr->inf) {
		cout << tr->inf << ' ';
		return PrintWay(tr->right, x);			//Ищем по правой ветке
	}

	else if (x < tr->inf) {
		cout << tr->inf << ' ';
		return PrintWay(tr->left, x);			//Ищем по левой ветке
	}
}


int main() {
	setlocale(LC_ALL, "RUS");
	int n, x;
	cout << "n = ";
	cin >> n;

	cout << "Заполните дерево:" << endl;
	tree* tr = NULL;							//Заполняем дерево
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(tr, x);
	}

	cout << endl << "--------------------------------------------" << endl;
	cout << "Отсортированный вывод дерева:" << endl;
	inorder(tr);
	
	cout << endl;
	cout << "Узел x = ";
	cin >> x;

	cout << endl << "Ответ:\n";		
	if (find(tr, x)) {					//Выводим путь, если узел x можно найти в дереве
		PrintWay(tr, x);
	}
	else {
		cout << "Узел x не содержится в данном дереве." << endl;
	}
	cout << endl;

	cout << "--------------------------------------------" << endl;
	system("pause");					//Пауза
	return 0;							//Конец программы
}