#include <iostream>
#include <iomanip>
#include "CDate.h"
#define ll long long

using namespace std;

double interest(double deposit_amount, double interest_rate, int day)
{
    return deposit_amount * (interest_rate / 100.0) * day / 360.0;
}

int main()
{
    double interest_rate, deposit_amount;
    CDate fi, se;
    cout << "Ngay gui tien: \n";
    cin >> fi;
    fi.standardize();
    cout << fi << '\n';

    cout << "---Nhap lai suat %(tren nam): ";
    cin >> interest_rate;
    cout << "---Nhap so tien gui: ";
    cin >> deposit_amount;

    cout << "TINH LAI SUAT TIEN GUI NGAN HANG !\n";

    cout << "\t1. Nhan tien sau N ngay\n";
    cout << "\t2. Nhan tien vao ngay (mm/dd/yy)\n";

    cout << "---Nhap option: ";

    int option2;
    cin >> option2;

    if (option2 == 1)
    {
        int day;
        cout << "---Nhap so ngay gui: ";
        cin >> day;

        cout << "So tien lai: " << interest(deposit_amount, interest_rate, day) << '\n';
        cout << "*Tong so tien nhan duoc la: " << deposit_amount + interest(deposit_amount, interest_rate, day) << '\n';
    }
    else
    {
        cout << "---Nhap ngay nhan tien: \n";
        cin >> se;
        se.standardize();
        int day = (se - fi).getSumDays();
        cout << fixed;
        cout << setprecision(5);
        cout << "So tien lai: " << interest(deposit_amount, interest_rate, day) << '\n';
        cout << "*Tong so tien nhan duoc la: " << deposit_amount + interest(deposit_amount, interest_rate, day) << '\n';
    }

    return 0;
}
