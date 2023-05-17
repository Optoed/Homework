#include <iostream>    //подключение библиотек ввода-вывода
#include <cmath>       //подключение библиотек математических функций    
using namespace std;

int main() { 
	setlocale(LC_ALL, "RUS");        //использование русской клавиатуры
	int n, k = 0, count = 0;
	cout << "n = ";
	cin >> n;           //ввод числа n
	int* a = new int[n];        //создание массива
	for (int i = 0; i < n; i++) {          
		cin >> a[i];          //заполнение массива
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {            //если a[i] - чётный, удаляем его
			for (int j = i + 1; j < n; j++) {
				a[j - 1] = a[j];          //процесс смещения (удаления)
			}
			a[n - k] = -99999;       
			k += 1;
			i -= 1;
			
			// ПРОВЕРКА
			
			//for (int c = 0; c < n; c++) cout << a[c] << " "
			//cout << "k = " << k << endl;
			//cout << endl;

		}
		count += 1;
		if (count == n) {        
			n -= k;
			break;
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++) {      
		cout << a[i] << " ";    //вывод оставшихся элементов
	}

	system("pause");     //завершение программы
	return 0;
}