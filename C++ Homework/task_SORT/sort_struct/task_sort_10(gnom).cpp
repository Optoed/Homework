/*
* Работа обязательно с файлами.
* В файле содержатся данные о сотрудниках предприятия: фамилия, должность, дата рождения (день, месяц, год), стаж работы, зарплата (не менее 20 человек).
* В новый файл вывести данные, отсортированные по какому-либо ключу (в зависимости от номера задания).
* Вывод в новом файле ОБЯЗАТЕЛЬНО должен быть отформатирован.
* Сначала по одному ключу, потом по другому означает сравнения вида:
* if(a[i].key1 < a[j].key1 || (a[i].key1 == a[j].key1 && a[i].key2 < a[j].key2))
*/

//10. Сначала по должности, потом по зарплате с помощью гномьей сортировки.

#include<iostream> //подключение библиотек
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include <algorithm>
using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megainput.txt"); //файл "in" с данными
ofstream out("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megaoutput10_gnom.txt"); //файл "out" для вывода данных

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

bool operator <= (people a, people b) { //переопределяем оператор < в соотвествии с условием

	vector<string> posts = { "Intern", "Junior", "Middle", "Junior" };

	vector<string>::iterator itera = find(posts.begin(), posts.end(), a.Post);
	vector<string>::iterator iterb = find(posts.begin(), posts.end(), b.Post);

	if ((itera-posts.begin()) < (iterb-posts.begin())) //сортируем по должности
		return true;

	if (((itera - posts.begin()) == (iterb - posts.begin())) && (a.Salary <= b.Salary)) //сортируем по зарплате
		return true;

	return false;
}


bool operator >= (people a, people b) {//переопределяем оператор < в соотвествии с условием
	vector<string> posts = { "Intern", "Junior", "Middle", "Senior" };

	vector<string>::iterator itera = find(posts.begin(), posts.end(), a.Post);
	vector<string>::iterator iterb = find(posts.begin(), posts.end(), b.Post);

	if ((itera - posts.begin()) > (iterb - posts.begin())) //сортируем по должности
		return true;

	if (((itera - posts.begin()) == (iterb - posts.begin())) && (a.Salary >= b.Salary)) //сортируем по зарплате
		return true;

	return false;
}

void gnom_sort(vector<people>& x) {  //гномья сортировка

	int i = 1;

	while (i < x.size()) { // процесс сортировки
		if (i == 0) {
			i++;
		}

		if (x[i - 1] >= x[i]) {
			i++;
		}

		else {
			swap(x[i - 1], x[i]);
			i--;
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
	gnom_sort(x); //вызываем функцию с сортировкой

	for (int i = 0; i < x.size(); i++)  //выводим в файл
		print(x[i]);

	cout << "Сортировка завершена!" << endl;

	return 0; //конец программы
}