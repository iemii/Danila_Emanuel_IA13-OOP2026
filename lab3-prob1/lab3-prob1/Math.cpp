#define _CRT_SECURE_NO_WARNINGS //nu ma lasa in pace tot imi da eroare sa folosesc strcpy_s strcat_s

#include "Math.h"
#include <iostream>
#include <cstdarg>//pentru functia cu nr variabil de parametri ...
#include <cstring>

int Math::Add(int x, int y)
{
    return x + y;
}

int Math::Add(int x, int y, int z)
{
    return x + y + z;
}

int Math::Add(double x, double y)
{
    return (int)(x + y);
}

int Math::Add(double x, double y, double z)
{
    return (int)(x + y + z);
}

int Math::Mul(int x, int y)
{
    return x * y;
}

int Math::Mul(int x, int y, int z)
{
    return x * y * z;
}

int Math::Mul(double x, double y)
{
    return (int)(x * y);
}

int Math::Mul(double x, double y, double z)
{
    return (int)(x * y * z);
}

int Math::Add(int count, ...)
{
    int s = 0;
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++)
    {
        s += va_arg(vl, int);//va_arg extrage urmatorul element din lista vl, stiind ca e int
    }
    va_end(vl);
    return s;
}

char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;
    int l = strlen(s1) + strlen(s2) + 1;
    char* s3 = new char[l];
    strcpy(s3, s1);
    strcat(s3, s2);
    return s3;
}