#include <iostream>
#include <math.h>

using namespace std;

class Time
{
    private:
        int tongSoGiay;
        int gio, phut, giay;
        int ngay;
    public:
        Time();
        Time(int);
        Time(int, int, int);
        virtual ~Time();

        void nhap();
        void xuat();

        friend Time operator + (Time, Time);
        friend Time operator - (Time, Time);

        friend istream & operator >> (istream &, Time &);
        friend ostream & operator << (ostream &, Time);

        Time operator++();
        Time operator++(int);
        Time operator--();
        Time operator--(int);

        void ngayGioPhutGiay();
};

Time::Time()
{
}

void Time::ngayGioPhutGiay()
{
    int temp = tongSoGiay;

    this->ngay = temp / (24 * 3600);
    temp %= (24 * 3600);

    this->gio = temp / 3600;
    temp %= 3600;

    this->phut = temp / 60;
    temp %= 60;

    this->giay = temp;
}

Time::Time(int giay)
{
    this->tongSoGiay = giay;
    ngayGioPhutGiay();
}

Time::Time(int gio, int phut, int giay)
{
    tongSoGiay = (gio * 3600) + (phut * 60) + giay;
    ngayGioPhutGiay();
}

Time::~Time()
{
}

void Time::nhap()
{
    cout << "Nhap gio: ";
    cin >> gio;

    cout << "Nhap phut: ";
    cin >> phut;

    cout << "Nhap giay: ";
    cin >> giay;

    tongSoGiay = (gio * 3600) + (phut * 60) + giay;
    ngayGioPhutGiay();
}

void Time::xuat()
{
    cout << ngay << "d" << gio << "h" << phut << "m" << giay << "s\n";
}

Time operator + (Time a, Time b)
{
    Time result;

    result.tongSoGiay = a.tongSoGiay + b.tongSoGiay;
    result.ngayGioPhutGiay();

    return result;
}

Time operator - (Time a, Time b)
{
    Time result;

    result.tongSoGiay = a.tongSoGiay - b.tongSoGiay;
    result.ngayGioPhutGiay();

    return result;
}

istream & operator >> (istream &inp, Time &p)
{
    inp >> p.gio >> p.phut >> p.giay;
    return inp;
}

ostream & operator << (ostream &out, Time p)
{
    out << p.ngay << "d" << p.gio << "h" << p.phut << "m" << p.giay << "s";
    return out;
}

Time Time::operator++()
{
    tongSoGiay++;
    ngayGioPhutGiay();
    return *this;
}

Time Time::operator++(int)
{
    Time t = *this;
    tongSoGiay++;
    ngayGioPhutGiay();
    return t;
}

Time Time::operator--()
{
    tongSoGiay--;
    ngayGioPhutGiay();
    return *this;
}

Time Time::operator--(int)
{
    Time t = *this;
    tongSoGiay--;
    ngayGioPhutGiay();
    return t;
}

int main()
{
    Time ThoiGian;
    Time ThoiGian2;
    int iOption;
    cout << "Menu:" << endl;
    cout << "0. Dung chuong trinh." << endl;
    cout << "1. Nhap thoi gian theo ham." << endl;
    cout << "2. Nhap thoi gian theo phep >>." << endl;
    cout << "3. Xuat thoi gian theo ham." << endl;
    cout << "4. Xuat thoi gian theo phep <<." << endl;
    cout << "5. Cong mot so nguyen vao thoi gian." << endl;
    cout << "6. Tru mot so nguyen vao thoi gian."<<endl;
    cout << "7. Cong hai thoi gain."<<endl;
    cout << "8. Tru hai thoi gain."<<endl;
    cout << "9. ++ giay."<<endl;
    cout << "10. -- giay."<<endl;
    cout << "11. Chuyen thoi gian ve ngay,gio,phut,giay."<<endl;
    do
    {
        cin >> iOption;
        switch (iOption)
        {
            case 0:
                exit;
            case 1:
                ThoiGian.nhap();
                break;
            case 2:
                cin>>ThoiGian;
                break;
            case 3:
                ThoiGian.xuat();
                break;
            case 4:
                cout<<ThoiGian;
                break;
            case 5:
                int tmp;
                cout<<"Nhap so giay can Cong :";
                cin>>tmp;
                ThoiGian= ThoiGian +tmp;
                break;
            case 6:
                cout<<"Nhap so giay can Tru :";
                cin>>tmp;
                ThoiGian= ThoiGian -tmp;
                break;
            case 7:
                {
                cout<<"Nhap them thoi gian can cong :";
                cin>>ThoiGian2;
                ThoiGian=ThoiGian+ThoiGian2;
                break;
                }
            case 8:
                cout<<"Nhap them thoi gian can tru :";
                cin>>ThoiGian2;
                ThoiGian=ThoiGian-ThoiGian2;
                break;
            case 9:
                ThoiGian++;
                break;
            case 10:
                ThoiGian--;
                break;
            case 11:
                ThoiGian.ngayGioPhutGiay();
                break;

        }
    } while (iOption<12 and iOption>=0);
    return 0;
}
