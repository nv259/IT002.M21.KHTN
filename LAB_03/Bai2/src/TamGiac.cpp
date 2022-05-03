#include "TamGiac.h"
#include <iostream>
#include <math.h>

using namespace std;

TamGiac::TamGiac()
{
    //ctor
}

TamGiac::TamGiac(ToaDo A, ToaDo B, ToaDo C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}

TamGiac::~TamGiac()
{
    //dtor
}

void TamGiac::nhap()
{
    double xA, yA, xB, yB, xC, yC;

    cout << "Nhap toa do xA, yA: \n";
    cin >> xA >> yA;

    cout << "Nhap toa do xB, yB: \n";
    cin >> xB >> yB;

    cout << "Nhap toa do xC, yC: \n";
    cin >> xC >> yC;

    A = ToaDo(xA, yA);
    B = ToaDo(xB, yB);
    C = ToaDo(xC, yC);
}

ostream & operator << (ostream &out, ToaDo p)
{
    out << p.x << " " << p.y;
    return out;
}

void TamGiac::xuat()
{
    cout << "Toa do dinh thu nhat: " << A.x << " " << A.y << "\n";
    cout << "Toa do dinh thu hai: " << B.x << " " << B.y << "\n";
    cout << "Toa do dinh thu ba: " << C.x << " " << C.y << "\n";

    switch (loai())
    {
        case -1:
            cout << "Khong phai la mot tam giac !";
            break;
        case 0:
            cout << "La tam giac nhon.";
            break;
        case 1:
            cout << "La tam giac vuong.";
            break;
        case 2:
            cout << "La tam giac deu.";
            break;
        case 3:
            cout << "La tam giac can.";
            break;
        default:
            cout << "La tam giac tu.";
            break;
    }
    cout << "\n";

    cout << "Chu vi: " << chuVi() << '\n';
    cout << "Dien tich: " << dienTich() << '\n';
    cout << "Tam duong tron noi tiep tam giac: " << tamDuongTronNoiTiep() << '\n';
    cout << "Tam duong tron ngoai tiep tam giac: " << tamDuongTronNgoaiTiep() << '\n';
}

double sqr(double x)
{
    return x * x;
}

void TamGiac::tinhDoDaiCacCanh()
{
    this->AB = sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
    this->AC = sqrt(sqr(A.x - C.x) + sqr(A.y - C.y));
    this->BC = sqrt(sqr(B.x - C.x) + sqr(B.y - C.y));
}

int TamGiac::loai()
{
    // khong la tam giac
    if (AB + AC <= BC || AB + BC <= AC || BC + AC <= AB)
        return -1;

    // la tam giac vuong
    if (sqr(AB) == sqr(AC) + sqr(BC) || sqr(AC) == sqr(AB) + sqr(BC)
        || sqr(BC) == sqr(AB) + sqr(AC))
        return 1;

    // la tam giac deu
    if (AB == AC && AB == BC)
        return 2;

    // la tam giac can
    if (AB == AC || AB == BC || AC == BC)
        return 3;

    // la tam giac tu
    if (sqr(AB) > sqr(AC) + sqr(BC) || sqr(AC) > sqr(AB) + sqr(BC)
        || sqr(BC) > sqr(AB) + sqr(AC))
        return 4;

    // la tam giac nhon
    return 0;
}

double TamGiac::chuVi()
{
    return AB + AC + BC;
}

double TamGiac::dienTich()
{
    double p = chuVi() / 2.0;
    return 1.0 * sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

ToaDo TamGiac::tamDuongTronNgoaiTiep()
{
    // dunno wut to do :Đ
}

ToaDo TamGiac::tamDuongTronNoiTiep()
{
    return ToaDo((A.x + B.x + C.x) / 3.0, (A.y + B.y + C.y) / 3.0);
}
