
//Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.

/*
Условие:
Дано дерево. Определить количество узлов, имеющих только левого потомка.

Пример для ввода:
n = 10
5 3 7 1 9 4 2 8 6 0
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


void inorder(tree* tr, int &count) {		//Симметричный - Л-К-П
	if (tr) {
		inorder(tr->left, count);
		cout << tr->inf << ' ';
		if (tr->left && !tr->right) {
			count++;
			cout << "Найден узел, имеющий ТОЛЬКО левого ребенка: " << tr->inf << " , теперь ";
		}
		watch(count);
		inorder(tr->right, count);
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




int main() {
	setlocale(LC_ALL, "RUS");

	int n, x;
	cout << "n = ";
	cin >> n;

	cout << "Заполните дерево:" << endl;
	tree* tr = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(tr, x);
	}
	cout << endl;

	int count = 0;
	inorder(tr, count);
	

	cout << endl << "Ответ: " << count << endl;

	system("pause");
	return 0;
}