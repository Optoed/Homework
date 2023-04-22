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
#include<vector>
#include<string.h>
#include<limits.h>
using namespace std;

const int MAX_NUMB = INT_MAX;

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
	string inf;
	stack* next;
};

void Push(stack*& h, string x) {			//Функция добавления элемента в стек
	stack* r = new stack;				//Создаём новый элемент
	r->inf = x;						//Информационное поле inf = x
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

void Print(stack*& h) {
	stack* copy_h = h;
	while (copy_h) {
		cout << copy_h->inf << ' ';
		copy_h = copy_h->next;
	}
	cout << endl;
}

string Pop(stack*& h) {					//Функция удаления элемента из стека (и возвращение его значения)
	string i = h->inf;					//Значение первого элемента
	stack* r = h;						//Указатель на голову стека
	h = h->next;						//Переносим указатель на следующий элемент
	delete r;							//Удаляем первый элемент
	return i;							//Возвращаем значение
}

struct FatherOfStack {      //Стек стеков
	stack* way_stack;
	FatherOfStack* next;
};

void PushFatherOfStack(FatherOfStack *& father_h, stack *& h) {
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


FatherOfStack * Move(stack *& h, string point, string finish, int min_size_stack, int a[9][9], vector<vector<string>> adlist, FatherOfStack* father_h) {

	//cout << "point = ";
	//cout << endl;
	int x = char_into_int(point[0]);
	int y = point[1] - '0';
	int pozition = (x - 1) * 8 + y;
	//cout << "x = " << x << "  y = " << y << "   pozition = " << pozition << endl;

	if (x + 2 <= 8 && y + 1 <= 8 && a[x + 2][y + 1] == 0) {
		//cout << "шаг 1  ";
		x += 2;
		y += 1;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;
			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	if (x - 2 >= 1 && y + 1 <= 8 && a[x - 2][y + 1] == 0) {
		//cout << "шаг 2  ";
		x -= 2;
		y += 1;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;
			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	if (x + 2 <= 8 && y - 1 >= 1 && a[x + 2][y - 1] == 0) {
		//cout << "шаг 3  ";
		x += 2;
		y -= 1;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;
			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	if (x - 2 >= 1 && y - 1 >= 1 && a[x - 2][y - 1] == 0) {
		//cout << "шаг 4  ";
		x -= 2;
		y -= 1;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;
			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	if (x + 1 <= 8 && y + 2 <= 8 && a[x + 1][y + 2] == 0) {
		//cout << "шаг 5  " ;
		x += 1;
		y += 2;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;
			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	if (x - 1 >= 1 && y + 2 <= 8 && a[x - 1][y + 2] == 0) {
		//cout << "шаг 6  " ;
		x -= 1;
		y += 2;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;
			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	if (x + 1 <= 8 && y - 2 >= 1 && a[x + 1][y - 2] == 0) {
		//cout << "шаг 7  ";
		x += 1;
		y -= 2;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;
			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	if (x - 1 >= 1 && y - 2 >= 1 && a[x - 1][y - 2] == 0) {
		//cout << "шаг 8  " ;
		x -= 1;
		y -= 2;
		point[0] = int_into_char(x);
		point[1] = y + '0';
		//cout << "point = " << point << endl;
		auto it = find(adlist[pozition - 1].begin(), adlist[pozition - 1].end(), point);
		if (it == adlist[pozition - 1].end()) {
			//cout << "Данной точки нет в списке смежности предыдущей точки" << endl;
			adlist[pozition - 1].push_back(point);
		}
		a[x][y] = 1;
		Push(h, point);

		if (point == finish) {
			a[x][y] = 0;
			//cout << "Мы на финише!" << endl;
			if (SizeOfStack(h) == min_size_stack) {
				PushFatherOfStack(father_h, h);
				//cout << "Добавил короткий стек!" << endl;
				Print(h);
			}
			else if (SizeOfStack(h) < min_size_stack) {
				ResetFatherOfStack(father_h);
				PushFatherOfStack(father_h, h);
				//cout << "Нашел ещё более короткий стек!" << endl;
				Print(h);
			}
			min_size_stack = SizeOfStack(h);
			Pop(h);
			Pop(h);
			point = h->inf;
			//Print(h);
			//cout << "head после попадания в финиш и удаления двух вершин = " << h->inf << endl;
			//cout << "point now = " << point << endl;

			return Move(h, point, finish, min_size_stack, a, adlist, father_h);
		}

		else {
			if (SizeOfStack(h) < min_size_stack) {
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
			else if (SizeOfStack(h) == min_size_stack) {
				Pop(h);
				point = h->inf;
				//cout << " Зашли в тупик!" << endl;
				//cout << "point = " << point << endl;
				//Print(h);
				return Move(h, point, finish, min_size_stack, a, adlist, father_h);
			}
		}
	}

	else if (SizeOfStack(h) > 1) {
		//cout << "Не можем дальше идти!" << endl;
		for (size_t i = 0; i < adlist[pozition - 1].size(); i++) {
			string this_point = adlist[pozition - 1][i];
			//cout << "this_point = " << this_point << endl;;
			int x = char_into_int(this_point[0]);
			int y = this_point[1] - '0';
			//cout << "x = " << x << "  y = " << y << endl;
			a[x][y] = 0;
		}
		//Print(h);
		/*
		int x = char_into_int(point[0]);
		int y = point[1] - '0';
		a[x][y] = 1;
		cout << "point = " << point << endl;
		*/

		Pop(h);
		point = h->inf;

		//Print(h);
		return Move(h, point, finish, min_size_stack, a, adlist, father_h);
	}

	else if (SizeOfStack(h) == 1) {
		//cout << "Мы не можем дальше идти и находимся в самом начале!" << endl;
		for (size_t i = 0; i < adlist[pozition - 1].size(); i++) {
			string this_point = adlist[pozition - 1][i];
			//cout << "this_point = " << this_point << endl;;
			int x = char_into_int(this_point[0]);
			int y = this_point[1] - '0';
			//cout << "x = " << x << "  y = " << y << endl;
			a[x][y] = 0;
		}
		//???Pop(h);
		return father_h;
	}
}



int main() {												//Главная функция
	setlocale(LC_ALL, "RUS");

	string start, finish;
	cout << "Введите клетку, откуда конь начинает свой путь (например, A2, буквы латинские и без пробелов!): ";
	cin >> start;
	cout << "Введите клетку, где конь должен закончить свой путь (например, E6, буквы латинские и без пробелов!): ";
	cin >> finish;
	cout << endl;
	/*
	coordinates coord_start, coord_finish;
	coord_start.x = char_into_int(start[0]);
	coord_start.y = start[1] - '0';
	int start_x = coord_start.x, start_y = coord_start.y;

	coord_finish.x = char_into_int(finish[0]);
	coord_finish.y = finish[1] - '0';
	int finish_x = coord_finish.x, finish_y = coord_finish.y;

	cout << "x(start) = " << coord_start.x << " y(start) = " << coord_start.y << endl;
	cout << "x(finish) = " << coord_finish.x << " y(finish) = " << coord_finish.y << endl << endl << endl;
	*/

	int a[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = 0;
		}
	}

	int x = char_into_int(start[0]);
	int y = start[1] - '0';
	a[x][y] = 1;

	stack* head = NULL;

	FatherOfStack* result = NULL;

	Push(head, start);

	vector<vector<string>> adlist(64);

	////////////////////////////////////////////////////////////////////

	result = Move(head, start, finish, MAX_NUMB, a, adlist, result);
	FatherOfStack* copy_result = result;
	cout << endl;
	while (copy_result) {
		cout << "Подходящий стек = " << copy_result->way_stack << " и вывод его содержимого, то есть кординат точек:" << endl;
		stack* one_of_stacks = copy_result->way_stack;

		while (one_of_stacks) {
			cout << one_of_stacks->inf << ' ';
			one_of_stacks = one_of_stacks->next;
		}

		copy_result = copy_result->next;
		cout << endl;
	}

	///////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////

	system("Pause");										//Пауза
	return 0;												//Конец программы
}
