#include <iostream>  
using namespace std;
int main()
{
    int desk[8][8]; // äîñêà 8õ8. ïóñòü íåçàíÿòûå êëåòêè áóäóò ðàâíû 10
    int nkx, nky, kkx, kky, x, y, n;
    cout << "Vvedite na4alnoe pologenie kon9I\n";//cisla ot 1 do 8, poetomu potom umenshaem na 1
    cin >> nkx;
    cin >> nky;
    cout << "Vvedite kone4noe pologenie kon9I\n";
    cin >> kkx;
    --kkx;
    cin >> kky;
    --kky;
    for (x = 0; x < 8; ++x)
        for (y = 0; y < 8; ++y)
            desk[x][y] = 100;
    desk[nkx - 1][nky - 1] = 0;
    for (n = 1; desk[kkx][kky] == 100; ++n)
        for (x = 0; x < 8; x++)
            for (y = 0; y < 8; y++)
                if (desk[x][y] == n - 1)
                {
                    if (x < 6 && y < 7 && desk[x + 2][y + 1] == 100)
                        desk[x + 2][y + 1] = n;
                    if (x < 6 && y>0 && desk[x + 2][y - 1] == 100)
                        desk[x + 2][y - 1] = n;
                    if (x > 1 && y < 7 && desk[x - 2][y + 1] == 100)
                        desk[x - 2][y + 1] = n;
                    if (x > 1 && y > 0 && desk[x - 2][y - 1] == 100)
                        desk[x - 2][y - 1] = n;
                    if (x < 7 && y>1 && desk[x + 1][y - 2] == 100)
                        desk[x + 1][y - 2] = n;
                    if (x < 7 && y < 6 && desk[x + 1][y + 2] == 100)
                        desk[x + 1][y + 2] = n;
                    if (x > 0 && y > 1 && desk[x - 1][y - 2] == 100)
                        desk[x - 1][y - 2] = n;
                    if (x > 0 && y < 6 && desk[x - 1][y + 2] == 100)
                        desk[x - 1][y + 2] = n;
                }

    for (y = 0; y < 8; ++y)
    {
        for (x = 0;x < 8; ++x)
            cout << desk[x][y] << " ";
        cout << endl;
    }
    system("PAUSE");
}