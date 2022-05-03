#include <iostream>
#include <math.h>

using namespace std;

class   ToaDo
{
    private:
        double x,y;
    public:
        ~ToaDo();
        ToaDo(){};
        ToaDo(double,double);
        double GetX();
        double GetY();
        void SetX(double);
        void SetY(double);
};

class   TamGiac
{
    private:
        ToaDo A,B,C;
        double a,b,c; // 3 canh cua tam gaic
    public:
        void TinhDoDaiCacCanh();
        void Nhap();
        void Xuat();
        bool HopLe();
        void PhanLoai();
        double TinhChuVi();
        double TinhDienTich();
        ToaDo TamNgoaiTiep();
        ToaDo TamNoiTiep();
        TamGiac(){};
        ~TamGiac();
};

ToaDo:: ~ToaDo()
{
    this ->x=0;
    this ->y=0;
}

ToaDo::ToaDo(double x, double y) : x(x) , y(y) {}

double ToaDo::GetX()
{
   return(x);
}

double ToaDo::GetY()
{
   return(y);
}

void ToaDo::SetX(double t)
{
    x=t;
}

void ToaDo::SetY(double t)
{
    y=t;
}

void TamGiac::TinhDoDaiCacCanh()
{
    a=sqrt((B.GetX()-C.GetX())*(B.GetX()-C.GetX())+(B.GetY()-C.GetY())*(B.GetY()-C.GetY()));
    b=sqrt((A.GetX()-C.GetX())*(A.GetX()-C.GetX())+(A.GetY()-C.GetY())*(A.GetY()-C.GetY()));
    c=sqrt((B.GetX()-A.GetX())*(B.GetX()-A.GetX())+(B.GetY()-A.GetY())*(B.GetY()-A.GetY()));
}
void TamGiac::Nhap()
{
    int X,Y;
    cout<<"Nhap toa do diem A:";
    cin>>X>>Y;
    A = {X,Y};
    cout<<"Nhap toa do diem B:";
    cin>>X>>Y;
    B = {X,Y};
    cout<<"Nhap toa do diem C:";
    cin>>X>>Y;
    C = {X,Y};
    TinhDoDaiCacCanh();
    if (HopLe()==0) {
        cout<<"Tam Giac Khong Hop Le";
        exit(0);
    }
}

void TamGiac::Xuat()
{
    cout<<"Toa do diem A :"<< '(' << A.GetX() << ',' << A.GetY() << ')'<<endl;
    cout<<"Toa do diem B :"<< '(' << B.GetX() << ',' << B.GetY() << ')'<<endl;
    cout<<"Toa do diem C :"<< '(' << C.GetX() << ',' << C.GetY() << ')'<<endl;
    cout<<"Do Dai Canh a: "<< this -> a<<endl;
    cout<<"Do Dai Canh b: "<< this -> b<<endl;
    cout<<"Do Dai Canh c: "<< this -> c<<endl;
}

bool TamGiac::HopLe()
{
    if (a+b> c and b+c> a and c+a> b) return(1); //Tam Giac Hop Le
    return(0); //Tam Giac Khong Hop Le
}

void TamGiac::PhanLoai()
{
    if (a==b or b==c or c==a)
        if (a==b and b==c)
            cout<<"Day La Tam Giac Deu"<<endl;
        else if (a*a == b*b + c*c or b*b == a*a + c*c or c*c == b*b + a*a)
            cout<<"Day La Tam Giac Vuong Can"<<endl;
        else cout<<"Day La Tam Giac Can"<<endl;
    else if (a*a == b*b + c*c or b*b == a*a + c*c or c*c == b*b + a*a)
            cout<<"Day La Tam Giac Vuong"<<endl;
    else
        cout<<"Day La Tam Giac Thuong";
}

double TamGiac::TinhChuVi()
{
    return (a+b+c);
}

double TamGiac::TinhDienTich()
{
    double P=(a+b+c)/2;
    return( sqrt(P*(P-a)*(P-b)*(P-c)) );
}

ToaDo TamGiac::TamNoiTiep()
{
    ToaDo RES;
    RES.SetX((a*A.GetX()+b*B.GetX()+c*C.GetX())/(a+b+c));
    RES.SetY((a*A.GetY()+b*B.GetY()+c*C.GetY())/(a+b+c));
    return(RES);
}

ToaDo TamGiac::TamNgoaiTiep()
{
    double a,b,c,d,e,f,g;

    a = B.GetY() - A.GetY();
    b = A.GetX() - B.GetX();
    c = a*(A.GetX())+ b*(A.GetY());

    e = C.GetY() - B.GetY();
    f = B.GetX() - C.GetX();
    g = a*(B.GetX())+ b*(B.GetY());

    ToaDo tmp((A.GetX() + B.GetX())/2,(A.GetY() + B.GetY())/2);
    c = -b*(tmp.GetX()) + a*(tmp.GetY());
    double temp = a;
    a = -b;
    b = temp;

    ToaDo tmp2((B.GetX() + C.GetX())/2,(B.GetY() + C.GetY())/2);
    g = -f*(tmp2.GetX()) + e*(tmp2.GetY());
    temp = e;
    e = -f;
    f = temp;

    double tmp3 = a*f - e*b;
    ToaDo RES;
    RES.SetX((f*c - b*g)/tmp3);
    RES.SetY((a*g - e*c)/tmp3);
    return(RES);
}
TamGiac::~TamGiac()
{
    this -> a=0;
    this -> b=0;
    this -> c=0;
    A= {0,0};
    B= {0,0};
    C= {0,0};
}

int main()
{
    TamGiac TG;
    int iOption;
    cout << "Menu:" << endl;
    cout << "0. Dung chuong trinh." << endl;
    cout << "1. Nhap tam giac." << endl;
    cout << "2. Xuat thong tin tam giac." << endl;
    cout << "3. Xet loai tam giac." << endl;
    cout << "4. Tinh chu vi." << endl;
    cout << "5. Tinh dien tich." << endl;
    cout << "6. Tam duong tron noi tiep tam giac"<<endl;
    cout << "7. Tam duong tron ngoai tiep tam giac"<<endl;
    do
    {
        cin >> iOption;
        switch (iOption)
        {
        case 0:
            exit(0);
        case 1:
            TG.Nhap();
            break;
        case 2:
            TG.Xuat();
            break;
        case 3:
            TG.PhanLoai();
            break;
        case 4:
            cout << "Chu vi: " << TG.TinhChuVi() << endl;
            break;
        case 5:
            cout << "Dien tich: " << TG.TinhDienTich() << endl;
            break;
        case 6:
            {
            cout<<"Toa do tam duong tron noi tiep tam giac la :";
            ToaDo Tam1=TG.TamNoiTiep();
            cout<<Tam1.GetX()<<':';
            cout<<Tam1.GetY()<<endl;
            break;
            }
        case 7:
            cout<<"Toa do tam duong tron ngoai tiep tam giac la :";
            ToaDo Tam2=TG.TamNgoaiTiep();
            cout<<Tam2.GetX()<<':';
            cout<<Tam2.GetY()<<endl;
            break;
        }
    } while (iOption<8 and iOption>=0);
    return 0;
}
