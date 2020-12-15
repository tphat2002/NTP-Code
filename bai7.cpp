#include<iostream>

using namespace std;
int main()
{
    int A[100];
    int n, x, tam;
    cout << "n = "; cin >> n;

    for (int i = 1; i <= n; i++)
        {
            cout << "So thu " << i << " la: ";
            cin >> A[i];
        }
    x = 1;
    while (x <= n)
        {
            for (int i = 1; i < n; i++)
                {    if (A[i] > A[i+1])
                        {
                            tam = A[i];
                            A[i] = A[i+1];
                            A[i+1] = tam;
                        }
                }
            x = x + 1;           
        }
    for (int i = 1; i <= n; i++) cout << A[i] << "  ";
    return 0;
}