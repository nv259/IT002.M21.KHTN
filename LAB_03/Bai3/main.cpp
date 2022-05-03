#include "Time.h"

int main()
{
    Time thoiGian;
    thoiGian.nhap();
    thoiGian.xuat();
    cout << '\n';

    cout << "Nhap gio, phut, giay: ";
    cin >> thoiGian;
    cout << thoiGian << '\n';

    Time temp(0, 0, 90);
    thoiGian = thoiGian + 60 - temp;
    cout << thoiGian << '\n';

    thoiGian++;
    cout << thoiGian << '\n';

    thoiGian--;
    cout << thoiGian << '\n';

    return 0;
}
