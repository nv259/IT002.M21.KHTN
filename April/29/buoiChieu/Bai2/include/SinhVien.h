#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "ConNguoi.h"

using namespace std;

class SinhVien : public ConNguoi
{
    public:
        SinhVien();
        virtual ~SinhVien();

    protected:

    private:
        string maSo;
};

#endif // SINHVIEN_H
