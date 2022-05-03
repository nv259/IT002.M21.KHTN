#include "VanPhong.h"
#include <iostream>

using namespace std;

VanPhong::VanPhong()
{
    //ctor
}

VanPhong::~VanPhong()
{
    //dtor
}

void VanPhong::tinhLuong()
{
    luong = soNgayLamViec * 100000;
}

istream & operator >> (istream &inp, VanPhong &p)
{
    p.nhap();
    cout << "Nhap so ngay lam viec: ";
    inp >> p.soNgayLamViec;

    return inp;
}

