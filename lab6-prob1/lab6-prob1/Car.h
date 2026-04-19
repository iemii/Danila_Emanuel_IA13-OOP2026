#pragma once
#include "Weather.h"
class Car
{
protected:
	float fuelCapacity;
	float fuelConsumption;
	float averageSpeedRain, averageSpeedSunny,averageSpeedSnow;
	const char* name;
public:
	virtual ~Car(){}
	virtual float GetSpeed(Weather w) const = 0;
	virtual float GetFuelCapacity() const  = 0;
	virtual float GetFuelConsumption() const = 0;
	virtual const char* GetName() const = 0;
};