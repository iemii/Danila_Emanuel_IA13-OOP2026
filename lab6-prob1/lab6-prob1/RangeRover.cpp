#include <iostream>
#include "RangeRover.h"
#include "Weather.h"

RangeRover::RangeRover()
{
	name = "RangeRover";
	fuelCapacity = 70.0f;
	fuelConsumption = 11.0f;
	averageSpeedSunny = 140.0f;
	averageSpeedRain = 120.0f;
	averageSpeedSnow = 90.0f;
}

float RangeRover::GetSpeed(Weather w) const
{
	switch (w)
	{
	case Weather::Sunny: return averageSpeedSunny;
	case Weather::Rain: return averageSpeedRain;
	case Weather::Snow: return averageSpeedSnow;
	}
	return 0;
}

float RangeRover::GetFuelCapacity() const
{
	return fuelCapacity;
}

float RangeRover::GetFuelConsumption() const
{
	return fuelConsumption;
}

const char* RangeRover::GetName() const
{
	return name;
}