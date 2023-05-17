#include <iostream> // /Подключение библиотек
#include <cmath>	//Использование математических функций
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS"); //Использование русской клавиатуры
	int A, X;
	cout << "Введите трехзначное число A\n";
	cin >> A; //Ввод числа А
	cout << "Введите однозначное число X\n";
	cin >> X; //Ввод числа Х

	if (A < 100 || A > 999 || X <= 0 || X > 9) //Проверяем на правильность введённых данных
	{
		cout << "Неправильно введены данные\n";
	}
	else //В этом случае данные верны
	{
		int a1 = A / 100;
		int a2 = (A / 10) % 10;
		int a3 = A % 10;
		int Anew;
		if (a1 > X && a2 > X && a3 > X)
		{
			Anew = A - 100;
			cout << Anew << endl;
		}
		else if (a1 > X && a2 > X)
		{
			Anew = A + 100;
			cout << Anew << endl;
		}
		else if (a1 < X && a2 < X && a3 < X)
		{
			Anew = A - 50;
			cout << Anew << endl;
		}
		else if (a2 < X && a3 < X)
		{
			Anew = A + 50;
			cout << Anew << endl;
		}
		else
		{
			Anew = A + 10;
			cout << Anew << endl;
		}
	}
	system("pause"); //Ставим на паузу
	return 0;		 ///Возвращаем ноль
}
