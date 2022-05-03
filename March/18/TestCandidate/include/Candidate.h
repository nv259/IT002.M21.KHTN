#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <string>

using namespace std;

class Candidate
{
    public:
        Candidate();
        Candidate(string, string, string, float, float, float);
        virtual ~Candidate();

        void nhap();
        void xuat();

        float tongDiem();
    protected:

    private:
        string MSSV, ten, ngaySinh;
        float diemToan, diemVan, diemAnh;
};

#endif // CANDIDATE_H
