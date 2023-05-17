//��� ����������������� ����.��������, �������� �� ���� �������.

#include <iostream>   //����������� ���������
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

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

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\ϸ��\\Desktop\\�++ Homework\\����� - ����� 2\\input1.txt");

vector<vector<int>> Gr;			//C����� ���������
vector<int> used;				//������ ���������� ������
vector<int> path;				//������ ������ ������������ ����


void go_in_depth(int x) {
	//used.resize(x);
	used[x] = 1;
	cout << '3';
	path.push_back(x);

	for (int i = 0; i < Gr[x].size(); i++) {
		if (used[Gr[x][i]] == 0) {
			go_in_depth(Gr[x][i]);
		}
	}
}


void componet_svyaz(int x) {
	cout << "1";
	//replace_if(used.begin(), used.end(), [](int x) {return x == 1; }, 0);
	used.clear();
	cout << "1";
	while (used.empty()) {
		cout << "1";
		path.clear();
		cout << '1';
		go_in_depth(x);
		cout << '2';
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
		//orient
		if (x > n || y > n) {

		}
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

	for (int i = 0; i < n; i++) {
		componet_svyaz(i);
		cout << endl;
	}
	


	system("pause");
	return 0;
}