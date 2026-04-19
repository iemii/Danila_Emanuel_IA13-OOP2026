#pragma once
#include "Car.h"

class Seat :public Car
{
public:
	Seat();
	float GetSpeed(Weather w) const override;
	float GetFuelCapacity() const override;
	float GetFuelConsumption() const override;
	const char* GetName() const override;
};