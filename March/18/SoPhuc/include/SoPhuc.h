#ifndef SOPHUC_H
#define SOPHUC_H


class SoPhuc
{
    public:
        SoPhuc();
        SoPhuc(float, float);
        virtual ~SoPhuc();

        void xuat();
        void nhap();

        void setThuc(float thuc);
        void setAo(float ao);

        float getThuc();
        float getAo();

        SoPhuc operator+(SoPhuc);
        SoPhuc operator-(SoPhuc);
        SoPhuc operator*(SoPhuc);
        SoPhuc operator/(SoPhuc);

    protected:

    private:
        float thuc, ao;
};

#endif // SOPHUC_H
