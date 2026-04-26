// lab7_prob1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"

float operator"" _Kelvin(unsigned long long k)
{
    return static_cast<float>(k) - 273.15f;
}

float operator"" _Fahrenheit(unsigned long long f)
{
    return ((static_cast<float>(f) - 32.0f) * 5.0f / 9.0f);
}

bool findByExactMatch(int param, int nodeValue)//callback(pointer la functie) pentru find
{
    return param == nodeValue;
}

bool sortDescending(int a, int b) 
{
    return a > b;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << "\n";
    std::cout << "120 Fahrenheit in Celsius: " << b<<"\n";
    


    Tree<int> tree;
    TreeNode<int>* root = tree.add_node(nullptr, 10);
    TreeNode<int>* child1 = tree.add_node(root, 50);
    TreeNode<int>* child2 = tree.add_node(root, 20);
    TreeNode<int>* child3 = tree.add_node(root, 40);

    std::cout << "Inseram 30 la indexul 1 al radacinii...\n";
    tree.insert(root, 30, 1);

    std::cout << "Copiii radacinii: ";
    for (int i = 0; i < root->childrenCount; i++) std::cout << root->children[i]->value << " ";
    std::cout << "\n";

    tree.sort(root);
    std::cout << "Dupa sortarea default (<): ";
    for (int i = 0; i < root->childrenCount; i++) std::cout << root->children[i]->value << " ";
    std::cout << "\n";

    tree.sort(root, sortDescending);
    std::cout << "Dupa sortarea cu callback (>): ";
    for (int i = 0; i < root->childrenCount; i++) std::cout << root->children[i]->value << " ";
    std::cout << "\n";

    tree.add_node(child2, 21);
    tree.add_node(child2, 22);
    std::cout << "\nNumarul total de copii (descendenti) din tot arborele: " << tree.count(nullptr) << "\n";

    std::cout << "\nCautam nodul cu valoarea 22... ";
    TreeNode<int>* foundNode = tree.find(22, findByExactMatch);
    if (foundNode != nullptr) std::cout << "Gasit!\n";

    std::cout << "Stergem nodul cu valoarea 20 (care are 2 copii)...\n";
    tree.delete_node(child2);
    std::cout << "Numarul total de descendenti a ramas: " << tree.count(nullptr) << "\n";
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
