#include "PhanSo.h"
#include <algorithm>
#include <iostream>

using namespace std;

PhanSo::PhanSo()
{
    //ctor
}

PhanSo::PhanSo(int tuSo, int mauSo)
{
    if (mauSo == 0)
        cout << "Mau bang 0, chuong trinh bi loi!", exit;

    this->tuSo = tuSo;
    this->mauSo = mauSo;
}

PhanSo::~PhanSo()
{
    //dtor
}

PhanSo PhanSo::operator+(PhanSo b)
{
    return PhanSo(tuSo * b.mauSo + mauSo * b.tuSo, mauSo * b.mauSo);
}

PhanSo PhanSo::operator-(PhanSo b)
{
    return PhanSo(tuSo * b.mauSo - mauSo * b.tuSo, mauSo * b.mauSo);
}

PhanSo PhanSo::operator*(PhanSo b)
{
    return PhanSo(tuSo * b.tuSo, mauSo * b.mauSo);
}

PhanSo PhanSo::operator/(PhanSo b)
{
    return PhanSo(tuSo * b.mauSo, mauSo * b.tuSo);
}

void PhanSo::nhap()
{
    cout << "Nhap hai so nguyen la tu so va mau so cua phan so: \n";
    cin >> tuSo >> mauSo;
    while (mauSo == 0)
    {
        cout << "Nhap lai mau khac 0!\n";
        cin >> mauSo;
    }
}

void PhanSo::xuat()
{
    rutGon();
    cout << tuSo;
    if (mauSo != 1)
        cout << "/" << mauSo;
    cout << "\n";
}

void PhanSo::setTuSo(int tuSo)
{
    this->tuSo = tuSo;
}

void PhanSo::setMauSo(int mauSo)
{
    this->mauSo = mauSo;
}

int PhanSo::getTuSo()
{
    return tuSo;
}

int PhanSo::getMauSo()
{
    return mauSo;
}

void PhanSo::rutGon()
{
    bool laSoAm = false;
    if (tuSo * mauSo < 0)
        laSoAm = true;
    tuSo = abs(tuSo);
    mauSo = abs(mauSo);

    int gcd = __gcd(tuSo, mauSo);

    tuSo /= gcd;
    mauSo /= gcd;

    if (laSoAm)
        tuSo *= -1;
}

