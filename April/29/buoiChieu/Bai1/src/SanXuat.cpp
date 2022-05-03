#include "SanXuat.h"
#include <iostream>

using namespace std;

SanXuat::SanXuat()
{
    //ctor
}

SanXuat::~SanXuat()
{
    //dtor
}

void SanXuat::tinhLuong(ll luongCanBan)
{
    luong = luongCanBan + soSanPham * 5000;
}

istream & operator >> (istream &inp, SanXuat &p)
{
    p.nhap();
    cout << "Nhap so san pham: ";
    inp >> p.soSanPham;
    return inp;
}
