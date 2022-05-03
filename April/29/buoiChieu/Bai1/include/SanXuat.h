#ifndef SANXUAT_H
#define SANXUAT_H
#include "NhanVien.h"

class SanXuat: public NhanVien
{
    public:
        SanXuat();
        virtual ~SanXuat();

        void tinhLuong(ll);

        friend istream & operator >> (istream &, SanXuat &);

    protected:

    private:
        int soSanPham;
};

#endif // SANXUAT_H
