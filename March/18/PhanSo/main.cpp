#include "PhanSo.h"
#include <iostream>

using namespace std;

int main()
{
    PhanSo a, b;
    a.nhap();
    b.nhap();

    PhanSo ab(1, 1);

    ab = a + b;
    ab.xuat();

    ab = a - b;
    ab.xuat();

    ab = a * b;
    ab.xuat();

    ab = a / b;
    ab.xuat();

    return 0;
}
