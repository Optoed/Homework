
/*
В файле содержатся данные о сотрудниках предприятия:
фамилия, должность, дата рождения (день, месяц, год), стаж работы, зарплата (не менее 20 человек).
Файл прикрепить.
Выполнить открытое и закрытое хэширование (лучше две разных программы).
Продемонстрировать поиск элемента (и в том и в другом случае) и удаление элемента (для открытого хэширования).
Хэш-функция и ключ хэширования - выбираете в опросе.

Программа должна демонстрировать - хэширование, вывод полученной хэш-таблицы, возможность ввода элемента, его поиск (вывести все данные, соответствующие этому элементу).
В случае открытого хэширования - удаление всех данных, соответствующих этому элементу.

Для открытого хэширования использовать самостоятельно написанные функции для двусвязного списка.
*/

//Закрытое хэширование
//Основная — двойное хеширование 
//Вспомогательная — метод деления по стажу

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include <algorithm>
#include<iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <clocale>
#include <cstdlib>
#include <windows.h>

using namespace std;


ifstream in("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Хэширование\\megainput.txt");
ofstream out("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Хэширование\\megaoutput.txt");


struct date {//дата
	int dd, mm, yy;
};


struct people {//данные о человеке
	string Surname; //фамилия
	string Post; //должность
	date DateOfBirth; //дата рождения
	int WorkExperience; //опыт работы (в годах)
	int Salary; //зарплата
};


date Str_to_Date(string str) {//из строки в дату
	date x;

	string temp = str.substr(0, 2);//день
	x.dd = stoi(temp);

	temp = str.substr(3, 2);//месяц
	x.mm = stoi(temp);

	temp = str.substr(6, 4);//год
	x.yy = stoi(temp);

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
		in >> temp.WorkExperience; //Опыт работы
		in >> temp.Salary;//зарплата
		x.push_back(temp);
	}

	return x;
}


bool operator == (people a, people b) {
	if (a.Post == b.Post && a.Salary == b.Salary && a.Surname == b.Surname && a.WorkExperience == a.WorkExperience &&
		a.DateOfBirth.dd == a.DateOfBirth.dd && a.DateOfBirth.mm == a.DateOfBirth.mm && a.DateOfBirth.yy == a.DateOfBirth.yy) {
		return true;
	}
	else {
		return false;
	}
}


people ElemCreate() {					//Создание структуры элемента из содержимого ввода данных
	cout << "\nВведите фамилию, должность, дату рождения, опыт работы и зарплату человека:\n";
	people elem;
	cin >> elem.Surname;//фамилия
	cin >> elem.Post; //должность
	string tmp;//дата рождения
	cin >> tmp;
	elem.DateOfBirth = Str_to_Date(tmp);
	cin >> elem.WorkExperience; //Опыт работы
	cin >> elem.Salary;//зарплата
	return elem;
}


string razdelitel() {      //красивый разделитель
	string razd(56, '-');
	return razd;
}


int h1(int number, int m) { // метод деления
	return number % m;
}


int HashFunction(vector<people>& hash_table, people x, int m, people INF) { // квадратичное хэширование
	int i = 0;
	int x_mod_m = h1(x.WorkExperience, m);
	int pozition = x_mod_m;
	while (pozition < m && !(hash_table[pozition] == INF)) {
		i++;
		pozition = h1(x_mod_m + i * (1 + h1(x.WorkExperience, m - 1)), m);
	}
	return pozition;
}


bool FindPeople(vector<people>& hash_table, people x, int m, people INF, int &elem_pozition) { // нахождение элемента в хэш-таблице
	int i = 0;
	int x_mod_m = h1(x.WorkExperience, m);
	int pozition = x_mod_m;

	while (pozition < m && !(hash_table[pozition] == INF) && !(hash_table[pozition] == x)) {
		i++;
		pozition = h1(x_mod_m + i * (1 + h1(x.WorkExperience, m - 1)), m);
	}

	if (pozition < m && hash_table[pozition] == x) {
		elem_pozition = pozition;
		return true;
	}

	else {
		return false;
	}
}


void HashTableFill(vector<people>& hash_table, vector<people>& x, int m, people INF) { // заполнение хэш-таблицы
	for (auto human : x) {
		int pozition = HashFunction(hash_table, human, m, INF);
		if (pozition < m) {
			hash_table[pozition] = human;
		}
	}
}


void PeopleOutPrint(people x) {//вывод в файл одного человека
	out << setw(15) << left << x.Surname;//по левому краю, 15 позиций для фамилии
	out << setw(9) << left << x.Post;//по левому краю, 15 позиций для должности

	if (x.DateOfBirth.dd < 10)
		out << left << " 0" << x.DateOfBirth.dd << '.';//добавляем 0
	else
		out << left << ' ' << x.DateOfBirth.dd << '.';

	if (x.DateOfBirth.mm < 10)
		out << left << '0' << x.DateOfBirth.mm << '.';//добавляем 0
	else
		out << left << x.DateOfBirth.mm << '.';

	out << setw(8) << left << x.DateOfBirth.yy;//на год 6 позиций
	out << setw(6) << left << x.WorkExperience;//по левому краю, 4 позиции для опыта работы
	out << setw(15) << left << x.Salary << endl;//зарплата
}


void FileOutPrint(vector<people>& hash_table) {		//Вывод таблицы в файл
	for (int i = 0; i < hash_table.size(); i++) {
		out << i << ":  ";
		PeopleOutPrint(hash_table[i]);
	}
}


int main() {
	setlocale(LC_ALL, "RUS");
	system("chcp 1251 >> null");  //Чтобы string из русских букв правильно работал

	int n = 24; //Количество людей
	vector<people> x;
	x = inFile();		//Данные о людях
	
	int m = 29; //Простое число большее N
	int m1 = 28;  // m1 = m - 1

	people INF;
	INF.Surname = ' ';
	INF.Post = ' ';
	INF.Salary = 0;
	INF.WorkExperience = 0;
	INF.DateOfBirth.dd = 0;
	INF.DateOfBirth.mm = 0;
	INF.DateOfBirth.yy = 0;

	vector<people> hash_table(m, INF);  //Хэш-таблица
	people elem;
	

	HashTableFill(hash_table, x, m, INF);  //Заполнения хэш-таблицы
	FileOutPrint(hash_table);  //Вывод в файл содержимого хэш-таблицы

	string answer = "да";

	while (answer == "да") {
		cout << "\nВведите 'да' - если хотите проверить человека на наличие в хэш-таблице;\n"
			<< "Введите 'нет' - если хотите завершить работу программы:\n";
		cin >> answer;

		while (answer != "нет" && answer != "да") {
			cout << "\nВы ошиблись, введите слово повторно (только да/нет):\n";
			cin >> answer;
		}	

		if (answer == "да") {
			people elem = ElemCreate();
			int elem_pozition;
			bool poz_check = FindPeople(hash_table, elem, m, INF, elem_pozition);

			if (poz_check) {
				cout << "\nЭтот человек найден и находится в " << elem_pozition << "-ой ячейке хэш-таблицы.\n";
			}
			else {
				cout << "\nТакой человек не найден в хэш-таблице.\n";
			}
		}

		else if (answer == "нет") {
			break;
		}

		cout << endl << endl;
	}

	return 0;
}