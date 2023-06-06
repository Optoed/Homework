
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
//����� ��������� �� ��������

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


void PeopleOutPrint(people x) {//����� � ����
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


bool operator == (people a, people b) {
	if (a.Post == b.Post && a.Salary == b.Salary && a.Surname == b.Surname && a.WorkExperience == a.WorkExperience &&
		a.DateOfBirth.dd == a.DateOfBirth.dd && a.DateOfBirth.mm == a.DateOfBirth.mm && a.DateOfBirth.yy == a.DateOfBirth.yy) {
		return true;
	}
	else {
		return false;
	}
}


struct list { // �������� ����������� ������
	people item; // �������� ��������
	list* prev; // ��������� �� ���������� �������
	list* next; // ��������� �� ��������� �������
};


void PushBackList(list*& head, list*& tail, people x) { // ������� ��������� people x � ����� ������
	list* p = new list;
	p->item = x;
	p->next = NULL;

	if (!head && !tail) { // ���� ������ ����
		p->prev = NULL;
		head = p;
	}
	else {
		tail->next = p;
		p->prev = tail;
	}

	tail = p; // ������� ���������� ������� 
}


list* FindInList(list*& head, list*& tail, people x) { // ����� ��������� people x � ������
	list* p = head; // ��������� �� ������ ������
	while (p) { // ������ �� ������ 
		if (p->item == x) {
			return p;
		}
		p = p->next;
	}
	return p;  //���������� ���������
}


void DeleteFromList(vector<pair<list*, list*>>& hash_table, list*& head, list*& tail, list* p, int &pozition) { // �������� ��-�� p �� ������
	if (p == head && p == tail) { //���� � - ������������ ��-� � ������
		head = tail = NULL;
		hash_table[pozition].first = head;
		hash_table[pozition].second = tail;
	}
	else if (p == head) { // ���� � - ��� ������
		head = head->next;
		head->prev = NULL;
		hash_table[pozition].first = head;
	}
	else if (p == tail) { // ���� � - ��� �����
		tail = tail->prev;
		hash_table[pozition].second = tail;
		tail->next = NULL;
	}
	else {            //��� ��������� ������
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	delete p; // �������� ������, �������� � 
}


void HashTableFill(vector<pair<list*, list*>>& hash_table, vector<people>& x, double& A, int& M) { //���������� ���-�������
	for (int i = 0; i < x.size(); i++) {
		//cout << "Salary = " << x[i].Salary << "\n";
		double Ax = x[i].Salary * A;
		//cout << "Ax = Salary * A = " << Ax << "\n";
		Ax -= floor(Ax);
		//cout << "������� Ax = " << Ax << "\n";
		Ax *= M;
		//cout << "Ax * M = " << Ax << "\n";
		int pozition = int(Ax);
		//cout << "����� �� Ax = " << pozition << "\n";
		PushBackList(hash_table[pozition].first, hash_table[pozition].second, x[i]);
		//cout << endl;
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


list* ElemFind(vector<pair<list*, list*>>& hash_table, people& elem, double& A, int& M, int &elem_pozition) {  //����� ������� �������� (���������� � ����� ������ ���������)
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	list* head = hash_table[pozition].first;
	list* tail = hash_table[pozition].second;
	//cout << "\n������ ������� ��������� � " << pozition << "-�� ������ ���-�������\n";
	elem_pozition = pozition;
	return FindInList(head, tail, elem);
}


void ElemPush(vector<pair<list*, list*>>& hash_table, people& elem, double& A, int& M) {   //������� ���������� �������� � ���-�������
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	PushBackList(hash_table[pozition].first, hash_table[pozition].second, elem); //�������� ������� � ������ ���-�������
}


void ElemDelete(vector<pair<list*, list*>>& hash_table, people& elem, double& A, int& M, list*& p) {  //�������� ��������
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
		list* h = hash_table[i].first; //��������� �� ������� �������� � i-������
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
	system("chcp 1251 >> null");  //����� string �� ������� ���� ��������� �������

	vector<people> x;
	x = inFile();		//������ � �����

	double A = (sqrt(5) - 1) / 2;
	//cout << "A = " << A << "\n";
	int M = 8; //����������� ���-�������

	vector<pair<list*, list*>> hash_table(M);  //���-�������
	people elem;

	HashTableFill(hash_table, x, A, M);  //���������� ���-�������
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
			list* poz_check = ElemFind(hash_table, elem, A, M, elem_pozition);

			if (poz_check) {
				cout << "\n���� ������� ������ � ��������� � " << elem_pozition << "-�� ������ ���-�������.\n";
				cout << "\n������ ��� ������� �� ������� (��/���)?\n";
				string answer_del;
				cin >> answer_del;

				while (answer_del != "���" && answer_del != "��") {
					cout << "\n�� ��������, ������� ����� �������� (������ ��/���):\n";
					cin >> answer_del;
				}

				if (answer_del == "��") {
					ElemDelete(hash_table, elem, A, M, poz_check);
					cout << elem.Surname << " ������� ���-�������...\n";
					out << endl << razdelitel() << endl << "���-������� ����� �������� �������� c �������� " << elem.Surname << "\n" << endl;
					FileOutPrint(hash_table);  //����� � ���� ����������� ���-�������
				}
				//������ ��� ��������� �������� ���� "���" ��� "������ �����"
			}
			else {
				cout << "\n����� ������� �� ������ � ���-�������.\n";
				cout << "\n������ ��� �������� � ������� (��/���)?\n";
				string answer_insert;
				cin >> answer_insert;

				while (answer_insert != "���" && answer_insert != "��") {
					cout << "\n�� ��������, ������� ����� �������� (������ ��/���):\n";
					cin >> answer_insert;
				}

				if (answer_insert == "��") {
					ElemPush(hash_table, elem, A, M);
					cout << elem.Surname << " ����� � ���-�������...\n";
					out << endl << razdelitel() << endl << "���-������� ����� ���������� ������ �������� c �������� " << elem.Surname << "\n" << endl;
					FileOutPrint(hash_table);  //����� � ���� ����������� ���-�������
				}
				//������ ��� ��������� �������� ���� "���" ��� "������ �����"
			}
		}
		else if (answer == "���") {
			break;
		}

		cout << endl << endl;
		//������ ��� ��������� �������� ���� "������ �����"
	}

	return 0;
}