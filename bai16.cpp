#include<iostream>

using namespace std;
int main()
{
    char tk;
    double tien, sodu, toithieu;

    cout << "Loai tk - tietkiem (t) hay vanglai (v): ";
    cin >> tk;
    cout << "So du toi thieu: ";
    cin >> toithieu;
    cout << "So du tai khoan: ";
    cin >> sodu;
    
    if (tk == 't')
        if (sodu < toithieu)
            cout << "Tien phat: 10$";
        else 
            cout << "Tien lai nhan duoc: " << sodu*1.04 - toithieu;
    if (tk == 'v')
        if ((sodu - toithieu) < 0)
            cout << "Tien phat: 25$";
        else if ((sodu - toithieu) < 5000)
            cout << "Tien lai nhan duoc: " << sodu*1.05 - toithieu;
        else
            cout << "Tien lai nhan duoc: " << sodu*1.03 - toithieu;
    return 0;
}