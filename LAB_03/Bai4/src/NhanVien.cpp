#include "NhanVien.h"
#include <string>
#include <time.h> // time
#include <stdlib.h> // rand
#include <iostream>

using namespace std;

NhanVien::NhanVien()
{
    //ctor
}

NhanVien::~NhanVien()
{
    //dtor
}

// ham random ho va ten
string gen_random_name(const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

// ham random ma nhan vien
string gen_random_id(const int len)
{
    static const char alphanum[] =
        "0123456789";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

void NhanVien::sinhNgauNhien()
{
    srand(time(NULL));

    maNhanVien = gen_random_id(rand() % 10 + 1);
    hoVaTen = gen_random_name(rand() % 10 + 1);
    soSanPham = rand() % 100 + 1;
    luong = rand() % 1000000000;
}

void NhanVien::nhap()
{
    cout << "Ma nhan vien: ";
    cin >> maNhanVien;

    cin.ignore();
    cout << "Ho va ten: ";
    getline(cin, hoVaTen);

    cout << "So san pham: ";
    cin >> soSanPham;
}

void NhanVien::xuat()
{
    cout << maNhanVien << "\t" << hoVaTen << "\t" << soSanPham << "\t" << luong << "\n";
}

void NhanVien::tinhLuong(ll luongCanBan)
{
    luong = luongCanBan * 4500 + soSanPham * 175;
    luong *= 1000;
}

string NhanVien::getMaNhanVien()
{
    return maNhanVien;
}

void NhanVien::setHoVaTen(string hoVaTen)
{
    this->hoVaTen = hoVaTen;
}

void NhanVien::setMaNhanVien(string maNhanVien)
{
    this->maNhanVien = maNhanVien;
}

void NhanVien::setSoSanPham(int soSanPham)
{
    this->soSanPham = soSanPham;
}

ll NhanVien::getLuong()
{
    return luong;
}
