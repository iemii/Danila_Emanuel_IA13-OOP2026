#pragma once
#include "Car.h"

class Volvo :public Car
{
public:
	Volvo();
	float GetSpeed(Weather w) const override;
	float GetFuelCapacity() const override;
	float GetFuelConsumption() const override;
	const char* GetName() const override;
};