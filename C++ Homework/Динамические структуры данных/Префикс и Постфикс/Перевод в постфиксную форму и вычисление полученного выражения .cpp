/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
Дано математическое выражение. Перевести его в постфиксную форму.

Примеры для ввода:

5+(3+(2+4*(3-1)+2)/4+1)*4
5*(2+3*7)+4
a*(b+c*d)+e

*/


#include <iostream>										//Подключение библиотеки ввода-вывода
#include <string>										//Подключение библиотеки строк
using namespace std;


struct stack {											//Стек описывается как struct следующим образом
	char inf;
	stack* next;
};


void push(stack*& h, char x) {							//Функция добавления элемента в стек
	stack* r = new stack;								//Создаём новый элемент
	r->inf = x;											//Информационное поле inf = x
	r->next = h;										//Cледующим элементов является h
	h = r;												//Теперь r является головой
}


char pop(stack*& h) {									//Функция удаления элемента из стека (и возвращение его значения)
	char i = h->inf;									//Значение первого элемента
	stack* r = h;										//Указатель на голову стека
	h = h->next;										//Переносим указатель на следующий элемент
	delete r;											//Удаляем первый элемент
	return i;											//Возвращаем значение
}


int prior(char &a) {									//Определяем "приоритет" символа в зависимости от того, что это за символ
	if (a == '(') {
		return 1;
	}
	else if (a == '+' || a == '-') {
		return 2;
	}
	else if (a == '*' || a == '/') {
		return 3;
	}
	else if (isdigit(a) || isalpha(a)) {
		return 4;
	}
	else if (a == ' ') {
		return 5;
	}
	else {
		return 6;
	}
}


