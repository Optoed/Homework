// Homework1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>                //библиотека для потока ввода-вывода
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
    float F = (1. / 5) * x * y + sqrt((pow(e, x - 1) + pow(e, y - 1)) / (pow(cos(x + 2 * y), 2)));    //формула функции F(x,y)
    cout << "Функция F(x,y) равна " << F << endl;    //вывод функции F(x,y)
    system("pause");               //задержка консоли
    return 0;
}

