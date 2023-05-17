//������ �� ��������� - 1
//������� ��������� Train, ���������� ������ � ������ ������, ������� �����������, ������� � ����.
//���������� ��� ������� ������ ����� �������� �� �������� �������. ���������� �������� �� ������������ ����� �������
//*������ ������� ������ ����������

#include<iostream>    //����������� ���������� �����-������
#include<string>     //����������� ���������� �����
using namespace std;


struct Train {      //��������� Train
	int number;        //����� ������
	int hour1;         //���� (����� �����������)  
	int minut1;        //������ (����� �����������)
	int hour2;         //���� (����� � ����)
	int minut2;        //������ (����� � ����)
};


Train STR_date(string str) {      //������� �� ������, ���������� ����� ������, ����� ����������� � ����� � ����, � ��������� Train

	Train data;

	string::size_type k, t = 0;
	string punct = ".,;:- ";      //�������������� �������
	k = str.find_first_of(punct);       //����� ������� ��������������� �������

	//--number-------
	string str1 = str.substr(t, k-t);         //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd1 = str1.c_str();
	int numb = atoi(sd1);
	data.number = numb;
	t = k + 1;
	k = str.find_first_of(punct, k + 1);

	//��hour1�������-
	string str2 = str.substr(t, k-t);           //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd2 = str2.c_str();
	int dd2 = atoi(sd2);
	data.hour1 = dd2;
	t = k + 1;
	k = str.find_first_of(punct, k + 1);

	 //���minut1�����-
	string str3 = str.substr(t, k - t);           //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd3 = str3.c_str();
	int dd3 = atoi(sd3);
	data.minut1 = dd3;
	t = k + 1;
	k = str.find_first_of(punct, k + 1);

	//��hour2�������-
	string str4 = str.substr(t, k - t);              //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd4 = str4.c_str(); 
	int dd4 = atoi(sd4);
	data.hour2 = dd4;
	t = k + 1;
	k = str.length();

	//���minut2�����-
	string str5 = str.substr(t, k - t);         //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd5 = str5.c_str();
	int dd5 = atoi(sd5);
	data.minut2 = dd5;

	return data;
}


Train Next(Train x) {         //���������� ����� �������� ������� ������

	Train y = x;

	int newhour = 0, newminut = 0;
	int sumaminut = (x.hour1 + x.hour2) * 60 + (x.minut1 + x.minut2);           //��������� ��� ���� � ������ � ���������� � ��������

	newhour = (sumaminut / 60) % 24;          //����� (����) ��������
	newminut = sumaminut % 60;              //����� (������) ��������

	y.hour2 = newhour;
	y.minut2 = newminut;

	cout << "����� ����� " << sumaminut << "; ���� �������� = " << newhour << "; ������ �������� = " << newminut << endl;

	return y;
}


void print(Train x) {        //������ ������ �� �����

	if ((x.hour2 < 10 && x.hour2 > 0) && (x.minut2 < 10 && x.minut2 > 0) ) {
		cout << "����� ������ = " << x.number << "; ����� ������� = " << x.hour1 << ":" << x.minut1         //������ ������
			<< "; ����� �������� = 0" << x.hour2 << ":0" << x.minut2 << endl;
	}

	else if ((x.hour2 >= 10) && (x.minut2 < 10 && x.minut2 > 0)) {
		cout << "����� ������ = " << x.number << "; ����� ������� = " << x.hour1 << ":" << x.minut1         //������ ������
			<< "; ����� �������� = " << x.hour2 << ":0" << x.minut2 << endl;
	}

	else if (x.hour2 < 10 && x.hour2 > 0 && (x.minut2 >= 10)) {
		cout << "����� ������ = " << x.number << "; ����� ������� = " << x.hour1 << ":" << x.minut1         //������ ������
			<< "; ����� �������� = 0" << x.hour2 << ":" << x.minut2 << endl;
	}

	else if (x.hour2 >= 10 && x.minut2 >= 10) {
		cout << "����� ������ = " << x.number << "; ����� ������� = " << x.hour1 << ":" << x.minut1         //������ ������
			<< "; ����� �������� = " << x.hour2 << ":" << x.minut2 << endl;
	}
	
}


int correct(string str) {        //�������� ������������ ������

	string punct = ".,;:- ";

	//if (str.length() < 13)            //������ ������������ �����: 1 12:40 3,6       ������� 11 ������
		//return -1;

	for (string::size_type i = 0; i < str.length(); i++) {
		if (i != str.find_first_of(punct, i)) {
			if (!isdigit(str[i]))
				return -1;
		}
	}

	Train data = STR_date(str);

	if (data.number <= 0)
		return -2;

	if (data.hour1 < 0 || data.hour1 > 23 || data.hour2 < 0)              //���� (����� �����������, � �������� �� 0 �� 23, �� ������������); ����� � ���� > 0
		return -3;

	if (data.minut1 < 0 || data.minut1 > 59 || data.minut2 < 0)         //������ (����� �����������, � �������� �� 0 �� 59, �� ������������); ����� � ���� > 0
		return -4;

	return 1;
}


int main() {      
	
	setlocale(LC_ALL, "RUS"); //������� ����������

	int N;      //���������� �������
	cout << "������� ���������� �������: ";
	cin >> N;    //���� ���������� �������
	cout << endl;

	for (int i = 0; i < N+1; i++) {
		string str;
		if (i != 0) 
			cout << i << ") ����� ������, ����� �����������(���� � ������), ����� � ����(���� � ������):" << endl;
		getline(cin, str);

		int fl = correct(str);          //����� ������� ��������� ������ ������ ��� ����� ������

		if (i != 0) {
			if (fl == -1)
				cout << "������������ ���� ������\n";

			else if (fl == -2)
				cout << "������������ ���� ������ ������\n";

			else if (fl == -3)
				cout << "������������ ���� ����� �����\n";

			else if (fl == -4)
				cout << "������������ ���� ����� �����\n";

			else {       //���� ��������� ����� ������
				Train data = STR_date(str);
				Train N_date = Next(data);
				print(N_date);
			}
			cout << endl;
		}
	}
	
	return 0;  //����� ���������
}