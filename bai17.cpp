#include<iostream>

using namespace std;
int main()
{
    double A1, A2, A3, A4, A5, B;
    double can_nang, co_tay, eo, hong, canh_tay, luong_mo, ptram_mo; 
    string gioi_tinh;

    cout << "Ban la nam hay nu: ";
    cin >> gioi_tinh;
    if (gioi_tinh == "nu")
        {
            cout << "Can nang: ";
            cin >> can_nang;
            A1 = (can_nang * 0.732) + 8.987;

            cout << "Kich thuoc co tay: ";
            cin >> co_tay;
            A2 = co_tay / 3.14;

            cout << "Kich thuoc eo: ";
            cin >> eo;
            A3 = eo * 0.157;

            cout << "Kich thuoc hong: ";
            cin >> hong;
            A4 = hong * 0.249;

            cout << "Kich thuoc canh tay: ";
            cin >> canh_tay;
            A5 = canh_tay * 0.434;

            B = A1 + A2 - A3 - A4 + A5;
        }
    if (gioi_tinh == "nam")
        {
            cout << "Can nang: ";
            cin >> can_nang;
            A1 = (can_nang * 0.732) + 8.987;

            cout << "Kich thuoc co tay: ";
            cin >> co_tay;
            A2 = co_tay / 3.14;

            B = A1 - A2;
        }
    luong_mo = can_nang - B;
    ptram_mo = luong_mo / can_nang * 100;

    cout << "luong mo cua ban la: " << luong_mo << endl;
    cout << "phan tram luong mo la: "<< ptram_mo << endl;
    return 0;
}