int main() {															//Главная функция
	setlocale(LC_ALL, "RUS");

	string str, result_str = "";
	cout << "Выражение в инфиксной форме (используйте только целые числа < 10):" << endl;
	getline(cin, str);													//Вводим Математическое выражение (то есть строку, можно с пробелами)
	cout << endl;
	stack* head = NULL;													//Инициализация стека

	for (size_t i = 0; i < str.size(); i++) {							//Проходимся по всей строке
		char a = str[i];												//i-тый элемент
		cout << "Элемент = " << a << endl;								//Выводим элемент (для наглядности)
		
		if (a == ' ') {													//Если есть пробелы, мы их просто пропускаем
			cout << "Пробел, следовательно пропускаем" << endl;
			continue;
		}
		
		if (isdigit(a) || isalpha(a)) {									//Если элемент - это число или буква
			cout << "Добавляем элемент в результирующую строку:" << endl;
			result_str += a;											//Записываем в результирующую строку и выводим её (для наглядности)
			cout << "result_str = " << result_str << endl;
		}

		if (a == '(') {													//Если элемент - это '(', то есть открывающая скобка
			cout << "Добавляем эл-т '(' в стек" << endl;
			push(head, a);												//То добавляем её в стек
		}

		if (a == '+' || a == '-' || a == '*' || a == '/') {				//Если элемент - это знак операции + - / *
			stack* r = head;											//Копируем стек с головой head
			if (r) {
				cout << "Вывод содержимого стека для наглядности: ";
				while (r) {												//Пока стек r не пуст
					char i = r->inf;									//Значение первого элемента
					cout << i << ' ';									//Вывод содержимого стека
					r = r->next;										//Теперь r имеет ссылку на следующий элемент
				}
				cout << endl;
			}

			if (!head) {												//Если стек пуст, то добавляем этот элемент в стек
				cout << "Стек head пуст, добавим в него этот элемент" << endl;
				push(head, a);
			}

			else if (head) {											//Если стек не пуст										
				if (prior(a) > prior(head->inf)) {						//Если приоритет этого элемента больше приоритета верхушки стека
					cout << "Приоритет символа больше приоритета верхушки стека, поэтому просто добавим этот символ в стек" << endl;
					push(head, a);
				}

				else if (prior(a) <= prior(head->inf)) {				//Если приоритет этого элемента <= приоритета верхушки стека
					cout << "Приоритет символа <= приоритета верхушки стека" << endl;

					while (head && prior(a) <= prior(head->inf)) {		//Пока стек не пуст и приоритет этого символа меньше/равен приоритету верхушки стека
						cout << "Верхушка стека = " << head->inf << endl;
						result_str += head->inf;                        //Добавляем верхушку стека в result_str и проходим так по стеку
						cout << "result_str = " << result_str << endl;
						head = head->next;
					}

					cout << "А теперь добавим сам элемент в стек" << endl;
					push(head, a);
				}
			}
		}

		if (a == ')') {													//Если элемент = закрывающей скобке
			while (a != '(') {											//Пока не встретится открывающая скобка, удаляем из стека верхушку и добавляем её в result_str
				a = pop(head);
				cout << "Верхушка элемента = " << a << endl;
				result_str += a;
				cout << "result_str = " << result_str << endl;
			}
			result_str.resize(result_str.size() - 1);					//Удаляем последний элемент, то есть '('
			cout << "result_str теперь = " << result_str << endl;
		}
		cout << endl;
	}

	cout << "Строка пройдена, теперь добавим оставшиеся в стеке элементы в result_str" << endl;
	while (head) {														//Пока стек не пуст, удаляем из него элементы и добавляем их в результирующую строку
		char s = pop(head);
		cout << "Верхушка стека = " << s << endl;
		result_str += s;
		cout << "result_str = " << result_str << endl;
	}
	cout << endl << endl;

	cout << "Исходное математическое выражение: " << str << endl;		//Вывод ответа
	cout << "Вывод в постфиксной форме:         " << result_str << endl << endl;

	/////////////////////////////////////////////////////
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl << "Часть 2: Вычисление значения выражения в постфиксной форме" << endl;
	cout << "Выражение в постфиксной форме = " << result_str << endl << endl;
	stack* head2 = NULL;												//Инициализируем новый стек
	int sum = 0;
	for (size_t i = 0; i < result_str.size(); i++) {							//Проходимся по всей строке
		char symbol = result_str[i];
		cout << "symbol = " << symbol << endl;
		if (isdigit(symbol) || isalpha(symbol)) {
			push(head2, symbol);
		}
		else {
			//
			stack* r = head2;											//Копируем стек с головой head
			if (r) {
				cout << "Вывод содержимого стека для наглядности: ";
				while (r) {												//Пока стек r не пуст
					char i = r->inf;									//Значение первого элемента
					cout << i << ' ';									//Вывод содержимого стека
					r = r->next;										//Теперь r имеет ссылку на следующий элемент
				}
				cout << endl;
			}
			//
			char symb_b = pop(head2);
			char symb_a = pop(head2);
			cout << "symb_b = " << symb_b << " и symb_a = " << symb_a << endl;
			int b = (symb_b - '0');
			int a = (symb_a - '0');
			cout << "b = " << b << " a = " << a << endl;
			switch (symbol)
			{
				case '+':
					sum = a + b;
					break;
				case '-':
					sum = a - b;
					break;
				case '*':
					sum = a * b;
					break;
				case '/':
					sum = a / b;
					break;
				default:
					cout << "Неправильный символ" << endl;
					break;
			}
			if (sum) {
				char sum_ch;
				cout << "sum(int) = " << sum << endl;
				sum_ch = sum + '0';
				cout << "sum_ch(char) = " << sum_ch << endl;
				push(head2, sum_ch);
			}
			cout << endl;
		}
	}

	if (head2) {
		cout << "Это постфиксное выражение равно: ";
		char ans = pop(head2);
		int ans_int = ans - '0';
		cout << ans_int << endl << endl;
	}
	/////////////////////////////////////////////////////////


	system("Pause");													//Пауза
	return 0;															//Конец программы
}

//5+(3+(2+4*(3-1)+2)/4+1)*4