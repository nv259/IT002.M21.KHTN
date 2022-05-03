#ifndef DIEM_H
#define DIEM_H


class Diem
{
    public:
        Diem();
        Diem(int, int);
        virtual ~Diem();

        int getX();
        int getY();

        void setX(int x);
        void setY(int y);

        void tinhTien(int, int);

        void nhap();
        void xuat();

        void ve(); // i do not know for sure :(
    protected:

    private:
        int x, y;
};

#endif // DIEM_H
