
//������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.

/*
�������:
���� ��������� �����.
������� ���������� ���� ����� �� ������ � �� ������ �.
������ ���� ������� ��� ������ � ����, ��������, �2 � �6.
���� ������ ���� ������� � ���� ������ ������ �2 �4 �6 D8 E6
*/

#include<iostream>									//����������� ���������� �����-������
#include<algorithm>									//����������� ���������� ����������

#include<iomanip>
#include<limits.h>									//����������� ���������� ��� INT_MAX

#include<vector>									//����������� ���������� ��������																
#include<stack>										//����������� ���������� ������	
#include<queue>										//����������� ���������� ��������

#include<string.h>									//����������� ��������� ��� ������������� �����
#include<string>

#define watch(x) cout << #x << " = " << x << endl   //������ ��� �������� ������ �������� ����������

using namespace std;

int min_count = INT_MAX;							//��� ������ ���� ����������� �����

int char_into_int(char a) {							//������� �������� ����� � �����
	if (a == 'A')
		return 1;
	if (a == 'B')
		return 2;
	if (a == 'C')
		return 3;
	if (a == 'D')
		return 4;
	if (a == 'E')
		return 5;
	if (a == 'F')
		return 6;
	if (a == 'G')
		return 7;
	if (a == 'H')
		return 8;
	else
		return -99999;
}

char int_into_char(int a) {							//������� �������� ����� � �����
	if (a == 1)
		return 'A';
	if (a == 2)
		return 'B';
	if (a == 3)
		return 'C';
	if (a == 4)
		return 'D';
	if (a == 5)
		return 'E';
	if (a == 6)
		return 'F';
	if (a == 7)
		return 'G';
	if (a == 8)
		return 'H';
	else
		return '?';
}


void bfs(string point, string &finish, vector<bool> &used, vector<vector<string>> &Gr) {		//����� � ������ ��� ������ ����������� ���� �� ������

	queue<string> buf;						//���� ����� ���������� ��� �����
	stack<string> answer;					//���� ����� ���������� ��� ������� pop'�� �����

	int x = char_into_int(point[0]);		
	int y = point[1] - '0';
	int pozition = (x - 1) * 8 + y;			//������� ������� ����� (�� 1 �� 64 ������������)

	used[pozition] = 1;						//�������� ���������
	buf.push(point);						//��������� ����� � ����� ������� buf
	
	while (!buf.empty()) {					//���� ������� buf �� �����, ������� � �������� � ���� ��������� ��� � ������� �����, ���� �� ����� �������. 
		string this_point = buf.front();	
		int this_x = char_into_int(this_point[0]);
		int this_y = this_point[1] - '0';
		int this_pozition = (this_x - 1) * 8 + this_y;
		buf.pop();
		answer.push(this_point);

		for (int i = 0; i < Gr[this_pozition-1].size(); ++i) {		//������ �� ���� ������� ������
			string t = Gr[this_pozition-1][i];
			int t_x = char_into_int(t[0]);
			int t_y = t[1] - '0';
			int t_pozition = (t_x - 1) * 8 + t_y;

			if (used[t_pozition] == 0) {							//���� �� ��� �� ���� � ���� �����
				buf.push(t);										//��������� � � �������
				used[t_pozition] = 1;								//�������� ���������, ����� ������ ���� �� ��������

				if (t == finish) {									//���� �� ������ � �����, �� ������� � ��������� ���� final_answer �������,
					stack<string> copy_answer = answer;				//����������� ���� �� start �� finish
					copy_answer.push(t);
					stack<string> final_answer;
					int count = 0;									//����� ���� count, ���������� ��� ���������� ����������� ����

					while (!copy_answer.empty()) {					//���� ����� answer �� �����, ���������� �� ���� ������ � ������ ��������� � ����-�����
						string top = copy_answer.top();
						copy_answer.pop();

						if (count < 2) {
							final_answer.push(top);
							count++;
						}

						else {
							int top_x = char_into_int(top[0]);
							int top_y = top[1] - '0';
							int top_pozition = (top_x - 1) * 8 + top_y;
							vector <string> Gr_top_poz = Gr[top_pozition - 1];

							for (auto it = Gr_top_poz.begin(); it != Gr_top_poz.end(); it++) {	
								if (*it == final_answer.top()) {								//���� ����� �������� � ���� ������ ��������� �������� �����-������
									final_answer.push(top);										//�� ��������� � � ����-����� � ��� ��� ���������� ����� ���������
									count++;
									break;
								}
							}
						}
					}

					if (count <= min_count) {			//���� ������ ����������� �� ����� ����
						cout << endl;
						while (!final_answer.empty()) {
							cout << final_answer.top() << ' ';
							final_answer.pop();
						}
						min_count = count;
						cout << endl;
					}

					used[t_pozition] = 0;			//����� �������� ������ 0, ����� � ���� �������� �� ���� ���
				}
			}
		}
	}
}


