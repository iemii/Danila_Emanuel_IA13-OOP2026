#include <iostream>
#include "Volvo.h"
#include "Weather.h"

Volvo::Volvo()
{
	name = "Volvo";
	fuelCapacity = 60.0f;
	fuelConsumption = 6.7f;
	averageSpeedSunny = 210.0f;
	averageSpeedRain = 130.0f;
	averageSpeedSnow = 70.0f;
}

float Volvo::GetSpeed(Weather w) const
{
	switch (w)
	{
		case Weather::Rain: return averageSpeedRain;
		case Weather::Sunny: return averageSpeedSunny;
		case Weather::Snow: return averageSpeedSnow;
	}
	return 0;
}

float Volvo::GetFuelCapacity() const
{
	return fuelCapacity;
}

float Volvo::GetFuelConsumption() const
{
	return fuelConsumption;
}

const char* Volvo::GetName() const
{
	return name;
}