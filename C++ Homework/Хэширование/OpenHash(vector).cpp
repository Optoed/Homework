
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
#include<list>
#include<iomanip>
#include<cmath>
#include <algorithm>
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
	x.dd = atoi(temp.c_str());

	temp = str.substr(3, 2);//�����
	x.mm = atoi(temp.c_str());

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

void print(people x) {//����� � ����
	out << setw(15) << left << x.Surname;//�� ������ ����, 15 ������� ��� �������
	out << setw(9) << left << x.Post;//�� ������ ����, 15 ������� ��� ���������
	if (x.DateOfBirth.dd < 10)
		out << left << ' 0' << x.DateOfBirth.dd << '.';//��������� 0
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


void HeshPrint(vector<vector<people>>& h) { //����� ���-�������
	for (int i = 0; i < h.size(); i++) {	
		for (int j = 0; j < h[i].size(); j++) {
			out << i << ":  ";
			print(h[i][j]);
		}
		out << endl;
	}
}


void HeshFill(vector<vector<people>>& h, vector<people>& x, double& A, int& M) { //���������� ���-�������
	for (int i = 0; i < x.size(); i++) {
		cout << "Salary = " << x[i].Salary << "\n";
		double Ax = x[i].Salary * A;
		cout << "Ax = Salary * A = " << Ax << "\n";
		Ax -= floor(Ax);
		cout << "������� Ax = " << Ax << "\n";
		Ax *= M;
		cout << "Ax * M = " << Ax << "\n";
		int pozition = int(Ax);
		cout << "����� �� Ax = " << pozition << "\n";
		h[pozition].push_back(x[i]);
		cout << endl;
	}
}


void ElemCreate(people& elem) {					//�������� ��������
	cout << "������� �������: ";
	cin >> elem.Surname;//�������
	cout << "������� ���������: ";
	cin >> elem.Post; //���������
	string tmp;//���� ��������
	cout << "������� ������� ������ ���� ��������: ";
	cin >> tmp;
	elem.DateOfBirth = Str_to_Date(tmp);
	cout << "������� ���� ������: ";
	cin >> elem.WorkExperience; //���� ������
	cout << "������� ��������: ";
	cin >> elem.Salary;//��������
}


void ElemPush(vector<vector<people>>& h, people& elem, double &A, int &M) {   //������� ���������� �������� � ���-������� � ����� ������� ����� �������� (���������� � ����� ������ ���������)
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	h[pozition].push_back(elem);
}


void ElemFind(vector<vector<people>>& h, people& elem, double& A, int& M) {  //����� ������� �������� (���������� � ����� ������ ���������)
	long double Ax = elem.Salary * A;
	Ax -= floor(Ax);
	Ax *= M;
	int pozition = int(Ax);
	cout << "\n������ ������� ��������� � " << pozition << "-�� ������ ���-�������\n";
}


void ElemDelete(vector<vector<people>>& h, people& elem, double& A, int& M) {  //�������� ��������
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
	x = inFile();		//������ � �����

	double A = (sqrt(5) - 1) / 2;
	cout << "A = " << A << "\n";
	int M = 8; //����������� ���-�������

	vector<vector<people>> h(M);  //���-�������

	HeshFill(h, x, A, M);

	HeshPrint(h);

	people elem;
	ElemCreate(elem);
	ElemPush(h, elem, A, M);
	out << endl << razdelitel() << endl << "���-������� ����� ���������� ������ ��������:\n" << endl;
	HeshPrint(h);

	ElemFind(h, elem, A, M);

	ElemDelete(h, elem, A, M);
	out << endl << razdelitel() << endl << "���-������� ����� �������� ��������:\n" << endl;
	HeshPrint(h);

	return 0;
}