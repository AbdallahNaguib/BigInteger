#include <iostream>
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H
using namespace std;
class big_integer{
    private:
        string num;
    public:
        bool isNeg=false;
        big_integer();
        big_integer(string);
        big_integer operator+(big_integer);
        big_integer operator-(big_integer);
        string getNum();
        void setNum(string);
        void check(string);
};



#endif // BIG_INTEGER_H
