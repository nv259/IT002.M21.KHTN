#include "SoPhuc.h"
#include <iostream>

using namespace std;

SoPhuc::SoPhuc()
{
    //ctor
}

SoPhuc::SoPhuc(float thuc, float ao)
{
    this->thuc = thuc;
    this->ao = ao;
}

SoPhuc::~SoPhuc()
{
    //dtor
}

void SoPhuc::xuat()
{
    printf("(%f, %f)", thuc, ao);
}

void SoPhuc::nhap()
{
    cin >> thuc >> ao;
}

void SoPhuc::setThuc(float thuc)
{
    this->thuc = thuc;
}

void SoPhuc::setAo(float ao)
{
    this->ao = ao;
}

float SoPhuc::getAo()
{
    return ao;
}

float SoPhuc::getThuc()
{
    return thuc;
}

SoPhuc SoPhuc::operator+(SoPhuc b)
{
    return SoPhuc(thuc + b.thuc, ao + b.ao);
}

SoPhuc SoPhuc::operator-(SoPhuc b)
{
    return SoPhuc(thuc - b.thuc, ao - b.ao);
}

SoPhuc SoPhuc::operator*(SoPhuc b)
{
    return SoPhuc(thuc * b.thuc - ao * b.ao, thuc * b.ao + ao * b.thuc);
}

SoPhuc SoPhuc::operator/(SoPhuc b)
{
    if (b.ao == 0 && b.thuc == 0)
        cout << "So thu 2 bang 0, chuong trinh sinh loi!", exit;
    return SoPhuc((thuc * b.thuc + ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao), (b.thuc * ao - thuc * b.ao) / (b.thuc * b.thuc + b.ao * b.ao));
}
