#ifndef MENU_H
#define MENU_H
#define ll long long

#include "NhanVien.h"
#include <string>

using namespace std;

class Menu
{
    public:
        Menu();
        Menu(const Menu &danhSach);
        virtual ~Menu();

        void ngauNhien();
        void nhap();
        void xuat();
        void capNhatThongTin(string maNhanVien);
        void tinhLuong();

        NhanVien luongCaoNhat();
        NhanVien luongThapNhat();
        void top10();
        void sapXepTheoLuong();

    protected:

    private:
        NhanVien arr[300];
        int soNhanVien;
        ll luongCanBan;
};

#endif // MENU_H
