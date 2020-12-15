#include<iostream>

using namespace std;
int main()
{
    double km, sum;

    cout << "Nhap so km: ";
    cin >> km;

    sum = 0;
    if (km < 2) 
        sum = km*15;
    else if (km < 6)
        sum = 15 + (km - 1)*13.5;
    else if (km < 120)
        sum = 15 + 4*13.5 + (km - 5)*11;
    else 
        sum = (15 + 4*13.5 + (km - 5)*11)*0.9; 
    
    cout << "tien = " << sum << " dong";
    return 0;
}