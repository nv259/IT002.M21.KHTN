#ifndef DATA_H
#define DATA_H

#include "SinhVien.h"
#include <iostream>

using namespace std;

class Data
{
    public:
        Data();
        virtual ~Data();

        int totNghiep();
        SinhVien thuKhoa();

        SinhVien &operator [] (int);
        friend istream & operator >> (istream &, Data &);
        friend ostream & operator << (ostream &, Data);

    protected:

    private:
        SinhVien a[8000];
        int soSinhVien;
};

#endif // DATA_H
