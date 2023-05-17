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

/*
���� ��� 1 �������� � ����� ��� � 0
	���� ������ ��������� ��� ���� ����� �� ����������,
		 �� ������� ��� (� ��������� � ����� ������ �����)
	�����
		���������� ��� ����� � ������ ��������� ���������� ����� (�� ���� ������ ����� ���������� ���������� ������, ���� �� ��� ������: ������� �������, ��������� ����� � ������� ��������� �������)
	1)���� ������ � �����,
		��������� ����� �������� �����.
		���� ����� ����� ���� ����� ������,
			�� ��������� ���� ���� � ����/������ ������/�������.
		����� ���� ����� ������ ����,
			�� ������� ������ ��������, ��������� ���� ��� ���� � ��������� ����������� ����� ����.
		������� 2 �������.
		return �������� �������.
	2)���� ������ �� � �����:
		2.1) ���� ������ ����� ����� ������ ��������, �� �������� �������.
		2.2) ���� ������ ����� ����� = ��������, �� �������� ��������� �������, ������� � � return ����������

���� ��� 2...

...

���� ��� 8 �������� � ����� ��� � 0
	���� ������ ��������� ��� ���� ����� �� ����������,
		 �� ������� ��� (� ��������� � ����� ������ �����)
	�����
		���������� ��� ����� � ������ ��������� ���������� ����� (�� ���� ������ ����� ���������� ���������� ������, ���� �� ��� ������: ������� �������, ��������� ����� � ������� ��������� �������)
	1)���� ������ � �����,
		��������� ����� �������� �����.
		���� ����� ����� ���� ����� ������,
			�� ��������� ���� ���� � ����/������ ������/�������.
		����� ���� ����� ������ ����,
			�� ������� ������ ��������, ��������� ���� ��� ���� � ��������� ����������� ����� ����.
		������� 2 �������.
		return �������� �������.
	2)���� ������ �� � �����:
		2.1) ���� ������ ����� ����� ������ ��������, �� �������� �������.
		2.2) ���� ������ ����� ����� = ��������, �� �������� ��������� �������, ������� � � return ����������

����� ���� ����� �����/������ ������ ������ 1, �� (�� ���� �� �� ����� ������ ����)
	������� �� ������ ��������� ������ ������� � �������� ��� �������, ������� � ���� ������ ���������. 
	������� �������.
	return �������� �������.

����� ���� ����� �����/������ ������ ����� 1, �� (�� � ����� ������ � �� ����� ������ ����)
	������� �� ������ ��������� ������ ������� � �������� ��� �������, ������� � ���� ������ ���������. 
	??������� �������??
	return ������/���� �������/������ �� ����� ����������� ������ (� ������ � ���� ������ ��� x ���������� ������� � ����� � ������������)

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
	stack* way_stack;
	FatherOfStack* next;
};

void PushInFatherOfStack(FatherOfStack *& father_h, stack *& h) {
	FatherOfStack* father_r = new FatherOfStack;
	father_r->way_stack = h;
	father_h = father_r;
}

void ResetFatherOfStack(FatherOfStack *& father_h) {							//�������� ������
	while (father_h) {
		FatherOfStack * p = father_h;
		father_h = father_h->next;
		delete p;
	}
}

void ResetStack(stack * & h) {
	while (h) {
		stack* r = h;
		h = h->next;
		delete r;
	}
}

FatherOfStack * move(stack *& h, int x, int y, int a[9][9], int size_stack, coordinates &coord_finish, FatherOfStack * father_h, stack * mmega_two, stack * mega_two) {

	if (SizeOfStack(h) < size_stack) {
		//cout << "sizeOfStack(h) = " << SizeOfStack(h) << " size_stack = " << size_stack << endl;

		if (x + 2 <= 8 && y + 1 <= 8 && a[x + 2][y + 1] == 0) {
			cout << "��� 1 ";
			a[x][y] = 1;
			push(h, x + 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}

			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}

		}
		if (x - 2 >= 1 && y + 1 <= 8 && a[x - 2][y + 1] == 0) {
			cout << "��� 2 ";
			a[x][y] = 1;
			push(h, x - 2, y + 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;


			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x + 2 <= 8 && y - 1 >= 1 && a[x + 2][y - 1] == 0) {
			cout << "��� 3 ";
			a[x][y] = 1;
			push(h, x + 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;


			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x - 2 >= 1 && y - 1 >= 1 && a[x - 2][y - 1] == 0) {
			cout << "��� 4 ";
			a[x][y] = 1;
			push(h, x - 2, y - 1);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;


			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x + 1 <= 8 && y + 2 <= 8 && a[x + 1][y + 2] == 0) {
			cout << "��� 5 ";
			a[x][y] = 1;
			push(h, x + 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x - 1 >= 1 && y + 2 <= 8 && a[x - 1][y + 2] == 0) {
			cout << "��� 6 ";
			a[x][y] = 1;
			push(h, x - 1, y + 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x + 1 <= 8 && y - 2 >= 1 && a[x + 1][y - 2] == 0) {
			cout << "��� 7 ";
			a[x][y] = 1;
			push(h, x + 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		if (x - 1 >= 1 && y - 2 >= 1 && a[x - 1][y - 2] == 0) {
			cout << "��� 8 ";
			a[x][y] = 1;
			push(h, x - 1, y - 2);
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl;
			

			if (h->inf_x == coord_finish.x && h->inf_y == coord_finish.y) {

				cout << "�� ����� �� �����" << endl;
				//cout << "_________--_____________________________----__---_-______" << endl;
				//cout << "���������� ���� ���� h ���� - ������ � ���������� ��� ����� � �������� ��� ������� � size_stack ������������ ��� �������" << endl;

				if (SizeOfStack(h) < size_stack) {
					//cout << "����� ��������� �٨ ������!" << endl;
					ResetFatherOfStack(father_h);
				}
				//cout << "������ size_stack = " << SizeOfStack(h) << endl;
				size_stack = SizeOfStack(h);

				PushInFatherOfStack(father_h, h);

				pop(h);
				push(mega_two, h->inf_x, h->inf_y);
				a[h->inf_x][h->inf_y] = 2;
				pop(h);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
			else {
				//coordinates x_y_head = pop(h);
				//a[h->inf_x][h->inf_y] = 1;
				//push(h, x_y_head.x, x_y_head.y);
				return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
			}
		}
		else {
			cout << endl << "------������ ���� ������ �� �����!"<< endl;
			/*
			cout << endl << "�� ��������������\n" << "����� ���� �����:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 0) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			*/
			cout << endl;
			cout << "����� ���� ������:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 1) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "����� ���� �����:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 2) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "����� ���� �����:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 3) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;

			bool flag3 = 0;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 3) {
						a[i][j] = 0;
						if (!flag3) {
							cout << "������ ���������� ������� � ����!" << endl;
							flag3 = 1;
						}
					}
				}
			}
			
			if (flag3 == 0) {
				while (mega_two) {
					a[mega_two->inf_x][mega_two->inf_y] = 0;
					mega_two = mega_two->next;
				}
			}

			if (flag3 == 0)
				cout << "�������� ����� (����� �����������) ���������!" << endl;
			cout << "������� (�����������) ������� �� ���������� ������� = " << h->inf_x << " " << h->inf_y << endl;

			push(mega_two, h->inf_x, h->inf_y);
			a[h->inf_x][h->inf_y] = 2;
			if (flag3) {
				push(mmega_two, h->inf_x, h->inf_y);
			}
			pop(h);
			/*
			cout << endl << "����� ��������������\n" << "����� ���� ����� : " << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 0) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			*/
			cout << endl;
			cout << "����� ���� ������:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 1) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "����� ���� �����:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 2) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;
			cout << "����� ���� �����:" << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (a[i][j] == 3) {
						cout << "x = " << i << " y = " << j << " ";
					}
				}
			}
			cout << endl;

			//������� 1 �������� ���
			//a[h->inf_x][h->inf_y] = 1;
			cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl << endl;
			return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
		}
	}
	else {
		cout << endl <<"            Stack �������� ����� �� ������� � ������ �� ������������ �����" << endl;
		/*
		if ((size_stack - SizeOfStack(h)) == 0) {
			pop(h);
			pop(h);
		}
		// else if ����� ������, ������ �� ���������
		else if ((size_stack - SizeOfStack(h)) == 1) {
			pop(h);
		}
		*/
		cout << "������� ������� �� ���������� ������� = " << h->inf_x << " " << h->inf_y << endl;
		a[h->inf_x][h->inf_y] = 3;
		pop(h);
		cout << "������� ������� �� ���������� ���� = " << h->inf_x << " " << h->inf_y << endl;
		a[h->inf_x][h->inf_y] = 0;
		pop(h);
		/*
		cout << endl << "����� ���� �����:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 0) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		*/
		cout << endl;
		cout << "����� ���� ������:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 1) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		cout << endl;
		cout << "����� ���� �����:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 2) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		cout << endl;
		cout << "����� ���� �����:" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (a[i][j] == 3) {
					cout << "x = " << i << " y = " << j << " ";
				}
			}
		}
		cout << endl;

		cout << "h->inf_x = " << h->inf_x << " h->inf_y = " << h->inf_y << endl << endl;
		return move(h, h->inf_x, h->inf_y, a, size_stack, coord_finish, father_h, mmega_two, mega_two);
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

	cout << "x(start) = " << coord_start.x << " y(start) = " << coord_start.y << endl;
	cout << "x(finish) = " << coord_finish.x << " y(finish) = " << coord_finish.y << endl << endl << endl;

	int a[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = 0;
		}
	}
	a[coord_start.x][coord_start.y] = 1;

	stack* head_one_way = NULL;

	FatherOfStack* result = NULL;

	push(head_one_way, start_x, start_y);

	stack* mmega_two = NULL;
	stack* mega_two = NULL;

	////////////////////////////////////////////////////////////////////

	result = move(head_one_way, start_x, start_y, a, MAX_NUMB, coord_finish, result, mmega_two, mega_two);
	FatherOfStack* copy_result = result;

	while (copy_result) {
		cout << "������ ���������� ���� = " << copy_result->way_stack << "� ����� ��� �����������, �� ���� �������� �����:" << endl;
		stack* one_of_stacks = copy_result->way_stack;

		while (one_of_stacks) {
			cout << "x = " << one_of_stacks->inf_x << "y = " << one_of_stacks->inf_y << endl;
			one_of_stacks = one_of_stacks->next;
		}

		copy_result = copy_result->next;
	}

	///////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////

	system("Pause");										//�����
	system("Pause");										//�����
	system("Pause");										//�����
	system("Pause");										//�����
	return 0;												//����� ���������
}