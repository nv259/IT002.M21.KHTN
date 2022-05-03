#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "ToaDo.h"
#include "string"

using namespace std;

class TamGiac
{
    public:
        TamGiac();
        TamGiac(ToaDo A, ToaDo B, ToaDo C);
        TamGiac(double xA, double yA, double xB, double yB, double xC, double yC) : A(xA, yA), B(xB, yB), C(xC, yC) {};
        virtual ~TamGiac();

        void nhap();
        void xuat();
        int loai();

        void tinhDoDaiCacCanh();

        double chuVi();
        double dienTich();
        ToaDo tamDuongTronNgoaiTiep();
        ToaDo tamDuongTronNoiTiep();

    protected:

    private:
        ToaDo A, B, C;
        double AB, AC, BC;
};

#endif // TAMGIAC_H
