/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
�������:

������� ������ �������� ���, 
����� ������ ������� ��� �� ������ �������� ��������������� ���� ���������, ��������� �� ���.

��������, ��� ������	5 2 9 1 3 7 1 2 9
��������� ������ ����	2 1 3 1 2 9
*/


#include<iostream>											//����������� ���������� �����-������
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
		if (r->prev == NULL) {
			h = h->next;
			h->prev = NULL;
			cout << "       A" << endl;
		}
		else {
			r->next->prev = r->prev;
			r->prev->next = r->next;
			h = h->next;
			cout << "       E" << endl;
		}
		
		
		
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
		cout << "       B" << endl;
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

struct number_data {										//���������, ���������� � ���� ����� � �����������
	int sum;
	int count;
};

number_data sum_count(list*& h, list*& t) {					//�������, ������������ ��������� number_data � ������ � ����������� ���� ��������� ������
	number_data numb;
	numb.sum = 0;
	numb.count = 0;

	while (h) {
		numb.sum += h->inf;
		numb.count++;
		if (h->next)
			h = h->next;
		else
			break;
	}

	while (h) {
		if (h->prev) {
			h = h->prev;
		}
		else {
			break;
		}
	}

	return numb;
}

list* result_list(list*& h, list*& t) {						//���������

	
	number_data numb = sum_count(h, t);

	cout << "sum = " << numb.sum << endl;
	cout << "count = " << numb.count << endl;


	while (h) {
		cout << endl;

		int i = h->inf;
		cout << "i = " << i << endl;
		numb.sum -= i;
		cout << "numb.sum = " << numb.sum << endl;
		numb.count--;
		cout << "numb.count = " << numb.count << endl;
		

		if (h->next) {
			
			if (i > int(numb.sum / numb.count)) {
				cout << "������� �������������� (���������� ����) ���� ��-���, ��������� �� i = " << i << ", ����� " << int(numb.sum / numb.count) << endl;
				cout << "i > �������� ���������������, ������� �������" << endl;

				cout << "��:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;

				del_node(h, t, h);

				cout << "�����:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;

			}
			else {
				cout << "������� �������������� (���������� ����) ���� ��-���, ��������� �� i = " << i << ", ����� " << int(numb.sum / numb.count) << endl;
				cout << "i <= �������� ���������������, ������� �� �������" << endl;

				cout << "��:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;

				
				h = h->next;

				cout << "�����:" << endl;
				if (h->prev)
					cout << " h->prev->inf = " << h->prev->inf << endl;
				cout << "h->inf = " << h->inf << endl;
				if (h->next)
					cout << " h->next->inf = " << h->next->inf << endl;
			}
		}

		else {
			cout << "��� ��� ��������� �������, ������������� �� �������!" << endl;
			break;
		}

	}
	cout << endl;

	while (h) {
		cout << h->inf << ' ';
		if (h->prev)
			cout << " h->prev->inf = " << h->prev->inf << endl;
		cout << "h->inf = " << h->inf << endl;
		if (h->next)
			cout << " h->next->inf = " << h->next->inf << endl;
		if (h->prev) {
			h = h->prev;
			
		}
		else {
			break;
		}
		cout << endl;
	}
	cout << endl;
	return h;
}


int main() {												//������� �������
	setlocale(LC_ALL, "RUS");

	cout << "�������: \n������� ���������� ������, ���������� ����� �����.\n������� ������ �������� ���, \n����� ������ ������� ��� �� ������ �������� ��������������� ���� ���������, ��������� �� ���.\n��������, ��� ������ 5 2 9 1 3 7 1 2 9, ��������� ������ ���� 2 1 3 1 2 9.\n" << endl;

	int n;													//���������� ����� �����
	cout << "n = ";
	cin >> n;												//������ ���������� ����� �����
	cout << endl;

	list* head = NULL;										//�������������
	list* tail = NULL;										//�������������
	int x;
	cout << "��������� ������ �������:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(head, tail, x);
	}

	head = result_list(head, tail);

	cout << "----------------------------------------------------------------" << endl;
	if (head)
		print(head, tail);
	else
		cout << "������ ����!" << endl;

	system("Pause");										//�����
	return 0;												//����� ���������
}