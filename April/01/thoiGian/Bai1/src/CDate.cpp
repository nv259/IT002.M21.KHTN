#include "CDate.h"
#include <iostream>

using namespace std;

CDate::CDate()
{
    //ctor
}

CDate::CDate(int day)
{
    sumDays = day;
    standardize();
}

CDate::CDate(int month, int day, int year)
{

    this->day = day;
    this->year = year;
    this->month = month;
}

CDate::~CDate()
{
    //dtor
}

void CDate::standardize()
{

}

CDate operator + (CDate date1, CDate date2)
{
    CDate result = date1;
    result.sumDays += date2.sumDays;
    result.standardize();

    return result;
}

CDate operator - (CDate date1, CDate date2)
{
    CDate result = date1;
    result.sumDays -= date2.sumDays;
    result.standardize();

    return result;
}

CDate CDate::operator++()
{
    this->day++;
    return *this;
}

CDate CDate::operator++(int)
{
    CDate t = *this;
    this->day++;
    return t;
}

CDate CDate::operator--()
{
    this->day--;
    return *this;
}

CDate CDate::operator--(int)
{
    CDate t = *this;
    this->day--;
    return t;
}

istream & operator >> (istream &inp, CDate &p)
{
    cout << "mm/dd/yyyy\n";
    inp >> p.month >> p.day >> p.year;
    return inp;
}

ostream & operator << (ostream &out, CDate p)
{
    out << p.month << " " << p.day << " " << p.year;
    return out;
}
