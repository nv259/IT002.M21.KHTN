#ifndef CONNGUOI_H
#define CONNGUOI_H


class ConNguoi
{
    public:
        ConNguoi();
        virtual ~ConNguoi();

        void nhap();

    protected:
        string hoVaTen;
        string ngaySinh;
        string gioiTinh;
        string sdt;

    private:
};

#endif // CONNGUOI_H
