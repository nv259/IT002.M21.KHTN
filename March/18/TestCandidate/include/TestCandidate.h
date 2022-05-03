#ifndef TESTCANDIDATE_H
#define TESTCANDIDATE_H
#include "Candidate.h"

class TestCandidate
{
    public:
        TestCandidate();
        TestCandidate(int);
        virtual ~TestCandidate();

        void nhap();
        void xuat();
        void xuatThiSinhTren15Diem();
    protected:

    private:
        int soLuong;
        Candidate *danhSachThiSinh;
};

#endif // TESTCANDIDATE_H
