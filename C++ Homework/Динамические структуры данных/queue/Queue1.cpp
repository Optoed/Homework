/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
Создать очередь, содержащую целые числа.
После всех чисел, равных минимальному числу, вставить последний четный элемент.
Например, было  2 8 2 1 6 8 8 1 2 2 8 2 1.
Стало  2 8 2 1 2 6 8 8 1 2 2 2 8 2 1 2
*/


#include<iostream>							//подключение библиотеки ввода-вывода
#include<limits.h>							//библиотека лимитов
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
	queue * head1 = h;						//Инициализация
	queue * tail1 = NULL;					//Инициализация
	queue* resh = NULL;						//Инициализация
	queue* rest = NULL;						//Инициализация
	int min = INT_MAX;
	int chet;

	while (head1) {							//Ищем минимум и последний четный 
		int x = head1->inf;
		head1 = head1->next;
		
		if (x < min)						
			min = x;

		if (x % 2 == 0)
			chet = x;
	}

	while (h) {								//Пока очередь не пуста
		int x = pop(h, t);					//Удаляем первый элемент и запоминаем его значение
		push(rest,resh, x);					//Записываем в результат rest

		if (x == min)						//Записываем после min последний четный
			push(rest, resh, chet);
	}

	return rest;							//Возвращаем очередь-результат rest
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

	queue * rest = result(head, tail);		//Результат
	cout << "Answer:" << endl;

	while (rest)							//Пока rest не станет пустым
		cout << pop(rest, tail) << " ";		//Выводим на экран элементы очереди rest функцией pop(...)
	cout << endl;

	system("Pause");						//Пауза
	return 0;								//Конец программы
}
