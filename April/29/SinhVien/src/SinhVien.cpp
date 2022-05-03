#include "SinhVien.h"
#include <iostream>
#include <string>

using namespace std;

SinhVien::SinhVien()
{
    //ctor
}

SinhVien::~SinhVien()
{
    //dtor
}

bool SinhVien::duocTotNghiep()
{
    return tongSoTinChi >= 145 && trungBinhTichLuy >= 5 && diemLuanVan >= 5;
}

void SinhVien::setDiemTrungBinh(float dtb)
{
    this->trungBinhTichLuy = dtb;
}

float SinhVien::getDiemTrungBinh()
{
    return trungBinhTichLuy;
}

istream & operator >> (istream &inp, SinhVien &p)
{

}

ostream & operator << (ostream &out, SinhVien p)
{
    out << p.maSo << '\t' << p.hoVaTen << '\t' << p.diaChi << '\t';
    out << p.tongSoTinChi << '\t' << p.trungBinhTichLuy << '\t';
    out << p.luanVan << '\t' << p.diemLuanVan;

    return out;
}

void SinhVien::nhap()
{
    cout << "MSSV: ";
    cin.ignore();
    cin >> maSo;
    cin.ignore();
    cout << "Ho va ten: ";
    getline(cin, hoVaTen);
    cout << "Dia chi: ";
    cin.ignore();
    getline(cin, diaChi);
    cout << "Tong so tin chi tich luy: ";
    cin >> tongSoTinChi;
    cout << "Diem trung binh tich luy: ";
    cin >> trungBinhTichLuy;
    cin.ignore();
    cout << "Luan van: ";
    getline(cin, luanVan);
    cout << "Diem luan van: ";
    cin >> diemLuanVan;
}
