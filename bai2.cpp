#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    double toan, ly, hoa;

    cout << "Diem toan = "; cin >> toan;
    cout << "Diem hoa = "; cin >> hoa;
    cout << "Diem ly = "; cin >> ly;

    if (((toan + ly + hoa) >= 15) && (fmin(toan,fmin(ly, hoa)) > 4))
        {
            cout << "Dau" << endl;
            if (fmin(toan,fmin(ly, hoa)) > 5)
                cout << "Hoc deu cac mon";
            else cout << "Hoc chua deu cac mon";
        }
    else cout << "Thi hong";
    return 0;
}