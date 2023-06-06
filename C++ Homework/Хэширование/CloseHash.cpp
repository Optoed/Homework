
/*
� ����� ���������� ������ � ����������� �����������:
�������, ���������, ���� �������� (����, �����, ���), ���� ������, �������� (�� ����� 20 �������).
���� ����������.
��������� �������� � �������� ����������� (����� ��� ������ ���������).
������������������ ����� �������� (� � ��� � � ������ ������) � �������� �������� (��� ��������� �����������).
���-������� � ���� ����������� - ��������� � ������.

��������� ������ ��������������� - �����������, ����� ���������� ���-�������, ����������� ����� ��������, ��� ����� (������� ��� ������, ��������������� ����� ��������).
� ������ ��������� ����������� - �������� ���� ������, ��������������� ����� ��������.

��� ��������� ����������� ������������ �������������� ���������� ������� ��� ����������� ������.
*/

//�������� �����������
//�������� � ������� ����������� 
//��������������� � ����� ������� �� �����

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


ifstream in("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\�����������\\megainput.txt");
ofstream out("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\�����������\\megaoutput.txt");


struct date {//����
	int dd, mm, yy;
};


struct people {//������ � ��������
	string Surname; //�������
	string Post; //���������
	date DateOfBirth; //���� ��������
	int WorkExperience; //���� ������ (� �����)
	int Salary; //��������
};


date Str_to_Date(string str) {//�� ������ � ����
	date x;

	string temp = str.substr(0, 2);//����
	x.dd = stoi(temp);

	temp = str.substr(3, 2);//�����
	x.mm = stoi(temp);

	temp = str.substr(6, 4);//���
	x.yy = stoi(temp);

	return x;
}


vector<people> inFile() {//���� �� �����
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;//�������
		in >> temp.Post; //���������
		string tmp;//���� ��������
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);
		in >> temp.WorkExperience; //���� ������
		in >> temp.Salary;//��������
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


people ElemCreate() {					//�������� ��������� �������� �� ����������� ����� ������
	cout << "\n������� �������, ���������, ���� ��������, ���� ������ � �������� ��������:\n";
	people elem;
	cin >> elem.Surname;//�������
	cin >> elem.Post; //���������
	string tmp;//���� ��������
	cin >> tmp;
	elem.DateOfBirth = Str_to_Date(tmp);
	cin >> elem.WorkExperience; //���� ������
	cin >> elem.Salary;//��������
	return elem;
}


string razdelitel() {      //�������� �����������
	string razd(56, '-');
	return razd;
}


int h1(int number, int m) { // ����� �������
	return number % m;
}


int HashFunction(vector<people>& hash_table, people x, int m, people INF) { // ������������ �����������
	int i = 0;
	int x_mod_m = h1(x.WorkExperience, m);
	int pozition = x_mod_m;
	while (pozition < m && !(hash_table[pozition] == INF)) {
		i++;
		pozition = h1(x_mod_m + i * (1 + h1(x.WorkExperience, m - 1)), m);
	}
	return pozition;
}


bool FindPeople(vector<people>& hash_table, people x, int m, people INF, int &elem_pozition) { // ���������� �������� � ���-�������
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


void HashTableFill(vector<people>& hash_table, vector<people>& x, int m, people INF) { // ���������� ���-�������
	for (auto human : x) {
		int pozition = HashFunction(hash_table, human, m, INF);
		if (pozition < m) {
			hash_table[pozition] = human;
		}
	}
}


void PeopleOutPrint(people x) {//����� � ���� ������ ��������
	out << setw(15) << left << x.Surname;//�� ������ ����, 15 ������� ��� �������
	out << setw(9) << left << x.Post;//�� ������ ����, 15 ������� ��� ���������

	if (x.DateOfBirth.dd < 10)
		out << left << " 0" << x.DateOfBirth.dd << '.';//��������� 0
	else
		out << left << ' ' << x.DateOfBirth.dd << '.';

	if (x.DateOfBirth.mm < 10)
		out << left << '0' << x.DateOfBirth.mm << '.';//��������� 0
	else
		out << left << x.DateOfBirth.mm << '.';

	out << setw(8) << left << x.DateOfBirth.yy;//�� ��� 6 �������
	out << setw(6) << left << x.WorkExperience;//�� ������ ����, 4 ������� ��� ����� ������
	out << setw(15) << left << x.Salary << endl;//��������
}


void FileOutPrint(vector<people>& hash_table) {		//����� ������� � ����
	for (int i = 0; i < hash_table.size(); i++) {
		out << i << ":  ";
		PeopleOutPrint(hash_table[i]);
	}
}


int main() {
	setlocale(LC_ALL, "RUS");
	system("chcp 1251 >> null");  //����� string �� ������� ���� ��������� �������

	int n = 24; //���������� �����
	vector<people> x;
	x = inFile();		//������ � �����
	
	int m = 29; //������� ����� ������� N
	int m1 = 28;  // m1 = m - 1

	people INF;
	INF.Surname = ' ';
	INF.Post = ' ';
	INF.Salary = 0;
	INF.WorkExperience = 0;
	INF.DateOfBirth.dd = 0;
	INF.DateOfBirth.mm = 0;
	INF.DateOfBirth.yy = 0;

	vector<people> hash_table(m, INF);  //���-�������
	people elem;
	

	HashTableFill(hash_table, x, m, INF);  //���������� ���-�������
	FileOutPrint(hash_table);  //����� � ���� ����������� ���-�������

	string answer = "��";

	while (answer == "��") {
		cout << "\n������� '��' - ���� ������ ��������� �������� �� ������� � ���-�������;\n"
			<< "������� '���' - ���� ������ ��������� ������ ���������:\n";
		cin >> answer;

		while (answer != "���" && answer != "��") {
			cout << "\n�� ��������, ������� ����� �������� (������ ��/���):\n";
			cin >> answer;
		}	

		if (answer == "��") {
			people elem = ElemCreate();
			int elem_pozition;
			bool poz_check = FindPeople(hash_table, elem, m, INF, elem_pozition);

			if (poz_check) {
				cout << "\n���� ������� ������ � ��������� � " << elem_pozition << "-�� ������ ���-�������.\n";
			}
			else {
				cout << "\n����� ������� �� ������ � ���-�������.\n";
			}
		}

		else if (answer == "���") {
			break;
		}

		cout << endl << endl;
	}

	return 0;
}