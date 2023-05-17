
// ������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.

#include<iostream>
#include<algorithm>

#include<iomanip>
#include<fstream>
#include<ostream>

#include<vector>
#include<map>
#include<array>
#include<set>

#include<string.h>
#include<string>

#include<stack>
#include<queue>

#define watch(x) cout << #x << " = " << x << endl


using namespace std;

/*
ifstream fin("input.txt");
ofstream fout("output.txt");
*/

void dfs(int x, vector<bool>& used, vector<vector<int>> Gr) {

	queue<int> buf;
	used[x] = 1;
	buf.push(x);
	watch(x);

	while (!buf.empty()) {
		int y = buf.front();
		buf.pop();
		for (int i = 0; i < Gr[y].size(); ++i) {
			int t = Gr[y][i];
			if (used[t] == 0) {
				buf.push(t);
				used[t] = 1;
				watch(t);
			}
		}
		cout << endl;
	}

}



int main() {
	setlocale(LC_ALL, "RUS");

	int n; //n = 64
	cout << "���-�� ������: ";
	cin >> n;
	vector<bool> used(n);
	vector<vector<int>> Gr;

	for (int i = 0; i < n; i++) {
		int vsz;
		cout << "����� ������ ���� ������ ������ �������: ";
		cin >> vsz;
		vector<int> vec(vsz);
		cout << "������� ���� ������ �������:" << endl;
		for (int j = 0; j < vsz; j++) {
			int x;
			cin >> x;
			vec.push_back(x);
		}
		Gr.push_back(vec);
		vec.clear();
	}

	int x;
	cout << "�������, � ������� �� �������� �����: ";
	cin >> x;

	dfs(x, used, Gr);


	system("pause");
	return 0;
}