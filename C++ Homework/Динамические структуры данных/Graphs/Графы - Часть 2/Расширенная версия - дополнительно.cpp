
//������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.

/*
�������:


������ ��� �����:
n = 10
5 3 7 1 9 4 2 8 6 0
*/

#include <iostream>									//����������� ���������� �����-������
#include <algorithm>									//����������� ���������� ����������
#include <limits.h>									//����������� ���������� ��� INT_MAX
#include <time.h>

#include <vector>									//����������� ���������� ��������																
#include <stack>										//����������� ���������� ������	
#include <queue>										//����������� ���������� ��������
#include <map>
#include <list>

#include <string.h>									//����������� ��������� ��� ������������� �����
#include <string>

#include <iomanip>
#include <fstream>

#include <clocale>
#include <cstdlib>
#include <windows.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#define watch(x) cout << #x << " = " << x << endl   //������ ��� �������� ������ �������� ����������

using namespace std;

ifstream in("C:\\Users\\ϸ��\\Desktop\\�++ Homework\\����� - ����� 2\\input1.txt");
ofstream out("C:\\Users\\ϸ��\\Desktop\\�++ Homework\\����� - ����� 2\\output1.txt");


int main() {
	setlocale(LC_ALL, "RUS");       // ����������� �������� ����� 
	system("chcp 1251 >> null");    // ����������� �������� �����
	SetConsoleCP(1251);             // ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);       // ��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_CTYPE, "Russian"); // ����������� �������� �����

	
	map<int, list<pair<int, double>>>l_Adj;

	int x, y, w;

	while (in.peek() != EOF) {
		in >> x >> y >> w;
		if (!isWeigth)
			w = 1.0;
		auto it_x = l_Adj.find(x);
		bool fl = true;
		if (it_x != l_Adj.end()) {
			for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++)
				if (it_y->first == y) {
					fl = false;
					break;
				}
		}

		if (orient) {
			if (fl) {
				l_Adj[x].push_back(make_pair(y, w));

				if (l_Adj.find(y) == l_Adj.end()) {
					l_Adj[y].push_back(make_pair(0, 0));
					auto it = l_Adj.find(y);
					it->second.erase(it->second.begin());
				}
			}
		}

		else if (fl) {
			l_Adj[x].push_back(make_pair(y, w));
			l_Adj[y].push_back(make_pair(x, w));
		}
	}



	system("pause");
	return 0;
}


