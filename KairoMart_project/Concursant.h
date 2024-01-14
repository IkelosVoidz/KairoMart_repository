#pragma once


#ifndef CONCURSANT_H
#define CONCURSANT_H
#include<iostream>
using namespace std;
class Concursant
{
public:
	Concursant();
	Concursant(const string& nom, int id);
	void conduir();
	const string getNom() const;
	const int getIdConcursant() const;
	const pair<int, int> getPosicioConcursant() const;
	void seleccionarVehicle(const string& nomVehicle);
	void seleccionarPersonatge(const string& personatge);


private:
	string nom;
	int id;
	pair<int, int> posicio;
	int voltesFetes;
	string vehicleSeleccionat, personatgeSelecionat;
};


#endif // !1


