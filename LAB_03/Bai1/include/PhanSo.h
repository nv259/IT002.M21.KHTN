#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

using namespace std;

class PhanSo
{
    public:
        PhanSo();
        PhanSo(int, int);
        PhanSo(int tuSo);
        virtual ~PhanSo();

        bool hopLe();

        void rutGon();
        void xuat();
        void nhap();

        PhanSo cong(PhanSo) const;
        PhanSo tru(PhanSo) const;
        PhanSo nhan(PhanSo) const;
        PhanSo chia(PhanSo) const;

        PhanSo operator - ();

        friend PhanSo operator + (PhanSo, PhanSo);
        friend PhanSo operator - (PhanSo, PhanSo);
        // friend PhanSo operator - (PhanSo);
        friend PhanSo operator * (PhanSo, PhanSo);
        friend PhanSo operator / (PhanSo, PhanSo);

        friend PhanSo operator == (PhanSo, PhanSo);
        friend PhanSo operator != (PhanSo, PhanSo);
        friend PhanSo operator > (PhanSo, PhanSo);
        friend PhanSo operator >= (PhanSo, PhanSo);
        friend PhanSo operator < (PhanSo, PhanSo);
        friend PhanSo operator <= (PhanSo, PhanSo);

        friend istream & operator >> (istream &, PhanSo &);
        friend ostream & operator << (ostream &, PhanSo);

    protected:

    private:
        int tuSo, mauSo;
};

#endif // PHANSO_H
