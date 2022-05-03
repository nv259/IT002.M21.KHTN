#include <iostream>
#include <iomanip>
#include "CDate.h"
#define ll long long

using namespace std;

double interest(double deposit_amount, double interest_rate, int day)
{
    return deposit_amount * (interest_rate / 100.0) * day / 360.0;
}

void notify(double money_amount)
{
    if (money_amount >= (ll) 1e9)
    {
        ll temp = (ll) money_amount / (ll) 1e9;
        cout << temp << " ty ";
        money_amount -= temp * (ll) 1e9;
    }

    if (money_amount >= (ll) 1e6)
    {
        ll temp = (ll) money_amount / (ll) 1e6;
        cout << temp << " trieu ";
        money_amount -= temp * (ll) 1e6;
    }

    if (money_amount >= (ll) 1e3)
    {
        ll temp = (ll) money_amount / (ll) 1e3;
        cout << temp << " nghin ";
        money_amount -= temp * (ll) 1e3;
    }
    cout << money_amount << " vnd\n";
}

int main()
{
    double interest_rate, deposit_amount;
    CDate fi, se;
    cout << "NHAP NGAY GUI TIEN: \n";
    cin >> fi;
    fi.standardize();
    cout << "==> " << fi << '\n';

    cout << "---Nhap lai suat %(tren nam): ";
    cin >> interest_rate;
    cout << "\n\t\t DON VI TIEN GUI NGAN HANG !\n";
    cout << "\t1.Nghin dong";
    cout << "\t2.Trieu dong";
    cout << "\t3.Ty dong\n";
    cout << "---Nhap option: ";
    int option1;
    cin >> option1;
    cout << "NHAP SO TIEN GUI: ";
    cin >> deposit_amount;
    cout << "==> " << deposit_amount << " ";

    switch (option1)
    {
        case 1:
            cout << "nghin";
            deposit_amount *= 1000;
            break;
        case 2:
            cout << "trieu";
            deposit_amount *= 1000000;
            break;
        case 3:
            cout << "ty";
            deposit_amount *= 1000000000;
            break;
    }

    cout << "\nCHUONG TRINH TINH LAI SUAT TIEN GUI NGAN HANG !\n";

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

        cout << fixed;
        cout << setprecision(5);
        cout << "SO TIEN LAI\n ";
        notify(interest(deposit_amount, interest_rate, day));
        cout << "TONG SO TIEN NHAN DUOC\n ";
        notify(deposit_amount + interest(deposit_amount, interest_rate, day));
    }
    else
    {
        cout << "---NHAP NGAY NHAN TIEN: \n";
        cin >> se;
        se.standardize();
        cout << "==> " << se << '\n';
        int day = (se - fi).getSumDays();
        cout << fixed;
        cout << setprecision(5);

        cout << "SO TIEN LAI\n";
        notify(interest(deposit_amount, interest_rate, day));
        cout << "TONG SO TIEN NHAN DUOC\n ";
        notify(deposit_amount + interest(deposit_amount, interest_rate, day));
    }

    return 0;
}
