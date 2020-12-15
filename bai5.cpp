#include<iostream>

using namespace std;
int main()
{
    int thang, nam, x;

    cout << "Nhap nam: "; cin >> nam;
    x = 1;
    if (nam % 4 == 0) cout << "Nam nhuan";
    else
        {
            cout << "Nam thuong" << endl;
            x = 0;
        }
    cout << "----------------" << endl;
    cout << "Nhap thang: "; cin >> thang;
    if (thang == 2)
        {
            if (x == 1) cout << "thang co 29 ngay";
            else cout << "thang co 28 ngay";
        }
    else if (((thang % 2 == 1) && (thang <= 7)) || ((thang % 2 == 0) && (thang >= 8)))
        cout << "Thang co 31 ngay";
    else 
        cout << "Thang co 30 ngay";
    return 0;
}