#include "DaThuc.h"

using namespace std;

int main()
{
    DaThuc a, b;

    a.nhap();
    a.xuat();

    b.nhap();
    b.xuat();

    DaThuc ab = a + b;
    ab.xuat();

    return 0;
}
