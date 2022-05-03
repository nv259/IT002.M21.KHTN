#include "TamGiac.h"
#include <iostream>
#include <utility>
#define pff pair<double, double>
#define X first
#define Y second
#include <math.h>
#define FLT_MAX 1e9

using namespace std;

TamGiac::TamGiac()
{
    //ctor
}

TamGiac::TamGiac(pff a, pff b, pff c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

TamGiac::~TamGiac()
{
    //dtor
}

pff TamGiac::trongTam()
{
    return {(a.X + b.X + c.X) / 3.0, (a.Y + b.Y + c.Y) / 3.0};
}

void TamGiac::xuat()
{
    printf("Ba dinh cua tam giac lan luot la: A(%f, %f), B(%f, %f), C(%f, %f)\n", a.X, a.Y, b.X, b.Y, c.X, c.Y);
}

void TamGiac::nhap()
{
    cout << "Nhap toa do X va Y cua dinh A: ";
    cin >> a.X >> a.Y;
    cout << "Nhap toa do X va Y cua dinh B: ";
    cin >> b.X >> b.Y;
    cout << "Nhap toa do X va Y cua dinh C: ";
    cin >> c.X >> c.Y;
}

void TamGiac::tinhTien(double dx, double dy)
{
    a.X += dx; a.Y += dy;
    b.X += dx; b.Y += dy;
    c.X += dx; c.Y += dy;
}

void TamGiac::quayQuanhTrucTam(pff &point, double goc) // radian
{
    pff p = tamDuongTronNgoaiTiep();
    // point.X = (point.X - p.X) * cos(goc) - (point.Y - p.Y) * sin(goc) + p.X;
    // point.X = (point.Y - p.Y) * sin(goc) + (point.X - p.X) * cos(goc) + p.Y;

    point.X -= p.X;
    point.Y -= p.Y;
    pff temp = point;

    point.X = temp.X * cos(goc) - temp.Y * sin(goc);
    point.Y = temp.X * sin(goc) + temp.Y * cos(goc);

    point.X += p.X;
    point.Y += p.Y;
}

void TamGiac::quay(double goc)
{
    quayQuanhTrucTam(a, goc);
    quayQuanhTrucTam(b, goc);
    quayQuanhTrucTam(c, goc);
}

void TamGiac::thuPhong(double doLon)
{
    pff p = trongTam();
    a = {doLon * (a.X - p.X) + p.X, doLon * (a.Y - p.Y) + p.Y};
    b = {doLon * (b.X - p.X) + p.X, doLon * (b.Y - p.Y) + p.Y};
    c = {doLon * (c.X - p.X) + p.X, doLon * (c.Y - p.Y) + p.Y};
}

void TamGiac::phuongTrinhDuongThang(pff P, pff Q, double &a, double &b, double &c)
{
    a = Q.second - P.second;
    b = P.first - Q.first;
    c = a*(P.first)+ b*(P.second);
}

void TamGiac::phuongTrinhDuongTrungTruc(pff P, pff Q, double &a, double &b, double &c)
{
    pff mid_point = make_pair((P.first + Q.first)/2,
                            (P.second + Q.second)/2);

    // c = -bx + ay
    c = -b*(mid_point.first) + a*(mid_point.second);

    double temp = a;
    a = -b;
    b = temp;
}

pff TamGiac::giaoHaiDuongThang(double a1, double b1, double c1,
                               double a2, double b2, double c2)
{
    double determinant = a1*b2 - a2*b1;
    if (determinant == 0)
        return make_pair(FLT_MAX, FLT_MAX);

    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

pff TamGiac::tamDuongTronNgoaiTiep()
{
    pff P, Q, R;
    P = a, Q = b, R = c;
    double a, b, c;
    phuongTrinhDuongThang(P, Q, a, b, c);

    double e, f, g;
    phuongTrinhDuongThang(Q, R, e, f, g);

    phuongTrinhDuongTrungTruc(P, Q, a, b, c);
    phuongTrinhDuongTrungTruc(Q, R, e, f, g);

    pff circumcenter =
           giaoHaiDuongThang(a, b, c, e, f, g);

    if (circumcenter.first == FLT_MAX &&
        circumcenter.second == FLT_MAX) return make_pair(FLT_MAX, FLT_MAX);

    else return circumcenter;
}

void TamGiac::ve()
{

}
