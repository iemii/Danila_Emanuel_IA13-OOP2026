#include "Sort.h"
#include <iostream>
#include <cstdlib>//pentru rand() si srand()
#include <ctime>//pentru time()
#include <cstdarg>//[entru va_list

Sort::Sort(int count, int min, int max)
{
	this->count = count;
	this->a = new int[count];
	srand((unsigned int)time(NULL));//generator de numere random
	for (int i = 0; i < count; i++)
		this->a[i] = min + rand() % (max - min + 1);//generam numar in intervalul min max
}

Sort::Sort(std::initializer_list<int> list)
{
	this->count = (int)list.size();
	this->a = new int[this->count];
	int i = 0;
	for (int element : list)
		this->a[i++] = element;
}

Sort::Sort(int* v, int count)
{
	this->count = count;
	this->a = new int[count];
	for (int i = 0; i < count; i++)
		this->a[i] = v[i];
}

Sort::Sort(int count, ...)
{
	this->count = count;
	this->a = new int[count];
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
		this->a[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(const char* string)
{
	this->count = 1;
	for (int i = 0; string[i]; i++)
		if (string[i] == ',')
			this->count++;
	this->a = new int[this->count];
	int k = 0;
	int nr = 0;
	for (int i = 0; string[i]; i++)
	{
		if (string[i] == ',')
		{
			this->a[k++] = nr;
			nr = 0;
		}
		else
			nr = nr * 10 + (string[i] - '0');
	}
	this->a[k] = nr;
}

Sort::~Sort()
{
	delete[] this->a;
}


void Sort::InsertSort(bool ascendent)
{
	int i, j, nr;
	for (i = 0; i < count; i++)
	{
		nr = a[i];
		j = i - 1;
		if (ascendent)
		{
			while (j >= 0 && a[j] > nr)
			{
				a[j + 1] = a[j];
				j--;
			}
		}
		else
			while (j >= 0 && a[j] < nr)
			{
				a[j + 1] = a[j];
				j--;
			}
		a[j + 1] = nr;
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j;
	for(i=0;i<count-1;i++)
		for (j = 0; j < count - i - 1; j++)
		{
			bool cond = ascendent ? (a[j] > a[j + 1]) : (a[j] < a[j + 1]);
			if (cond)
			{
				int aux = a[j];
				a[j] = a[j + 1];
				a[j + 1] = aux;
			}
		}
}

int Sort::Partition(int low, int high, bool ascendent)
{
	int pivot = a[high];
	int i = (low - 1);

	for (int j = low; j < high; j++)
	{
		bool cond = ascendent ? (a[j] < pivot) : (a[j] > pivot);
		if (cond)
		{
			i++;
			int aux = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
	}
	int aux = a[i + 1];
	a[i + 1] = a[high];
	a[high] = aux;
	return(i + 1);
}

void Sort::QuickSortHelp(int low, int high, bool ascendent)
{
	if (low < high)
	{
		int p = Partition(low, high, ascendent);
		QuickSortHelp(low, p - 1, ascendent);
		QuickSortHelp(p + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortHelp(0, count - 1, ascendent);
}

void Sort::Print()
{
	for (int i = 0; i < count; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

int Sort::GetElementsCount()
{
	return count;
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < count)
		return a[index];
	return -1;
}