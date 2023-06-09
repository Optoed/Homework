/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
������ 1.1. �������: 
������� ����, ���������� ����� �����.
������� ����� ����, ������� ����� ������� ����� ������� (�������, ���������� � ���������� ��� �� �����) ��������� ��������.
������� ���������� ����� � ����� ����� ������ ��������� � ��������������.
��������, ���� 1 2 3 4 5 6 7 8 9, �����  1 0 2 3 4 5 6 7 8 9
*/


#include<iostream>						//����������� ���������� �����-������
using namespace std;


struct stack {							//���� ����������� ��� struct ��������� �������
	int inf;
	stack * next;
};


void push(stack * &h, int x) {			//������� ���������� �������� � ����
	stack * r = new stack;				//������ ����� �������
	r -> inf = x;						//�������������� ���� inf = x
	r -> next = h;						//C�������� ��������� �������� h
	h = r;								//������ r �������� �������
}


int pop(stack * &h) {					//������� �������� �������� �� ����� (� ����������� ��� ��������)
	int i = h -> inf;					//�������� ������� ��������
	stack * r = h;						//��������� �� ������ �����
	h = h -> next;						//��������� ��������� �� ��������� �������
	delete r;							//������� ������ �������
	return i;							//���������� ��������
}


void reverse(stack * &h) {				//������� "���������" �����
	stack * head1 = NULL;				//������������� ��������� �����

	while (h)							//���� ���� �� ����
		push(head1, pop(h));			//������������ �� ������ ����� � ������

	h = head1;							//�������������� ���������
}


stack * result(stack * &h, int &elem) {	//������� ������ ����������
	stack * res = NULL;					//�������������
	stack * h1 = NULL;					//�������������

	bool flag = 0;

	while (h) {							//���� ���� �� ����
		int x = pop(h);					//������� ������ ������� � ���������� ��� ��������

		push(res, x);					//���������� � ��������� res

		if (flag == 0 && x % 2 != 0) {	//��������� ����� ������� ����� ������� ���������
			push(res, elem);
			flag = 1;
		}
	}

	reverse(res);						//�������������� ����-��������� res
	return res;							//���������� ����-��������� res
}




int main() {							//������� �������
	setlocale(LC_ALL, "RUS");

	int n;								//���������� ����� �����
	cout << "n = ";
	cin >> n;							//������ ���������� ����� �����
	cout << endl;

	stack * head = NULL;				//�������������
	int x;
	for (int i = 0; i < n; i++) {		//������� ����
		cin >> x;						//������ �����
		push(head, x);					//��������� ����
	}

	reverse(head);						//�������������� ����, ����� ��� ��� �������, � ������� �� ������� �����

	int elem;							//������ ����� �������
	cout << "����� ������� = ";
	cin >> elem;

	stack * res = result(head, elem);	//��������� (����, ��� �� ����� ����� ������� ����� ������� ���������)
	cout << endl;
	while (res)							//���� res �� ������ ������
		cout << pop(res) << " ";		//������� �� ����� �������� ����� res �������� pop(...)
	cout << endl;
	
	system("Pause");					//�����
	return 0;							//����� ���������
}
