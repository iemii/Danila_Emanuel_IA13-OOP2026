#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count < 10)
		numbers[count++] = x;
	else
		return false;
	return true;
}

void NumberList::Sort()
{
	int i, j,aux;
	for (i = 0; i < this->count-1; i++)
		for(j=i+1;j<this->count;j++)
			if (this->numbers[i] > this->numbers[j])
			{
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}

void NumberList::Print()
{
	int i;
	for (i = 0; i < this->count; i++)
		std::cout << this->numbers[i] << ' ';
	std::cout << std::endl;
}