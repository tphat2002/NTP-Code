#include<iostream>

using namespace std;
int main()
{
    int gio, phut, giay;
    
    cout << "Nhap: gio...phut...giay: ";
    cin >> gio >> phut >> giay;
    if (gio >= 0 and gio <= 24 and phut >= 0 and phut <=60 and giay >= 0 and giay <= 60)
        cout << "Gio hop  le";
    else cout << "Kh hop le";
    return 0;
}