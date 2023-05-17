
//Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.

/*
Условие:


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

/*
void preorder (tree* tr) {		//Прямой - К-Л-П
	if (tr) {
		cout << tr->inf << ' ';
		preorder(tr->left);
		preorder(tr->right);
	}
}

void postorder (tree* tr) {		//Обратный - Л-П-К
	if (tr) {
		postorder(tr->left);
		postorder(tr->right);
		cout << tr->inf << ' ';
	}
}
*/

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


tree* find(tree* tr, int x) {			//Функция поиска
	if (!tr || x == tr->inf) {			//Если дерево пусто или имеет только корень, равный этому элементу x
		return tr;
	}

	if (x > tr->inf) {				
		return find(tr->right, x);		//Ищем по правой ветке
	}

	else if (x < tr->inf) {
		return find(tr->left, x);		//Ищем по левой ветке
	}
}


tree* Min(tree* tr) {					//Поиск минимума
	if (!tr->left) {					//Если нет левого ребенка,
		return tr;						//вернем сам корень
	}
	else {								
		return Min(tr->left);			//Иначе идём по левой ветке до конца
	}
}

tree* Max(tree* tr) {					//Поиск максимума
	if (!tr->right) {					//Если нет правого ребенка,
		return tr;						//вернем сам корень
	}
	else {
		return Max(tr->right);			//Иначе идём по правой ветке до конца
	}
}


/*
tree *Next(tree*tr, int x){//поиск следующего
74 tree* n = find( tr , x);
17
75 if (n−>right)//если есть правый ребенок
76 return Min(n−>right);//min по правой ветке
77 tree *y = n−>parent; //родитель
78 while (y && n == y−>right){//пока не дошли до корня или узел - правый ребенок
79 n = y;//идем вверх по дереву
80 y = y−>parent;
81 }
82 return y;//возвращаем родителя
83 }
84
85 tree *Prev(tree *tr, int x){//поиск предыдущего
86 tree *n = find(tr , x);
87 if (n−>left)//если есть левый ребенок
88 return Max(n−>left);//max по левой ветке
89 tree *y = n−>parent;//родитель
90 while(y && n == y−>left){//пока не дошли до корня или узел - левый ребенок
91 n = y;//идем вверх по дереву
92 y = y−>parent;
93 }
94 return y;//возвращаем родителя
95 }
96
97
98 void Delete(tree *&tr, tree *v){//удаление узла
99 tree *p = v−>parent;
100 if (!p) tr = NULL; //дерево содержит один узел
101 else if (!v−>left && !v−>right){//если нет детей
102 if (p−>left == v) //указатель у родителя меняем на NULL
103 p−>left = NULL;
104 if (p−>right == v)
105 p−>right = NULL;
106 delete v;
107 }
108 else if (!v−>left || !v−>right){//если только один ребенок
109 if (!p) { //если удаляем корень, у которого 1 ребенок
110 if (!v−>left){ //если есть правый ребенок
111 tr = v−>right; //он становится корнем
112 v−>parent = NULL;
113 }
114 else { //аналогично для левого
18
115 tr = v−>left;
116 v−>parent = NULL;
117 }
118 }
119 else {
120 if (!v−>left){//если есть правый ребенок
121 if (p−>left == v) //если удаляемый узел явл. левым ребенком
122 p−>left = v−>right; //ребенок удаляемого узла становится левым ребенком
своего "деда"
123 else
124 p−>right = v−>right; ////ребенок удаляемого узла становится правым
ребенком своего "деда"
125 v−>right−>parent = p; //родителем ребенка становится его "дед"
126 }
127 else{//аналогично для левого ребенка
128 if (p−>left == v)
129 p−>left = v−>left;
130 else
131 p−>right = v−>left;
132 v−>left−>parent = p;
133 }
134 delete v;
135 }
136 }
137 else{//есть оба ребенка
138 tree *succ = Next(tr, v−>inf);//следующий за удаляемым узлом
139 v−>inf = succ−>inf; //присваиваем значение
140 if (succ−>parent−>left ==succ){//если succ левый ребенок
141 succ−>parent−>left = succ−>right; //его правый ребенок становится левым
ребенком своего "деда"
142 if (succ−>right) //если этот ребенок существует
143 succ−>right−>parent = succ−>parent; //его родителем становится "дед"
144 }
145 else {//аналогично если succ - правsq ребенок
146 succ−>parent−>right = succ−>right;
147 if (succ−>right)
148 succ−>right−>parent = succ−>parent;
149 }
150 delete succ;
151 }
19
152 }

*/


int main() {
	int n, x;
	cout << "n = ";
	cin >> n;

	tree* tr = NULL;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		cin >> x;
		insert(tr, x);
	}

	inorder(tr);
	
	cout << endl;
	cout << "min = " << Min(tr)->inf << endl;
	cout << "max = " << Max(tr)->inf << endl;
	cout << "x = ";
	cin >> x;

	if (find(tr, x)) {
		/*
		cout << "next = " << Next(tr, x)−>inf << endl;
		cout << "prev = " << Prev(tr, x)−>inf << endl;
		Delete(tr , find ( tr , x));
		inorder ( tr );
		cout << endl;
		*/
	}
	
	else {
		cout << "Such node not exist in this tree\n";
	}

	system("pause");
	return 0;
}