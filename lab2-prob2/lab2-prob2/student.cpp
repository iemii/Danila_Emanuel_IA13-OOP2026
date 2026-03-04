#include "student.h"
#include <iostream>
#include <cstring>

void student::setname(const char* inputName)
{
	this->name = new char[strlen(inputName) + 1];
	memset(this->name, 0, strlen(inputName) + 1);
	memcpy(this->name, inputName, strlen(inputName));
}

const char* student::getname() const
{
	return this->name;
}

void student::setmate(float notamate)
{
	this->mate = notamate;
}

float student::getmate() const
{
	return this->mate;
}

void student::seteng(float notaeng)
{
	this->eng = notaeng;
}

float student::geteng() const
{
	return this->eng;
}

void student::setist(float notaist)
{
	this->ist = notaist;
}

float student::getist() const
{
	return this->ist;
}

float student::medie() const
{
	return (this->mate + this->ist + this->eng) / 3.0f;
}
