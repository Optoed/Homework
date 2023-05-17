#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

#define move_types 8

int possible_moves[move_types][2] = {
        {-1, -2}, {-2, -1}, {-2,  1}, { 1, -2},
        {-1,  2}, { 2, -1}, { 1,  2}, { 2,  1}
};

int** global;
int size_x, size_y;
int max_moves, back_ret;


/*‘ункци€ провер€ет может ли быть сделан ход на клетку с координатами x,y*/
int move_possible(int x, int y)
{
    return x >= 0 && y >= 0 && x < size_x&& y < size_y&& global[x][y] == 0;
}


int find_path(int cur_x, int cur_y, int move_num)
{
    int next_x = 0, next_y = 0;
    global[cur_x][cur_y] = move_num;

    if (move_num > max_moves)
        return 1;

    for (int i = 0; i < move_types; i++)
    {
        next_x = cur_x + possible_moves[i][0];
        next_y = cur_y + possible_moves[i][1];
        if (move_possible(next_x, next_y) && find_path(next_x, next_y, move_num + 1))
            return 1;
    }

    global[cur_x][cur_y] = 0;
    back_ret++;
    move_num++;
    return 0;
}



/*главна€ функци€*/
void main()
{
    setlocale(LC_ALL, "");

    int i, nrows, ncols, sy, sx, ** desc = NULL;
    time_t start, end;
    //вводим данные
    cout << "¬ведите размерность доски (от 2 до 8) :" << endl
        << "по оси \"X\"\t"; cin >> size_x;
    cout << "по оси \"Y\"\t";cin >> size_y;
    if (size_x > 8 && size_x < 2 && size_y>8 && size_y < 2)
    {
        cout << "Ќеверный размер";system("pause");return;
    }
    //провер€ем размерность
    cout << "¬ведите начальные координаты:" << endl
        << " оордината по оси\"X\"\t";cin >> sx;
    cout << " оордината по оси\"Y\"\t";cin >> sy;
    //провер€ем координаты


    start = time(NULL);//стартуем
    //инициализируем увзвтель и выдел€ем пам€ть
    desc = (int**)malloc(sizeof(int) * size_x);
    for (i = 0; i < size_x; ++i)
        desc[i] = (int*)malloc(sizeof(int) * size_y);

    //инициализируем другие переменные
    back_ret = 0;
    global = desc;
    max_moves = size_x * size_y - 1;

    //занул€ем массив
    for (int i = 0; i < size_x; ++i) {
        for (int j = 0; j < size_y; ++j)
            global[i][j] = 0;
    }


    //поиск решени€
    if (find_path(sx, sy, 1)) {
        cout << "___________________________________________" << endl
            << "\t***–ешение***" << endl
            << "___________________________________________" << endl;
        for (int i = 0; i < size_x; ++i) {
            cout << endl;
            for (int j = 0; j < size_y; ++j)
                cout << global[i][j] << "\t";
            cout << endl;
        }
        cout << "___________________________________________" << endl;
    }
    else cout << "Ќет решени€" << endl;


    //освобождаем пам€ть
    for (i = 0; i < size_x; ++i)
        free(desc[i]);
    free(desc);
    end = time(NULL);//врем€ конца цикла

    //врем€ поиска решени€
    cout << "врем€ поиска решени€ " << difftime(end, start) << " сек." << endl;
    cout << "___________________________________________" << endl;
    system("pause");
}