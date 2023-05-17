/*
* Работа обязательно с файлами.
* В файле содержатся данные о сотрудниках предприятия: фамилия, должность, дата рождения (день, месяц, год), стаж работы, зарплата (не менее 20 человек).
* В новый файл вывести данные, отсортированные по какому-либо ключу (в зависимости от номера задания).
* Вывод в новом файле ОБЯЗАТЕЛЬНО должен быть отформатирован.
* Сначала по одному ключу, потом по другому означает сравнения вида:
* if(a[i].key1 < a[j].key1 || (a[i].key1 == a[j].key1 && a[i].key2 < a[j].key2))
*/

//12. Сначала по фамилии, потом по стажу работы, потом по зарплате с помощью сортировки чет - нечет.


#include<iostream> //подключение библиотек
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include <algorithm>
using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megainput.txt"); //файл "in" с данными
ofstream out("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megaoutput12_odd_even.txt"); //файл "out" для вывода данных

struct date {     // структура даты рождения
	int dd, mm, yy;
};

struct people {          //данные о человеке
	string Surname; //фамилия
	string Post; //должность
	date DateOfBirth; //дата рождения
	int WorkExperience; //опыт работы (в годах)
	int Salary; //зарплата
};

date Str_to_Date(string str) {//из строки в дату
	date x;

	string temp = str.substr(0, 2);//день
	x.dd = atoi(temp.c_str());

	temp = str.substr(3, 2);//месяц
	x.mm = atoi(temp.c_str());

	temp = str.substr(6, 4);//год
	x.yy = atoi(temp.c_str());

	return x;
}

vector<people> inFile() {//ввод из файла
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;//фамилия

		in >> temp.Post; //должность

		string tmp;//дата рождения
		in >> tmp;

		temp.DateOfBirth = Str_to_Date(tmp);

		in >> temp.WorkExperience; //опыт работы

		in >> temp.Salary;//зарплата

		x.push_back(temp);
	}

	return x;
}



void print(people x) {//вывод в файл
	out << setw(14) << left << x.Surname;//по левому краю, 10 позиций для фамилии
	out << setw(12) << left << x.Post;//по левому краю, 10 позиций для фамилии

	if (x.DateOfBirth.dd < 10)
		out << left << '0' << x.DateOfBirth.dd << '.'; //добавляем 0
	else
		out << left << x.DateOfBirth.dd << '.';

	if (x.DateOfBirth.mm < 10)
		out << '0' << x.DateOfBirth.mm << '.'; //добавляем 0
	else
		out << x.DateOfBirth.mm << '.';

	out << left << setw(10) << x.DateOfBirth.yy;//год рождения

	out << left << setw(6) << x.WorkExperience; //опыт работы

	out << left << setw(10) << x.Salary << endl;//зарплата

}

bool operator < (people a, people b) { //переопределяем оператор < в соотвествии с условием

	if (a.Surname < b.Surname) //сортируем по фамилии
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience > b.WorkExperience)) //сортируем по опыту работы
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience == b.WorkExperience) && (a.Salary > b.Salary)) //сортируем по зарплате
		return true;

	return false;
}


bool operator > (people a, people b) {//переопределяем оператор < в соотвествии с условием

	if (a.Surname > b.Surname) //сортируем по фамилии
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience < b.WorkExperience)) //сортируем по опыту работы
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience == b.WorkExperience) && (a.Salary < b.Salary)) //сортируем по зарплате
		return true;

	return false;
}

void odd_even_sort(vector<people>& x) {  //быстрая сортировка

	for (int i = 0; i < x.size() - 1;i++) {
		if (i % 2 == 0) {
			for (int j = 2; j < x.size() - 1; j += 2) {
				if (x[j - 1] > x[j]) {
					swap(x[j - 1], x[j]);
				}
			}
		}
		else {
			for (int j = 1; j < x.size() - 1; j += 2) {
				if (x[j - 1] > x[j]) {
					swap(x[j - 1], x[j]);
				}
			}
		}
	}

}


int main() { //главная функция

	setlocale(LC_ALL, "RUS"); //русская клавиатура

	if (!in.is_open()) {    //проверяем, открылся ли файл
		cout << "Файл не был открыт!" << endl;
	}
	else
		cout << "Файл открыт!" << endl;

	vector<people> x;
	x = inFile();
	vector<string> posts = { "Intern", "Junior", "Middle", "Senior" }; //список должностей
	odd_even_sort(x); //вызываем функцию с сортировкой

	for (int i = 0; i < x.size(); i++)  //выводим в файл
		print(x[i]);

	cout << "Сортировка завершена!" << endl;

	return 0; //конец программы
}