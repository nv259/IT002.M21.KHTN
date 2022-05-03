#include "Time.h"

Time::Time()
{
    //ctor
}

void Time::ngayGioPhutGiay()
{
    int temp = tongSoGiay;

    this->ngay = temp / (24 * 3600);
    temp %= (24 * 3600);

    this->gio = temp / 3600;
    temp %= 3600;

    this->phut = temp / 60;
    temp %= 60;

    this->giay = temp;
}

Time::Time(int giay)
{
    this->tongSoGiay = giay;
    ngayGioPhutGiay();
}

Time::Time(int gio, int phut, int giay)
{
    tongSoGiay = (gio * 3600) + (phut * 60) + giay;
    ngayGioPhutGiay();
}

Time::~Time()
{
    //dtor
}


void Time::nhap()
{
    cout << "Nhap gio: ";
    cin >> gio;

    cout << "Nhap phut: ";
    cin >> phut;

    cout << "Nhap giay: ";
    cin >> giay;

    tongSoGiay = (gio * 3600) + (phut * 60) + giay;
    ngayGioPhutGiay();
}

void Time::xuat()
{
    cout << ngay << "d" << gio << "h" << phut << "m" << giay << "s\n";
}

Time operator + (Time a, Time b)
{
    Time result;

    result.tongSoGiay = a.tongSoGiay + b.tongSoGiay;
    result.ngayGioPhutGiay();

    return result;
}

Time operator - (Time a, Time b)
{
    Time result;

    result.tongSoGiay = a.tongSoGiay - b.tongSoGiay;
    result.ngayGioPhutGiay();

    return result;
}

istream & operator >> (istream &inp, Time &p)
{
    inp >> p.gio >> p.phut >> p.giay;
    return inp;
}

ostream & operator << (ostream &out, Time p)
{
    out << p.ngay << "d" << p.gio << "h" << p.phut << "m" << p.giay << "s";
    return out;
}

Time Time::operator++()
{
    tongSoGiay++;
    ngayGioPhutGiay();
    return *this;
}

Time Time::operator++(int)
{
    Time t = *this;
    tongSoGiay++;
    ngayGioPhutGiay();
    return t;
}

Time Time::operator--()
{
    tongSoGiay--;
    ngayGioPhutGiay();
    return *this;
}

Time Time::operator--(int)
{
    Time t = *this;
    tongSoGiay--;
    ngayGioPhutGiay();
    return t;
}
