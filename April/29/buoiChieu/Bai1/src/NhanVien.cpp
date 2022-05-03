#include "NhanVien.h"
#include <iostream>

NhanVien::NhanVien()
{
    //ctor
}

NhanVien::~NhanVien()
{
    //dtor
}

void NhanVien::nhap()
{
    cout << "Ho va ten: ";
    cin.ignore();
    getline(cin, hoVaTen);
    cout << "Ngay sinh: ";
    cin.ignore();
    getline(cin, ngaySinh);
}

void NhanVien::xuat()
{

}

ostream &operator << (ostream &out, NhanVien p)
{
    out << p.hoVaTen << '\t' << p.ngaySinh << '\t' << p.luong;
    return out;
}
