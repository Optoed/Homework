//Задачи на использование строк - 4
//Ваш выбор : Дан файл, содержащий список известных людей и даты их жизни.
//Вывести в новый файл только людей, которые прожили более 50 лет и жили в XIX веке.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RUS");

    char buff[100]; // буфер промежуточного хранения считываемого из файла текста
    ifstream fin("input.txt");
    ofstream fout("output.txt"); // создаём объект класса ofstream для записи и связываем его с файлом

    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом

    else
    {
        int count = 1;
        string line;     //
        while (getline(fin, line)) {                         //проходим по всем строкам в вайле
            cout << endl;
            cout << count << ") " << line << endl;
            //string::size_type n = line.size();               //длина строки
            //cout << n << endl;
            string::size_type skobka1 = line.find('(');      //позиция открывающей скобки
            cout << "Позиция открывающей скобки = " << skobka1 << endl;
            string::size_type tire = line.find('-');         //позиция тире
            cout << "Позиция тире = " << tire << endl;
            string::size_type skobka2 = line.find(')');      //позиция закрывающей скобки
            cout << "Позиция закрывающей скобки = " << skobka2 << endl;
            string date1 = line.substr(skobka1 + 1);         //подстрока, содержащая все эл-ты строки, начиная с позиции открывающей скобки + 1
            cout << "Подстрока, содерж эл-ты строки, начиная с позиции открывающей скобки + 1 = " << date1 << endl;
            string firstdate = "";
            for (int i = 0; i < 4; i++) {       //проверка на 4 цифры
                if (date1[i] != '-')
                    firstdate += date1[i];
                else
                    break;
            }
            const char* fdate = firstdate.c_str();        
            string seconddate = "";
            string date2 = line.substr(tire + 1, skobka2);      //подстрока, эквивалентная дате конца жизни
            for (int i = 0; i < 4; i++) {
                if (date2[i] != '.')
                    seconddate += date2[i];
                else
                    break;
            }
            const char* sdate = seconddate.c_str();
            int fd = atoi(fdate);         //переводим в число
            cout << "Дата рождения = " << fd << endl;
            int sd = atoi(sdate);         //переводим в число
            cout << "Дата конца жизни = " << sd << endl;
            if (abs(sd - fd) > 50 && (fd / 100 == 18 || sd / 100 == 18)) {         //проверка, что человек жил больше 50 лет и в 19 веке
                fout << line; // запись строки в файл
                cout << "Подходящий человек, который жил более 50 лет и в XIX веке = " << line << endl;
                fout << endl;
            }
            else {
                cout << "Человек не подходит, тк жил меньше 50 лет или не в XIX веке" << endl;
            }
            count += 1;
        }
    }

    fout.close(); // закрываем файл
    return 0;
}