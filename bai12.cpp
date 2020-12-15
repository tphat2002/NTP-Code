#include<iostream>

using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x <= 9)
        cout << x;
    else
        cout << char(x + 55);
    return 0;
}