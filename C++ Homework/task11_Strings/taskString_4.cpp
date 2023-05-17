//������ �� ������������� ����� - 4
//��� ����� : ��� ����, ���������� ������ ��������� ����� � ���� �� �����.
//������� � ����� ���� ������ �����, ������� ������� ����� 50 ��� � ���� � XIX ����.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RUS");

    char buff[100]; // ����� �������������� �������� ������������ �� ����� ������
    ifstream fin("input.txt");
    ofstream fout("output.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������

    if (!fin.is_open()) // ���� ���� �� ������
        cout << "���� �� ����� ���� ������!\n"; // �������� �� ����

    else
    {
        int count = 1;
        string line;     //
        while (getline(fin, line)) {                         //�������� �� ���� ������� � �����
            cout << endl;
            cout << count << ") " << line << endl;
            //string::size_type n = line.size();               //����� ������
            //cout << n << endl;
            string::size_type skobka1 = line.find('(');      //������� ����������� ������
            cout << "������� ����������� ������ = " << skobka1 << endl;
            string::size_type tire = line.find('-');         //������� ����
            cout << "������� ���� = " << tire << endl;
            string::size_type skobka2 = line.find(')');      //������� ����������� ������
            cout << "������� ����������� ������ = " << skobka2 << endl;
            string date1 = line.substr(skobka1 + 1);         //���������, ���������� ��� ��-�� ������, ������� � ������� ����������� ������ + 1
            cout << "���������, ������ ��-�� ������, ������� � ������� ����������� ������ + 1 = " << date1 << endl;
            string firstdate = "";
            for (int i = 0; i < 4; i++) {       //�������� �� 4 �����
                if (date1[i] != '-')
                    firstdate += date1[i];
                else
                    break;
            }
            const char* fdate = firstdate.c_str();        
            string seconddate = "";
            string date2 = line.substr(tire + 1, skobka2);      //���������, ������������� ���� ����� �����
            for (int i = 0; i < 4; i++) {
                if (date2[i] != '.')
                    seconddate += date2[i];
                else
                    break;
            }
            const char* sdate = seconddate.c_str();
            int fd = atoi(fdate);         //��������� � �����
            cout << "���� �������� = " << fd << endl;
            int sd = atoi(sdate);         //��������� � �����
            cout << "���� ����� ����� = " << sd << endl;
            if (abs(sd - fd) > 50 && (fd / 100 == 18 || sd / 100 == 18)) {         //��������, ��� ������� ��� ������ 50 ��� � � 19 ����
                fout << line; // ������ ������ � ����
                cout << "���������� �������, ������� ��� ����� 50 ��� � � XIX ���� = " << line << endl;
                fout << endl;
            }
            else {
                cout << "������� �� ��������, �� ��� ������ 50 ��� ��� �� � XIX ����" << endl;
            }
            count += 1;
        }
    }

    fout.close(); // ��������� ����
    return 0;
}