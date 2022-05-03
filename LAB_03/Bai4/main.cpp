#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{
    Menu danhSach;
    danhSach.ngauNhien();
    danhSach.xuat();

    danhSach.nhap();
    danhSach.xuat();

    danhSach.capNhatThongTin("21520378");

    NhanVien nhanVienXuatSac = danhSach.luongCaoNhat();
    nhanVienXuatSac.xuat();

    NhanVien nhanVienTe = danhSach.luongThapNhat();
    nhanVienTe.xuat();

    danhSach.top10();

    return 0;
}
