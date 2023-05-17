/*
* ������ ����������� � �������.
* � ����� ���������� ������ � ����������� �����������: �������, ���������, ���� �������� (����, �����, ���), ���� ������, �������� (�� ����� 20 �������).
* � ����� ���� ������� ������, ��������������� �� ������-���� ����� (� ����������� �� ������ �������).
* ����� � ����� ����� ����������� ������ ���� ��������������.
* ������� �� ������ �����, ����� �� ������� �������� ��������� ����:
* if(a[i].key1 < a[j].key1 || (a[i].key1 == a[j].key1 && a[i].key2 < a[j].key2))
*/

//1. �� �������� � ������� ������� ����������.

#include<iostream> //����������� ���������
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\��� �������\\���������������� � �����������\\�++ Homework\\task_SORT\\megainput.txt"); //���� "in" � �������
ofstream out("C:\\Users\\User\\Desktop\\��� �������\\���������������� � �����������\\�++ Homework\\task_SORT\\megaoutput1_fast.txt"); //���� "out" ��� ������ ������

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
	if (a.Salary < b.Salary) //��������� �� ��������
		return true;

	return false;
}

bool operator > (people a, people b) {//�������������� �������� < � ����������� � ��������
	if (a.Salary > b.Salary) //��������� �� ��������
		return true;
	
	return false;
}

void quick_sort(vector<people>&x, int l, int r) {  //������� ����������
	
	int i = l, j = r;
	people m = x[(l + r) / 2]; //������� �������
	
	while (i <= j) { // ������� ����������
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


int main() { //������� �������

	setlocale(LC_ALL, "RUS"); //������� ����������

	if (!in.is_open()) {    //���������, �������� �� ����
		cout << "���� �� ��� ������!";
	}
	else
		cout << "���� ������!";

	vector<people> x;
	x = inFile();
	size_t l = 0, r = x.size() - 1;

	quick_sort(x, l, r); //�������� ������� � �����������

	for (int i = 0; i < x.size(); i++)  //������� � ����
		print(x[i]);

	return 0; //����� ���������
}