/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
Пример 1.1. УСЛОВИЕ: 
Создать двусвязный список, содержащий целые числа.

*/


#include<iostream>							//Подключение библиотеки ввода-вывода
using namespace std;


struct list {								//Двусвязный список описывается как list следующим образом
	int inf;
	list* next;
	list* prev;
};


void push(list *&h, list *&t, int x) {		 
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

void print(list *&h, list *&t, int x) {
	list* p = h;
	cout << "Вывод содержимого двусвязного списка:" << endl;
	while (p) {
		cout << p->inf << ' ' << endl;
		p = p->next;
	}
}

list* find(list *&h, list *&t, int x) {
	list* p = h;
	while (p) {
		if (p->inf == x) {
			break;
		}
		p = p->next;
	}
	return p;
}


void insert_after(list *&h, list *&t, list *r, int y) {
	list *p = new list;
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


void del_node(list*& h, list*& t, list* r) {				
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

void del_list(list*& h, list*& t) {
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = NULL;
		delete p;
	}
}

int main() {							//Главная функция
	setlocale(LC_ALL, "RUS");

	int n;								//Количество целых чисел
	cout << "n = ";
	cin >> n;							//Вводим количество целых чисел
	cout << endl;

	list * head = NULL;					//Инициализация
	list* tail = NULL;
	int x;
	for (int i = 0; i < n; i++) {		//Создаем list
		cin >> x;						//Вводим число
		push(head, tail, x);			//Заполняем list
	}
	
	system("Pause");					//Пауза
	return 0;							//Конец программы
}
