
/*
В файле содержатся данные о сотрудниках предприятия:
фамилия, должность, дата рождения (день, месяц, год), стаж работы, зарплата (не менее 20 человек).
Файл прикрепить.
Выполнить открытое и закрытое хэширование (лучше две разных программы).
Продемонстрировать поиск элемента (и в том и в другом случае) и удаление элемента (для открытого хэширования).
Хэш-функция и ключ хэширования - выбираете в опросе.

Программа должна демонстрировать - хэширование, вывод полученной хэш-таблицы, возможность ввода элемента, его поиск (вывести все данные, соответствующие этому элементу).
В случае открытого хэширования - удаление всех данных, соответствующих этому элементу.

Для открытого хэширования использовать самостоятельно написанные функции для двусвязного списка.
*/

//Открытое хэширование
//Метод умножения по зарплате

// Метод деления по году рождения

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


struct date { // дата
    int dd, mm, yyyy;
};


struct person {// данные о человеке
    string Surname;
    string Post;
    date DateOfBirth;
    int LengthOfService;
    int Salary;
};


vector<person> people; // вектор "людей"


void input() { // чтение данных из файла
    ifstream in("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Хэширование\\megainput.txt");
    person pers;
    string s;
    while (in.peek() != EOF) {
        in >> pers.Surname;
        in >> pers.Post;
        in >> s;
        // работа с датой рождения
        pers.DateOfBirth.dd = stoi(s.substr(0, 2));
        pers.DateOfBirth.mm = stoi(s.substr(3, 5));
        pers.DateOfBirth.yyyy = stoi(s.substr(6, 4));
        in >> pers.LengthOfService;
        in >> pers.Salary;
        people.push_back(pers); // добавление нового эл-та в вектор 

    }
}


struct list { // описание двусвязного списка
    person item; // значение элемента
    list* prev; // указатель на предыдущий элемент
    list* next; // указатель на слудующий элемент
};


void push_back(list*& head, list*& tail, person x) { // вставка в конец списка
    list* p = new list;
    p->item = x;
    p->next = NULL;
    if (!head && !tail) { // если список пуст
        p->prev = NULL;
        head = p;
    }
    else {
        tail->next = p;
        p->prev = tail;
    }
    tail = p; // элемент становится хвостом 
}


bool operator == (person a, person b) { // переопределение оператора сравнения
    return (a.Surname == b.Surname && a.Salary == b.Salary && a.Post == b.Post &&
        a.LengthOfService == b.LengthOfService && a.DateOfBirth.dd == b.DateOfBirth.dd &&
        a.DateOfBirth.mm == b.DateOfBirth.mm && a.DateOfBirth.yyyy == a.DateOfBirth.yyyy);
}


list* find(list*& head, list*& tail, person x) { // поиск элемента со значением х в списке
    list* p = head; // указатель на голову
    while (p) { // проход по списку 
        if (p->item == x) return p;
        p = p->next;
    }
    return p;
}


int m; // размер хэш-таблицы
vector<pair<list*, list*>> hash_t; // хэш-таблица


int h(int year) { // хэш-функция, деление
    return year % m;
}


void hash_table() { // заполнение хэш-таблицы
    hash_t.resize(m);
    for (auto el : people) {
        int k = h(el.DateOfBirth.yyyy);
        push_back(hash_t[k].first, hash_t[k].second, el);
    }
}


list* find_in_hash(person x) { // поиск элемента в хэш-таблице
    int k = h(x.DateOfBirth.yyyy);
    auto head = hash_t[k].first;
    auto tail = hash_t[k].second;
    return find(head, tail, x);
}


void del_elem(list*& head, list*& tail, list* p, int k) { // удаление эл-та p
    if (p == head && p == tail) { // р единственный эл-т в списке
        head = tail = NULL;
        hash_t[k].first = head;
        hash_t[k].second = tail;
    }
    else if (p == head) { // р - это голова
        head = head->next;
        head->prev = NULL;
        hash_t[k].first = head;
    }
    else if (p == tail) { // р - хвост
        tail = tail->prev;
        hash_t[k].second = tail;
        tail->next = NULL;
    }
    else {
        p->next->prev = p->prev;
        p->prev->next = p->next;
    }
    delete p; // очищение памяти, удаление р 
}


void del_from_hash(person x, list*& p) { // удаление элемента из хэш-таблицы
    int k = h(x.DateOfBirth.yyyy);
    auto head = hash_t[k].first;
    auto tail = hash_t[k].second;
    del_elem(head, tail, p, k);
}


void output() { // форматированный вывод в файл 
    ofstream out("C:\\Users\\Пётр\\Desktop\\C++ Homework\\Хэширование\\megaoutput.txt");
    for (int k = 0; k < m; ++k) {
        out << k << ":\n";
        list* p = hash_t[k].first;
        while (p) {
            person pers = p->item;
            out << setw(14) << left << pers.Surname; //по левому краю, 10 позиций для фамилии
            out << setw(15) << left << pers.Post;
            if (pers.DateOfBirth.dd < 10) out << left << '0' << pers.DateOfBirth.dd << '.'; //добавляем 0
            else out << left << pers.DateOfBirth.dd << ".";
            if (pers.DateOfBirth.mm < 10) out << '0' << pers.DateOfBirth.mm << '.';
            else out << pers.DateOfBirth.mm << '.';
            out << setw(6) << left << pers.DateOfBirth.yyyy; //на год 6 позиций
            out << setw(4) << left << pers.LengthOfService;
            out << left << setw(8) << pers.Salary << endl; //запрлата
            p = p->next;
        }
        out << '\n';
    }
}


int main() {
    input();
    m = 13;
    hash_table();
    output();
    int var = 1;

    while (true) {
        cout << "Enter 1 if you want to check for an item in the list\n";
        cout << "Enter 0 if you want to exit the program\n";
        cin >> var;
        if (var == 0) break;
        person pers;
        string data;
        cout << "Enter the surname, post, date of birth, length of service and salary of the person:\n";
        cin >> pers.Surname >> pers.Post >> data >> pers.LengthOfService >> pers.Salary;
        pers.DateOfBirth.dd = stoi(data.substr(0, 2));
        pers.DateOfBirth.mm = stoi(data.substr(3, 5));
        pers.DateOfBirth.yyyy = stoi(data.substr(6, 4));
        list* p = find_in_hash(pers); // поиск элемента 

        if (p) {
            cout << "This person is on the list\n";
            cout << "Enter 1 (0) if you (don't) want to remove this person from the list: ";
            cin >> var;
            if (var == 1) { // удаление эл-та
                del_from_hash(pers, p);
                cout << "This person has been removed from the list\n";
                output();
            }
        }
        else cout << "This person is not on the list\n";
        cout << '\n';
    }
}