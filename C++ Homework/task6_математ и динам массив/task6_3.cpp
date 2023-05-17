// task6_3
// В условии 3 номера есть опечатка, при сумме P`(x) + P(x) коэффициент первого члена (его степень = n) не изменится,
// в показанном в условии примере вывод идёт в обратном порядке!


#include <iostream>    //подключение библиотек
#include <cmath>
using namespace std;


int* createA(int n) {           //функция создания и заполнения массива для P(x)
	int* a = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		int koefa;
		cin >> koefa;
		a[i] = koefa;
	}
	return a;
}

int* createAnew(int* a, int n) {              //функция создания массива для P`(x)
	int* anew = new int[n + 1];
	anew[0] = 0;
	return anew;
}

void printA(int* a, int n) {           //функция вывода P(x)
	cout << endl;
	cout << "Коэффициенты членов многочлена P(x)" << endl;
	for (int i = 0; i < n + 1; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

void printAnew(int*anew, int n) {                //функция вывода P`(x)
	cout << endl;
	cout << "Коэффициенты членов многочлена P'(x)" << endl;
	for (int i = 0; i < n + 1; i++) {
		cout << anew[i] << ' ';
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");   //использование русской клавиатуры

	int n;
	cout << "n = ";
	cin >> n;          //ввод n
	cout << endl;

	int* a = createA(n);
	printA(a, n);

	int* anew = createAnew(a, n);

	cout << endl;
	for (int i = 0; i < n; i++) {
		anew[i+1] = a[i] * (n - i);               //нахождение коэффициентов в P`(x)
	}
	printAnew(anew, n);

	cout << endl;
	int* aanew = new int[n + 1];
	cout << "Итог: коэффициенты многочлена P(x) + P`(x)" << endl;
	for (int i = 0; i < n + 1; i++) {
		aanew[i] = a[i] + anew[i];                         //сумма коэффициентов P(x) + P`(x)
		cout << aanew[i] << ' ';
	}

	cout << endl;
	cout << endl;
	system("pause");           //пауза и завершение программы
	return 0;
}
