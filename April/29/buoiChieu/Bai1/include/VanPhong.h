#ifndef VANPHONG_H
#define VANPHONG_H

#include <iostream>
#include "NhanVien.h"

using namespace std;

class VanPhong : public NhanVien
{
    public:
        VanPhong();
        virtual ~VanPhong();

        void tinhLuong();

        friend istream & operator >> (istream &, VanPhong &);
    protected:

    private:
        int soNgayLamViec;
};

#endif // VANPHONG_H
