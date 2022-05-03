#include "PhanSo.h"

int main()
{
    PhanSo a(2, 3), b(1, 4), c(3, 1), d(2, 5);
    a = b * -c;
    c = (b + 2) * 2 / a;
    d = a/3 + (b * c - 2) / 5;

    cout << a;
    cout << endl;
    cout << b;
    cout << endl;
    cout << c;
    cout << endl;
    cout << d;

    cout << (a < b);
    cout << endl;

    cout << (b > d);
    cout << endl;

    c = 3;

    cout << (c <= 3);
    cout << endl;

    return 0;
}
