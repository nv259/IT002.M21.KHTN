#ifndef NHANVIEN_H
#define NHANVIEN_H
#define ll long long

#include <string>
#include <iostream>

using namespace std;

class NhanVien
{
    public:
        NhanVien();
        virtual ~NhanVien();

        friend ostream &operator << (ostream &, NhanVien);

    protected:
        void nhap();
        void xuat();

        ll luong;
    private:
        string hoVaTen, ngaySinh;
};

#endif // NHANVIEN_H
