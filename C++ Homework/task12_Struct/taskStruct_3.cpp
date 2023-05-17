//������ �� ��������� - 3
//����������� ������� ��� ������ � ������������� �������:
//����,����� � ���� ������������ �����, ��������, ���������, ���������, ������� ���� ������;
//����������, ���������� � ���������� �����, ���������� � ���������� �����.

#include<iostream>
#include<string>
using namespace std;


#include<iostream>    //����������� ���������� �����-������
#include<string>     //����������� ���������� �����
using namespace std;


struct Train {      //��������� Train
	int chislitel1;
	int znamenatel1;
	int chislitel2;
	int znamenatel2;
	
	int znamenatelproizvedenie;
	int suma;
	int raznost;
	int proizvedenie;

	int delenieVchislitel;
	int delenieVznamenatel;
};

int NOD(int a, int b) {        //����������� ������� ������ ����������� ������ ��������
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;

	else if (a > b)
		return NOD(a - b, b);

	else return NOD(a, b - a);

}



Train STR_date(string str) {      //������� �� ������ � ��������� Train

	Train data;

	string::size_type k, t = 0;
	k = str.find('/');       //����� ������� ��������������� �������

	//--chislitel1-------
	string str1 = str.substr(t, k - t);         //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd1 = str1.c_str();
	int dd1 = atoi(sd1);
	data.chislitel1 = dd1;
	t = k + 1;
	k = str.find(' ', k + 1);

	//���znamenatel1������-
	string str2 = str.substr(t, k - t);           //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd2 = str2.c_str();
	int dd2 = atoi(sd2);
	data.znamenatel1 = dd2;
	t = k + 1;
	k = str.find('/', k + 1);

	//���chislitel2�����-
	string str3 = str.substr(t, k - t);           //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd3 = str3.c_str();
	int dd3 = atoi(sd3);
	data.chislitel2 = dd3;
	t = k + 1;
	k = str.length();

	//��znamenatel2�������-
	string str4 = str.substr(t, k - t);              //�������� �������� ������ � ����� � ��������� ����� ����� � ��������� Train data
	const char* sd4 = str4.c_str();
	int dd4 = atoi(sd4);
	data.znamenatel2 = dd4;

	return data;
}


Train Next(Train x) {         //��������� ��������� �������� ���������

	Train y = x;

	y.znamenatelproizvedenie = x.znamenatel1 * x.znamenatel2;
	y.suma = x.chislitel1 * x.znamenatel2 + x.chislitel2 * x.znamenatel1;
	y.raznost = x.chislitel1 * x.znamenatel2 - x.chislitel2 * x.znamenatel1;
	y.proizvedenie = x.chislitel1 * x.chislitel2;

	y.delenieVchislitel = x.chislitel1 * x.znamenatel2;
	y.delenieVznamenatel = x.chislitel2 * x.znamenatel1;

	return y;
}


