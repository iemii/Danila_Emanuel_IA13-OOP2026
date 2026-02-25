#include "NumberList.h"
#include <iostream>

int main()
{
	int i;
	NumberList l;
	l.Init();

	l.Add(1);
	l.Add(30);
	l.Print();

	l.Sort();
	l.Print();

	for (i = 0; i < 10; i++)
		if (!l.Add(i * 10))
			std::cout << "Lista este plina";
	return 0;
}