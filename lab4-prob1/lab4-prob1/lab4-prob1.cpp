#include <iostream>
#include "Sort.h"

int main()
{
    std::cout << "1.test random constructor & bubbleSort (descr):" << std::endl;
    Sort s1(10, 1, 100); // 10 elemente intre 1 si 100
    s1.Print();
    s1.BubbleSort(false);
    s1.Print();
    std::cout << std::endl;

    std::cout << "2.test initializer list & insertSort (cresc):" << std::endl;
    Sort s2({ 50, 20, 10, 80, 40 });
    s2.Print();
    s2.InsertSort(true);
    s2.Print();
    std::cout << std::endl;

    std::cout << "3.test existing vector & quickSort (descr):" << std::endl;
    int v[] = { 15, 8, 99, 32, 7 };
    Sort s3(v, 5);
    s3.Print();
    s3.QuickSort(false);
    s3.Print();
    std::cout << std::endl;

    std::cout << "4.test variadic constructor & quickSort (cresc):" << std::endl;
    //primul parametru indica nr de elemente care urmeaza
    Sort s4(6, 100, 2, 45, 12, 8, 90);
    s4.Print();
    s4.QuickSort(true);
    s4.Print();
    std::cout << std::endl;

    std::cout << "5.test string constructor & info metode:" << std::endl;
    Sort s5("10,40,100,5,70");
    s5.Print();
    std::cout << "Numar total de elemente: " << s5.GetElementsCount() << std::endl;
    std::cout << "Elementul de la indexul 2: " << s5.GetElementFromIndex(2) << std::endl;

    return 0;
}