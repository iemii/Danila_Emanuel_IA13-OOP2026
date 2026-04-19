#include <iostream>
#include "BMW.h"
#include "Weather.h"

BMW::BMW()
{
	name = "BMW";
	fuelCapacity = 70.0f;
	fuelConsumption = 7.0f;
	averageSpeedSunny = 230.0f;
	averageSpeedRain = 130.0f;
	averageSpeedSnow = 70.0f;
}

float BMW::GetSpeed(Weather w) const
{
	switch (w)
	{
		case Weather::Sunny: return averageSpeedSunny;
		case Weather::Rain: return averageSpeedRain;
		case Weather::Snow: return averageSpeedSnow;
	}
	return 0;
}

float BMW::GetFuelCapacity() const
{
	return fuelCapacity;
}

float BMW::GetFuelConsumption() const
{
	return fuelConsumption;
}

const char* BMW::GetName() const
{
	return name;
}