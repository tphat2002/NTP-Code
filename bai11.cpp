#include<iostream>

using namespace std;
int main()
{
    double km, tienphat;

    cout << "Nhap so km: ";
    cin >> km;

    if (km <= 5) 
        tienphat = 0;
    else if (km <= 10)
        tienphat = 0.7;
    else if (km <= 20)
        tienphat = 2.5;
    else if (km <= 35)
        tienphat = 5.5;
    else tienphat = 7.5;
    
    cout << "tien phat = " << tienphat << " trieu dong";
    return 0;
}