
/*
��� ����������������� ����.

��������� ��������� �������:

1) ������� ������� ���� ��� ������� ����, ���� �� ����������.
*/

/*
���������� txt-�����:

6 10
0 1
0 2
0 4
0 5
1 3
1 4
2 3
2 4
3 4
3 5

*/

#include <iostream>   //����������� ���������
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\������������ ��������� ������\\Graphs\\����� - ����� 2\\inputEulerian.txt");


vector<vector<int>> Gr;			//C����� ���������



void Eulerian(int& n) {			//�������� ������ �������� ����/�����
	int v1 = -1, v2 = -1;		//������������ ��� ������� � -1

	bool checkcycle = 0;
	for (int i = 0; i < n; i++) {
		if (Gr[i].size() % 2 != 0) {		//������� ������� ��������
			if (v1 == -1) {
				v1 = i;
			}
			else if (v2 == -1) {
				v2 = i;
			}
			else {
				checkcycle = 1;		//��������: "������ 2-� �������� ��������"
			}
		}
	}

	if (v1 != -1) {				//���� �������� ������� ���� - �������� ����� �����
		Gr[v1].push_back(v2);
		Gr[v2].push_back(v1);
	}

	stack<int> st;
	st.push(v1);			//��������� � ���� ����� �������, ��������, v1
	vector<int> res;		//�������������� ������

	while (!st.empty()) {		//������� ��� ����� � ��������� ���� � res
		int v = st.top();
		if (Gr[v].size() != 0) {  
			st.push(Gr[v][0]);
			if (Gr[Gr[v][0]].size() > 0) {
				Gr[Gr[v][0]].erase(find(Gr[Gr[v][0]].begin(), Gr[Gr[v][0]].end(), v));
			}
			Gr[v].erase(Gr[v].begin());
		}
		else {
			res.push_back(v);
			st.pop();
		}
	}

	if (v1 != -1) {   //������� "���������" �����, ������� ��������� �����
		for (int i = 0; i + 1 < res.size(); i++) {
			if (res[i] == v1 && res[i + 1] == v2 || res[i] == v2 && res[i + 1] == v1) {
				vector<int> res2;
				for (int j = i + 1; j < res.size(); j++) {
					res2.push_back(res[j]);
				}
				for (int j = 1; j <= i; j++) {
					res2.push_back(res[j]);
				}
				res = res2;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {		//���������, �������� �� �����
		if (Gr[i].size()) {
			checkcycle = 1;
			break;
		}
	}

	if (checkcycle == 1) {
		cout << "\n���� ���������, �������� ����� ���\n\n";
	}
	else {								//����� ����
		cout << "\n����� ����: ";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << "\n\n";
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
		
		if (x > n || y > n) { //������ �� ������
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
	cout << endl;
	
	Eulerian(n);	//����� ������� �������� ����/�����

	system("pause");
	return 0;
}