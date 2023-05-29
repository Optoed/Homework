
//��� ��������������� ����. ����������� �������������� ����������
//(P.s. � ���������������� ������ �������������� ���������� �����, ��������, ���������)

/* ���������� input4.txt �����
9 14
0 1
0 2
1 2
1 3
1 4
2 4
2 5
3 6
4 6
5 4
5 7
6 7
6 8
7 8
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

ifstream in("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\������������ ��������� ������\\Graphs\\����� - ����� 2\\inputTopologicalSort.txt");

vector<vector<int>> Gr;			//C����� ���������
vector<int> used;				//������ ���������� ������
vector<int> order;				//������ ������ ������������ ����


void TopologicalSort(int x, int &n) {		//������� �������������� ���������� (�������� �� TopologicalSort)
	used.resize(n);
	used[x] = 1;

	for (int i = 0; i < Gr[x].size(); i++) {
		if (used[Gr[x][i]] == 0) {
			TopologicalSort(Gr[x][i], n);
		}
	}

	order.push_back(x);
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
		//orient
		else {
			Gr[x].push_back(y);		//���� ���������������, ������� � ������ ��������� x ��������� y
			//Gr[y].push_back(x);		//���� �����������������, ������� � ������ ��������� y ��������� x
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

	TopologicalSort(0, n);

	reverse(order.begin(), order.end());

	cout << "\n��������� �������������� ����������: ";
	for (auto i : order) {
		cout << i << ' ';
	}
	cout << "\n\n";

	system("pause");
	return 0;
}