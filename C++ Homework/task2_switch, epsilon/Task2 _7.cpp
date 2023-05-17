#include <iostream> // /Подключение библиотек
#include <cmath>	//Использование математических функций
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS"); //Использование русской клавиатуры

	float x;
	cout << "x = ";
	cin >> x; //Ввод числа x
	const float eps = 0.00000001;
	if (x < -5)
	{
		cout << "Корень из отрицательного числа\n";
	}
	else if (abs(x + 1) < eps)
	{
		cout << "Деление на 0\n";
	}
	else if (x > 4 || abs(x - 4) < eps)
	{
		cout << "Логарифм из неположительного числа\n";
	}
	else
	{
		float Y = (sqrt(x + 5) + log(8 - 2 * x)) / sqrt(x * x + 2 * x + 1);
		cout << "Функция F(x) определена и равна " << Y << endl; //Вывод F(x)
	}

	system("pause"); //Ставим на паузу
	return 0;		 ///Возвращаем ноль
}
