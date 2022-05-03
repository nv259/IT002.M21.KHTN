#ifndef DATHUC_H
#define DATHUC_H

#include <vector>
#include <iostream>

using namespace std;

class DaThuc
{
    public:
        DaThuc();
        virtual ~DaThuc();

        float tinhGiaTri(float);
        pair<int, float> &operator [] (int);
        // DaThuc operator - ();

        friend DaThuc operator - (const DaThuc &);
        friend DaThuc operator + (const DaThuc &, const DaThuc &);
        friend DaThuc operator - (const DaThuc &, const DaThuc &);

        friend istream & operator >> (istream &, DaThuc &);
        friend ostream & operator << (ostream &, DaThuc);

    protected:

    private:
        vector <pair<int, float>> arr;
};

#endif // DATHUC_H
