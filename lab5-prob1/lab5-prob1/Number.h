#pragma once
#include <iostream>

class Number {
private:
    char* value;
    int base;

    long long GetBase10Value() const;
    static char* ConvertToBase(long long val10, int base);

public:

    Number(const char* value, int base);
    Number(int val);//pentru n4

    //copy constructor, move constructor
    Number(const Number& other);
    Number(Number&& other);

    ~Number();

    //copy/move operators
    Number& operator=(const Number& other);
    Number& operator=(Number&& other);
    Number& operator=(int val);         //pt n1
    Number& operator=(const char* val); //pt n4

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

    char operator[](int index) const;

    //operatori aritmetici
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& other);

    //operatori relationali
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    //operator prefixat si postfixat
    Number& operator--();
    Number operator--(int);
};
