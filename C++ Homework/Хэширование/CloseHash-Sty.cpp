// �������� � ������������ �����������, ��������������� � ����� ��������� �� �����

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;


struct date { // ����
    int dd, mm, yyyy;
};


struct person {// ������ � ��������
    string Surname;
    string Post;
    date DateOfBirth;
    int LengthOfService;
    int Salary;
};


vector<person> people; // ������ "�����"


void input() { // ������ ������ �� �����
    ifstream in("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\�����������\\megainput.txt");
    person pers;
    string s;
    while (in.peek() != EOF) {
        in >> pers.Surname;
        in >> pers.Post;
        in >> s;
        // ������ � ����� ��������
        pers.DateOfBirth.dd = stoi(s.substr(0, 2));
        pers.DateOfBirth.mm = stoi(s.substr(3, 5));
        pers.DateOfBirth.yyyy = stoi(s.substr(6, 4));
        in >> pers.LengthOfService;
        in >> pers.Salary;
        people.push_back(pers); // ���������� ������ ��-�� � ������ 

    }
}


bool operator == (person a, person b) { // �������������� ��������� 
    return (a.Surname == b.Surname && a.Salary == b.Salary && a.Post == b.Post &&
        a.LengthOfService == b.LengthOfService && a.DateOfBirth.dd == b.DateOfBirth.dd &&
        a.DateOfBirth.mm == b.DateOfBirth.mm && a.DateOfBirth.yyyy == a.DateOfBirth.yyyy);
}


int m, c1, c2; // ������ ������� � ����-��
const double a = (sqrt(5) - 1) / 2; // ������� �������
vector<person> hash_t; // ���-�������

person INF;


int h1(int x) { // ���������
    double ax = x * a;
    int axm = (ax - (int)ax) * m;
    return axm;
}

int h(person x) { // ������������ �����������
    int i = 0;
    int k = h1(x.LengthOfService);
    int ind = k;
    while (ind < m && !(hash_t[ind] == INF)) {
        i++;
        ind = k + c1 * i + c2 * i * i;
    }
    return ind;
}


void hash_table() { // ���������� ���-�������
    hash_t.assign(m, INF);
    for (auto el : people) {
        int k = h(el);
        if (k < m) hash_t[k] = el;
    }
}


bool find(person x) { // ���������� �������� � ���-�������
    int i = 0;
    int k = h1(x.LengthOfService);
    int ind = k;
    while (ind < m && !(hash_t[ind] == INF) && !(hash_t[ind] == x)) {
        i++;
        ind = k + c1 * i + c2 * i * i;
    }
    if (ind < m && hash_t[ind] == x)
        return true;
    return false;
}


void output() { // ��������������� ����� � ���� 
    ofstream out("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\�����������\\megaoutput.txt");
    for (int k = 0; k < m; ++k) {
        out << k << ": ";
        person pers = hash_t[k];
        out << setw(14) << left << pers.Surname; //�� ������ ����, 10 ������� ��� �������
        out << setw(15) << left << pers.Post;
        if (pers.DateOfBirth.dd < 10) out << left << '0' << pers.DateOfBirth.dd << '.'; //��������� 0
        else out << left << pers.DateOfBirth.dd << ".";
        if (pers.DateOfBirth.mm < 10) out << '0' << pers.DateOfBirth.mm << '.';
        else out << pers.DateOfBirth.mm << '.';
        out << left << setw(6) << pers.DateOfBirth.yyyy; //�� ��� 6 �������
        out << setw(4) << left << pers.LengthOfService;
        out << left << setw(8) << pers.Salary << endl; //��������
    }
    out << '\n';
}


int main() {
    input();
    m = 32;
    c1 = 1;
    c2 = 1;
    hash_table();
    output();
    int var = 1;

    while (true) {
        cout << "Enter 1 if you want to check for an item in the list\n";
        cout << "Enter 0 if you want to exit the program\n";
        cin >> var;
        if (var == 0) break;
        person pers;
        string data;
        cout << "Enter the surname, post, date of birth, length of service and salary of the person:\n";
        cin >> pers.Surname >> pers.Post >> data >> pers.LengthOfService >> pers.Salary;
        pers.DateOfBirth.dd = stoi(data.substr(0, 2));
        pers.DateOfBirth.mm = stoi(data.substr(3, 5));
        pers.DateOfBirth.yyyy = stoi(data.substr(6, 4));

        if (find(pers)) cout << "This person is on the list\n";
        else cout << "This person is not on the list\n";
        cout << '\n';
    }
}