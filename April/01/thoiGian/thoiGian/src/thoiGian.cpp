#include "thoiGian.h"
#include <iostream>
#include <iomanip>

using namespace std;

thoiGian::thoiGian()
{
    //ctor
}

thoiGian::~thoiGian()
{
    //dtor
}

thoiGian::thoiGian(int gio, int phut = 0, int giay = 0)
{
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
}

int thoiGian::getGio()
{
    return gio;
}

int thoiGian::getPhut()
{
    return phut;
}

int thoiGian::getGiay()
{
    return giay;
}

void thoiGian::setGio(int gio)
{
    this->gio = gio;
}

void thoiGian::setPhut(int phut)
{
    this->phut = phut;
}

void thoiGian::setGiay(int giay)
{
    this->giay = giay;
}

void thoiGian::nhap()
{
    do
    {
        cout << "Nhap gio: ";
        cin >> gio;
        cout << "Nhap phut: ";
        cin >> phut;
        cout << "Nhap giay: ";
        cin >> giay;
    } while (!hopLe());
}

void thoiGian::xuat()
{
    cout << setfill('0') << setw(2) << gio << ":" << setw(2) << phut << ":" << setw(2) << giay;
    if (is12)
        if (is_morning) cout << " AM";
        else cout << " PM";
    cout << '\n';
}

void thoiGian::to12h()
{
    is12 = true;

    if (gio <= 12) is_morning = true;
    else
    if (gio < 24)
    {
        gio -= 12;
        is_morning = false;
    }
    else
    {
        gio = 0;
        is_morning = true;
    }
}

bool thoiGian::hopLe()
{
    if (gio < 0 || gio > 24) return false;
    if (phut < 0 || phut > 60) return false;
    if (giay < 0 || giay > 0) return false;
}
