#include "Date.h"
#include <iostream>

using namespace std;

Date::Date()
{
    //ctor
}

Date::~Date()
{
    //dtor
}

Date::Date(int month, int day, int year)
{
    this->month = month;
    this->year = year;
    this->day = day;
}

bool Date::validate()
{
    if (day < 0) return false;
    if (month < 0 || month > 12) return false;
    if (month == 2)
    {
        if (is_leap_year() && day > 29) return false;
        if (!is_leap_year() && day > 28) return false;
        return true;
    }

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 31) return false;
            break;
        default:
            if (day > 30) return false;
            break;
    }

    return true;
}

bool Date::is_leap_year()
{
    return !(year % 4);
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDay(int day)
{
    int prev_day = this->day;
    this->day = day;
    if (!validate())
    {
        cout << "lew lew, stupid";
        this->day = prev_day;
    }
}

void Date::setMonth(int month)
{
    int prev_month = this->month;
    this->month = month;
    if (!validate())
    {
        cout << "lew lew, stupid";
        this->month = prev_month;
    }
}

void Date::setYear(int year)
{
    int prev_year = this->year;
    this->year = year;
    if (!validate())
    {
        cout << "lew lew, stupid";
        this->year = prev_year;
    }
}

Date operator >> (istream &inp, Date &data)
{
    string s;
    inp >> s;
    int temp[3], num = 0;
    int cc = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            if (!isdigit(s[i-1]))
                num = 0;
            num = num * 10 + (s[i] - '0');
        }
        else temp[cc++] = num;
    }
}

Date operator << (ostream &out, const Date &data)
{
    out << data.month << '/' << data.day << '/' << data.year << '\n';
}
