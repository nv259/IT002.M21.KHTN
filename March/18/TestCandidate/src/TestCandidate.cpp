#include "TestCandidate.h"
#include <iostream>
#include "Candidate.h"

using namespace std;

TestCandidate::TestCandidate()
{
    //ctor
}

TestCandidate::TestCandidate(int soLuong)
{
    this->soLuong = soLuong;
    danhSachThiSinh = new Candidate [soLuong];
}

TestCandidate::~TestCandidate()
{
    delete [] danhSachThiSinh;
}

void TestCandidate::nhap()
{
    cout << "Nhap so luong thi sinh: ";
    cin >> soLuong;

    danhSachThiSinh = new Candidate [soLuong];

    for (int i = 0; i < soLuong; i++)
    {
        danhSachThiSinh[i].nhap();
        cout << '\n';
    }
}

void TestCandidate::xuat()
{
    for (int i = 0; i < soLuong; i++)
    {
        danhSachThiSinh[i].xuat();
        cout << '\n';
    }
}

void TestCandidate::xuatThiSinhTren15Diem()
{
    for (int i = 0; i < soLuong; i++)
        if (danhSachThiSinh[i].tongDiem() > 15.0)
        {
            danhSachThiSinh[i].xuat();
            cout << '\n';
        }
}
