#include "String.h"

String::String()
{
    for (int i = 0; i < 500; i++)
        str[i] = '\0';
}

String::~String()
{
    //dtor
}

String::String(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        this->str[i] = str[i];
}

String::String(const String &str)
{
    for (int i = 0; str.str[i] != '\0'; i++)
        this->str[i] = str.str[i];
}

int String::length()
{
    for (int i = 0; ; i++)
        if (str[i] == '\0') return i;
}

String String::operator+(const String &o)
{
    int n = length();
    String result;
    for (int i = 0; i < n; i++)
      result.str[i] = str[i];

    for (int i = 0; o.str[i] != '\0'; i++)
        result.str[n + i] = o.str[i];
    return result;
}

void String::reverse()
{
    int n = length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

istream& operator>> (istream &inp, String &str)
{
    inp >> str.str;
}

ostream& operator<< (ostream &out, String &str)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
        out << (char) str.str[i];
}
