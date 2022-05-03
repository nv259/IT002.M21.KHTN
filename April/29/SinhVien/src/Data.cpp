#include "Data.h"
#include <string>

using namespace std;

Data::Data()
{
    //ctor
}

Data::~Data()
{
    //dtor
}

int Data::totNghiep()
{
    int result = 0;
    for (int i = 0; i < soSinhVien; i++)
        if (a[i].duocTotNghiep()) result++;
}

SinhVien Data::thuKhoa()
{
    SinhVien result;
    result.setDiemTrungBinh(0);

    for (int i = 0; i < soSinhVien; i++)
        if (result.getDiemTrungBinh() < a[i].getDiemTrungBinh())
            result = a[i];
    return result;
}

SinhVien & Data::operator [] (int i)
{
    return a[i];
}

istream & operator >> (istream &inp, Data &p)
{
    cout << "Nhap so luong sinh vien: ";
    inp >> p.soSinhVien;

    for (int i = 0; i < p.soSinhVien; i++)
    {
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << '\n';
        p[i].nhap();
    }

    return inp;
}

ostream & operator << (ostream &out, Data p)
{
    for (int i = 0; i < p.soSinhVien; i++)
        out << p[i] << '\n';
    //
    return out;
}
