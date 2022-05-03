#ifndef CDATE_H
#define CDATE_H

#include <iostream>

using namespace std;

class CDate
{
    public:
        CDate();
        CDate(int);
        CDate(int, int, int);
        virtual ~CDate();

        void standardize();

        friend CDate operator + (CDate, CDate);
        friend CDate operator - (CDate, CDate);
        CDate operator ++ ();
        CDate operator -- ();
        CDate operator ++(int);
        CDate operator --(int);

        friend istream & operator >> (istream &, CDate &);
        friend ostream & operator << (ostream &, CDate);

    protected:

    private:
        int day, month, year;
        int sumDays;
};

#endif // CDATE_H
