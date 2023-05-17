/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
���� �������������� ���������. ��������� ��� � ����������� �����.

������� ��� �����:

5+(3+(2+4*(3-1)+2)/4+1)*4
5*(2+3*7)+4
a*(b+c*d)+e

*/


#include <iostream>										//����������� ���������� �����-������
#include <string>										//����������� ���������� �����
using namespace std;


struct stack {											//���� ����������� ��� struct ��������� �������
	char inf;
	stack* next;
};


void push(stack*& h, char x) {							//������� ���������� �������� � ����
	stack* r = new stack;								//������ ����� �������
	r->inf = x;											//�������������� ���� inf = x
	r->next = h;										//C�������� ��������� �������� h
	h = r;												//������ r �������� �������
}


char pop(stack*& h) {									//������� �������� �������� �� ����� (� ����������� ��� ��������)
	char i = h->inf;									//�������� ������� ��������
	stack* r = h;										//��������� �� ������ �����
	h = h->next;										//��������� ��������� �� ��������� �������
	delete r;											//������� ������ �������
	return i;											//���������� ��������
}


int prior(char &a) {									//���������� "���������" ������� � ����������� �� ����, ��� ��� �� ������
	if (a == '(') {
		return 1;
	}
	else if (a == '+' || a == '-') {
		return 2;
	}
	else if (a == '*' || a == '/') {
		return 3;
	}
	else if (isdigit(a) || isalpha(a)) {
		return 4;
	}
	else if (a == ' ') {
		return 5;
	}
	else {
		return 6;
	}
}


int main() {															//������� �������
	setlocale(LC_ALL, "RUS");

	string str, result_str = "";
	cout << "��������� � ��������� ����� (����������� ������ ����� ����� < 10):" << endl;
	getline(cin, str);													//������ �������������� ��������� (�� ���� ������, ����� � ���������)
	cout << endl;
	stack* head = NULL;													//������������� �����

	for (size_t i = 0; i < str.size(); i++) {							//���������� �� ���� ������
		char a = str[i];												//i-��� �������
		cout << "������� = " << a << endl;								//������� ������� (��� �����������)
		
		if (a == ' ') {													//���� ���� �������, �� �� ������ ����������
			cout << "������, ������������� ����������" << endl;
			continue;
		}
		
		if (isdigit(a) || isalpha(a)) {									//���� ������� - ��� ����� ��� �����
			cout << "��������� ������� � �������������� ������:" << endl;
			result_str += a;											//���������� � �������������� ������ � ������� � (��� �����������)
			cout << "result_str = " << result_str << endl;
		}

		if (a == '(') {													//���� ������� - ��� '(', �� ���� ����������� ������
			cout << "��������� ��-� '(' � ����" << endl;
			push(head, a);												//�� ��������� � � ����
		}

		if (a == '+' || a == '-' || a == '*' || a == '/') {				//���� ������� - ��� ���� �������� + - / *
			stack* r = head;											//�������� ���� � ������� head
			if (r) {
				cout << "����� ����������� ����� ��� �����������: ";
				while (r) {												//���� ���� r �� ����
					char i = r->inf;									//�������� ������� ��������
					cout << i << ' ';									//����� ����������� �����
					r = r->next;										//������ r ����� ������ �� ��������� �������
				}
				cout << endl;
			}

			if (!head) {												//���� ���� ����, �� ��������� ���� ������� � ����
				cout << "���� head ����, ������� � ���� ���� �������" << endl;
				push(head, a);
			}

			else if (head) {											//���� ���� �� ����										
				if (prior(a) > prior(head->inf)) {						//���� ��������� ����� �������� ������ ���������� �������� �����
					cout << "��������� ������� ������ ���������� �������� �����, ������� ������ ������� ���� ������ � ����" << endl;
					push(head, a);
				}

				else if (prior(a) <= prior(head->inf)) {				//���� ��������� ����� �������� <= ���������� �������� �����
					cout << "��������� ������� <= ���������� �������� �����" << endl;

					while (head && prior(a) <= prior(head->inf)) {		//���� ���� �� ���� � ��������� ����� ������� ������/����� ���������� �������� �����
						cout << "�������� ����� = " << head->inf << endl;
						result_str += head->inf;                        //��������� �������� ����� � result_str � �������� ��� �� �����
						cout << "result_str = " << result_str << endl;
						head = head->next;
					}

					cout << "� ������ ������� ��� ������� � ����" << endl;
					push(head, a);
				}
			}
		}

		if (a == ')') {													//���� ������� = ����������� ������
			while (a != '(') {											//���� �� ���������� ����������� ������, ������� �� ����� �������� � ��������� � � result_str
				a = pop(head);
				cout << "�������� �������� = " << a << endl;
				result_str += a;
				cout << "result_str = " << result_str << endl;
			}
			result_str.resize(result_str.size() - 1);					//������� ��������� �������, �� ���� '('
			cout << "result_str ������ = " << result_str << endl;
		}
		cout << endl;
	}

	cout << "������ ��������, ������ ������� ���������� � ����� �������� � result_str" << endl;
	while (head) {														//���� ���� �� ����, ������� �� ���� �������� � ��������� �� � �������������� ������
		char s = pop(head);
		cout << "�������� ����� = " << s << endl;
		result_str += s;
		cout << "result_str = " << result_str << endl;
	}
	cout << endl << endl;

	cout << "�������� �������������� ���������: " << str << endl;		//����� ������
	cout << "����� � ����������� �����:         " << result_str << endl << endl;

	/////////////////////////////////////////////////////
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl << "����� 2: ���������� �������� ��������� � ����������� �����" << endl;
	cout << "��������� � ����������� ����� = " << result_str << endl << endl;
	stack* head2 = NULL;												//�������������� ����� ����
	int sum = 0;
	for (size_t i = 0; i < result_str.size(); i++) {							//���������� �� ���� ������
		char symbol = result_str[i];
		cout << "symbol = " << symbol << endl;
		if (isdigit(symbol) || isalpha(symbol)) {
			push(head2, symbol);
		}
		else {
			//
			stack* r = head2;											//�������� ���� � ������� head
			if (r) {
				cout << "����� ����������� ����� ��� �����������: ";
				while (r) {												//���� ���� r �� ����
					char i = r->inf;									//�������� ������� ��������
					cout << i << ' ';									//����� ����������� �����
					r = r->next;										//������ r ����� ������ �� ��������� �������
				}
				cout << endl;
			}
			//
			char symb_b = pop(head2);
			char symb_a = pop(head2);
			cout << "symb_b = " << symb_b << " � symb_a = " << symb_a << endl;
			int b = (symb_b - '0');
			int a = (symb_a - '0');
			cout << "b = " << b << " a = " << a << endl;
			switch (symbol)
			{
				case '+':
					sum = a + b;
					break;
				case '-':
					sum = a - b;
					break;
				case '*':
					sum = a * b;
					break;
				case '/':
					sum = a / b;
					break;
				default:
					cout << "������������ ������" << endl;
					break;
			}
			if (sum) {
				char sum_ch;
				cout << "sum(int) = " << sum << endl;
				sum_ch = sum + '0';
				cout << "sum_ch(char) = " << sum_ch << endl;
				push(head2, sum_ch);
			}
			cout << endl;
		}
	}

	if (head2) {
		cout << "��� ����������� ��������� �����: ";
		char ans = pop(head2);
		int ans_int = ans - '0';
		cout << ans_int << endl << endl;
	}
	/////////////////////////////////////////////////////////


	system("Pause");													//�����
	return 0;															//����� ���������
}

//5+(3+(2+4*(3-1)+2)/4+1)*4