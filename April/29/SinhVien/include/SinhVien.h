#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>

using namespace std;

class SinhVien
{
    public:
        SinhVien();
        virtual ~SinhVien();

        bool duocTotNghiep();
        void setDiemTrungBinh(float);
        float getDiemTrungBinh();

        void nhap();

        friend istream & operator >> (istream &, SinhVien &);
        friend ostream & operator << (ostream &, SinhVien);


    protected:

    private:
        string maSo, hoVaTen, diaChi;
        int tongSoTinChi;
        float trungBinhTichLuy;
        string luanVan;
        float diemLuanVan;
};

#endif // SINHVIEN_H