void print(Train x) {        //������ ������ �� �����

	if (x.znamenatel1 != 0 && x.znamenatel2 != 0) {
		float nod, nod2;
		cout << "����� ������� �����: " << endl;
		cout << x.chislitel1 << "/" << x.znamenatel1 << " � " << x.chislitel2 << "/" << x.znamenatel2 << endl;
		nod = NOD(x.chislitel1, x.znamenatel1);
		nod2 = NOD(x.chislitel2, x.znamenatel2);
		cout << "������ ����� � ����������� ���� = " << x.chislitel1 / nod << "/" << x.znamenatel1 / nod << endl;
		cout << "������ ����� � ����������� ���� = " << x.chislitel2 / nod2 << "/" << x.znamenatel2 / nod2 << endl;
		float a, b, a2, b2;
		a = x.chislitel1 / nod;
		b = x.znamenatel1 / nod;
		a2 = x.chislitel2 / nod;
		b2 = x.znamenatel2 / nod;
		cout << "������ ����� � ���������� ���� " << a/b << endl;
		cout << "������ ����� � ���������� ���� " << a2/b2 << endl;
		int inta = a, intb = b, inta2 = a2, intb2 = b2;
		if (inta > intb)
			cout << "������ ����� � ���� ���������� ����� = " << inta / intb << "(" << inta % intb << "/" << b << ")" << endl;
		else
			cout << "������ ����� � ���� ���������� ����� = "  << a << "/" << b << endl;
		if (inta2 > intb2)
			cout << "������ ����� � ���� ���������� ����� = " << inta2 / intb2 << "(" << inta2 % intb2 << "/" << b2 << ")" << endl;
		else
			cout << "������ ����� � ���� ���������� ����� = " << a2 / nod << "/" << b2 / nod << endl;
		cout << endl;


		cout << "����� ������� �����: " << endl;
		cout << x.chislitel1 << "/" << x.znamenatel1 << " + " << x.chislitel2 << "/" << x.znamenatel2 << " = " << x.suma << "/" << x.znamenatelproizvedenie << endl;
		nod = NOD(x.suma, x.znamenatelproizvedenie);
		cout << "����� ������ � ����������� ���� = " << x.suma / nod << "/" << x.znamenatelproizvedenie / nod << endl;
		a = x.suma / nod;
		b = x.znamenatelproizvedenie / nod;
		cout << "����� ������ � ���������� ���� " << a / b << endl;
		inta = a;
		intb = b;	
		if (inta > intb)
			cout << "����� ������ � ���� ���������� ����� = " << inta / intb << "(" << inta % intb << "/" << b << ")" << endl;
		else
			cout << "����� ������ � ���� ���������� ����� = " << a << "/" << b << endl;
		cout << endl;

		cout << "�������� ������� �����: " << endl;
		cout << x.chislitel1 << "/" << x.znamenatel1 << " - " << x.chislitel2 << "/" << x.znamenatel2 << " = " << x.raznost << "/" << x.znamenatelproizvedenie << endl;
		nod = NOD(abs(x.raznost), abs(x.znamenatelproizvedenie));
		if (nod != 0) {
			cout << "�������� ������ � ����������� ���� = " << x.raznost / nod << "/" << x.znamenatelproizvedenie / nod << endl;
			a = x.raznost / nod;
			b = x.znamenatelproizvedenie / nod;
			cout << "�������� ������ � ���������� ���� " << a / b << endl;
			inta = a;
			intb = b;
			if (abs(inta) > intb && inta > 0)
				cout << "�������� ������ � ���� ���������� ����� = " << inta / intb << "(" << inta % intb << "/" << b << ")" << endl;
			else if (abs(inta) > intb && inta < 0)
				cout << "�������� ������ � ���� ���������� ����� = " << inta / intb << "(" << abs(inta) % intb << "/" << b << ")" << endl;
			else
				cout << "�������� ������ � ���� ���������� ����� = " << a << "/" << b << endl;
		}
		else
			cout << "�������� ������ � ����������� ���� = 0" << endl;
		cout << endl;

		cout << "������������ ������� �����: " << endl;
		cout << x.chislitel1 << "/" << x.znamenatel1 << " * " << x.chislitel2 << "/" << x.znamenatel2 << " = " << x.proizvedenie << "/" << x.znamenatelproizvedenie << endl;
		nod = NOD(x.proizvedenie, x.znamenatelproizvedenie);
		cout << "������������ ������ � ����������� ���� = " << x.proizvedenie / nod << "/" << x.znamenatelproizvedenie / nod << endl;
		a = x.proizvedenie / nod;
		b = x.znamenatelproizvedenie / nod;
		cout << "������������ ������ � ���������� ���� " << a / b << endl;
		inta = a;
		intb = b;
		if (inta > intb)
			cout << "������������ ������ � ���� ���������� ����� = " << inta / intb << "(" << inta % intb << "/" << b << ")" << endl;
		else
			cout << "������������ ������ � ���� ���������� ����� = " << a << "/" << b << endl;
		cout << endl;

		if (x.chislitel2 != 0) {
			cout << "������� ������� �����: " << endl;
			cout << x.chislitel1 << "/" << x.znamenatel1 << " : " << x.chislitel2 << "/" << x.znamenatel2 << " = " << x.delenieVchislitel << "/" << x.delenieVznamenatel << endl;
			nod = NOD(x.delenieVchislitel, x.delenieVznamenatel);
			a = x.delenieVchislitel / nod;
			b = x.delenieVznamenatel / nod;
			cout << "������� ������ � ����������� ���� = " << x.delenieVchislitel / nod << "/" << x.delenieVznamenatel / nod << endl;
			cout << "������� ������ � ���������� ���� " << a / b << endl;
			inta = a;
			intb = b;
			if (inta > intb)
				cout << "������� ������ � ���� ���������� ����� = " << inta / intb << "(" << inta % intb << "/" << b << ")" << endl;
			else
				cout << "������� ������ � ���� ���������� ����� = " << a << "/" << b << endl;
			cout << endl;
		}
		else {
			cout << "������� �� 0 (��� ������� ������) ������!" << endl;
		}
	}
	else {
		cout << "������� �� 0. ������!" << endl;
	}
}


int correct(string str) {        //�������� ������������ ������

	string punct = "/ ";

	if (str.length() < 7)            //������ ������������ �����: 1/6 4/5   - ������� 7 ������
		return -1;

	for (string::size_type i = 0; i < str.length(); i++) {
		if (i != str.find_first_of(punct, i)) {
			if (!isdigit(str[i]))
				return -1;
		}
	}

	return 1;
}


int main() {

	setlocale(LC_ALL, "RUS"); //������� ����������

	int N;      //���������� ��������
	cout << "������� N: ";
	cin >> N;    //���� ���������� ��������
	cout << endl;

	for (int i = 0; i < N + 1; i++) {
		string str;
		if (i > 0)
			cout << i << ") ������� ��� ������� ����� ����� ������:" << endl;
		getline(cin, str);
		cout << endl;

		int fl = correct(str);          //����� ������� ��������� ������ ������ ��� ����� ������

		if (fl == -1) {
			if (i != 0)
				cout << "������������ ���� ������\n";
		}

		else {       //���� ��������� ����� ������
			Train data = STR_date(str);
			Train N_date = Next(data);
			print(N_date);
		}
		cout << endl;
	}

	return 0;  //����� ���������
}