#ifndef CDATE_H
#define CDATE_H

#include <iostream>

using namespace std;

class CDate
{
    public:
        CDate();
        CDate(int);
        virtual ~CDate();
        void standardize();

        int getSumDays();
        bool isFullYear();
        bool isFullYear(int);

        friend CDate operator + (const CDate &, const CDate &);
        friend CDate operator - (const CDate &, const CDate &);

        CDate operator ++ ();
        CDate operator -- ();
        CDate operator ++ (int);
        CDate operator -- (int);

        friend istream & operator >> (istream &, CDate &);
        friend ostream & operator << (ostream &, CDate);
    protected:

    private:
        int day, month, year;
        int sumDays;
};

#endif // CDATE_H
