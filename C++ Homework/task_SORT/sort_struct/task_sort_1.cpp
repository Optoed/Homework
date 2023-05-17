#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;


ifstream in("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megainput.txt");
ofstream out("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\megaoutput.txt");

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
	x.yy = atoi(temp.c_str());

	return x;
}

vector<people> inFile() {//ввод из файла
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;//фамилия
		in >> temp.Post;
		string tmp;//дата рождения
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);
		in >> temp.WorkExperience;
		in >> temp.Salary;//зарплата
		x.push_back(temp);
	}

	return x;
}

void print(people x) {//вывод в файл
	out << x.Surname;//по левому краю, 10 позиций для фамилии
	out << x.Post;//по левому краю, 10 позиций для фамилии
	if (x.DateOfBirth.dd < 10)
		out << left << ' 0' << x.DateOfBirth.dd << '.';//добавляем 0
	else
		out << left << ' ' << x.DateOfBirth.dd << '.';

	if (x.DateOfBirth.mm < 10)
		out << '0' << x.DateOfBirth.mm << '.';
	else
		out << x.DateOfBirth.mm << '.';

	out << x.DateOfBirth.yy << ' ';//на год 6 позиций
	out << x.WorkExperience << ' ';//по левому краю, 10 позиций для фамилии
	out << x.Salary << endl;//зарплата
	
}

bool operator < (people a, people b) {//переопределяем оператор < в соотвествии с условием
	if (a.Surname < b.Surname)
		return true;
	if (a.Surname == b.Surname && a.DateOfBirth.yy < b.DateOfBirth.yy)
		return true;
	if (a.Surname == b.Surname && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Salary < b.Salary)
		return true;
	return false;

}

void stupid_sort(vector<people> &x) {//глупая сортировка
	for (int i = 0; i < x.size() - 1;) {
		if (x[i + 1] < x[i]) {//не на месте
			swap(x[i], x[i + 1]);//поменяли
			i = 0;//возвращаемя в начало
		}
		else
			i++;//идем дальше
	}
	
}

int main() {
	vector<people> x;
	x = inFile();
	stupid_sort(x);

	for (int i = 0; i < x.size(); i++)
		print(x[i]);

	return 0;
}