#pragma once


#ifndef CONCURSANT_H
#define CONCURSANT_H
#include<iostream>
#include "Vehicle.h"
#include "Personatge.h"
#include "Punt2D.h"
#include <memory>
#include "Accelerar.h"
#include "AccelerarGirant.h"
#include "AccelerarDerrepant.h"

using namespace std;
class Concursant
{
public:
	Concursant();
	Concursant(const string& n);
	Concursant(const string& _nom, int _id, const Punt2D& pos);
	Concursant(const Concursant& other);
	Concursant& operator=(const Concursant& other);
	~Concursant();
	void Conduir(const Punt2D& dir);
	string GetNom() const;
	int GetId() const;
	int GetVoltesFetes() const;
	Punt2D GetPosicio() const;
	shared_ptr<Vehicle> GetVehicle() const;
	shared_ptr<Personatge> GetPersonatge() const;
	void SeleccionarVehicle(shared_ptr<Vehicle> vec);
	void SeleccionarPersonatge(shared_ptr<Personatge> pers);
	bool EstaPenalitzat();
	

private:
	string nom;
	int id;
	Punt2D posicio;
	int voltesFetes;
	shared_ptr<Vehicle> vehicleSeleccionat;
	shared_ptr<Personatge> personatgeSeleccionat;
	shared_ptr<Accelerar> AccRecte;
	shared_ptr<AccelerarDerrepant> AccDerr;
	shared_ptr<AccelerarGirant> AccGir;
};

#endif


