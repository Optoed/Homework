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
#include<limits.h>
using namespace std;


struct coordinates {										//Структура, включающая в себя сумму и колличество
	int x;
	int y;
};


int char_into_int (char a) {
	char alphabet[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	for (int i = 0; i < 8; i++) {
		if (alphabet[i] == a) {
			return i + 1;
			break;
		}
		else {
			return 0;
		}
	}
}


char int_into_char(int a) {
	char alphabet[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	if (a > 0 && a < 8) {
		return alphabet[a];
	}
	else {
		return 0;
	}
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


stack * move(stack *& h, int x, int y) {
	stack* h1 = NULL;

	if (x + 2 <= 8 && y + 1 <= 8) {
		cout << "шаг 1 ";
		push(h1, x + 2, y + 1);
	}
	if (x - 2 >= 1 && y + 1 <= 8) {
		cout << "шаг 2 ";
		push(h1, x - 2, y + 1);
	}
	if (x + 2 <= 8 && y - 1 >= 1) {
		cout << "шаг 3 ";
		push(h1, x + 2, y - 1);
	}
	if (x - 2 >= 1 && y - 1 >= 1) {
		cout << "шаг 4 ";
		push(h1, x - 2, y - 1);
	}
	if (x + 1 <= 8 && y + 2 <= 8) {
		cout << "шаг 5 ";
		push(h1, x + 1, y + 2);
	}
	if (x - 1 >= 1 && y + 2 <= 8) {
		cout << "шаг 6 ";
		push(h1, x - 1, y + 2);
	}
	if (x + 1 <= 8 && y - 2 >= 1) {
		cout << "шаг 7 ";
		push(h1, x + 1, y - 2);
	}
	if (x - 1 >= 1 && y - 2 >= 1) {
		cout << "шаг 8 ";
		push(h1, x - 1, y - 2);
	}
	cout << endl;
	return h1;
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


	
	while (head_point) {
		cout << "Входные x и y = " << start_x << " " << start_y << endl;
		head_one_way = move(head_one_way, start_x, start_y);
		stack* copy_one_way = head_one_way;

		while (copy_one_way) {
			//copy_one_way = head_one_way;
			int i = 1;
			cout << "Проход " << i << endl;
			i += 1;
			start_x = copy_one_way->inf_x;
			cout << "start_x = " << start_x << endl;
			start_y = copy_one_way->inf_y;
			cout << "start_y = " << start_y << endl;;
			head_one_way = move(head_one_way, start_x, start_y);
			stack* copy_in_while = head_one_way;
			while (copy_in_while) {
				cout << "x = " << copy_in_while->inf_x << " y = " << copy_in_while->inf_y << endl;
				a[copy_in_while->inf_x][copy_in_while->inf_y];
				copy_in_while = copy_in_while->next;
			}
			copy_one_way = copy_one_way->next;
			cout << "цикл в While(copy_one_way) завершен" << endl;
		}

		cout << "САМ Цикл вайл завершен" << endl << endl;

	}

	

	system("Pause");										//Пауза
	return 0;												//Конец программы
}
