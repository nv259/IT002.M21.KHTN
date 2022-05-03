#include "TamGiac.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    TamGiac triangle;
    triangle.nhap();
    triangle.xuat();

    triangle.tinhTien(-1.5, -1.5);
    triangle.xuat();

    cout << triangle.tamDuongTronNgoaiTiep().first << ' ' << triangle.tamDuongTronNgoaiTiep().second <<  '\n';
    triangle.quay(acos(0.0) * 2.0); // counter clock-wise radian
    triangle.xuat();

    triangle.thuPhong(2.0);
    triangle.xuat();

    return 0;
}
