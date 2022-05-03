#ifndef TAMGIAC_H
#define TAMGIAC_H
#include <utility>
#define pff pair<double, double>

using namespace std;

class TamGiac
{
    public:
        TamGiac();
        TamGiac(pff, pff, pff);
        virtual ~TamGiac();

        pff trongTam();
        void phuongTrinhDuongThang(pff P, pff Q, double &a, double & b, double &c);
        void phuongTrinhDuongTrungTruc(pff P, pff Q, double &a, double &b, double &c);
        pff tamDuongTronNgoaiTiep();
        pff giaoHaiDuongThang(double a1, double b1, double c1,
                              double a2, double b2, double c2);

        void nhap();
        void xuat();

        void tinhTien(double, double);
        void quayQuanhTrucTam(pff &, double); // radian
        void quay(double goc); // góc
        void thuPhong(double doLon);

        void ve(); // i dunno sir

    protected:

    private:
        pff a, b, c;
};

#endif // TAMGIAC_H
