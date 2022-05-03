#include "Data.h"

using namespace std;

int main()
{
    Data danhSach;
    cin >> danhSach;
    cout << "\n---\n";
    cout << "MSSV\tHO VA TEN\tDIA CHI\tTSTCTL\tDTBTL\tLUAN VAN\tDLV\n";
    cout << danhSach << '\n';
    cout << "So luong sinh vien du dieu kien tot nghiep: " << danhSach.totNghiep() << '\n';
    SinhVien thuKhoa = danhSach.thuKhoa();
    cout << "Thong tin thu khoa: \n" << thuKhoa;
    return 0;
}
