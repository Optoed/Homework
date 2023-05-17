/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
�������:

���� ��������� �����. 
������� ���������� ���� ����� �� ������ � �� ������ �. 
������ ���� ������� ��� ������ � ����, ��������, �2 � �6. 
���� ������ ���� ������� � ���� ������ ������ �2 �4 �6 D8 E6

*/


#include<iostream>											//����������� ���������� �����-������
#include<string>
#include<limits.h>
using namespace std;

const int MAX_NUMB = INT_MAX;

struct coordinates {										//���������, ���������� � ���� ����� � �����������
	int x;
	int y;
};


int char_into_int (char a) {
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
		return -999;
}


char int_into_char(int a) {
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


struct stack {							//���� ����������� ��� struct ��������� �������
	int inf_x;
	int inf_y;
	stack* next;
};

void push(stack*& h, int x, int y) {			//������� ���������� �������� � ����
	stack* r = new stack;				//������ ����� �������
	r->inf_x = x;						//�������������� ���� inf = x
	r->inf_y = y;
	r->next = h;						//C�������� ��������� �������� h
	h = r;								//������ r �������� �������
}

int SizeOfStack(stack *& h) {
	int size = 0;
	stack* copy_h = h;
	while (copy_h) {
		size++;
		copy_h = copy_h->next;
	}
	return size;
}

coordinates pop(stack*& h) {					//������� �������� �������� �� ����� (� ����������� ��� ��������)
	int i_x = h->inf_x;					//�������� ������� ��������
	int i_y = h->inf_y;
	stack* r = h;						//��������� �� ������ �����
	h = h->next;						//��������� ��������� �� ��������� �������
	delete r;							//������� ������ �������
	coordinates x_y;
	x_y.x = i_x;
	x_y.y = i_y;
	return x_y;							//���������� ��������
}

struct FatherOfStack {      //���� ������
	stack way_stack;
	stack* next;
};


stack * move(stack *& h, int x, int y, int a[9][9], int size_stack, coordinates &coord_finish) {

	if (SizeOfStack(h) < size_stack) {
		cout << "sizeOfStack(h) = " << SizeOfStack(h) << " size_stack = " << size_stack << endl;

		if (x + 2 <= 8 && y + 1 <= 8 && a[x + 2][y + 1] == 0) {
			cout << "��� 1 ";
			push(h, x + 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� ������� (������)
				size_stack = SizeOfStack(h);
				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move - ������
				pop(h);
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}

			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}

		}
		if (x - 2 >= 1 && y + 1 <= 8 && a[x - 2][y + 1] == 0) {
			cout << "��� 2 ";
			push(h, x - 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� �������, � ����� size_stack ������������ ��� �������, � �������� ����������� ������� �����

				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move
				return h;
			}
			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x + 2 <= 8 && y - 1 >= 1 && a[x + 2][y - 1] == 0) {
			cout << "��� 3 ";
			push(h, x + 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				return h;
			}
			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� �������, � ����� size_stack ������������ ��� �������, � �������� ����������� ������� �����

				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x - 2 >= 1 && y - 1 >= 1 && a[x - 2][y - 1] == 0) {
			cout << "��� 4 ";
			push(h, x - 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				return h;
			}
			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� �������, � ����� size_stack ������������ ��� �������, � �������� ����������� ������� �����

				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x + 1 <= 8 && y + 2 <= 8 && a[x + 1][y + 2] == 0) {
			cout << "��� 5 ";
		
			push(h, x + 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				return h;
			}
			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� �������, � ����� size_stack ������������ ��� �������, � �������� ����������� ������� �����

				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x - 1 >= 1 && y + 2 <= 8 && a[x - 1][y + 2] == 0) {
			cout << "��� 6 ";
			push(h, x - 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				return h;
			}
			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� �������, � ����� size_stack ������������ ��� �������, � �������� ����������� ������� �����

				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x + 1 <= 8 && y - 2 >= 1 && a[x + 1][y - 2] == 0) {
			cout << "��� 7 ";
			push(h, x + 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				return h;
			}
			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� �������, � ����� size_stack ������������ ��� �������, � �������� ����������� ������� �����

				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		if (x - 1 >= 1 && y - 2 >= 1 && a[x - 1][y - 2] == 0) {
			cout << "��� 8 ";
			push(h, x - 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			
			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				cout << "�� ����� �� �����" << endl;
				return h;
			}
			else {
				coordinates x_y_head = pop(h);
				a[h->inf_x][h->inf_y] = 1;
				push(h, x_y_head.x, x_y_head.y);
				//���������� ���� ���� h ����-������ � ���������� ��� ����� � �������� ��� �������, � ����� size_stack ������������ ��� �������, � �������� ����������� ������� �����

				//� ������ ���� ������� 2 �������� (���� �� �����, �� ����) � ������� ���������� ������� move
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
			}
		}
		else {
			cout << "------������ ���� ������ �� �����!" << endl;
			pop(h);
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 1) {
						a[i][j] = 0;
					}
				}
			}
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
		}
	}
	else {
		cout << endl <<"------------Stack �������� ����� �� ������� � ������ �� ������������ �����" << endl;
		if ((size_stack - SizeOfStack(h)) == 0) {
			pop(h);
			pop(h);
		}
		// else if ����� ������, ������ �� ���������
		else if ((size_stack - SizeOfStack(h)) == 1) {
			pop(h);
		}

		cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
		return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish);
	}
}



