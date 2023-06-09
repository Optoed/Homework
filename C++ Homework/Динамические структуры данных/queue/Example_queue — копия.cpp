﻿/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
Пример 1.2. УСЛОВИЕ:Создать очередь, состоящую из целых чисел.
Удалить все повторяющиеся элементы, оставив только их первые вхождения.
(Например, вводится следующий набор данных: 1 2 3 1 2 4 1.
Результат: 1 2 3 4.)
*/


#include<iostream>							//подключение библиотеки ввода-вывода
using namespace std;


struct queue {								//очередь описывается как struct следующим образом
	int inf;
	queue * next;
};


void push(queue*& h, queue * &t, int x) {	//вставка элемента в очередь
	queue* r = new queue;					//создаем новый элемент
	r -> inf = x;							//информационное поле inf = x
	r -> next = NULL;						//всегда последний(?)

	if (!h && !t) {							//если очередь пуста
		h = t = r;							//это и голова, и хвост
	}

	else {
		t -> next = r;						//r - следующий для хвоста
		t = r;								//теперь r - хвост
	}
}


int pop(queue*& h, queue *&t) {				//удаление элемента из очереди
	queue* r = h;							//создаем указатель на голову
	int i = h -> inf;						//сохраняем значение головы
	h = h -> next;							//сдвигаем указатель на следующий элемент

	if (!h)									
		t = NULL;

	delete r;								//удаляем первый элемент
	return i;
}


queue * result(queue * &h, queue * &t) {	//Функция записи результата
	queue * head1 = NULL;					//Инициализация
	queue * tail1 = NULL;					//Инициализация
	queue* resh = NULL;						//Инициализация
	queue* rest = NULL;						//Инициализация

	while (h) {								//Пока очередь не пуста
		int x = pop(h, t);					//Удаляем первый элемент и запоминаем его значение
		push(rest,resh, x);					//Записываем в результат rest

		cout << "x = " << x << endl;
		while (h) {							//Пока очередь не пуста
			int y = pop(h, t);				//Удаляем элемент из очереди и запоминаем его значение
			
			if (y != x)	{					//Если он не равен x
				push(head1, tail1, y);		//Записываем в новую очередь
				cout << "y = " << y << endl;
			}
		}
		cout << endl;
		h = head1;							//Переобозначаем указатели (h, т.е. head, - теперь это head1)
		cout << "h = " << h << endl;
		t = tail1;							//Переобозначаем указатели (h, т.е. head, - теперь это head1)
		cout << "t = " << t << endl;
		head1 = NULL;						//Переобозначаем указатели (обнуляем head1)
		tail1 = NULL;						//Переобозначаем указатели (обнуляем tail1)
		cout << endl;

	}

	return rest;								//Возвращаем очередь-результат rest
}




int main() {								//Главная функция
	setlocale(LC_ALL, "RUS");

	int n;									//Количество целых чисел
	cout << "n = ";
	cin >> n;								//Вводим количество целых чисел
	cout << endl;

	queue * head = NULL;					//Инициализация
	queue * tail = NULL;					//Инициализация
	int x;

	for (int i = 0; i < n; i++) {			//Создаем очередь
		cin >> x;							//Вводим число
		push(head, tail, x);				//Заполняем очередь
	}
	cout << endl;
	
	/*
	while (head) {
		cout << pop(head, tail) << " ";
	}
	cout << endl;
	*/

	queue * rest = result(head, tail);		//Результат (Очередь, где мы удалили все повторяющиеся числа)
	cout << endl;

	cout << "tail = " << tail << endl;
	cout << "head = " << head << endl;

	while (rest)							//Пока rest не станет пустым
		cout << pop(rest, tail) << " ";		//Выводим на экран элементы очереди rest функцией pop(...)
	cout << endl;

	system("Pause");						//Пауза
	return 0;								//Конец программы
}
