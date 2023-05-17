// task1_10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>                //библиотека для потока входа-выхода
#include <cmath>                   //библиотека математических функций
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");      //использование русской клавиатуры
	float x, y;
	cout << "Введите число x\n"; 
	cin >> x;                      //ввод значения числа x        
	cout << "Введите число y\n"; 
	cin >> y;                      //ввод значения числа y
	float e = exp(1.0);
	float F = sqrt(cos(pow(e,sqrt(y+x))) / (sin(sqrt(pow(x,2)) - sqrt(pow(y,2)))));      //формула функции F(x,y)
	cout << "Функция F(x,y) равна " << F << endl;      //вывод функции F(x,y)
	system("pause");               //задержка консоли
	return 0;
}

