#include<iostream>

using namespace std;
int main()
{
    int a, b, c;

    cout << "Nhap a, b, c: "; 
    cin >> a >> b >> c;
    
    if (a*a + b*b == c*c || b*b + c*c == a*a or c*c + a*a == b*b)
        cout << "a, b, c tao thanh tam giac vuong";
    else
        cout << "a, b, c KHONG tao thanh tam giac vuong";

    return 0;
}