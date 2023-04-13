/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
УСЛОВИЕ:

Дана шахматная доска. 
Вывести кратчайший путь конем от клетки А до клетки В. 
Должны быть введены две клетки в виде, например, А2 и Е6. 
Путь должен быть выведен в виде списка клеток А2 В4 С6 D8 E6

*/


#include<iostream>											//Подключение библиотеки ввода-вывода
#include<string>
#include<limits.h>
using namespace std;

const int MAX_NUMB = INT_MAX;

struct coordinates {										//Структура, включающая в себя сумму и колличество
	int x;
	int y;
};


int char_into_int (char a) {
	if (a == 'A')
		return 1;
	if (a == 'B')
		return 2;
	if (a == 'C')
		return 3;
	if (a == 'D')
		return 4;
	if (a == 'E')
		return 5;
	if (a == 'F')
		return 6;
	if (a == 'G')
		return 7;
	if (a == 'H')
		return 8;
	else
		return -999;
}


char int_into_char(int a) {
	if (a == 1)
		return 'A';
	if (a == 2)
		return 'B';
	if (a == 3)
		return 'C';
	if (a == 4)
		return 'D';
	if (a == 5)
		return 'E';
	if (a == 6)
		return 'F';
	if (a == 7)
		return 'G';
	if (a == 8)
		return 'H';
	else
		return '?';
}


struct stack {							//Стек описывается как struct следующим образом
	int inf_x;
	int inf_y;
	stack* next;
};


void push(stack*& h, int x, int y) {			//Функция добавления элемента в стек
	stack* r = new stack;				//Создаём новый элемент
	r->inf_x = x;						//Информационное поле inf = x
	r->inf_y = y;
	r->next = h;						//Cледующим элементов является h
	h = r;								//Теперь r является головой
}

int SizeOfStack(stack *& h) {
	int size = 0;
	stack* copy_h = h;
	while (copy_h) {
		size++;
		copy_h = copy_h->next;
	}
	return size;
}

coordinates pop(stack*& h) {					//Функция удаления элемента из стека (и возвращение его значения)
	int i_x = h->inf_x;					//Значение первого элемента
	int i_y = h->inf_y;
	stack* r = h;						//Указатель на голову стека
	h = h->next;						//Переносим указатель на следующий элемент
	delete r;							//Удаляем первый элемент
	coordinates x_y;
	x_y.x = i_x;
	x_y.y = i_y;
	return x_y;							//Возвращаем значение
}


stack * move(stack *& h, int x, int y, int a[8][8], int size_stack, coordinates &coord_finish) {
	//Попробуй без a[x][y]
	if (SizeOfStack(h) < size_stack) {
		if (x + 2 <= 8 && y + 1 <= 8 && a[x + 2][y + 1] == 0) {
			cout << "шаг 1 ";
			push(h, x + 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}

		}
		if (x - 2 >= 1 && y + 1 <= 8 && a[x - 2][y + 1] == 0) {
			cout << "шаг 2 ";
			push(h, x - 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x + 2 <= 8 && y - 1 >= 1 && a[x + 2][y - 1] == 0) {
			cout << "шаг 3 ";
			push(h, x + 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x - 2 >= 1 && y - 1 >= 1 && a[x - 2][y - 1] == 0) {
			cout << "шаг 4 ";
			push(h, x - 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x + 1 <= 8 && y + 2 <= 8 && a[x + 1][y + 2] == 0) {
			cout << "шаг 5 ";
			push(h, x + 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x - 1 >= 1 && y + 2 <= 8 && a[x - 1][y + 2] == 0) {
			cout << "шаг 6 ";
			push(h, x - 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x + 1 <= 8 && y - 2 >= 1 && a[x + 1][y - 2] == 0) {
			cout << "шаг 7 ";
			push(h, x + 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x - 1 >= 1 && y - 2 >= 1 && a[x - 1][y - 2] == 0) {
			cout << "шаг 8 ";
			push(h, x - 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			a[h->inf_x][h->inf_y] = 1;
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				a[h->inf_x][h->inf_y] = 0;
				cout << "Мы дошли до конца" << endl;
				return h;
			}
			else {
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		else {
			//вероятно тут не 0, а h с удалением лишней верхушки
			return 0;
		}
	}
	else {
		//вероятно тут не 0, а h с удалением лишней верхушки
		return 0;
	}
}



int main() {												//Главная функция
	setlocale(LC_ALL, "RUS");

	string start, finish;
	cout << "Введите клетку, откуда конь начинает свой путь (например, A2, буквы латинские и без пробелов!): ";
	cin >> start;
	cout << "Введите клетку, где конь должен закончить свой путь (например, E6, буквы латинские и без пробелов!): ";
	cin >> finish;

	coordinates coord_start, coord_finish;
	coord_start.x = char_into_int(start[0]);
	coord_start.y = start[1] - '0';
	int start_x = coord_start.x, start_y = coord_start.y;

	coord_finish.x = char_into_int(finish[0]);
	coord_finish.y = finish[1] - '0';
	int finish_x = coord_finish.x, finish_y = coord_finish.y;

	cout << "x = " << coord_start.x << " y = " << coord_start.y << endl;
	cout << "x (finish) = " << coord_finish.x << " y (finish) = " << coord_finish.y << endl;

	int a[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			a[i][j] = 0;
		}
	}
	a[coord_start.x][coord_start.y] = 1;

	stack* head_point = NULL;
	stack* head_one_way = NULL;
	stack* head_full_way = NULL;

	push(head_point, start_x, start_y);
	push(head_one_way, start_x, start_y);

	bool step = 0;
	int size_stack;

	while (head_point) {

		if (step == 0) {

			cout << "Входные x = " << start_x << " y = " << start_y << endl;

			head_one_way = move(head_one_way, start_x, start_y, a, MAX_NUMB, coord_finish);
			stack* copy_one_way = head_one_way;

			size_stack = SizeOfStack(copy_one_way);
			cout << "Размер стека = " << size_stack << endl;

			if (!copy_one_way) {
				cout << "copy one way пуст!!" << endl;
			}

			while (copy_one_way) {
				cout << "copy_one_way->inf_x = " << copy_one_way->inf_x << " copy_one_way->inf_y = " << copy_one_way->inf_y << endl;
				copy_one_way = copy_one_way->next;
			}


			pop(head_one_way);
			pop(head_one_way);
			start_x = head_one_way->inf_x;
			start_y = head_one_way->inf_y;

			cout << "САМ Цикл вайл завершен" << endl << endl;
			step = 1;
		}


		else {
			cout << "Входные x = " << start_x << " y = " << start_y << endl;

			head_one_way = move(head_one_way, start_x, start_y, a, size_stack, coord_finish);
			stack* copy_one_way = head_one_way;

			size_stack = SizeOfStack(copy_one_way);
			cout << "Размер стека = " << size_stack << endl;

			if (!copy_one_way) {
				cout << "copy one way пуст!!" << endl;
			}

			while (copy_one_way) {
				cout << "copy_one_way->inf_x = " << copy_one_way->inf_x << " copy_one_way->inf_y = " << copy_one_way->inf_y << endl;
				copy_one_way = copy_one_way->next;
			}


			pop(head_one_way);
			pop(head_one_way);
			start_x = head_one_way->inf_x;
			start_y = head_one_way->inf_y;

			cout << "САМ Цикл вайл завершен" << endl << endl;
		}
	}

	

	system("Pause");										//Пауза
	return 0;												//Конец программы
}
