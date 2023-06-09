
//��� ������������, ����������������� ����. ����� ���������� ���������� �� �������� ������� �� ���� ��������� ������. ������� �� ������ ����� ����, �� � ��� ���� ����.

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
#include <queue>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define watch(x) cout << #x <<" = " << x << endl;

ifstream in("C:\\Users\\ϸ��\\Desktop\\C++ Homework\\������������ ��������� ������\\Graphs\\����� - ����� 2\\input4.txt");


bool BFS(int &a, int &b, int &n, vector<int>&used, vector<int>&path, queue<int>&buf, vector<vector<int>>&Gr) {	//����� ����� � ������, ������� ���������� � ������� a
	used.resize(n, 0);
	path.resize(n);
	used[a] = 1;
	path.push_back(a);
	buf.push(a);

	bool check = 0;

	while (!buf.empty()) {
		int y = buf.front();
		buf.pop();
		
		for (int i = 0; i < Gr[y].size(); i++) {	//���������� �� ������ ���������
			if (used[Gr[y][i]] == 0) {			//�� ��� �� �������� ������ �������
				buf.push(Gr[y][i]);
				path[Gr[y][i]] = y;				//������� = ������� ��-�� ������ ���������, �� ��� ������� ���������� ������ ������ ������� Gr[y][i] (������ = y)
				used[Gr[y][i]] = 1;				//�������� ������� ��� ����������
				if (Gr[y][i] == b) {
					check = 1;
				}
			}
		}
	}

	return check;
}



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

	int a, b;			//������ ������� a � b
	cout << "\n\na = ";
	cin >> a;
	
	for (b = 0; b < n; b++) {
		if (a == b) {}

		else {
			vector<int> used;				//������ ���������� ������
			vector<int> path;				//������ ������ ������������ ����� ���� � ������ � ������
			vector<int> short_path;			//���������� ���� �� a �� b
			queue<int> buf;					//������ ��������� ������� ��� ������ � ������

			bool check = BFS(a, b, n, used, path, buf, Gr);		//����� ���������������� ������ ������ � �������
			if (check == 0) {
				cout << "\n����� a = " << a << " � b = " << b << " ���� ���(��������� � ������ ����������� ���������)\n\n";
			}

			else {
				int copy_b = b;				//������ ����� b, ���� ����� �������� � b ��� ��������
				while (copy_b != a) {		//� short_path ��������� ��� ���� (��������� ������ ������� � ������ ������� �������� ����� ������� � ��� ���� b != a, �� ���� ��� � ����� � ������)
					short_path.push_back(copy_b);
					//cout << "copy_b = " << copy_b << ",  ������ copy_b (path[copy_b]) = " << path[copy_b] << endl;    //��� �����������
					copy_b = path[copy_b];		//b ������ ����� ������ b, ����� ������� �����-������ ������� b �������� a, ��� ����������� � ��������� if(), � �� ���� ���� ����������
					if (copy_b == a) {
						//cout << "copy_b = " << copy_b << ",  ������ copy_b (path[copy_b]) = " << path[copy_b] << endl;    //��� �����������
						short_path.push_back(copy_b);
					}
				}

				reverse(short_path.begin(), short_path.end());

				cout << "\n\n���������� ���� �� a = " << a << " �� b = " << b << " �����:\n";				//����� ������
				for (auto elem : short_path) {
					cout << elem << ' ';
				}
				cout << "\n����� ���� �� a = " << a << " �� b = " << b << " ����� " << short_path.size() - 1 << endl << endl;

				path.clear();
				short_path.clear();
			}
		}
	}

	
	system("pause");
	return 0;
}