#include <iostream>
#include "Circuit.h"

//variabilele sunt create si primesc direct valoarea finala
Circuit::Circuit() : length(0), weathercondition(Weather::Sunny), carscount(0), finishedcount(0), dnfcount(0) {}

Circuit::~Circuit()
{
	for (int i = 0; i < carscount; i++)
		delete cars[i];
}

void Circuit::SetLength(float l)
{
	length = l;
}

void Circuit::SetWeather(Weather w)
{
	weathercondition = w;
}

void Circuit::AddCar(Car* car)
{
	if (carscount < 100)
		cars[carscount++] = car;
}

void Circuit::Race()
{
	finishedcount = 0;
	dnfcount = 0;

	for (int i = 0; i < carscount; i++)
	{
		float requiredfuel = (length / 100.0f) * cars[i]->GetFuelConsumption();

		if (requiredfuel <= cars[i]->GetFuelCapacity())//daca am suficienta benzina sa termin cursa
		{
			finishedcars[finishedcount] = cars[i];
			finishedtime[finishedcount] = length / cars[i]->GetSpeed(weathercondition);
			finishedcount++;
		}
		else
			dnfcars[dnfcount++] = cars[i];
	}

	//sortez masinile care au terminat in functie de timp
	for(int i=0;i<finishedcount-1;i++)
		for(int j=i+1;j<finishedcount;j++)
			if (finishedtime[i] >= finishedtime[j])
			{
				float temptime = finishedtime[i];
				finishedtime[i] = finishedtime[j];
				finishedtime[j] = temptime;

				//interschimb si pointerii catre masini pentru a pastra corespondenta
				Car* tempcar = finishedcars[i];
				finishedcars[i] = finishedcars[j];
				finishedcars[j] = tempcar;
			}
}

void Circuit::ShowFinalRanks()
{
	std::cout << "--- FINAL RANKS ---\n";
	for (int i = 0; i < finishedcount; i++)
		std::cout << i + 1 << ". " << finishedcars[i]->GetName() << " - Time:" << finishedtime[i] << " hours\n";
}

void Circuit::ShowWhoDidNotFinish()
{
	std::cout << "\n--- DID NOT FINISH (Out of fuel) ---\n";
	for (int i = 0; i < dnfcount; i++)
		std::cout << "- " << dnfcars[i]->GetName() << "\n";
}