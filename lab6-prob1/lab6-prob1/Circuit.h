#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
	float length;
	Weather weathercondition;

	Car* cars[100];
	int carscount;

	Car* finishedcars[100];
	float finishedtime[100];
	int finishedcount;

	Car* dnfcars[100];
	int dnfcount;

public:
	Circuit();
	~Circuit();

	void SetLength(float l);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};