#include "Menu.h"
#include <iostream>
#include <algorithm> // sort

using namespace std;

Menu::Menu()
{
    //ctor
}

Menu::Menu(const Menu &danhSach)
{
    soNhanVien = danhSach.soNhanVien;
    luongCanBan = danhSach.luongCanBan;

    for (int i = 0; i < soNhanVien; i++)
        arr[i] = danhSach.arr[i];
}

Menu::~Menu()
{
    //dtor
}

void Menu::ngauNhien()
{
    soNhanVien = 300;
    for (int i = 0; i < 300; i++)
        arr[i].sinhNgauNhien();
}

void Menu::nhap()
{
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;

    cout << "Nhap so luong nhan vien: ";
    cin >> soNhanVien;

    for (int i = 0; i < soNhanVien; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i + 1 <<"\n";
        arr[i].nhap();
        arr[i].tinhLuong(luongCanBan);
    }
}

void Menu::xuat()
{
    cout << "DANH SACH NHAN VIEN: \n";
    cout << " \tID\tHo Va Ten\tSo San Pham\tLuong\n";

    for (int i = 0; i < soNhanVien; i++)
    {
        cout << i << '\t';
        arr[i].xuat();
    }
}

bool compare(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.length(); i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

void Menu::capNhatThongTin(string maNhanVien)
{
    for (int i = 0; i < soNhanVien; i++)
    {
        if ((compare(arr[i].getMaNhanVien(), maNhanVien)))
        {
            arr[i].nhap();
            return;
        }
    }

    cout << "Khong ton tai ma nhan vien nay !";
}

void Menu::tinhLuong()
{
    for (int i = 0; i < soNhanVien; i++)
        arr[i].tinhLuong(luongCanBan);
}

NhanVien Menu::luongCaoNhat()
{
    int pos = -1;
    ll _max = -1;

    for (int i = 0; i < soNhanVien; i++)
    {
        if (_max < arr[i].getLuong())
        {
            pos = i;
            _max = arr[i].getLuong();
        }
    }

    return arr[pos];
}

NhanVien Menu::luongThapNhat()
{
    int pos = -1;
    ll _min = 1e18;

    for (int i = 0; i < soNhanVien; i++)
    {
        if (_min > arr[i].getLuong())
        {
            pos = i;
            _min = arr[i].getLuong();
        }
    }

    return arr[pos];
}

bool cmp(NhanVien fi, NhanVien se)
{
    return fi.getLuong() > se.getLuong();
}

void Menu::sapXepTheoLuong()
{
    sort(arr, arr + soNhanVien, cmp);
}

void Menu::top10()
{
    Menu temp(*this);

    temp.sapXepTheoLuong();
    for (int i = 0; i < min(10, soNhanVien); i++)
    {
        cout << i << "\t";
        temp.arr[i].xuat();
    }
}
