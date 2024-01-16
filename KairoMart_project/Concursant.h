#pragma once


#ifndef CONCURSANT_H
#define CONCURSANT_H
#include<iostream>
#include "Vehicle.h"
#include "Personatge.h"
#include "Punt2D.h"

using namespace std;
class Concursant
{
public:
	Concursant();
	Concursant(const string& nom, int id, int x, int y);
	~Concursant();
	void Conduir(const Punt2D& dir);
	string GetNom() const;
	int GetId() const;
	int GetVoltesFetes() const;
	Punt2D GetPosicio() const;
	void seleccionarVehicle(Vehicle* vec);
	void seleccionarPersonatge(Personatge* pers);

private:
	string nom;
	int id;
	Punt2D posicio;
	int voltesFetes;
	Vehicle* vehicleSeleccionat;
	Personatge* personatgeSeleccionat;
};

#endif


