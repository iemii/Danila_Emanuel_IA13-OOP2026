#include <iostream>
#include "Fiat.h"
#include "Weather.h"

Fiat::Fiat()
{
	name = "Fiat";
	fuelCapacity = 40.0f;
	fuelConsumption = 9.0f;
	averageSpeedSunny = 130.0f;
	averageSpeedRain = 90.0f;
	averageSpeedSnow = 50.0f;
}

float Fiat::GetSpeed(Weather w) const
{
	switch (w)
	{
		case Weather::Sunny: return averageSpeedSunny;
		case Weather::Rain: return averageSpeedRain;
		case Weather::Snow: return averageSpeedSnow;
	}
	return 0;
}

float Fiat::GetFuelCapacity() const
{
	return fuelCapacity;
}

float Fiat::GetFuelConsumption() const
{
	return fuelConsumption;
}

const char* Fiat::GetName() const
{
	return name;
}