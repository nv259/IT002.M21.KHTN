#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
    public:
        Time();
        Time(int);
        Time(int, int, int);
        virtual ~Time();

        void nhap();
        void xuat();

        friend Time operator + (Time, Time);
        friend Time operator - (Time, Time);

        friend istream & operator >> (istream &, Time &);
        friend ostream & operator << (ostream &, Time);

        Time operator++();
        Time operator++(int);
        Time operator--();
        Time operator--(int);

        void ngayGioPhutGiay();
    protected:

    private:
        int tongSoGiay;
        int gio, phut, giay;
        int ngay;
};

#endif // TIME_H
