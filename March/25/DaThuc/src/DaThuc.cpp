#include "DaThuc.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

DaThuc::DaThuc()
{
    //ctor
}

DaThuc::DaThuc(int n)
{
    this->n = n;
    a.resize(n + 1);
}

DaThuc::~DaThuc()
{
    //dtor
}

void DaThuc::nhap()
{
    cout << "Nhap n: ";
    cin >> n; // cuc bo
    a.resize(n+1);

    for (int i = 0; i <= n; i++)
    {
        cout << "Nhap a[" << i + 1<< "]: ";
        cin >> a[i];
    }
    cout << '\n';
}

void DaThuc::xuat()
{
    cout << "P(X) = ";
    int cnt = n;

    for (vector <int>::iterator a_i = a.begin(); a_i != a.end() - 1; a_i++)
    {
        cout << *a_i << "x^" << cnt-- << " + ";
    }

    cout << a[n]<< '\n';
}

DaThuc DaThuc::operator+(DaThuc Y)
{
    DaThuc result(n);

    int chenhLech = max(n, Y.n) - min(n, Y.n);

    if (Y.n > n)
    {
        for (int i = 0; i < chenhLech; i++)
            result.a[i] = Y.a[i];
    }
    else {
        for (int i = 0; i < chenhLech; i++)
            result.a[i] = a[i];
    }

    for (int i = 0; i <= n; i++)
        result.a[chenhLech + i] = (Y.n > n) ? a[i] + Y.a[i + chenhLech] : a[i + chenhLech] + Y.a[i];

    return result;
}

DaThuc DaThuc::operator-(DaThuc Y)
{
    DaThuc result(max(n, Y.n));

    int chenhLech = max(n, Y.n) - min(n, Y.n);

    if (Y.n > n)
    {
        for (int i = 0; i < chenhLech; i++)
            result.a[i] = Y.a[i];
    }
    else {
        for (int i = 0; i < chenhLech; i++)
            result.a[i] = a[i];
    }

    for (int i = 0; i <= min(n, Y.n); i++)
        result.a[chenhLech + i] = (Y.n > n) ? a[i] - Y.a[i + chenhLech] : a[i + chenhLech] - Y.a[i];

    return result;

}

ll DaThuc::giaTri(int x)
{
    ll result = 0;
    int cnt = n;

    for (auto a_i : a)
        result += a_i * pow(x, cnt--);

    return result;
}
