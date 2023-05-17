/*
* ������ ����������� � �������.
* � ����� ���������� ������ � ����������� �����������: �������, ���������, ���� �������� (����, �����, ���), ���� ������, �������� (�� ����� 20 �������).
* � ����� ���� ������� ������, ��������������� �� ������-���� ����� (� ����������� �� ������ �������).
* ����� � ����� ����� ����������� ������ ���� ��������������.
* ������� �� ������ �����, ����� �� ������� �������� ��������� ����:
* if(a[i].key1 < a[j].key1 || (a[i].key1 == a[j].key1 && a[i].key2 < a[j].key2))
*/

//12. ������� �� �������, ����� �� ����� ������, ����� �� �������� � ������� ���������� ��� - �����.


#include<iostream> //����������� ���������
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include <algorithm>
using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\��� �������\\���������������� � �����������\\�++ Homework\\task_SORT\\megainput.txt"); //���� "in" � �������
ofstream out("C:\\Users\\User\\Desktop\\��� �������\\���������������� � �����������\\�++ Homework\\task_SORT\\megaoutput12_odd_even.txt"); //���� "out" ��� ������ ������

struct date {     // ��������� ���� ��������
	int dd, mm, yy;
};

struct people {          //������ � ��������
	string Surname; //�������
	string Post; //���������
	date DateOfBirth; //���� ��������
	int WorkExperience; //���� ������ (� �����)
	int Salary; //��������
};

date Str_to_Date(string str) {//�� ������ � ����
	date x;

	string temp = str.substr(0, 2);//����
	x.dd = atoi(temp.c_str());

	temp = str.substr(3, 2);//�����
	x.mm = atoi(temp.c_str());

	temp = str.substr(6, 4);//���
	x.yy = atoi(temp.c_str());

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



void print(people x) {//����� � ����
	out << setw(14) << left << x.Surname;//�� ������ ����, 10 ������� ��� �������
	out << setw(12) << left << x.Post;//�� ������ ����, 10 ������� ��� �������

	if (x.DateOfBirth.dd < 10)
		out << left << '0' << x.DateOfBirth.dd << '.'; //��������� 0
	else
		out << left << x.DateOfBirth.dd << '.';

	if (x.DateOfBirth.mm < 10)
		out << '0' << x.DateOfBirth.mm << '.'; //��������� 0
	else
		out << x.DateOfBirth.mm << '.';

	out << left << setw(10) << x.DateOfBirth.yy;//��� ��������

	out << left << setw(6) << x.WorkExperience; //���� ������

	out << left << setw(10) << x.Salary << endl;//��������

}

bool operator < (people a, people b) { //�������������� �������� < � ����������� � ��������

	if (a.Surname < b.Surname) //��������� �� �������
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience > b.WorkExperience)) //��������� �� ����� ������
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience == b.WorkExperience) && (a.Salary > b.Salary)) //��������� �� ��������
		return true;

	return false;
}


bool operator > (people a, people b) {//�������������� �������� < � ����������� � ��������

	if (a.Surname > b.Surname) //��������� �� �������
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience < b.WorkExperience)) //��������� �� ����� ������
		return true;

	if ((a.Surname == b.Surname) && (a.WorkExperience == b.WorkExperience) && (a.Salary < b.Salary)) //��������� �� ��������
		return true;

	return false;
}

void odd_even_sort(vector<people>& x) {  //������� ����������

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


int main() { //������� �������

	setlocale(LC_ALL, "RUS"); //������� ����������

	if (!in.is_open()) {    //���������, �������� �� ����
		cout << "���� �� ��� ������!" << endl;
	}
	else
		cout << "���� ������!" << endl;

	vector<people> x;
	x = inFile();
	vector<string> posts = { "Intern", "Junior", "Middle", "Senior" }; //������ ����������
	odd_even_sort(x); //�������� ������� � �����������

	for (int i = 0; i < x.size(); i++)  //������� � ����
		print(x[i]);

	cout << "���������� ���������!" << endl;

	return 0; //����� ���������
}