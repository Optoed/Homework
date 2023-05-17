/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
������ 1. �������: 
������� ���������� ������, ���������� ����� �����.\n
����� ���� �����, ������ ������������ �����, �������� ��������� ������ �������.\n
��������, ����  2 8 2 1 6 8 8 1 2 2 8 2 1\n
�����			2 8 2 1 2 6 8 8 1 2 2 2 8 2 1 2\n
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


void insert_after(list*& h, list*& t, list* r, int y) {		//������� ����� r
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


list* result_list(list*& h, list*& t) {				//���������

	int min = INT_MAX, chet;

	bool flag = 0;

	while (h) {
		if (h->inf < min) {
			min = h->inf;
		}
		if ((h->inf) % 2 == 0) {
			chet = h->inf;
			if (!flag)
				flag = 1;
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

	if (flag) {
		cout << "������� = " << min << endl;
		cout << "��������� ������ = " << chet << endl;

		while (h) {
			if (h->inf == min) {
				insert_after(h, t, h, chet);
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
	}

	return h;
}


int main() {												//������� �������
	setlocale(LC_ALL, "RUS");

	cout << "������ 1. �������: \n������� ���������� ������, ���������� ����� �����.\n����� ���� �����, ������ ������������ �����, �������� ��������� ������ �������.\n��������, ����  2 8 2 1 6 8 8 1 2 2 8 2 1\n�����		2 8 2 1 2 6 8 8 1 2 2 2 8 2 1 2\n" << endl;

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

	head = result_list(head, tail);

	if (head)
		print(head, tail);
	else
		cout << "������ ����!" << endl;


	system("Pause");										//�����
	return 0;												//����� ���������
}