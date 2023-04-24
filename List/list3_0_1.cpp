/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
УСЛОВИЕ:

Удалить лишние элементы так, 
чтобы каждый элемент был не больше среднего арифметического всех элементов, следующих за ним.

Например, для списка	5 2 9 1 3 7 1 2 9
результат должен быть	2 1 3 1 2 9
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

struct number_data {										//Структура, включающая в себя сумму и колличество
	int sum;
	int count;
};

number_data sum_count(list*& h, list*& t) {					//Функция, возвращающая структуру number_data с суммой и количеством всех элементов списка
	number_data numb;
	numb.sum = 0;
	numb.count = 0;

	while (h) {
		numb.sum += h->inf;
		numb.count++;
		if (h->next)
			h = h->next;
		else
			break;
	}

	while (h) {
		if (h->prev) {
			h = h->prev;
		}
		else {
			break;
		}
	}

	return numb;
}

list* result_list(list*& h, list*& t) {						//Результат

	number_data numb = sum_count(h, t);

	cout << "sum = " << numb.sum << endl;
	cout << "count = " << numb.count << endl;


	while (h) {
		int i = h->inf;
		cout << "i = " << i << endl;
		numb.sum -= i;
		cout << "numb.sum = " << numb.sum << endl;
		numb.count--;
		cout << "numb.count = " << numb.count << endl;
		

		if (h->next) {
			if (i > int(numb.sum / numb.count)) {
				cout << "Среднее арифметическое (округлённое вниз) всех эл-тов, следующих за i = " << i << ", равно " << int(numb.sum / numb.count) << endl;
				cout << "i > среднего арифметического, поэтому удаляем" << endl;

				cout << "До:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;

				
				list* pr = NULL;
				if (h->prev) {
					pr = h->prev;
				}

				del_node(h, t, h);

				if (pr) {
					h->prev = pr;
				}

				cout << "После:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;

			}
			else {
				cout << "Среднее арифметическое (округлённое вниз) всех эл-тов, следующих за i = " << i << ", равно " << int(numb.sum / numb.count) << endl;
				cout << "i <= среднего арифметического, поэтому не удаляем" << endl;

				cout << "До:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;

				
				h = h->next;

				cout << "После:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;
				

				
			}
		}

		else {
			cout << "Это был последний элемент, следовательно не удаляем!" << endl;
			break;
		}

	}
	cout << endl;

	while (h) {
		cout << h->inf << ' ';
		if (h->prev)
			cout << " h->prev->inf = " << h->prev->inf << endl;
		cout << "h->inf = " << h->inf << endl;
		if (h->next)
			cout << " h->next->inf = " << h->next->inf << endl;
		if (h->prev) {
			h = h->prev;
			
		}
		else {
			break;
		}
		cout << endl;
	}
	cout << endl;
	return h;
}


int main() {												//Главная функция
	setlocale(LC_ALL, "RUS");

	cout << "УСЛОВИЕ: \nСоздать двусвязный список, содержащий целые числа.\nУдалить лишние элементы так, \nчтобы каждый элемент был не больше среднего арифметического всех элементов, следующих за ним.\nНапример, для списка 5 2 9 1 3 7 1 2 9, результат должен быть 2 1 3 1 2 9.\n" << endl;

	int n;													//Количество целых чисел
	cout << "n = ";
	cin >> n;												//Вводим количество целых чисел
	cout << endl;

	list* head = NULL;										//Инициализация
	list* tail = NULL;										//Инициализация
	int x;
	cout << "Заполните список числами:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(head, tail, x);
	}

	head = result_list(head, tail);

	cout << "----------------------------------------------------------------" << endl;
	if (head)
		print(head, tail);
	else
		cout << "Список пуст!" << endl;

	system("Pause");										//Пауза
	return 0;												//Конец программы
}
