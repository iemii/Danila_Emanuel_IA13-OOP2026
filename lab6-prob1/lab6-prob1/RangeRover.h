#pragma once
#include "Car.h"

class RangeRover :public Car
{
public:
	RangeRover();
	float GetSpeed(Weather w) const override;
	float GetFuelCapacity() const override;
	float GetFuelConsumption() const override;
	const char* GetName() const override;
};