int main() {						//������� �������
	setlocale(LC_ALL, "RUS");		//������� ���������

	vector<bool> used(100);			//� ������ ������� �������� "1" ���������� �������
	vector<vector<string>> Gr;		//������ ���������
	
	string start;
	cout << "����� ������, � ������� �� �������� �����: ";
	cin >> start;

	string finish;
	cout << "����� ������, ���� �� ����� �������: ";
	cin >> finish;

	for (int x = 1; x <= 8; x++) {    //��������� ������ ��������� ��� ������ ����� �� ��������� �����    

		for (int y = 1; y <= 8; y++) {

			vector<string> vec;
			
			if ((x + 2) > 0 && (y + 1) > 0 && (x + 2) <= 8 && (y + 1) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x + 2);
				poz[1] = (y + 1) + '0';
				vec.push_back(poz);														//���� ����������, �� ���������
			}
			if ((x + 2) > 0 && (y - 1) > 0 && (x + 2) <= 8 && (y - 1) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x + 2);
				poz[1] = (y - 1) + '0';
				vec.push_back(poz);														//���� ����������, �� ���������
			}
			if ((x - 2) > 0 && (y + 1) > 0 && (x - 2) <= 8 && (y + 1) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x - 2);
				poz[1] = (y + 1) + '0';
				vec.push_back(poz);														//���� ����������, �� ���������
			}
			if ((x - 2) > 0 && (y - 1) > 0 && (x - 2) <= 8 && (y - 1) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x - 2);
				poz[1] = (y - 1) + '0';
				vec.push_back(poz);														//���� ����������, �� ���������
			}

			if ((x + 1) > 0 && (y + 2) > 0 && (x + 1) <= 8 && (y + 2) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x + 1);
				poz[1] = (y + 2) + '0';
				vec.push_back(poz);														//���� ����������, �� ���������
			}
			if ((x + 1) > 0 && (y - 2) > 0 && (x + 1) <= 8 && (y - 2) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x + 1);
				poz[1] = (y - 2) + '0';	
				vec.push_back(poz);														//���� ����������, �� ���������
			}
			if ((x - 1) > 0 && (y + 2) > 0 && (x - 1) <= 8 && (y + 2) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x - 1);
				poz[1] = (y + 2) + '0';
				vec.push_back(poz);														//���� ����������, �� ���������
			}
			if ((x - 1) > 0 && (y - 2) > 0 && (x - 1) <= 8 && (y - 2) <= 8) {			//��������, ��� ����� � ������ ��������� ����������
				string poz = "__";
				poz[0] = int_into_char(x - 1);
				poz[1] = (y - 2) + '0';
				vec.push_back(poz);														//���� ����������, �� ���������
			}

			Gr.push_back(vec);				//��������� ���� ������ (������ ������) ��������� � ������ ��������� ���� �����

			vec.clear();					//������� ������ ��������� ���� �����
		}
	}


	cout << endl << "-----------------------------------------------------------------" << endl;

	bfs(start, finish, used, Gr);			//����� ������� ������ � ������ 
	
	cout << endl << "-----------------------------------------------------------------" << endl;

	system("pause");						//����� 
	return 0;								//����� ���������
}