#pragma once
#include <initializer_list>

class Sort
{
private:
	int* a;
	int count;

	void QuickSortHelp(int low, int high, bool ascendent);
	int Partition(int low, int high, bool ascendent);

public:
	Sort(int count, int min, int max);//constructor cu valori random
	Sort(std::initializer_list<int> list);//din initializer list
	Sort(int* v, int count);//vector existent
	Sort(int count, ...);//parametri variadici
	Sort(const char* string);//dintr un string
	~Sort();//destructor

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);
};