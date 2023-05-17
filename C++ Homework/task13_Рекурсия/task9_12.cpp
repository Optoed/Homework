//Задачи на использование рекурсивных функций - 12

#include <iostream>           //подключение библиотек ввода-вывода
#include <cmath>              //подключение библиотеки математических функций
#include <cstring>            //подключение библиотеки строки
using namespace std;

//рекурсивная функция перевода числа из 2-ой в 10-ую систему счисления
long Transformation(char str[64], int position, long number, long plus) {       
	if (position < strlen(str)) {
		if (str[strlen(str) - position] == '1') {
			return Transformation(str, position + 1, number+plus, plus*2);
		}
		else if (str[strlen(str) - position] == '0') {
			return Transformation(str, position + 1, number, plus * 2);
		}
		//если при вводе двоичного числа использовались символы помимо 0 и 1
		else if (str[strlen(str) - position] != '0' && str[strlen(str) - position] != '1') { 
			cout << "число в двоичной системе счисления было записано неверно" << endl;
		}
	}	
	else if (position == strlen(str)) {
		if (str[strlen(str) - position] == '1') {
			cout << "Answer (число в 10-ой системе счисления): " << number + plus << endl;
		}
		else if (str[strlen(str) - position] == '0') {
			cout << "Answer чЧисло в 10-ой системе счисления): " << number << endl;
		}
		//если при вводе двоичного числа использовались символы помимо 0 и 1
		else if (str[strlen(str) - position] != '0' && str[strlen(str) - position] != '1') { 
			cout << "число в двоичной системе счисления было записано неверно" << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");       //русская клавиатура

	long number = 0; //число в 10-ой степени счисления
	int position = 1;   //позиция (степень двойки)
	long plus = 1; //число, которое мы добавляем к number
	char str[64]; 
	cout << "Введите число в двоичной системе счисления:" << endl;
	cin >> str;      //ввод числа в двоичной степени счисления

	cout << endl;
	//вывод ответа
	Transformation(str, position, number, plus);

	return 0; //завершение работы программы
}