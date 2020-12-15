#include<iostream>

using namespace std;
int main() 
{
    double BMI, W, H;

    cout << "Can nang cua ban la bn: "; cin >> W;
    cout << " Ban cao bao nhieu met? "; cin >> H;
    BMI = W / H / H;
    if (BMI < 18.5)
        cout << "Duoi chuan";
    else if (BMI < 25)
        cout << "Chuan";
    else if (BMI < 30)
        cout << "Thua can";
    else if (BMI < 40)
        cout << "Beo  - nen giam can";
    else 
        cout << "Rat beo";
    return 0;
}