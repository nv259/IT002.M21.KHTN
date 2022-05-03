#include "Candidate.h"
#include <string>
#include <iostream>

using namespace std;

Candidate::Candidate()
{
    //ctor
}

Candidate::Candidate(string MSSV, string ten, string ngaySinh, float dT, float dV, float dA)
{
    this->MSSV = MSSV;
    this->ten = ten;
    this->ngaySinh = ngaySinh;
    this->diemToan = dT;
    this->diemVan = dV;
    this->diemAnh = dA;
}

Candidate::~Candidate()
{
    //dtor
}

void Candidate::nhap()
{
    cout << "Nhap MSSV: ";
    cin >> MSSV;
    cout << "Nhap ten thi sinh: ";
    cin >> ten;
    cout << "Nhap ngay thang nam sinh cua thi sinh(dd/mm/yy): ";
    cin >> ngaySinh;
    cout << "Nhap diem toan: ";
    cin >> diemToan;
    cout << "Nhap diem van: ";
    cin >> diemVan;
    cout << "Nhap diem anh: ";
    cin >> diemAnh;
}

void Candidate::xuat()
{
    printf("MSSV: %s\nTen: %s\nNgay thang nam sinh: %s\nDiem Toan: %f\nDiem Van: %f\nDiem Anh: %f\nTong diem: %f\n", MSSV, ten, ngaySinh, diemToan, diemVan, diemAnh, tongDiem());
}

float Candidate::tongDiem()
{
    return diemAnh + diemToan + diemVan;
}
