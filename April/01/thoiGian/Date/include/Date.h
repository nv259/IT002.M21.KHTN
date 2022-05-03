#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>

using namespace std;

class Date
{
    public:
        Date();
        Date(int, int, int);
        virtual ~Date();

        bool validate();

        int getDay();
        int getMonth();
        int getYear();

        void setDay(int);
        void setMonth(int);
        void setYear(int);

        bool is_leap_year();

        friend Date operator << (ostream &out, const Date &data);
    protected:

    private:
        int day, month, year;
};

#endif // DATE_H
