// lab3-prob1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Math.h"

int main()
{
    std::cout << "add int,int: " << Math::Add(5, 10) << std::endl;
    std::cout << "add int,int,int: " << Math::Add(5, 15, 30) << std::endl;
    std::cout << "add double,double: " << Math::Add(2.5, 4.4) << std::endl;
    std::cout << "add double,double,double: " << Math::Add(1.75, 10.75, 4.45) << std::endl;

    std::cout << "mul int,int: " << Math::Mul(5, 5) << std::endl;
    std::cout << "mul int,int,int: " << Math::Mul(5, 5, 5) << std::endl;
    std::cout << "mul double,double: " << Math::Mul(2.5, 1.25) << std::endl;
    std::cout << "mul double,double,double: " << Math::Mul(12.5, 2.75, 3.33) << std::endl;

    std::cout << "Add(5 numere:1,2,3,4,5): " << Math::Add(5, 1, 2, 3, 4, 5) << std::endl;

    const char* s1 = "Hello ";
    const char* s2 = "World!";
    char* s3 = Math::Add(s1, s2);
    if (s3 != nullptr)
    {
        std::cout << s3 << std::endl;
        delete[] s3;//sterg memoria alocata dinamic
    }

    //cazul nullptr
    char* nulls3 = Math::Add(s1, nullptr);
    if (nulls3 == nullptr)
    {
        std::cout << "ok";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
