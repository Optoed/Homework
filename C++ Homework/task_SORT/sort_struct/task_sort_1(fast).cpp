/*
* Работа обязательно с файлами.
* В файле содержатся данные о сотрудниках предприятия: фамилия, должность, дата рождения (день, месяц, год), стаж работы, зарплата (не менее 20 человек).
* В новый файл вывести данные, отсортированные по какому-либо ключу (в зависимости от номера задания).
* Вывод в новом файле ОБЯЗАТЕЛЬНО должен быть отформатирован.
* Сначала по одному ключу, потом по другому означает сравнения вида:
* if(a[i].key1 < a[j].key1 || (a[i].key1 == a[j].key1 && a[i].key2 < a[j].key2))
*/

//1. По зарплате с помощью быстрой сортировки.

#include<iostream> //подключение библиотек
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megainput.txt"); //файл "in" с данными
ofstream out("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megaoutput1_fast.txt"); //файл "out" для вывода данных

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
	if (a.Salary < b.Salary) //сортируем по зарплате
		return true;

	return false;
}

bool operator > (people a, people b) {//переопределяем оператор < в соотвествии с условием
	if (a.Salary > b.Salary) //сортируем по зарплате
		return true;
	
	return false;
}

void quick_sort(vector<people>&x, int l, int r) {  //быстрая сортировка
	
	int i = l, j = r;
	people m = x[(l + r) / 2]; //опорный элемент
	
	while (i <= j) { // процесс сортировки
		while (x[i] > m) {
			i++;
			
		}
		while (x[j] < m) {
			j--;
		
		}
		if (i <= j) {
			swap(x[i], x[j]);
			j--;
			i++;
		
		}
	}

	if (j - l > 0)
		quick_sort(x, l, j);
	if (r - i > 0)
		quick_sort(x, i, r);
}


int main() { //главная функция

	setlocale(LC_ALL, "RUS"); //русская клавиатура

	if (!in.is_open()) {    //проверяем, открылся ли файл
		cout << "Файл не был открыт!";
	}
	else
		cout << "Файл открыт!";

	vector<people> x;
	x = inFile();
	size_t l = 0, r = x.size() - 1;

	quick_sort(x, l, r); //вызываем функцию с сортировкой

	for (int i = 0; i < x.size(); i++)  //выводим в файл
		print(x[i]);

	return 0; //конец программы
}