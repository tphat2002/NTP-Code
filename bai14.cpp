#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    double a, b, c, denta, x, x1, x2;

    cout << "Nhap a, b, c cho phuong trinh ax^2 + bx +c : "; 
    cin >> a >> b >> c;

    denta = b*b - 4*a*c;
    if (a == 0)
        if (b == 0)
            if (c == 0) cout << " Phuong trinh co nghiem voi moi x";
            else cout << "Phuong trinh vo nghiem";
        else cout << " x = " << -c/b;
    else if (denta == 0)
            cout << "Nghiem kep x = " << -b/2/a;
    else
        {
           cout << "x1 = " << (-b + sqrt(denta))/(2*a) << endl;
           cout << "x2 = " << (-b - sqrt(denta))/(2*a);
        }
    return 0;
}