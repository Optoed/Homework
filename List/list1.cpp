/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
Пример 1. УСЛОВИЕ: 
Создать двусвязный список, содержащий целые числа.\n
После всех чисел, равных минимальному числу, вставить последний четный элемент.\n
Например, было  2 8 2 1 6 8 8 1 2 2 8 2 1\n
Стало			2 8 2 1 2 6 8 8 1 2 2 2 8 2 1 2\n
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


void insert_after(list*& h, list*& t, list* r, int y) {		//Вставка после r
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


list* result_list(list*& h, list*& t) {				//Результат

	int min = INT_MAX, chet;

	bool flag = 0;

	while (h) {
		if (h->inf < min) {
			min = h->inf;
		}
		if ((h->inf) % 2 == 0) {
			chet = h->inf;
			if (!flag)
				flag = 1;
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

	if (flag) {
		cout << "Минимум = " << min << endl;
		cout << "Последний четный = " << chet << endl;

		while (h) {
			if (h->inf == min) {
				insert_after(h, t, h, chet);
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
	}

	return h;
}


int main() {												//Главная функция
	setlocale(LC_ALL, "RUS");

	cout << "Пример 1. УСЛОВИЕ: \nСоздать двусвязный список, содержащий целые числа.\nПосле всех чисел, равных минимальному числу, вставить последний четный элемент.\nНапример, было  2 8 2 1 6 8 8 1 2 2 8 2 1\nСтало		2 8 2 1 2 6 8 8 1 2 2 2 8 2 1 2\n" << endl;

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

	head = result_list(head, tail);

	if (head)
		print(head, tail);
	else
		cout << "Список пуст!" << endl;


	system("Pause");										//Пауза
	return 0;												//Конец программы
}
