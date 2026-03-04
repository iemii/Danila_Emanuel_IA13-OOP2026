// lab3-prob2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Canvas.h"
#include <iostream>

int main()
{

    Canvas desen(50, 20);

    desen.DrawRect(2, 2, 15, 8, '#');//un dreptunghi gol
    desen.FillRect(20, 2, 30, 8, '@');//un dreptunghi plin
    desen.DrawCircle(10, 14, 5, '*');//un cerc gol
    desen.FillCircle(30, 14, 4, '%');//un cerc plin
    desen.DrawLine(40, 2, 48, 18, '/');//linie oblic
    desen.Print();
    desen.Clear();

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
