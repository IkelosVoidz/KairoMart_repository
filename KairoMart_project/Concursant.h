#pragma once


#ifndef CONCURSANT_H
#define CONCURSANT_H
#include<iostream>
#include "Vehicle.h"
#include "Personatge.h"

using namespace std;
class Concursant
{
public:
	Concursant();
	Concursant(const string& nom, int id);
	void Conduir();
	const string getNom() const;
	const int getId() const;
	const pair<int, int> getPosicio() const;
	void seleccionarVehicle(const Vehicle& vec);
	void seleccionarPersonatge(const Personatge& pers);

private:
	string nom;
	int id;
	pair<int, int> posicio;
	int voltesFetes;
	Vehicle vehicleSeleccionat;
	Personatge personatgeSeleccionat;
};

#endif


