#pragma once
#include <string>

class student
{
public:
	char* name;
	float mate, eng, ist;
	void setname(const char* name);
	const char* getname() const;//marcat const pt a putea fi apelat din functii
	void setmate(float mate);
	float getmate() const;
	void seteng(float eng);
	float geteng() const;
	void setist(float ist);
	float getist() const;
	float medie() const;
};