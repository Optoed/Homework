//��� ����������������� ����. �������� � ���� �����, ����������� ������� A � B.

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

int main() {
	setlocale(LC_ALL, "RUS");

	vector<vector<int>> Gr;			//C����� ���������
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
		//ne orient
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

	int a, b;
	cout << "\n������� ������� a = ";
	cin >> a;
	watch(a);

	cout << "������� ������� b = ";
	cin >> b;
	watch(b);
	
	if (a > n || b > n) {
		cout << "\n�����: ����� ������� ���\n\n";
	}

	else {
		if (a != b) {
			if (find(Gr[a].begin(), Gr[a].end(), b) == Gr[a].end()) {
				Gr[a].push_back(b);			//������� ����� ab (�� ���� ��������������� �� ��������� ��� ������ ��������� � �� ������ ����)
			}
			if (find(Gr[b].begin(), Gr[b].end(), a) == Gr[b].end()) {
				Gr[b].push_back(a);			//������� ����� ab (�� ���� ��������������� �� ��������� ��� ������ ��������� � �� ������ ����)
			}
		}

		cout << "\n������ ���������:\n"; 
		for (int i = 0; i < n; i++) {  //����� ����������� ������ ���������
			cout << "x = " << i << ": ";
			for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
				cout << *it << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}