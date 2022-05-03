#ifndef CONGTY_H
#define CONGTY_H

#include "SanXuat.h"
#include "VanPhong.h"

class CongTy
{
    public:
        CongTy();
        virtual ~CongTy();

        void tinhLuong();

        friend istream &operator >> (istream &, CongTy &);
        friend ostream &operator << (ostream &, CongTy);
    protected:

    private:
        int soSanXuat, soVanPhong;
        SanXuat sx[5555];
        VanPhong vp[5555];
        int luongCanBan;
};

#endif // CONGTY_H
