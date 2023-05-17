
//Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.

/*
Условие:
Дана шахматная доска.
Вывести кратчайший путь конем от клетки А до клетки В.
Должны быть введены две клетки в виде, например, А2 и Е6.
Путь должен быть выведен в виде списка клеток А2 В4 С6 D8 E6
*/

#include<iostream>									//Подключение библиотеки ввода-вывода
#include<algorithm>									//Подключение библиотеки алгоритмов

#include<iomanip>
#include<limits.h>									//Подключение библиотеки для INT_MAX

#include<vector>									//Подключение библиотеки векторов																
#include<stack>										//Подключение библиотеки стеков	
#include<queue>										//Подключение библиотеки очередей

#include<string.h>									//Подключение библиотек для использования строк
#include<string>

#define watch(x) cout << #x << " = " << x << endl   //Макрос для быстрого вывода значения переменной

using namespace std;

int min_count = INT_MAX;							//Для поиска пути минимальной длины

int char_into_int(char a) {							//Функция перевода буквы в цифру
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
		return -99999;
}

char int_into_char(int a) {							//Функция перевода цифры в букву
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


void bfs(string point, string &finish, vector<bool> &used, vector<vector<string>> &Gr) {		//Обход в ширину для поиска кратчайшего пути до финиша

	queue<string> buf;						//Сюда будем записывать все точки
	stack<string> answer;					//Сюда будем записывать все уденные pop'ом точки

	int x = char_into_int(point[0]);		
	int y = point[1] - '0';
	int pozition = (x - 1) * 8 + y;			//Находим позицию точки (от 1 до 64 включительно)

	used[pozition] = 1;						//Отмечаем единичкой
	buf.push(point);						//Добавляем точку в общую очередь buf
	
	while (!buf.empty()) {					//Пока очередь buf не пуста, удаляем её верхушку и ищем добавляем все её смежные точки, куда мы можем попасть. 
		string this_point = buf.front();	
		int this_x = char_into_int(this_point[0]);
		int this_y = this_point[1] - '0';
		int this_pozition = (this_x - 1) * 8 + this_y;
		buf.pop();
		answer.push(this_point);

		for (int i = 0; i < Gr[this_pozition-1].size(); ++i) {		//Проход по всем смежным точкам
			string t = Gr[this_pozition-1][i];
			int t_x = char_into_int(t[0]);
			int t_y = t[1] - '0';
			int t_pozition = (t_x - 1) * 8 + t_y;

			if (used[t_pozition] == 0) {							//Если мы ещё не были в этой точке
				buf.push(t);										//Добавляем её в очередь
				used[t_pozition] = 1;								//Отмечаем единичкой, чтобы больше сюда не попадать

				if (t == finish) {									//Если мы попали в финиш, то создаем и заполняем стек final_answer точками,
					stack<string> copy_answer = answer;				//образующими путь от start до finish
					copy_answer.push(t);
					stack<string> final_answer;
					int count = 0;									//Длина пути count, используем для нахождения кратчайшего пути

					while (!copy_answer.empty()) {					//Пока копия answer не пуста, проходимся по всем точкам и верные добавляем в стек-ответ
						string top = copy_answer.top();
						copy_answer.pop();

						if (count < 2) {
							final_answer.push(top);
							count++;
						}

						else {
							int top_x = char_into_int(top[0]);
							int top_y = top[1] - '0';
							int top_pozition = (top_x - 1) * 8 + top_y;
							vector <string> Gr_top_poz = Gr[top_pozition - 1];

							for (auto it = Gr_top_poz.begin(); it != Gr_top_poz.end(); it++) {	
								if (*it == final_answer.top()) {								//Если точка содержит в своём списке смежности верхушку стека-ответа
									final_answer.push(top);										//то добавляем её в стек-ответ и уже она становится новой верхушкой
									count++;
									break;
								}
							}
						}
					}

					if (count <= min_count) {			//Ищем только минимальные по длине пути
						cout << endl;
						while (!final_answer.empty()) {
							cout << final_answer.top() << ' ';
							final_answer.pop();
						}
						min_count = count;
						cout << endl;
					}

					used[t_pozition] = 0;			//Финиш отмечаем всегда 0, чтобы в него попадать ни один раз
				}
			}
		}
	}
}


int main() {						//Главная функция
	setlocale(LC_ALL, "RUS");		//Русская раскладка

	vector<bool> used(100);			//В данном векторе отмечаем "1" посещенные вершины
	vector<vector<string>> Gr;		//Список смежности
	
	string start;
	cout << "Точка старта, с которой мы начинаем обход: ";
	cin >> start;

	string finish;
	cout << "Точка финиша, куда мы хотим попасть: ";
	cin >> finish;

	for (int x = 1; x <= 8; x++) {    //Заполняем список смежности для каждой точке на шахматной доске    

		for (int y = 1; y <= 8; y++) {

			vector<string> vec;
			
			if ((x + 2) > 0 && (y + 1) > 0 && (x + 2) <= 8 && (y + 1) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x + 2);
				poz[1] = (y + 1) + '0';
				vec.push_back(poz);														//Если существует, то добавляем
			}
			if ((x + 2) > 0 && (y - 1) > 0 && (x + 2) <= 8 && (y - 1) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x + 2);
				poz[1] = (y - 1) + '0';
				vec.push_back(poz);														//Если существует, то добавляем
			}
			if ((x - 2) > 0 && (y + 1) > 0 && (x - 2) <= 8 && (y + 1) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x - 2);
				poz[1] = (y + 1) + '0';
				vec.push_back(poz);														//Если существует, то добавляем
			}
			if ((x - 2) > 0 && (y - 1) > 0 && (x - 2) <= 8 && (y - 1) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x - 2);
				poz[1] = (y - 1) + '0';
				vec.push_back(poz);														//Если существует, то добавляем
			}

			if ((x + 1) > 0 && (y + 2) > 0 && (x + 1) <= 8 && (y + 2) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x + 1);
				poz[1] = (y + 2) + '0';
				vec.push_back(poz);														//Если существует, то добавляем
			}
			if ((x + 1) > 0 && (y - 2) > 0 && (x + 1) <= 8 && (y - 2) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x + 1);
				poz[1] = (y - 2) + '0';	
				vec.push_back(poz);														//Если существует, то добавляем
			}
			if ((x - 1) > 0 && (y + 2) > 0 && (x - 1) <= 8 && (y + 2) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x - 1);
				poz[1] = (y + 2) + '0';
				vec.push_back(poz);														//Если существует, то добавляем
			}
			if ((x - 1) > 0 && (y - 2) > 0 && (x - 1) <= 8 && (y - 2) <= 8) {			//Проверка, что точка в списке смежности существует
				string poz = "__";
				poz[0] = int_into_char(x - 1);
				poz[1] = (y - 2) + '0';
				vec.push_back(poz);														//Если существует, то добавляем
			}

			Gr.push_back(vec);				//Добавляем этот список (вектор вернее) смежности в Список смежности всех точек

			vec.clear();					//Очищаем список смежности этой точки
		}
	}


	cout << endl << "-----------------------------------------------------------------" << endl;

	bfs(start, finish, used, Gr);			//Вызов функции обхода в ширину 
	
	cout << endl << "-----------------------------------------------------------------" << endl;

	system("pause");						//Пауза 
	return 0;								//Конец программы
}