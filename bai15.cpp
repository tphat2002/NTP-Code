#include<iostream>

using namespace std;
int main()
{
    double a, b;
    char x;

    cout << "Nhap toan hang a, b: "; 
    cin >> a >> b;
    cout << "Nhap toan tu: ";
    cin >> x;
    
    switch (x)
        {
        case '+':
            cout << a << " + " << b << " = " << a + b;
            break;

        case '-':
            cout << a << " - " << b << " = " << a - b;
          break;

        case '*':
            cout << a << " * " << b << " = " << a * b;
            break;

        case '/':
            cout << a << " / " << b << " = " << a / b;
            break;       
        }
    return 0;
}