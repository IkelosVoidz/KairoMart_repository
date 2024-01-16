#include "Concursant.h"
Concursant::Concursant() {
	id = 0;
	nom = " ";
	posicio = Punt2D();
	voltesFetes = 0;
	personatgeSeleccionat = nullptr;
	vehicleSeleccionat = nullptr;
		
}
Concursant::Concursant(const string& _nom, int _id, int x , int y) {
	id = _id;
	nom = _nom;
	posicio = Punt2D(x,y);
	voltesFetes = 0;
	personatgeSeleccionat = nullptr;
	vehicleSeleccionat = nullptr;
}

Concursant::~Concursant()
{
	delete vehicleSeleccionat;
	delete personatgeSeleccionat;
}

void Concursant::Conduir(const Punt2D& dir)
{
	Punt2D newPos = vehicleSeleccionat->FesAccelerar(dir, posicio);

	if (newPos.es_igual(Punt2D())) {
		
		cout << "La Posicio es invalida, torna-ho a intentar" << endl;
		return;
	}
	else {
		posicio = newPos;

		//mirar si ha creuat de volta
	}
}

string Concursant::GetNom() const
{
	return nom;
}

int Concursant::GetId() const
{
	return id;
}

int Concursant::GetVoltesFetes() const
{
	return voltesFetes;
}

Punt2D Concursant::GetPosicio() const
{
	return posicio;
}

Vehicle* Concursant::GetVehicle() const
{
	return vehicleSeleccionat;
}

Personatge* Concursant::GetPersonatge() const
{
	return personatgeSeleccionat;
}

void Concursant::seleccionarVehicle(Vehicle* vec)
{
	vehicleSeleccionat = vec;
}

void Concursant::seleccionarPersonatge(Personatge* pers)
{
	personatgeSeleccionat = pers;
}
