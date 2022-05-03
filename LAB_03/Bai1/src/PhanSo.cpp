#include "PhanSo.h"

PhanSo::PhanSo()
{
    //ctor
}

PhanSo::PhanSo(int tuSo, int mauSo)
{
    this->tuSo = tuSo;
    this->mauSo = mauSo;
    rutGon();
}

PhanSo::PhanSo(int tuSo)
{
    this->tuSo = tuSo;
    mauSo = 1;
}

PhanSo::~PhanSo()
{
    //dtor
}

void PhanSo::rutGon()
{

}

bool PhanSo::hopLe()
{
    return mauSo != 0;
}

void PhanSo::xuat()
{

}

void PhanSo::nhap()
{

}

PhanSo PhanSo::cong(PhanSo b) const
{

}

PhanSo PhanSo::tru(PhanSo b) const
{

}

PhanSo PhanSo::nhan(PhanSo b) const
{

}

PhanSo PhanSo::chia(PhanSo b) const
{

}

PhanSo operator + (PhanSo a, PhanSo b)
{
    return PhanSo(a.tuSo * b.mauSo + a.mauSo * b.tuSo, a.mauSo * b.mauSo);
}

PhanSo operator - (PhanSo a, PhanSo b)
{
    return PhanSo(a.tuSo * b.mauSo - a.mauSo * b.tuSo, a.mauSo * b.mauSo);
}

/*PhanSo operator - (PhanSo a)
{
    // cach dung ham toan cuc
    return PhanSo(-a.tuSo, a.mauSo);
}*/

PhanSo PhanSo::operator - ()
{
    // cach dung ham thanh phan
    return PhanSo(-tuSo, mauSo);
}

PhanSo operator * (PhanSo a, PhanSo b)
{
    return PhanSo(a.tuSo * b.tuSo, a.mauSo * b.mauSo);
}

PhanSo operator / (PhanSo a, PhanSo b)
{
    return PhanSo(a.tuSo * b.mauSo, a.mauSo * b.tuSo);
}

PhanSo operator == (PhanSo a, PhanSo b)
{
    return ((double) a.tuSo / a.mauSo == (double) b.tuSo / b.mauSo);
}

PhanSo operator != (PhanSo a, PhanSo b)
{
    return !((double) a.tuSo / a.mauSo == (double) b.tuSo / b.mauSo);
}

PhanSo operator > (PhanSo a, PhanSo b)
{
    return ((double) a.tuSo / a.mauSo > (double) b.tuSo / b.mauSo);
}

PhanSo operator >= (PhanSo a, PhanSo b)
{
    return ((double) a.tuSo / a.mauSo >= (double) b.tuSo / b.mauSo);
}

PhanSo operator < (PhanSo a, PhanSo b)
{
    return ((double) a.tuSo / a.mauSo < (double) b.tuSo / b.mauSo);
}

PhanSo operator <= (PhanSo a, PhanSo b)
{
    return ((double) a.tuSo / a.mauSo <= (double) b.tuSo / b.mauSo);
}

istream & operator >> (istream &inp, PhanSo &p)
{
    inp >> p.tuSo >> p.mauSo;
    return inp;
}

ostream & operator << (ostream &out, PhanSo p)
{
    if (!p.hopLe())
        out << "Phan so khong hop le!";
    else
    {
        out << p.tuSo;
        if (p.mauSo != 1)
            out << '/' << p.mauSo;
    }
}
