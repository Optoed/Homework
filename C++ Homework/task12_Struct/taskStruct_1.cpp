//Задачи на структуры - 1
//Создать структуру Train, содержащую данные о номере поезда, времени отправления, времени в пути.
//Определить для каждого поезда время прибытия на конечную станцию. Необходима проверка на корректность ввода времени
//*Первым выводит лишнюю информацию

#include<iostream>    //подключение библиотеки ввода-вывода
#include<string>     //подключение библиотеки строк
using namespace std;


struct Train {      //структура Train
	int number;        //номер поезда
	int hour1;         //часы (время отправления)  
	int minut1;        //минуты (время отправления)
	int hour2;         //часы (время в пути)
	int minut2;        //минуты (время в пути)
};


Train STR_date(string str) {      //перевод из строки, содержащей номер поезда, время отправления и время в пути, в структуру Train

	Train data;

	string::size_type k, t = 0;
	string punct = ".,;:- ";      //разделительные символы
	k = str.find_first_of(punct);       //поиск первого разделительного символа

	//--number-------
	string str1 = str.substr(t, k-t);         //операция перевода строки в число и занесение этого числа в структуру Train data
	const char* sd1 = str1.c_str();
	int numb = atoi(sd1);
	data.number = numb;
	t = k + 1;
	k = str.find_first_of(punct, k + 1);

	//—–hour1———————-
	string str2 = str.substr(t, k-t);           //операция перевода строки в число и занесение этого числа в структуру Train data
	const char* sd2 = str2.c_str();
	int dd2 = atoi(sd2);
	data.hour1 = dd2;
	t = k + 1;
	k = str.find_first_of(punct, k + 1);

	 //———minut1—————-
	string str3 = str.substr(t, k - t);           //операция перевода строки в число и занесение этого числа в структуру Train data
	const char* sd3 = str3.c_str();
	int dd3 = atoi(sd3);
	data.minut1 = dd3;
	t = k + 1;
	k = str.find_first_of(punct, k + 1);

	//—–hour2———————-
	string str4 = str.substr(t, k - t);              //операция перевода строки в число и занесение этого числа в структуру Train data
	const char* sd4 = str4.c_str(); 
	int dd4 = atoi(sd4);
	data.hour2 = dd4;
	t = k + 1;
	k = str.length();

	//———minut2—————-
	string str5 = str.substr(t, k - t);         //операция перевода строки в число и занесение этого числа в структуру Train data
	const char* sd5 = str5.c_str();
	int dd5 = atoi(sd5);
	data.minut2 = dd5;

	return data;
}


Train Next(Train x) {         //определяем время прибытия каждого поезда

	Train y = x;

	int newhour = 0, newminut = 0;
	int sumaminut = (x.hour1 + x.hour2) * 60 + (x.minut1 + x.minut2);           //переводим все часы в минуты и складываем с минутами

	newhour = (sumaminut / 60) % 24;          //время (часы) прибытия
	newminut = sumaminut % 60;              //время (минуты) прибытия

	y.hour2 = newhour;
	y.minut2 = newminut;

	cout << "сумма минут " << sumaminut << "; часы прибытия = " << newhour << "; минуты прибытия = " << newminut << endl;

	return y;
}


void print(Train x) {        //печать данных на экран

	if ((x.hour2 < 10 && x.hour2 > 0) && (x.minut2 < 10 && x.minut2 > 0) ) {
		cout << "Номер поезда = " << x.number << "; Время отбытия = " << x.hour1 << ":" << x.minut1         //печать данных
			<< "; Время прибытия = 0" << x.hour2 << ":0" << x.minut2 << endl;
	}

	else if ((x.hour2 >= 10) && (x.minut2 < 10 && x.minut2 > 0)) {
		cout << "Номер поезда = " << x.number << "; Время отбытия = " << x.hour1 << ":" << x.minut1         //печать данных
			<< "; Время прибытия = " << x.hour2 << ":0" << x.minut2 << endl;
	}

	else if (x.hour2 < 10 && x.hour2 > 0 && (x.minut2 >= 10)) {
		cout << "Номер поезда = " << x.number << "; Время отбытия = " << x.hour1 << ":" << x.minut1         //печать данных
			<< "; Время прибытия = 0" << x.hour2 << ":" << x.minut2 << endl;
	}

	else if (x.hour2 >= 10 && x.minut2 >= 10) {
		cout << "Номер поезда = " << x.number << "; Время отбытия = " << x.hour1 << ":" << x.minut1         //печать данных
			<< "; Время прибытия = " << x.hour2 << ":" << x.minut2 << endl;
	}
	
}


int correct(string str) {        //проверка корректности данных

	string punct = ".,;:- ";

	//if (str.length() < 13)            //пример минимального ввода: 1 12:40 3,6       минимум 11 знаков
		//return -1;

	for (string::size_type i = 0; i < str.length(); i++) {
		if (i != str.find_first_of(punct, i)) {
			if (!isdigit(str[i]))
				return -1;
		}
	}

	Train data = STR_date(str);

	if (data.number <= 0)
		return -2;

	if (data.hour1 < 0 || data.hour1 > 23 || data.hour2 < 0)              //часы (время отправления, в пределах от 0 до 23, всё включительно); время в пути > 0
		return -3;

	if (data.minut1 < 0 || data.minut1 > 59 || data.minut2 < 0)         //минуты (время отправления, в пределах от 0 до 59, всё включительно); время в пути > 0
		return -4;

	return 1;
}


int main() {      
	
	setlocale(LC_ALL, "RUS"); //русская клавиатура

	int N;      //количество поездов
	cout << "Введите количество поездов: ";
	cin >> N;    //ввод количества поездов
	cout << endl;

	for (int i = 0; i < N+1; i++) {
		string str;
		if (i != 0) 
			cout << i << ") Номер поезда, время отправления(часы и минуты), время в пути(часы и минуты):" << endl;
		getline(cin, str);

		int fl = correct(str);          //Далее следуют возможные выводы ошибок при вводе данных

		if (i != 0) {
			if (fl == -1)
				cout << "Неправильный ввод данных\n";

			else if (fl == -2)
				cout << "Неправильный ввод номера поезда\n";

			else if (fl == -3)
				cout << "Неправильный ввод числа часов\n";

			else if (fl == -4)
				cout << "Неправильный ввод числа минут\n";

			else {       //если правильно ввели данные
				Train data = STR_date(str);
				Train N_date = Next(data);
				print(N_date);
			}
			cout << endl;
		}
	}
	
	return 0;  //конец программы
}