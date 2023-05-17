//номер 16

#include <iostream>    //подключение библиотек ввода-вывода
#include <cmath>       //подключение библиотек математических функций    
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <set>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");        //использование русской клавиатуры
	;
	set <int> first{ 3, 5 };

	auto it = first.begin();

	for (int i = 1; it != first.end(); i++, it++) {
		cout << *it << " ";
	}

	system("pause");     //завершение программы
	return 0;
}