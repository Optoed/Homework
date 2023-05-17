#include <iostream>
#include <string>
using namespace std;

int main() {
    // put your code here
    int n;
    cin >> n;
    int hour, minut, sec;
    hour = (n / 3600);
    minut = (n - hour * 3600) / 60;
    sec = n - hour * 3600 - minut * 60;
    hour %= 24;
    string kminut = "";
    string ksec = "";
    if (minut < 10) kminut = "0";
    if (sec < 10) ksec = "0";
    cout << hour << ":" << kminut << minut << ":" << ksec << sec;
    return 0;
}