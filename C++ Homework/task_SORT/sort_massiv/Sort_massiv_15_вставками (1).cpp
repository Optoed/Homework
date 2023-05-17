/*
* В файле содержится двумерный массив размерностью n × n.
* В новый файл вывести отсортированный массив.
* 
* 15. Диагонали, параллельные побочной по возрастанию с помощью сортировки вставками.
*/

#include <iostream> //подключение библиотек
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


ifstream fin("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\sort_massiv\\input_sort_massiv.txt"); //открываем файл с данными
ofstream fout("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\sort_massiv\\output_sort_massiv_15.txt"); //записываем ответ в новый файл


bool Check() {    //Проверяем, открылся ли файл

	if (!fin.is_open()) {  
		return 0;
	}

	else {
		return 1;
	}
}

vector <vector<int> > Fill() {  //Считывание с исходного файла данных в vector <vecotr <int> > a

	vector <vector<int> > a;

	bool move = 0;
	int number;

	string line, subline;
	string::size_type k, pos;

	while (getline(fin, line)) { //считываем строки исходного файла

		if (move == 1) {         //Первую строчку мы пропускаем и не считываем, так как там записан размер массива
			vector <int> a1;
			pos = 0;
			k = line.find(' ', pos);
			while (k != string::npos) { //проходимся по строке и записываем в вектор
				subline = line.substr(pos, k - pos);
				number = stoi(subline);
				a1.push_back(number);
				pos = k + 1;
				k = line.find(' ', pos);
			}
			
			if (k > line.size()) {
				k = line.size();
				subline = line.substr(pos, k - pos);
				number = stoi(subline);
				a1.push_back(number);
			}

			a.push_back(a1);
		}
		
		else {
			move = 1;
		}
	}

	return a; //возвращаем вектор чисел
}

void Sort(vector<vector<int> >& a) {     //Сортировка (как в условии)

	vector<int>vecforsort;

	for (int stroka = 0; stroka < a.size(); stroka++) {

		for (int stolbec = stroka, l = 0; stolbec >= 0, l <= stroka; stolbec--, l++) {
			cout << "l = " << l << " j = " << stolbec << " a[l][stolbec] = " << a[l][stolbec] << endl;
			vecforsort.push_back(a[l][stolbec]);
 		}

		for (int i = 1; i <= stroka; i++) {
			int j = i;
			while (j > 0 && vecforsort[j] < vecforsort[j - 1]) {
				swap(vecforsort[j], vecforsort[j - 1]);
				j--;
			}
		}

		for (int stolbec = stroka, l = 0; stolbec >= 0, l <= stroka; stolbec--, l++) {
			a[l][stolbec] = vecforsort[l];
			cout << " vecforsort[l] = " << a[l][stolbec] << endl;
			
		}
		
		vecforsort.clear();

		if (stroka == a.size()-1) {



			cout << endl;
			for (int l = 1; l <= stroka; l++) {
				int p = l;

				for (int p = l, stolbec = stroka; stolbec >= 0, p <= stroka; p++, stolbec--) {
					cout << "p = " << p << " stolbec = " << stolbec << " a[p][stolbec] = " << a[p][stolbec] << endl;
					vecforsort.push_back(a[p][stolbec]);
				}
				
				for (int i = 0; i < vecforsort.size(); i++) {
					cout << "   element = " << vecforsort[i] << endl;
				}
				cout << "Размер векфорсорт = " << vecforsort.size() << endl;
				cout << "            a.size() " << a.size() << " p = " << p << endl;
				for (int i = 1; i < a.size() - p ; i++) {
					int j = i;
					cout << vecforsort[j - 1] << ' ' << vecforsort[j] << endl;
					while (j > 0 && vecforsort[j] < vecforsort[j - 1]) {
						swap(vecforsort[j], vecforsort[j - 1]);
						cout << j << endl;
						j--;
					}
					cout << "i = " << i << endl;
					
				}
				cout << endl;
				for (auto i : vecforsort) {
					cout << "   element = " << i << endl;
				}

				for (int p = l, stolbec = stroka, i = 0; stolbec >= 0, p <= stroka; p++, stolbec--, i++) {
					cout << "SSSSSSSSSS" << " p = " << p << " stolbec = " << stolbec << " a[p][stolbec] = " << a[p][stolbec] << endl;
					cout << " vecforsort[p] = " << vecforsort[i] << endl;
					a[p][stolbec] = vecforsort[i];
				}

				vecforsort.clear();
			}
		}

	}

}

void Print(vector<vector<int>> &a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

void Output(vector <vector <int> >& a) {

	fout << a.size() << endl;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (j < a.size() - 1)
				fout << a[i][j] << ' ';
			else
				fout << a[i][j];
		}
		fout << endl;
	}
	cout << "Содержимое отсортированого n*n двумерного массива было записано в output_sort_massiv_15.txt" << endl;
}

int main() {

	setlocale(LC_ALL, "RUS");

	bool check = Check();

	if (check)
		cout << "Файл открылся!" << endl;
	else
		cout << "Файл не открылся!" << endl;
	cout << endl;

	vector<vector<int> > a, a_sort;

	a = Fill();

	cout << "Вывод исходного n*n двумерного массива:" << endl;
	cout << a.size() << endl;
	Print(a);
	
	cout << endl;

	a_sort = a;
	int l = 0;
	int r = a_sort.size() - 1;

	Sort(a_sort);

	cout << "Вывод n*n двумерного массива после сортировки вставками:" << endl;
	cout << a.size() << endl;
	Print(a_sort);
	cout << endl;

	Output(a_sort);

	fin.close();
	fout.close();

	return 0;
}