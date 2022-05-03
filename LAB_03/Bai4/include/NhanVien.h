#ifndef NHANVIEN_H
#define NHANVIEN_H
#define ll long long

#include <string>

using namespace std;

class NhanVien
{
    public:
        NhanVien();
        virtual ~NhanVien();

        void nhap();
        void xuat();
        void sinhNgauNhien();
        void tinhLuong(ll luongCanBan);
        void setMaNhanVien(string);
        void setHoVaTen(string);
        void setSoSanPham(int soSanPham);
        string getMaNhanVien();
        ll getLuong();

    protected:

    private:
        string maNhanVien, hoVaTen;
        int soSanPham;
        ll luong;
};

#endif // NHANVIEN_H
