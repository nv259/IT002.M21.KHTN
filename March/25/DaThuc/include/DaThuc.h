#ifndef DATHUC_H
#define DATHUC_H
#define ll long long
#include <vector>

using namespace std;

class DaThuc
{
    public:
        DaThuc();
        DaThuc(int);
        virtual ~DaThuc();

        void nhap();
        void xuat();

        DaThuc operator+ (DaThuc Y);
        DaThuc operator- (DaThuc Y);

        ll giaTri(int x);
    private:
        int n; // a.size()
        vector <int> a;
};

#endif // DATHUC_H