int main() {												//������� �������
	setlocale(LC_ALL, "RUS");

	string start, finish;
	cout << "������� ������, ������ ���� �������� ���� ���� (��������, A2, ����� ��������� � ��� ��������!): ";
	cin >> start;
	cout << "������� ������, ��� ���� ������ ��������� ���� ���� (��������, E6, ����� ��������� � ��� ��������!): ";
	cin >> finish;

	coordinates coord_start, coord_finish;
	coord_start.x = char_into_int(start[0]);
	coord_start.y = start[1] - '0';
	int start_x = coord_start.x, start_y = coord_start.y;

	coord_finish.x = char_into_int(finish[0]);
	coord_finish.y = finish[1] - '0';
	int finish_x = coord_finish.x, finish_y = coord_finish.y;

	cout << "x = " << coord_start.x << " y = " << coord_start.y << endl;
	cout << "x (finish) = " << coord_finish.x << " y (finish) = " << coord_finish.y << endl;

	int a[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = 0;
		}
	}
	a[coord_start.x][coord_start.y] = 1;

	stack* head_point = NULL;
	stack* head_one_way = NULL;
	stack* head_full_way = NULL;

	push(head_point, start_x, start_y);
	push(head_one_way, start_x, start_y);

	bool step = 0;
	int size_stack;

	while (head_point) {

		if (step == 0) {

			cout << "������� x = " << start_x << " y = " << start_y << endl;

			head_one_way = move(head_one_way, start_x, start_y, a, MAX_NUMB, coord_finish);
			stack* copy_one_way = head_one_way;

			size_stack = SizeOfStack(copy_one_way);
			cout << "������ ����� = " << size_stack << endl;

			if (!copy_one_way) {
				cout << "copy one way ����!!" << endl;
			}

			while (copy_one_way) {
				cout << "copy_one_way->inf_x = " << copy_one_way->inf_x << " copy_one_way->inf_y = " << copy_one_way->inf_y << endl;
				copy_one_way = copy_one_way->next;
			}


			pop(head_one_way);
			coordinates predposl = pop(head_one_way);
			//a[predposl.x][predposl.y] = 0;
			start_x = head_one_way->inf_x;
			start_y = head_one_way->inf_y;

			cout << "��� ���� ���� ��������" << endl << endl;
			step = 1;
		}


		else {
			cout << "������� x = " << start_x << " y = " << start_y << endl;

			head_one_way = move(head_one_way, start_x, start_y, a, size_stack, coord_finish);
			stack* copy_one_way = head_one_way;

			size_stack = SizeOfStack(copy_one_way);
			cout << "������ ����� = " << size_stack << endl;

			if (!copy_one_way) {
				cout << "copy one way ����!!" << endl;
			}

			while (copy_one_way) {
				cout << "copy_one_way->inf_x = " << copy_one_way->inf_x << " copy_one_way->inf_y = " << copy_one_way->inf_y << endl;
				copy_one_way = copy_one_way->next;
			}


			pop(head_one_way);
			pop(head_one_way);
			start_x = head_one_way->inf_x;
			start_y = head_one_way->inf_y;

			cout << "��� ���� ���� ��������" << endl << endl;
		}
	}

	

	system("Pause");										//�����
	return 0;												//����� ���������
}