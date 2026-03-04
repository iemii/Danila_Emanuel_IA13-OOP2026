#include "functii.h"
#include <cstring>

int comparename(const student& s1, const student& s2)
{
	int res = strcmp(s1.getname(), s2.getname());
	if (res == 0)
		return 0;
	if (res > 0)
		return 1;
	else
		return -1;
}

int comparemate(const student& s1, const student& s2)
{
	if (s1.getmate() == s2.getmate())
		return 0;
	else
		if (s1.getmate() < s2.getmate())
			return -1;
		else
			return 1;
}

int compareeng(const student& s1, const student& s2)
{
	if (s1.geteng() == s2.geteng())
		return 0;
	else
		if (s1.geteng() < s2.geteng())
			return -1;
		else
			return 1;
}

int compareist(const student& s1, const student& s2)
{
	if (s1.getist() == s2.getist())
		return 0;
	else
		if (s1.getist() < s2.getist())
			return -1;
		else
			return 1;
}

int comparemedie(const student& s1, const student& s2)
{
	float m1 = s1.medie();
	float m2 = s2.medie();
	if (m1 == m2)
		return 0;
	if (m1 > m2)
		return 1;
	else
		return 0;
}
