#include "Concursant.h"
Concursant::Concursant() {
	id = 0;
	nom = " ";
	posicio.first = 0;
	posicio.second = 0;
	voltesFetes = 0;
}
Concursant::Concursant(const string& _nom, int _id) {
	id = _id;
	nom = _nom;
	posicio.first = 0;
	posicio.second = 0;
	voltesFetes = 0;
}

void Concursant::Conduir()
{

}

const string Concursant::getNom() const
{
	return nom;
}

const int Concursant::getId() const
{
	return id;
}

const pair<int, int> Concursant::getPosicio() const
{
	return posicio;
}

void Concursant::seleccionarVehicle(const Vehicle& vec)
{
	vehicleSeleccionat = vec;
}

void Concursant::seleccionarPersonatge(const Personatge& pers)
{
	personatgeSeleccionat = pers;
}