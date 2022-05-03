#include "CDate.h"
#include <iomanip>

const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

CDate::CDate()
{
    //ctor
}

CDate::CDate(int day)
{
    this->sumDays = day;
    standardize();
}

CDate::~CDate()
{
    //dtor
}

bool CDate::isFullYear()
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            return true;
        return false;
    }

    if (year % 4 == 0)
        return true;

    return false;
}

bool CDate::isFullYear(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            return true;
        return false;
    }

    if (year % 4 == 0)
        return true;

    return false;
}

void CDate::standardize()
{
    int temp = sumDays;
    year = 0;
    month = 0;
    day = 0;

    for (int i = 0; ; i++)
    {
        temp -= isFullYear(year + 1) ? 366 : 365;
        if (temp >= 0)
            year++;
        else
        {
            temp += isFullYear(year + 1) ? 366 : 365;
            break;
        }
    }

    for (int i = 1; i <= 12; i++)
    {
        if (temp >= daysInMonth[i])
        {
            temp -= daysInMonth[i];
            month++;
        }
        else break;
    }

    day = temp;
}

CDate operator + (const CDate &date1, const CDate &date2)
{
    CDate result;
    result.sumDays = date1.sumDays + date2.sumDays;
    result.standardize();
    return result;
}

CDate operator - (const CDate &date1, const CDate &date2)
{
    CDate result;
    result.sumDays = date1.sumDays - date2.sumDays;
    result.standardize();
    return result;
}

CDate CDate::operator ++ ()
{
    this->sumDays++;
    this->standardize();
    return *this;
}

CDate CDate::operator-- ()
{
    this->sumDays--;
    this->standardize();
    return *this;
}

CDate CDate::operator++ (int)
{
    CDate t = *this;
    this->sumDays++;
    this->standardize();
    return t;
}

CDate CDate::operator-- (int)
{
    CDate t = *this;
    this->sumDays--;
    this->standardize();
    return t;
}

istream & operator >> (istream &inp, CDate &p)
{
    cout << "month: ";
    inp >> p.month;
    cout << "day: ";
    inp >> p.day;
    cout << "year: ";
    inp >> p.year;

    p.sumDays = 0;
    for (int i = 1; i <= p.year; i++)
        p.sumDays += p.isFullYear(i) ? 366 : 365;

    for (int i = 1; i <= p.month; i++)
        p.sumDays += daysInMonth[i];

    p.sumDays += p.day;
    return inp;
}

ostream & operator << (ostream &out, CDate p)
{
    out << setfill('0') << setw(2) << p.month << "m" << p.day << "d" << p.year << "y";
    return out;
}

int CDate::getSumDays()
{
    return sumDays;
}
