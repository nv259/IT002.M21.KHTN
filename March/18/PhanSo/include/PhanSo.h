#ifndef PHANSO_H
#define PHANSO_H


class PhanSo
{
    public:
        PhanSo();
        PhanSo(int, int);
        virtual ~PhanSo();

        PhanSo operator+ (PhanSo b);
        PhanSo operator- (PhanSo);
        PhanSo operator* (PhanSo);
        PhanSo operator/ (PhanSo);

        void xuat();
        void nhap();

        void setTuSo(int tuSo);
        void setMauSo(int mauSo);

        int getTuSo();
        int getMauSo();

        void rutGon();

    protected:

    private:
        int tuSo, mauSo;
};

#endif // PHANSO_H
