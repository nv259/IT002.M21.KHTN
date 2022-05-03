#include "SoPhuc.h"
#include <iostream>

using namespace std;

int main()
{
    SoPhuc a, b;
    a.setThuc(0); cout << a.getThuc() << "\n";
    a.setAo(0); cout << a.getAo() << "\n";

    a.nhap();
    b.nhap();

    SoPhuc ab(1, 2);

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
