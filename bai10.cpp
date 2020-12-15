#include<iostream>

using namespace std;
int main()
{
    double chu, tien;

    cout << "Nhap kWh: ";
    cin >> chu;

    tien = 0;
    if (chu < 101) 
        tien = chu*1000;
    else if (chu < 151)
        tien = 100*1000 + (chu - 100)*1200;
    else if (chu < 201)
        tien = 100*1000 + 50*1200 + (chu - 150)*2000;
    else 
        tien = 100*1000 + 50*1200 + 50*2000 + (chu - 200)*2500;  
    cout << "tien = " << tien << " dong";
    return 0;
}