#include "thoiGian.h"
#include <iostream>

using namespace std;

int main()
{
    thoiGian clock1, clock2(13, 53, 2);

    clock1.nhap();
    clock1.setGio(24);

    clock1.xuat();
    clock1.to12h();

    clock1.xuat();

    return 0;
}
