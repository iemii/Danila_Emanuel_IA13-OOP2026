#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <cmath>

long long Number::GetBase10Value() const //conversia din string(baza curenta) in long long baza 10
{
    long long val10 = 0;
    long long p = 1;
    int len = strlen(this->value);

    for (int i = len - 1; i >= 0; i--) {
        int digitVal = 0;
        if (value[i] >= '0' && value[i] <= '9') {
            digitVal = value[i] - '0';
        }
        else if (value[i] >= 'A' && value[i] <= 'F') {
            digitVal = value[i] - 'A' + 10;
        }
        else if (value[i] >= 'a' && value[i] <= 'f') {
            digitVal = value[i] - 'a' + 10;
        }
        val10 += digitVal * p;
        p *= this->base;
    }
    return val10;
}

char* Number::ConvertToBase(long long val10, int base)//conversie din long long (baza10) in string (baza mea)
{
    if (val10 == 0)
    {
        char* zero = new char[2];
        zero[0] = '0';
        zero[1] = '\0';
        return zero;
    }

    char buffer[100];
    int index = 0;
    while (val10 > 0)
    {
        int rem = val10 % base;
        if (rem < 10)
            buffer[index++] = '0' + rem;
        else
            buffer[index++] = 'A' + (rem - 10);
        val10 /= base;
    }

    char* result = new char[index + 1];
    for (int i = 0; i < index; i++)
        result[i] = buffer[index - 1 - i];
    result[index] = '\0';
    return result;
}

Number::Number(const char* value, int base)
{
    this->base = base;
    this->value = new char[strlen(value) + 1];
    strcpy(this->value, value);
}

Number::Number(int val)
{
    this->base = 10;//baza default
    this->value = ConvertToBase(val, 10);
}


Number::Number(const Number& other) 
{
    this->base = other.base;
    this->value = new char[strlen(other.value) + 1];
    strcpy(this->value, other.value);
}

Number::Number(Number&& other) 
{
    this->base = other.base;
    this->value = other.value;
    other.value = nullptr;
}


Number::~Number()
{
    if (this->value != nullptr)
        delete[] this->value;
}


Number& Number::operator=(const Number& other)
{
    if (this != &other)
    {
        delete[] this->value;
        this->base = other.base;
        this->value = new char[strlen(other.value) + 1];
        strcpy(this->value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other)
{
    if (this != &other)
    {
        delete[] this->value;
        this->base = other.base;
        this->value = other.value;
        other.value = nullptr;
    }
    return *this;
}

Number& Number::operator=(int val)
{
    long long val10 = val;
    delete[] this->value;
    this->value = ConvertToBase(val10, this->base);//pastreaza baza curenta
    return *this;
}

Number& Number::operator=(const char* val)
{
    delete[] this->value;
    this->value = new char[strlen(val) + 1];
    strcpy(this->value, val);
    return *this;
}

void Number::SwitchBase(int newBase)
{
    if (this->base == newBase) return;
    long long val10 = GetBase10Value();
    delete[] this->value;
    this->value = ConvertToBase(val10, newBase);
    this->base = newBase;
}

void Number::Print() const
{
    std::cout << this->value << '\n';
}

int Number::GetDigitsCount() const
{
    return strlen(this->value);
}

int Number::GetBase() const
{
    return this->base;
}

char Number::operator[](int index) const
{
    if (index >= 0 && index < strlen(this->value))
        return this->value[index];
    return '\0';//"out of bounds"
}

Number operator+(const Number& n1, const Number& n2) 
{
    long long val1 = n1.GetBase10Value();
    long long val2 = n2.GetBase10Value();
    int maxBase = (n1.base > n2.base) ? n1.base : n2.base;

    Number result("0", maxBase);
    delete[] result.value;
    result.value = Number::ConvertToBase(val1 + val2, maxBase);
    return result;
}

Number operator-(const Number& n1, const Number& n2) 
{
    long long val1 = n1.GetBase10Value();
    long long val2 = n2.GetBase10Value();
    int maxBase = (n1.base > n2.base) ? n1.base : n2.base;

    long long diff = (val1 > val2) ? (val1 - val2) : 0; //prevenim rezultate negative pe string

    Number result("0", maxBase);
    delete[] result.value;
    result.value = Number::ConvertToBase(diff, maxBase);
    return result;
}

Number& Number::operator+=(const Number& other) 
{
    long long val1 = this->GetBase10Value();
    long long val2 = other.GetBase10Value();

    int targetBase = (this->base > other.base) ? this->base : other.base;
    this->base = targetBase;

    delete[] this->value;
    this->value = ConvertToBase(val1 + val2, targetBase);
    return *this;
}


bool Number::operator>(const Number& other) const
{
    return this->GetBase10Value() > other.GetBase10Value();
}
bool Number::operator<(const Number& other) const
{
    return this->GetBase10Value() < other.GetBase10Value();
}
bool Number::operator>=(const Number& other) const
{
    return this->GetBase10Value() >= other.GetBase10Value();
}
bool Number::operator<=(const Number& other) const
{
    return this->GetBase10Value() <= other.GetBase10Value();
}
bool Number::operator==(const Number& other) const
{
    return this->GetBase10Value() == other.GetBase10Value();
}
bool Number::operator!=(const Number& other) const
{
    return this->GetBase10Value() != other.GetBase10Value();
}

Number& Number::operator--()
{
    int len = strlen(this->value);
    if (len > 1)
    {
        char* newValue = new char[len];
        strcpy(newValue, this->value + 1);//mut poz la st
        delete[] this->value;
        this->value = newValue;
    }
    else if (len == 1)//daca mai e doar o cifra
    {
        this->value[0] = '0';
    }
    return *this;
}

Number Number::operator--(int)
{
    Number temp(*this);
    int len = strlen(this->value);
    if (len > 1) 
    {
        this->value[len - 1] = '\0'; //scurtam stringul
    }
    else if (len == 1)
    {
        this->value[0] = '0';
    }
    return temp;
}