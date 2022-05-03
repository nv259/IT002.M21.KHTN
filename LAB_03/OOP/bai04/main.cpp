#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

#define ll long long

using namespace std;

class NhanVien
{
    private:
        string maNhanVien, hoVaTen;
        int soSanPham;
        ll luong;
    public:
        NhanVien();
        virtual ~NhanVien();

        void nhap();
        void xuat();
        void sinhNgauNhien();
        void tinhLuong(ll luongCanBan);
        void setMaNhanVien(string);
        void setHoVaTen(string);
        void setSoSanPham(int soSanPham);
        string getMaNhanVien();
        ll getLuong();
};

class Menu
{
    private:
        NhanVien arr[300];
        int soNhanVien;
        ll luongCanBan;
    public:
        Menu();
        Menu(const Menu &danhSach);
        virtual ~Menu();

        void ngauNhien();
        void nhap();
        void xuat();
        void capNhatThongTin(string maNhanVien);
        void tinhLuong();

        NhanVien luongCaoNhat();
        NhanVien luongThapNhat();
        void top10();
        void sapXepTheoLuong();
        void TimKiem(string maNhanVien);
};

Menu::Menu()
{
    //ctor
}

Menu::Menu(const Menu &danhSach)
{
    soNhanVien = danhSach.soNhanVien;
    luongCanBan = danhSach.luongCanBan;

    for (int i = 0; i < soNhanVien; i++)
        arr[i] = danhSach.arr[i];
}

Menu::~Menu()
{
    //dtor
}

void Menu::ngauNhien()
{
    soNhanVien = 300;
    for (int i = 0; i < 300; i++)
        arr[i].sinhNgauNhien();
}

void Menu::nhap()
{
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;

    cout << "Nhap so luong nhan vien: ";
    cin >> soNhanVien;

    for (int i = 0; i < soNhanVien; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i + 1 <<"\n";
        arr[i].nhap();
        arr[i].tinhLuong(luongCanBan);
    }
}

void Menu::xuat()
{
    cout << "DANH SACH NHAN VIEN: \n";
    cout << " \t  ID\t       Ho Va Ten     So San Pham        Luong\n";

    for (int i = 0; i < soNhanVien; i++)
    {
        cout << i << '\t';
        arr[i].xuat();
    }
}

bool compare(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.length(); i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

void Menu::capNhatThongTin(string maNhanVien)
{
    for (int i = 0; i < soNhanVien; i++)
    {
        if ((compare(arr[i].getMaNhanVien(), maNhanVien)))
        {
            arr[i].nhap();
            return;
        }
    }

    cout << "Khong ton tai ma nhan vien nay !";
}

void Menu::TimKiem(string maNhanVien)
{
    for (int i = 0; i < soNhanVien; i++)
    {
        if ((compare(arr[i].getMaNhanVien(), maNhanVien)))
        {
            arr[i].xuat();
            return;
        }
    }

    cout << "Khong ton tai ma nhan vien nay !";
}
void Menu::tinhLuong()
{
    for (int i = 0; i < soNhanVien; i++)
        arr[i].tinhLuong(luongCanBan);
}

NhanVien Menu::luongCaoNhat()
{
    int pos = -1;
    ll _max = -1;

    for (int i = 0; i < soNhanVien; i++)
    {
        if (_max < arr[i].getLuong())
        {
            pos = i;
            _max = arr[i].getLuong();
        }
    }

    return arr[pos];
}

NhanVien Menu::luongThapNhat()
{
    int pos = -1;
    ll _min = 1e18;

    for (int i = 0; i < soNhanVien; i++)
    {
        if (_min > arr[i].getLuong())
        {
            pos = i;
            _min = arr[i].getLuong();
        }
    }

    return arr[pos];
}

bool cmp(NhanVien fi, NhanVien se)
{
    return fi.getLuong() > se.getLuong();
}

void Menu::sapXepTheoLuong()
{
    sort(arr, arr + soNhanVien, cmp);
}

void Menu::top10()
{
    Menu temp(*this);

    temp.sapXepTheoLuong();
    for (int i = 0; i < min(10, soNhanVien); i++)
    {
        cout << i << "\t";
        temp.arr[i].xuat();
    }
}

NhanVien::NhanVien()
{
    //ctor
}

NhanVien::~NhanVien()
{
    //dtor
}

// ham random ho va ten
string gen_random_name(const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

// ham random ma nhan vien
string gen_random_id(const int len)
{
    static const char alphanum[] =
        "0123456789";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

void NhanVien::sinhNgauNhien()
{
    //srand(time(0));

    maNhanVien = gen_random_id(rand() % 7 + 1);
    hoVaTen = gen_random_name(rand() % 7 + 1);
    soSanPham = rand() % 100 + 1;
    luong = rand() % 1000000000;
}

void NhanVien::nhap()
{
    cout << "Ma nhan vien: ";
    cin >> maNhanVien;

    cin.ignore();
    cout << "Ho va ten: ";
    getline(cin, hoVaTen);

    cout << "So san pham: ";
    cin >> soSanPham;
}

void NhanVien::xuat()
{
    cout << maNhanVien << "\t\t" << hoVaTen << "\t\t" << soSanPham << "\t\t" << luong << "\n";
}

void NhanVien::tinhLuong(ll luongCanBan)
{
    luong = luongCanBan * 4500 + soSanPham * 175;
    luong *= 1000;
}

string NhanVien::getMaNhanVien()
{
    return maNhanVien;
}

void NhanVien::setHoVaTen(string hoVaTen)
{
    this->hoVaTen = hoVaTen;
}

void NhanVien::setMaNhanVien(string maNhanVien)
{
    this->maNhanVien = maNhanVien;
}

void NhanVien::setSoSanPham(int soSanPham)
{
    this->soSanPham = soSanPham;
}

ll NhanVien::getLuong()
{
    return luong;
}

int main()
{
    Menu danhSach;
    int iOption;
    cout << "Menu:" << endl;
    cout << "0. Dung chuong trinh." << endl;
    cout << "1. Nhap thong tin nhan vien." << endl;
    cout << "2. Khoi tao phuong phap tu dong." << endl;
    cout << "3. Xuat thong tin nhan vien." << endl;
    cout << "4. Tim theo ma nhan vien." << endl;
    cout << "5. Tinh luong cap nhat luong toan bo nhan vien." << endl;
    cout << "6. Tim nhan vien co luong cao nhat."<<endl;
    cout << "7. Tim nhan vien co luong thap nhat."<<endl;
    cout << "8. Top 10 nhan vien co luong cao nhat."<<endl;
    do
    {
        cin >> iOption;
        switch (iOption)
        {
            case 0:
                exit;
            case 1:
                danhSach.nhap();
                break;
            case 2:
                danhSach.ngauNhien();
                break;
            case 3:
                danhSach.xuat();
                break;
            case 4:
                {
                string Ma;
                cin>>Ma;
                danhSach.TimKiem(Ma);
                break;
                }
            case 5:
                {
                cout<<"Nhap ma nhan vien:";
                string Ma;
                cin>>Ma;
                danhSach.capNhatThongTin(Ma);
                break;
                }
            case 6:
                {
                NhanVien nhanVienXuatSac = danhSach.luongCaoNhat();
                nhanVienXuatSac.xuat();
                break;
                }
            case 7:
                {
                NhanVien nhanVienTe = danhSach.luongThapNhat();
                nhanVienTe.xuat();
                break;
                }
            case 8:
                danhSach.top10();

        }
    } while (iOption<9 and iOption>=0);
    return 0;
}
