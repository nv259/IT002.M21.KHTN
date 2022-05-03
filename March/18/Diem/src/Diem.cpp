#include "Diem.h"
#include <iostream>

using namespace std;

Diem::Diem()
{
    //ctor
}

Diem::Diem(int x, int y)
{
    this->x = x;
    this->y = y;
}

Diem::~Diem()
{
    //dtor
}

int Diem::getX()
{
    return x;
}

int Diem::getY()
{
    return y;
}

void Diem::setX(int x)
{
    this->x = x;
}

void Diem::setY(int y)
{
    this->y = y;
}

void Diem::nhap()
{
    cin >> x >> y;
}

void Diem::xuat()
{
    printf("(%d, %d)\n", x, y);
}
