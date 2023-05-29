
/*
#include <stdlib.h>
#include <stdio.h>
#include <clocale>
#include <cstdlib>
#include <windows.h>
#include <sstream>
#include <cstring>
#include <time.h>
#include <numeric>
#include <cmath>
#include <iterator>
#include <iomanip>
*/

//��� ����������������� ����. ��������, �������� �� ���� �������.

/* ���������� input4.txt �����
13 13
0 1
0 2
0 5
0 6
3 5
4 3
5 4
6 4
7 8
10 9
9 11
9 12
12 11
*/

#include <iostream>   //����������� ���������
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\������������ ��������� ������\\Graphs\\����� - ����� 2\\input4.txt");

vector<vector<int>> Gr;			//C����� ���������
vector<int> used;				//������ ���������� ������
vector<int> path;				//������ ������ ������������ ����


void go_in_depth(int x) {		//������� ������ � �������
	used.resize(100);
	used[x] = 1;
	path.push_back(x);

	for (int i = 0; i < Gr[x].size(); i++) {
		if (used[Gr[x][i]] == 0) {
			go_in_depth(Gr[x][i]);
		}
	}
}


void componet_svyaz(int x) {	//������� ������ ����������� ���������
	replace_if(used.begin(), used.end(), [](int x) {return x == 1; }, 0);
	used.clear();

	while (used.empty()) {
		path.clear();
		go_in_depth(x);
		for (auto it = path.begin(); it != path.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
}


int main() {
	setlocale(LC_ALL, "RUS");	

	int n, m;

	cout << "������� ���������� ������ = n = ";
	in >> n;
	cout << n << endl;

	cout << "������� ���������� ����� = m = ";
	in >> m;
	cout << m << endl;

	Gr.resize(n);					//������ ������ ���������
	
	while (in.peek() != EOF) {		//���������� �� ���������� ����� "in" � ��������� ��� ����� ������� � ���� x, y
		int x, y;
		in >> x >> y;
		
		if (x > n || y > n) {

		}
		//ne orient
		else {
			Gr[x].push_back(y);		//���� �����������������, ������� � ������ ��������� x ��������� y
			Gr[y].push_back(x);		//���� �����������������, ������� � ������ ��������� y ��������� x
		}
	}
	
	for (int i = 0; i < n; i++) {	//������� ������������� �������� ���� ��� ����
		sort(Gr[i].begin(), Gr[i].end());
		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
	}

	cout << "\n������ ���������:\n";
	for (int i = 0; i < n; i++) {	//����� ����������� ������ ���������
		cout << "x = " << i << ": ";
		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	int count_svyaz = 0;
	cout << endl << "���������� ���������:\n";
	componet_svyaz(0);			//������ ���������� ���������
	count_svyaz += 1;
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			componet_svyaz(i);
			count_svyaz += 1;
		}
	}
	
	if (count_svyaz == 1) {
		cout << "\n�����: ���� �������� ������� (��� ��� ������ ���� ���������� ���������)\n\n";
	}
	else if (count_svyaz > 1) {
		cout << "\n�����: ���� �������� �� ������� (��� ��� ������ ����� ���������� ���������)\n\n";
	}
	else {
		cout << "\n�����: count_svyaz == 0, � ������ ���-�� ���� ������\n\n";
	}

	system("pause");
	return 0;
}