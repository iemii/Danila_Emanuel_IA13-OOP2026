#pragma once
#include "Car.h"

class Fiat :public Car
{
public:
	Fiat();
	float GetSpeed(Weather w) const override;
	float GetFuelCapacity() const override;
	float GetFuelConsumption() const override;
	const char* GetName() const override;
};