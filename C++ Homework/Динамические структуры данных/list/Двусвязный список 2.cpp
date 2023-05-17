/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
Пример 1.1. УСЛОВИЕ:
Создать двусвязный список, содержащий целые числа.
Выполнить циклический сдвиг списка так, чтобы на первом месте был первый максимальный элемент.
Например, было  1 2 5 1 4 5 3 4 5 2 
Стало			5 1 4 5 3 4 5 2 1 2
*/


#include<iostream>											//Подключение библиотеки ввода-вывода
#include<limits.h>
using namespace std;


struct list {												//Двусвязный список описывается как list следующим образом
	int inf;
	list* next;
	list* prev;
};


void push(list*& h, list*& t, int x) {						//Вставка элемента в список
	list* r = new list;
	r->inf = x;
	r->next = NULL;

	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}

	else {
		t->next = r;
		r->prev = t;
	}

	t = r;
}


void print(list*& h, list*& t) {						//вывод элементов списка
	list* p = h;
	cout << endl << "Вывод содержимого двусвязного списка:" << endl;
	while (p) {
		cout << p->inf << ' ';
		p = p->next;
	}
	cout << endl << endl;
}


list* find(list*& h, list*& t, int x) {						//Поиск элемента в списке
	list* p = h;
	while (p) {
		if (p->inf == x) {
			break;
		}
		p = p->next;
	}
	return p;
}


void insert_after(list*& h, list*& t, list* r, int y) {		//Вставка элемента после определённого элемента
	list* p = new list;
	p->inf = y;

	if (r == t) {
		p->next = NULL;
		p->prev = r;
		r->next = p;
		t = p;
	}

	else {
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}
}


void del_node(list*& h, list*& t, list* r) {				//Удаление элемента из списка
	if (r == h && r == t) {
		h = t = NULL;
	}
	else if (r == h) {
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}


void del_list(list*& h, list*& t) {							//Очищение списка
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = NULL;
		delete p;
	}
}


list* result_list(list*& h, list*& t, int &n) {				//Результат

	int max = INT_MIN, count = 0;
	bool flag = 0;

	while (h) {
		if (h->inf > max) {
			max = h->inf;
		}
		if (h->next) {
			h = h->next;
		}
		else {
			break;
		}
	}

	while (h) {
		if (h->prev) {
			h = h->prev;
		}
		else {
			break;
		}
	}

	cout << "Первый максимум = " << max << endl;
	while (h) {
		if (count != n) {
			int i = h->inf;
			if (i == max) {
				cout << "Первый максимум теперь на первом месте. Циклический сдвиг окончен!" << endl;
				break;
			}
			del_node(h, t, h);
			push(h, t, i);
			count++;
		}
		else {
			cout << "Циклический сдвиг не возможен!" << endl;
		}
	}

	return h;
}


int main() {												//Главная функция
	setlocale(LC_ALL, "RUS");

	cout << "Пример 1. УСЛОВИЕ: \nСоздать двусвязный список, содержащий целые числа.\nВыполнить циклический сдвиг списка так, чтобы на первом месте был первый максимальный элемент.\nНапример, было  1 2 5 1 4 5 3 4 5 2.\nСтало		5 1 4 5 3 4 5 2 1 2.\n" << endl;

	int n;													//Количество целых чисел
	cout << "n = ";
	cin >> n;												//Вводим количество целых чисел
	cout << endl;

	list* head = NULL;										//Инициализация
	list* tail = NULL;										//Инициализация
	int x;
	cout << "Заполните двусвязный список числами:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(head, tail, x);
	}

	head = result_list(head, tail, n);

	if (head)
		print(head, tail);
	else
		cout << "Список пуст!" << endl;

	system("Pause");										//Пауза
	return 0;												//Конец программы
}