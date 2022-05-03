#ifndef STRING_H
#define STRING_H
#include <iostream>

using namespace std;

class String
{
    private:
        char str[500];
    public:
        String();
        virtual ~String();
        String(char *str);
        String(const String &str);

        int length();

        String operator+ (const String &o);

        void reverse();
        friend istream &operator >> (istream &inp, String &str);
        friend ostream &operator << (ostream &out, String &str);
};


#endif // STRING_H
