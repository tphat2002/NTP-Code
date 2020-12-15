#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    int a, b;
    cout << "Kiem tra CHINH PHUONG so a = ";
    cin >> a;

    b = sqrt(a);
    if (b*b == a) cout << "So a = " << a << " la so chinh phuong";
    else cout << "So a = " << a << " KHONG la chinh phuong";
    return 0;
}