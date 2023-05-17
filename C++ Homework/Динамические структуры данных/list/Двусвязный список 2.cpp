/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
������ 1.1. �������:
������� ���������� ������, ���������� ����� �����.
��������� ����������� ����� ������ ���, ����� �� ������ ����� ��� ������ ������������ �������.
��������, ����  1 2 5 1 4 5 3 4 5 2 
�����			5 1 4 5 3 4 5 2 1 2
*/


#include<iostream>											//����������� ���������� �����-������
#include<limits.h>
using namespace std;


struct list {												//���������� ������ ����������� ��� list ��������� �������
	int inf;
	list* next;
	list* prev;
};


void push(list*& h, list*& t, int x) {						//������� �������� � ������
	list* r = new list;
	r->inf = x;
	r->next = NULL;

	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}

	else {
		t->next = r;
		r->prev = t;
	}

	t = r;
}


void print(list*& h, list*& t) {						//����� ��������� ������
	list* p = h;
	cout << endl << "����� ����������� ����������� ������:" << endl;
	while (p) {
		cout << p->inf << ' ';
		p = p->next;
	}
	cout << endl << endl;
}


list* find(list*& h, list*& t, int x) {						//����� �������� � ������
	list* p = h;
	while (p) {
		if (p->inf == x) {
			break;
		}
		p = p->next;
	}
	return p;
}


void insert_after(list*& h, list*& t, list* r, int y) {		//������� �������� ����� ������������ ��������
	list* p = new list;
	p->inf = y;

	if (r == t) {
		p->next = NULL;
		p->prev = r;
		r->next = p;
		t = p;
	}

	else {
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}
}


void del_node(list*& h, list*& t, list* r) {				//�������� �������� �� ������
	if (r == h && r == t) {
		h = t = NULL;
	}
	else if (r == h) {
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}


void del_list(list*& h, list*& t) {							//�������� ������
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = NULL;
		delete p;
	}
}


list* result_list(list*& h, list*& t, int &n) {				//���������

	int max = INT_MIN, count = 0;
	bool flag = 0;

	while (h) {
		if (h->inf > max) {
			max = h->inf;
		}
		if (h->next) {
			h = h->next;
		}
		else {
			break;
		}
	}

	while (h) {
		if (h->prev) {
			h = h->prev;
		}
		else {
			break;
		}
	}

	cout << "������ �������� = " << max << endl;
	while (h) {
		if (count != n) {
			int i = h->inf;
			if (i == max) {
				cout << "������ �������� ������ �� ������ �����. ����������� ����� �������!" << endl;
				break;
			}
			del_node(h, t, h);
			push(h, t, i);
			count++;
		}
		else {
			cout << "����������� ����� �� ��������!" << endl;
		}
	}

	return h;
}


int main() {												//������� �������
	setlocale(LC_ALL, "RUS");

	cout << "������ 1. �������: \n������� ���������� ������, ���������� ����� �����.\n��������� ����������� ����� ������ ���, ����� �� ������ ����� ��� ������ ������������ �������.\n��������, ����  1 2 5 1 4 5 3 4 5 2.\n�����		5 1 4 5 3 4 5 2 1 2.\n" << endl;

	int n;													//���������� ����� �����
	cout << "n = ";
	cin >> n;												//������ ���������� ����� �����
	cout << endl;

	list* head = NULL;										//�������������
	list* tail = NULL;										//�������������
	int x;
	cout << "��������� ���������� ������ �������:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(head, tail, x);
	}

	head = result_list(head, tail, n);

	if (head)
		print(head, tail);
	else
		cout << "������ ����!" << endl;

	system("Pause");										//�����
	return 0;												//����� ���������
}