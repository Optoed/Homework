
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

//Открытое хэширование
//Метод умножения по зарплате

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


void PeopleOutPrint(people x) {//вывод в файл
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


bool operator == (people a, people b) {
	if (a.Post == b.Post && a.Salary == b.Salary && a.Surname == b.Surname && a.WorkExperience == a.WorkExperience &&
		a.DateOfBirth.dd == a.DateOfBirth.dd && a.DateOfBirth.mm == a.DateOfBirth.mm && a.DateOfBirth.yy == a.DateOfBirth.yy) {
		return true;
	}
	else {
		return false;
	}
}


struct list { // описание двусвязного списка
	people item; // значение элемента
	list* prev; // указатель на предыдущий элемент
	list* next; // указатель на слудующий элемент
};


void PushBackList(list*& head, list*& tail, people x) { // вставка структуры people x в конец списка
	list* p = new list;
	p->item = x;
	p->next = NULL;

	if (!head && !tail) { // если список пуст
		p->prev = NULL;
		head = p;
	}
	else {
		tail->next = p;
		p->prev = tail;
	}

	tail = p; // элемент становится хвостом 
}


list* FindInList(list*& head, list*& tail, people x) { // поиск структуры people x в списке
	list* p = head; // указатель на голову списка
	while (p) { // проход по списку 
		if (p->item == x) {
			return p;
		}
		p = p->next;
	}
	return p;  //возвращаем указатель
}


void DeleteFromList(vector<pair<list*, list*>>& hash_table, list*& head, list*& tail, list* p, int &pozition) { // удаление эл-та p из списка
	if (p == head && p == tail) { //Если р - единственный эл-т в списке
		head = tail = NULL;
		hash_table[pozition].first = head;
		hash_table[pozition].second = tail;
	}
	else if (p == head) { // Если р - это голова
		head = head->next;
		head->prev = NULL;
		hash_table[pozition].first = head;
	}
	else if (p == tail) { // Если р - это хвост
		tail = tail->prev;
		hash_table[pozition].second = tail;
		tail->next = NULL;
	}
	else {            //Все остальные случаи
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	delete p; // очищение памяти, удаление р 
}


void HashTableFill(vector<pair<list*, list*>>& hash_table, vector<people>& x, double& A, int& M) { //Заполнения хэш-таблицы
	for (int i = 0; i < x.size(); i++) {
		//cout << "Salary = " << x[i].Salary << "\n";
		double Ax = x[i].Salary * A;
		//cout << "Ax = Salary * A = " << Ax << "\n";
		Ax -= floor(Ax);
		//cout << "остаток Ax = " << Ax << "\n";
		Ax *= M;
		//cout << "Ax * M = " << Ax << "\n";
		int pozition = int(Ax);
		//cout << "целое от Ax = " << pozition << "\n";
		PushBackList(hash_table[pozition].first, hash_table[pozition].second, x[i]);
		//cout << endl;
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


list* ElemFind(vector<pair<list*, list*>>& hash_table, people& elem, double& A, int& M, int &elem_pozition) {  //Поиск позиции элемента (Определяем в какой ячейке находится)
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	list* head = hash_table[pozition].first;
	list* tail = hash_table[pozition].second;
	//cout << "\nДанный элемент находится в " << pozition << "-ой ячейке Хэш-таблицы\n";
	elem_pozition = pozition;
	return FindInList(head, tail, elem);
}


void ElemPush(vector<pair<list*, list*>>& hash_table, people& elem, double& A, int& M) {   //Функция добавления элемента в хэш-таблицу
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	PushBackList(hash_table[pozition].first, hash_table[pozition].second, elem); //Добавили элемент в список хеш-таблицы
}


void ElemDelete(vector<pair<list*, list*>>& hash_table, people& elem, double& A, int& M, list*& p) {  //Удаление элемента
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	list* head = hash_table[pozition].first;
	list* tail = hash_table[pozition].second;
	DeleteFromList(hash_table, head, tail, p, pozition);
}


void FileOutPrint(vector<pair<list*, list*>>& hash_table) {
	for (int i = 0; i < hash_table.size(); i++) {
		list* h = hash_table[i].first; //Указатель на первого человека в i-списке
		while (h) {
			people x = h->item;
			out << i << ":  ";
			PeopleOutPrint(x);
			h = h->next;
		}
		out << endl;
	}
}


string razdelitel() {
	string razd(56, '-');
	return razd;
}


int main() {
	setlocale(LC_ALL, "RUS");
	system("chcp 1251 >> null");  //Чтобы string из русских букв правильно работал

	vector<people> x;
	x = inFile();		//Данные о людях

	double A = (sqrt(5) - 1) / 2;
	//cout << "A = " << A << "\n";
	int M = 8; //размерность хэш-таблицы

	vector<pair<list*, list*>> hash_table(M);  //Хэш-таблица
	people elem;

	HashTableFill(hash_table, x, A, M);  //Заполнения хэш-таблицы
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
			list* poz_check = ElemFind(hash_table, elem, A, M, elem_pozition);

			if (poz_check) {
				cout << "\nЭтот человек найден и находится в " << elem_pozition << "-ой ячейке хэш-таблицы.\n";
				cout << "\nХотите его удалить из таблицы (да/нет)?\n";
				string answer_del;
				cin >> answer_del;

				while (answer_del != "нет" && answer_del != "да") {
					cout << "\nВы ошиблись, введите слово повторно (только да/нет):\n";
					cin >> answer_del;
				}

				if (answer_del == "да") {
					ElemDelete(hash_table, elem, A, M, poz_check);
					cout << elem.Surname << " покинул хэш-таблицу...\n";
					out << endl << razdelitel() << endl << "Хэш-таблица после удаления человека c фамилией " << elem.Surname << "\n" << endl;
					FileOutPrint(hash_table);  //Вывод в файл содержимого хэш-таблицы
				}
				//Можешь ещё прописать варианты если "нет" или "другой ответ"
			}
			else {
				cout << "\nТакой человек не найден в хэш-таблице.\n";
				cout << "\nХотите его добавить в таблицу (да/нет)?\n";
				string answer_insert;
				cin >> answer_insert;

				while (answer_insert != "нет" && answer_insert != "да") {
					cout << "\nВы ошиблись, введите слово повторно (только да/нет):\n";
					cin >> answer_insert;
				}

				if (answer_insert == "да") {
					ElemPush(hash_table, elem, A, M);
					cout << elem.Surname << " внесён в хэш-таблицу...\n";
					out << endl << razdelitel() << endl << "Хэш-таблица после добавления нового человека c фамилией " << elem.Surname << "\n" << endl;
					FileOutPrint(hash_table);  //Вывод в файл содержимого хэш-таблицы
				}
				//Можешь ещё прописать варианты если "нет" или "другой ответ"
			}
		}
		else if (answer == "нет") {
			break;
		}

		cout << endl << endl;
		//Можешь ещё прописать варианты если "другой ответ"
	}

	return 0;
}