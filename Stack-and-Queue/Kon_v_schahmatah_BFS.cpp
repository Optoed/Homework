
// Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.

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

int char_into_int(char a) {
	if (a == 'A')
		return 0;
	if (a == 'B')
		return 1;
	if (a == 'C')
		return 2;
	if (a == 'D')
		return 3;
	if (a == 'E')
		return 4;
	if (a == 'F')
		return 5;
	if (a == 'G')
		return 6;
	if (a == 'H')
		return 7;
	else
		return -99999;
}

char int_into_char(int a) {
	if (a == 0)
		return 'A';
	if (a == 1)
		return 'B';
	if (a == 2)
		return 'C';
	if (a == 3)
		return 'D';
	if (a == 4)
		return 'E';
	if (a == 5)
		return 'F';
	if (a == 6)
		return 'G';
	if (a == 7)
		return 'H';
	else
		return '?';
}


void dfs(string point, vector<bool> &used, vector<vector<int>> &Gr) {

	queue<string> buf;

	int x = char_into_int(point[0]);
	int y = point[1] - '0';
	int pozition = x * 8 + y;

	used[pozition] = 1;
	buf.push(point);
	watch(point);

	while (!buf.empty()) {
		string this_point = buf.front();
		int this_x = char_into_int(this_point[0]);
		int this_y = this_point[1] - '0';
		int this_pozition = this_x * 8 + this_y;
		buf.pop();
		for (int i = 0; i < Gr[this_pozition].size(); ++i) {
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

	vector<bool> used(64);
	vector<vector<int>> Gr; //Возможно тут string
	
	string start;
	cout << "Вершина, с которой мы начинаем обход: ";
	cin >> start;

	for (int x = 0; x < 8; x++) {    //i = x*8+y       
		
		for (int y = 0; y < 8; y++) {

			vector<int> vec;

			if (((x + 2) * 2 + y + 1) > 0 && ((x + 2) * 2 + y + 1) < 64) {
				//string word = 
				vec.push_back((x + 2) * 2 + y + 1); // word 
			}
			if (((x + 2) * 2 + y - 1) > 0 && ((x + 2) * 2 + y - 1) < 64) {
				vec.push_back((x + 2) * 2 + y - 1);
			}
			if (((x - 2) * 2 + y + 1) > 0 && ((x - 2) * 2 + y + 1) < 64) {
				vec.push_back((x - 2) * 2 + y + 1);
			}
			if (((x - 2) * 2 + y - 1) > 0 && ((x - 2) * 2 + y - 1) < 64) {
				vec.push_back((x - 2) * 2 + y - 1);
			}

			if (((x + 1) * 2 + y + 2) > 0 && ((x + 1) * 2 + y + 2) < 64) {
				vec.push_back((x + 1) * 2 + y + 2);
			}
			if (((x + 1) * 2 + y - 2) > 0 && ((x + 1) * 2 + y - 2) < 64) {
				vec.push_back((x + 1) * 2 + y - 2);
			}
			if (((x - 1) * 2 + y + 2) > 0 && ((x - 1) * 2 + y + 2) < 64) {
				vec.push_back((x - 1) * 2 + y + 2);
			}
			if (((x - 1) * 2 + y - 2) > 0 && ((x - 1) * 2 + y - 2) < 64) {
				vec.push_back((x - 1) * 2 + y - 2);
			}

			Gr.push_back(vec);

			vec.clear();

		}
	}

	
	////////////////////////////
	dfs(start, used, Gr);


	system("pause");
	return 0;
}
