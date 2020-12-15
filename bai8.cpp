#include<iostream>

using namespace std;
int main()
{
    int a, b, c, m, n;

    cout << "Nhap a, b, c: "; 
    cin >> a >> b >> c;

    if (a + b <= c or b + c <= a or c + a <= b)
        cout << "a, b, c kh tao thanh tam giac";
    else if (a == b and b == c)
        cout << "Tam giac deu";
    else if (a == b or b == c or c == a)
        cout << "Tam giac can";
    else if (a*a + b*b == c*c or b*b + c*c == a*a or c*c + a*a == b*b)
        cout << "Tam giac vuong";
    else
        cout << "Tam giac thuong";
    
    return 0;
}