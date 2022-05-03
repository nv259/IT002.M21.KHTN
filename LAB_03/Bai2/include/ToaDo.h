#ifndef TOADO_H
#define TOADO_H


class ToaDo
{
    public:
        double x, y;

        ToaDo();
        ToaDo(double, double);
        virtual ~ToaDo();

        int getX();
        int getY();
        void setX(int);
        void setY(int);

    protected:

    private:
        // int x, y;
};

#endif // TOADO_H
