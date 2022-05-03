#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class PhanSo {
private:
    int tu, mau;
    int GCD(int a, int b);
public:
    PhanSo();
    PhanSo(int tu, int mau);
    void KhoiTaoTuDong();
    void RutGon();
    void Nhap();
    void Xuat();
    bool operator < (const PhanSo &other) const;
    bool operator > (const PhanSo &other) const;
    bool operator <= (const PhanSo &other) const;
    bool operator >= (const PhanSo &other) const;
    bool operator == (const PhanSo &other) const;
    PhanSo operator + (const PhanSo &other) const;
    friend operator - (const PhanSo &other);
    PhanSo operator - (const PhanSo &other) const;
    PhanSo operator * (const PhanSo &other) const;
    PhanSo operator / (const PhanSo &other) const;
    friend istream& operator >> (istream& is, PhanSo &a);
    friend ostream& operator << (ostream &os, PhanSo p);
    ~PhanSo();
};

PhanSo::PhanSo() {this->tu = 0, this->mau = 1;}
PhanSo::PhanSo(int tu, int mau) : tu(tu), mau(mau) {this->RutGon();}

int PhanSo::GCD(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return GCD(b, a % b);
}

void PhanSo::KhoiTaoTuDong() {
    srand(time(0));
	this -> tu = rand();
	this -> mau = rand();
}

void PhanSo::RutGon() {
    int gcd = GCD(this->tu, this->mau);
    this->tu /= gcd, this->mau /= gcd;

    if (this->tu == 0) this->mau = 1;
    else if (this->mau < 0) this->tu = -this->tu, this->mau = -this->mau;
}

void PhanSo::Nhap() {
    cout<<"Nhap Tu So :";
    cin >> this->tu ;
    cout<<"Nhap Mau So :";
    cin >> this->mau;
}

void PhanSo::Xuat() {
    cout << this->tu << '/' << this->mau<<endl;
}

bool PhanSo::operator < (const PhanSo &other) const {
    PhanSo A = *this, B = other;

    A.RutGon(); B.RutGon();
    return A.tu * B.mau < A.mau * B.tu;
}

bool PhanSo::operator > (const PhanSo &other) const {
    return other < *(this);
}

bool PhanSo::operator <= (const PhanSo &other) const {
    PhanSo A = *this, B = other;

    A.RutGon(); B.RutGon();
    return A.tu * B.mau <= A.mau * B.tu;
}

bool PhanSo::operator >= (const PhanSo &other) const {
    return other <= *(this);
}

bool PhanSo::operator == (const PhanSo &other) const {
    if (other < *(this) || other > *(this)) return false;
    return true;
}

PhanSo PhanSo::operator + (const PhanSo &other) const {
    int tu = this->tu * other.mau + this->mau * other.tu;
    int mau = this->mau * other.mau;

    PhanSo ans(tu, mau);
    return ans;
}

PhanSo PhanSo::operator - (const PhanSo &other) const {
    int tu = this->tu * other.mau - this->mau * other.tu;
    int mau = this->mau * other.mau;

    PhanSo ans(tu, mau);
    return ans;
}

PhanSo PhanSo::operator * (const PhanSo &other) const {
    int tu = this->tu * other.tu;
    int mau = this->mau * other.mau;

    PhanSo ans(tu, mau);
    return ans;
}

PhanSo PhanSo::operator / (const PhanSo &other) const {
    int tu = this->tu * other.mau;
    int mau = this->mau * other.tu;

    PhanSo ans(tu, mau);
    return ans;
}

istream& operator >> (istream &is, PhanSo &p){
    is >> p.tu >> p.mau;
    while (!p.mau){
        cout << "Nhap lai mau so: "; //nhập lại mẫu số nếu mẫu số = 0
        is >> p.mau;
        }
    p.RutGon();
    return is;
}

ostream& operator << (ostream &os, PhanSo p){
    os << p.tu;
    if (p.tu != 0 && p.mau != 1)
        os << "/" << p.mau;
    return os;
}

PhanSo::~PhanSo() {this->tu = 0, this->mau = 1;}

int main()
{
    PhanSo p1, p2;
    int iOption;
    /*PhanSo a(2,3),b(1,4),c(3,1),d(2,5);
    a = b* -c;
    c = (b+2)* 2/a;
    d = a/3 + (b*c-2)/5;*/
    do
    {
        cout << "Menu:" << endl;
        cout << "0. Dung chuong trinh." << endl;
        cout << "1. Nhap phan so p1." << endl;
        cout << "2. Nhap phan so p2." << endl;
        cout << "3. Xuat phan so p1." << endl;
        cout << "4. Xuat phan so p2." << endl;
        cout << "5. Cong hai phan so." << endl;
        cout << "6. Tru hai phan so." << endl;
        cout << "7. Nhap hai phan so." << endl;
        cout << "8. Chia hai phan so." << endl;
        cout << "9. Khoi tao tu dong phan so p1" <<endl;
        cout << "10. Khoi tao tu dong phan so p2" <<endl;
        cout << "11. So Sanh hai phan so p1 va p2" <<endl;
        cin >> iOption;
        switch (iOption)
        {
            case 0:
                exit(0);
            case 1:
                cin>>p1;
                break;
            case 2:
                cin>>p2;
                break;
            case 3:
                cout<<p1<<endl;
                break;
            case 4:
                cout<<p2<<endl;
                break;
            case 5:
                cout<<(p1 + p2); cout << '\n';
                break;
            case 6:
                cout<<(p1 - p2); cout << '\n';
                break;
            case 7:
                cout<<(p1 * p2); cout << '\n';
                break;
            case 8:
                cout<<(p1 / p2); cout << '\n';
                break;
            case 9:
                p1.KhoiTaoTuDong();
                break;
            case 10:
                p2.KhoiTaoTuDong();
                break;
            case 11:
                if (p1 < p2) cout<<"p1 < p2"<<endl;
                else if (p1 > p2) cout<<"p1 > p2"<<endl;
                else if (p1 == p2) cout<<"p1 = p2"<<endl;
                break;
        }
    } while (iOption<12 and iOption>=0);
    return 0;
}
