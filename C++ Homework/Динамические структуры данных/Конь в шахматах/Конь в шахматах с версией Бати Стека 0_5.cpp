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

/*
Если шаг 1 возможен и ведет нас в 0
	Если список смежности для этой точки не существует,
		 то создаем его (и добавляем в общий список точек)
	Иначе
		Записываем эту точку в список смежности предыдущей точки (то есть скорее всего используем двусвязный список, либо же для стеков: удаляем вершину, добавляем точку и обратно добавляем вершину)
	1)Если попали в финиш,
		Последнюю точку отмечаем нулем.
		Если длина этого пути равна мимуму,
			то добавляем этот путь в стек/список стеков/списков.
		Иначе Если длина меньше пути,
			то очищаем список списоков, добавляем туда наш путь и обновляем минимальную длину пути.
		Удаляем 2 вершины.
		return Рекурсим функцию.
	2)Если попали не в финиш:
		2.1) Если размер этого стека меньше минимума, то Рекурсим функцию.
		2.2) Если размер этого стека = минимуму, то отмечаем единичкой вершину, удаляем её и return рекурсимся

Если шаг 2...

...

Если шаг 8 возможен и ведет нас в 0
	Если список смежности для этой точки не существует,
		 то создаем его (и добавляем в общий список точек)
	Иначе
		Записываем эту точку в список смежности предыдущей точки (то есть скорее всего используем двусвязный список, либо же для стеков: удаляем вершину, добавляем точку и обратно добавляем вершину)
	1)Если попали в финиш,
		Последнюю точку отмечаем нулем.
		Если длина этого пути равна мимуму,
			то добавляем этот путь в стек/список стеков/списков.
		Иначе Если длина меньше пути,
			то очищаем список списоков, добавляем туда наш путь и обновляем минимальную длину пути.
		Удаляем 2 вершины.
		return Рекурсим функцию.
	2)Если попали не в финиш:
		2.1) Если размер этого стека меньше минимума, то Рекурсим функцию.
		2.2) Если размер этого стека = минимуму, то отмечаем единичкой вершину, удаляем её и return рекурсимся

Иначе если длина стека/списка сейчас больше 1, то (то есть мы не можем никуда идти)
	Смотрим на список смежности данной вершины и обнуляем все вершины, лежащие в этом списке смежности. 
	Удаляем вершину.
	return Рекурсим фукнцию.

Иначе если длина стека/списка сейчас равна 1, то (мы в самом начале и не можем никуда идти)
	Смотрим на список смежности данной вершины и обнуляем все вершины, лежащие в этом списке смежности. 
	??Удаляем вершину??
	return Список/стек списков/стеков со всеми кратчайшими путями (в идеале в этот момент все x превратить обратно в буквы и перезаписать)

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

struct FatherOfStack {      //Стек стеков
	stack* way_stack;
	FatherOfStack* next;
};

void PushInFatherOfStack(FatherOfStack *& father_h, stack *& h) {
	FatherOfStack* father_r = new FatherOfStack;
	father_r->way_stack = h;
	father_h = father_r;
}

void ResetFatherOfStack(FatherOfStack *& father_h) {							//Очищение списка
	while (father_h) {
		FatherOfStack * p = father_h;
		father_h = father_h->next;
		delete p;
	}
}

void ResetStack(stack * & h) {
	while (h) {
		stack* r = h;
		h = h->next;
		delete r;
	}
}

FatherOfStack * move(stack *& h, int x, int y, int a[9][9], int size_stack, coordinates &coord_finish, FatherOfStack * father_h, stack * mmega_two, stack * mega_two) {

	if (SizeOfStack(h) < size_stack) {
		//cout << "sizeOfStack(h) = " << SizeOfStack(h) << " size_stack = " << size_stack << endl;

		if (x + 2 <= 8 && y + 1 <= 8 && a[x + 2][y + 1] == 0) {
			cout << "шаг 1 ";
			a[x][y] = 1;
			push(h, x + 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}

			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}

		}
		if (x - 2 >= 1 && y + 1 <= 8 && a[x - 2][y + 1] == 0) {
			cout << "шаг 2 ";
			a[x][y] = 1;
			push(h, x - 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;


			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x + 2 <= 8 && y - 1 >= 1 && a[x + 2][y - 1] == 0) {
			cout << "шаг 3 ";
			a[x][y] = 1;
			push(h, x + 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;


			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x - 2 >= 1 && y - 1 >= 1 && a[x - 2][y - 1] == 0) {
			cout << "шаг 4 ";
			a[x][y] = 1;
			push(h, x - 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;


			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x + 1 <= 8 && y + 2 <= 8 && a[x + 1][y + 2] == 0) {
			cout << "шаг 5 ";
			a[x][y] = 1;
			push(h, x + 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x - 1 >= 1 && y + 2 <= 8 && a[x - 1][y + 2] == 0) {
			cout << "шаг 6 ";
			a[x][y] = 1;
			push(h, x - 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x + 1 <= 8 && y - 2 >= 1 && a[x + 1][y - 2] == 0) {
			cout << "шаг 7 ";
			a[x][y] = 1;
			push(h, x + 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x - 1 >= 1 && y - 2 >= 1 && a[x - 1][y - 2] == 0) {
			cout << "шаг 8 ";
			a[x][y] = 1;
			push(h, x - 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "Мы дошли до конца" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "Записываем этот стек h куда - нибудь и запоминаем его длину и отмечаем как минимум и size_stack приравниваем его размеру" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "ДЛИНА ОКАЗАЛАСЬ ЕЩЁ МЕНЬШЕ!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "Теперь size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		else {
			cout << endl << "------Дальше конь ходить не может!"<< endl;
			/*
			cout << endl << "До преобразований\n" << "Вывод всех нулей:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 0) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			*/
			cout << endl;
			cout << "Вывод всех единиц:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 1) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "Вывод всех двоек:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 2) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "Вывод всех троек:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 3) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;

			bool flag3 = 0;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 3) {
						a[i][j] = 0;
						if (!flag3) {
							cout << "тройки превращаем обратно в нули!" << endl;
							flag3 = 1;
						}
					}
				}
			}
			
			if (flag3 == 0) {
				while (mega_two) {
					a[mega_two->inf_x][mega_two->inf_y] = 0;
					mega_two = mega_two->next;
				}
			}

			if (flag3 == 0)
				cout << "Удаление двоек (кроме центральной) завершено!" << endl;
			cout << "ВЕРШИНА (центральная) КОТОРУЮ МЫ ОБОЗНАЧАЕМ двойкой = " << h->inf_x << " " << h->inf_y << endl;

			push(mega_two, h->inf_x, h->inf_y);
			a[h->inf_x][h->inf_y] = 2;
			if (flag3) {
				push(mmega_two, h->inf_x, h->inf_y);
			}
			pop(h);
			/*
			cout << endl << "После преобразований\n" << "Вывод всех нулей : " << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 0) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			*/
			cout << endl;
			cout << "Вывод всех единиц:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 1) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "Вывод всех двоек:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 2) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "Вывод всех троек:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 3) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;

			//Добавил 1 возможно зря
			//a[h->inf_x][h->inf_y] = 1;
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl << endl;
			return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
		}
	}
	else {
		cout << endl <<"            Stack превысил лимит по размеру и теперь мы возвращаемся назад" << endl;
		/*
		if ((size_stack - SizeOfStack(h)) == 0) {
			pop(h);
			pop(h);
		}
		// else if можем убрать, ничего не изменится
		else if ((size_stack - SizeOfStack(h)) == 1) {
			pop(h);
		}
		*/
		cout << "ВЕРШИНА КОТОРУЮ МЫ ОБОЗНАЧАЕМ Тройкой = " << h->inf_x << " " << h->inf_y << endl;
		a[h->inf_x][h->inf_y] = 3;
		pop(h);
		cout << "ВЕРШИНА КОТОРУЮ МЫ ОБОЗНАЧАЕМ нулём = " << h->inf_x << " " << h->inf_y << endl;
		a[h->inf_x][h->inf_y] = 0;
		pop(h);
		/*
		cout << endl << "Вывод всех нулей:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 0) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		*/
		cout << endl;
		cout << "Вывод всех единиц:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 1) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		cout << endl;
		cout << "Вывод всех двоек:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 2) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		cout << endl;
		cout << "Вывод всех троек:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 3) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		cout << endl;

		cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl << endl;
		return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
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

	cout << "x(start) = " << coord_start.x << " y(start) = " << coord_start.y << endl;
	cout << "x(finish) = " << coord_finish.x << " y(finish) = " << coord_finish.y << endl << endl << endl;

	int a[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = 0;
		}
	}
	a[coord_start.x][coord_start.y] = 1;

	stack* head_one_way = NULL;

	FatherOfStack* result = NULL;

	push(head_one_way, start_x, start_y);

	stack* mmega_two = NULL;
	stack* mega_two = NULL;

	////////////////////////////////////////////////////////////////////

	result = move(head_one_way, start_x, start_y, a, MAX_NUMB, coord_finish, result, mmega_two, mega_two);
	FatherOfStack* copy_result = result;

	while (copy_result) {
		cout << "Первый подходящий стек = " << copy_result->way_stack << "и вывод его содержимого, то есть кординат точек:" << endl;
		stack* one_of_stacks = copy_result->way_stack;

		while (one_of_stacks) {
			cout << "x = " << one_of_stacks->inf_x << "y = " << one_of_stacks->inf_y << endl;
			one_of_stacks = one_of_stacks->next;
		}

		copy_result = copy_result->next;
	}

	///////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////

	system("Pause");										//Пауза
	system("Pause");										//Пауза
	system("Pause");										//Пауза
	system("Pause");										//Пауза
	return 0;												//Конец программы
}