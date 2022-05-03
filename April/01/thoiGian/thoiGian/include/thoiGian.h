#ifndef THOIGIAN_H
#define THOIGIAN_H


class thoiGian
{
    public:
        thoiGian();
        thoiGian(int, int, int);
        virtual ~thoiGian();

        int getGio();
        int getPhut();
        int getGiay();

        void setGio(int);
        void setPhut(int);
        void setGiay(int);

        void nhap();
        void xuat();
        void to12h();

        bool hopLe();

    protected:

    private:
        int gio, phut, giay;
        bool is12, is_morning;
};

#endif // THOIGIAN_H
