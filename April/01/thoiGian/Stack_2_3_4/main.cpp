#include "Stack.h"
#include <iostream>

using namespace std;

void integer_factor()
{
    int n;

    cout << "Nhap so nguyen N <= 10^6: ";
    cin >> n;

    Stack int_factor;
    int divident = 2;

    while (n != 1)
    {
        if (n % divident == 0)
        {
            int_factor.push(divident);
            n /= divident;
            continue;
        }

        divident++;
    }

    cout << int_factor.top();
    int_factor.pop();
    while (int_factor.isEmpty() == false)
    {
        cout << " * " << int_factor.top();
        int_factor.pop();
    }
}

void convert(int n, int base)
{
    Stack storage;
    cout << "So " << n << " chuyen sang he " << base << " la: ";

    while (n)
    {
        storage.push(n % base);
        n /= base;
    }

    while (!storage.isEmpty())
    {
        if (storage.top() < 10)
            cout << storage.top();
        else
            cout << (char) ('A' + storage.top() - 10);

        storage.pop();
    }
    cout << '\n';
}

void number_conversion()
{
    int n;
    cout << "Nhap so nguyen duong N <= 10^9: ";
    cin >> n;

    convert(n, 16);
    convert(n, 8);
    convert(n, 2);
}

int main()
{
    integer_factor(); // 3rd
    number_conversion(); // 4th

    return 0;
}
