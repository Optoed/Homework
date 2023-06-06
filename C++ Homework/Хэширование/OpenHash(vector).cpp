
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
#include<list>
#include<iomanip>
#include<cmath>
#include <algorithm>
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
	x.dd = atoi(temp.c_str());

	temp = str.substr(3, 2);//месяц
	x.mm = atoi(temp.c_str());

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

void print(people x) {//вывод в файл
	out << setw(15) << left << x.Surname;//по левому краю, 15 позиций для фамилии
	out << setw(9) << left << x.Post;//по левому краю, 15 позиций для должности
	if (x.DateOfBirth.dd < 10)
		out << left << ' 0' << x.DateOfBirth.dd << '.';//добавляем 0
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


void HeshPrint(vector<vector<people>>& h) { //Вывод хэш-таблицы
	for (int i = 0; i < h.size(); i++) {	
		for (int j = 0; j < h[i].size(); j++) {
			out << i << ":  ";
			print(h[i][j]);
		}
		out << endl;
	}
}


void HeshFill(vector<vector<people>>& h, vector<people>& x, double& A, int& M) { //Заполнения хэш-таблицы
	for (int i = 0; i < x.size(); i++) {
		cout << "Salary = " << x[i].Salary << "\n";
		double Ax = x[i].Salary * A;
		cout << "Ax = Salary * A = " << Ax << "\n";
		Ax -= floor(Ax);
		cout << "остаток Ax = " << Ax << "\n";
		Ax *= M;
		cout << "Ax * M = " << Ax << "\n";
		int pozition = int(Ax);
		cout << "целое от Ax = " << pozition << "\n";
		h[pozition].push_back(x[i]);
		cout << endl;
	}
}


void ElemCreate(people& elem) {					//Создание элемента
	cout << "Введите фамилию: ";
	cin >> elem.Surname;//фамилия
	cout << "Введите должность: ";
	cin >> elem.Post; //должность
	string tmp;//дата рождения
	cout << "Введите введите полную дату рождения: ";
	cin >> tmp;
	elem.DateOfBirth = Str_to_Date(tmp);
	cout << "Введите опыт работы: ";
	cin >> elem.WorkExperience; //Опыт работы
	cout << "Введите зарплату: ";
	cin >> elem.Salary;//зарплата
}


void ElemPush(vector<vector<people>>& h, people& elem, double &A, int &M) {   //Функция добавления элемента в хэш-таблицу и поиск позиции этого элемента (Определяем в какой ячейке находится)
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	h[pozition].push_back(elem);
}


void ElemFind(vector<vector<people>>& h, people& elem, double& A, int& M) {  //Поиск позиции элемента (Определяем в какой ячейке находится)
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	cout << "\nДанный элемент находится в " << pozition << "-ой ячейке Хэш-таблицы\n";
}


void ElemDelete(vector<vector<people>>& h, people& elem, double& A, int& M) {  //Удаление элемента
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	for (int i = 0; i < h[pozition].size(); i++) {
		if (h[pozition][i] == elem) {
			h[pozition].erase(h[pozition].begin() + i);
			break;
		}
	}
}


string razdelitel() {
	string razd(56, '-');
	return razd;
}


int main() {
	setlocale(LC_ALL, "RUS");
	


	vector<people> x;
	x = inFile();		//Данные о людях

	double A = (sqrt(5) - 1) / 2;
	cout << "A = " << A << "\n";
	int M = 8; //размерность хэш-таблицы

	vector<vector<people>> h(M);  //Хэш-таблица

	HeshFill(h, x, A, M);

	HeshPrint(h);

	people elem;
	ElemCreate(elem);
	ElemPush(h, elem, A, M);
	out << endl << razdelitel() << endl << "Хэш-таблица после добавления нового элемента:\n" << endl;
	HeshPrint(h);

	ElemFind(h, elem, A, M);

	ElemDelete(h, elem, A, M);
	out << endl << razdelitel() << endl << "Хэш-таблица после удаления элемента:\n" << endl;
	HeshPrint(h);

	return 0;
}