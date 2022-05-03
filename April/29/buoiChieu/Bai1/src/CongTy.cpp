#include "CongTy.h"

CongTy::CongTy()
{
    //ctor
}

CongTy::~CongTy()
{
    //dtor
}

istream & operator >> (istream &inp, CongTy &p)
{
    cout << "Nhap muc luong can ban: ";
    inp >> p.luongCanBan;
    cout << "Nhap so nhan vien san xuat: ";
    inp >> p.soSanXuat;
    for (int i = 0; i < p.soSanXuat; i++)
    {
        cout << "Nhap thong tin nhan vien san xuat thu " << i + 1 << "\n";
        inp >> p.sx[i];
    }

    cout << "Nhap so nhan vien van phong: ";
    inp >> p.soVanPhong;
    for (int i = 0; i < p.soVanPhong; i++)
    {
        cout << "Nhap thong tin nhan vien van phong thu " << i + 1 << "\n";
        inp >> p.vp[i];
    }

    return inp;
}

ostream & operator << (ostream &out, CongTy p)
{
    out << "---Thong tin nhan vien san xuat---\n";
    out << "HO VA TEN\tNGAY SINH\tLUONG\n";
    for (int i = 0; i < p.soSanXuat; i++)
        out << p.sx[i] << "\n";

    cout << "\n";

    out << "---Thong tin nhan vien van phong---\n";
    out << "HO VA TEN\tNGAY SINH\tLUONG\n";
    for (int i = 0; i < p.soVanPhong; i++)
        out << p.vp[i] << "\n";
}

void CongTy::tinhLuong()
{
    for (int i = 0; i < soSanXuat; i++)
        sx[i].tinhLuong(luongCanBan);
    for (int i = 0; i < soVanPhong; i++)
        vp[i].tinhLuong();
}
