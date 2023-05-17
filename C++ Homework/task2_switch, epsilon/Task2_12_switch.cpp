#include <iostream>               //подключение библиотек
#include <cmath>                  //использование математических операций
using namespace std; 

int main() {
	setlocale(LC_ALL, "RUS");          //использование русской клваиатуры
	int d, m, y;
	cout << "Введите день, месяц и год через пробел\n";
	cin >> d >> m >> y;           //ввод чисел дня, месяца и года

	if (m > 12 || m < 0) {
		cout << "Неправильно введён месяц\n" << endl;
	}
	else {
		switch (m) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:   //31 день в месяце
				if (d < 0 || d > 31) {
					cout << "Неправильно введён день\n" << endl; break;
				}
				else {
					cout << "Дата корректна\n";
					if (m = 1) {
						cout << d << " января " << y << " года\n";
						cout << "осталось дней: " << 31 - d << endl; break;
					}
					else if (m = 3) {
						cout << d << " марта " << y << " года\n";
						cout << "осталось дней: " << 31 - d << endl; break;
					}
					else if (m = 5) {
						cout << d << " мая " << y << " года\n";
						cout << "осталось дней: " << 31 - d << endl; break;
					}
					else if (m = 7) {
						cout << d << " июля " << y << " года\n";
						cout << "осталось дней: " << 31 - d << endl; break;
					}
					else if (m = 8) {
						cout << d << " августа " << y << " года\n";
						cout << "осталось дней: " << 31 - d << endl; break;
					}
					else if (m = 10) {
						cout << d << " откября " << y << " года\n";
						cout << "осталось дней: " << 31 - d << endl; break;
					}
					else if (m = 12) {
						cout << d << " декабря " << y << " года\n";
						cout << "осталось дней: " << 31 - d << endl; break;
					}
				}


			case 4: case 6: case 9: case 11:   //30 дней в месяце
				if (d < 0 || d > 30) {
					cout << "Неправильно введён день\n" << endl; break;
				}
				else {
					cout << "Дата корректна\n";
					if (m = 4) {
						cout << d << " апреля " << y << " года\n";
						cout << "осталось дней: " << 30 - d << endl; break;
					}
					else if (m = 6) {
						cout << d << " июня " << y << " года\n";
						cout << "осталось дней: " << 30 - d << endl; break;
					}
					else if (m = 9) {
						cout << d << " мая " << y << " года\n";
						cout << "осталось дней: " << 30 - d << endl; break;
					}
					else if (m = 11) {
						cout << d << " ноября " << y << " года\n";
						cout << "осталось дней: " << 30 - d << endl; break;
					}

				}

			case 2: // Февраль
				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {  //високосный год
					if (d <= 0 || d > 29) {
						cout << "Неправильно введен день\n" << endl;
					}
					else {
						cout << "Дата корректна, год является високосным!\n";
						cout << d << " февраля " << y << " года\n";
						cout << "осталось дней: " << 29 - d << endl; break;
					}
				}
				else {                        //невисокосный год
					if (d <= 0 || d > 28) {
						cout << "Неправильно введен день\n" << endl;
					}
					else {
						cout << "Дата корректна, год не является високосным!\n";
						cout << d << " февраля " << y << " года\n";
						cout << "осталось дней: " << 28 - d << endl; break;
					}
				}

		}
	}
	system("pause");               //стоп
	return 0;                     //возвращаем в 0
}
