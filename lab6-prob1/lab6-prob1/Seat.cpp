#include <iostream>
#include "Seat.h"
#include "Weather.h"

Seat::Seat()
{
	name = "Seat";
	fuelCapacity = 50.0f;
	fuelConsumption = 11.0f;
	averageSpeedSunny = 110.0f;
	averageSpeedRain = 80.0f;
	averageSpeedSnow = 45.0f;
}

float Seat::GetSpeed(Weather w) const
{
	switch (w)
	{
		case Weather::Sunny: return averageSpeedSunny;
		case Weather::Rain: return averageSpeedRain;
		case Weather::Snow: return averageSpeedSnow;
	}
	return 0;
}

float Seat::GetFuelCapacity() const
{
	return fuelCapacity;
}

float Seat::GetFuelConsumption() const
{
	return fuelConsumption;
}

const char* Seat::GetName() const
{
	return name;
}