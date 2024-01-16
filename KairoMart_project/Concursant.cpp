#include "Concursant.h"
#include "Cursa.h"
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
	Cursa* instanciaCursa = Cursa::GetInstance();

	if (newPos.es_igual(Punt2D())) {
		
		cout << "La Posicio es invalida, torna-ho a intentar" << endl;
		return;
	}
	else {
		// mirar si ha creuat la meta i sumar/restar les voltes actuals en conseqüència.
		vector<Punt2D> meta = instanciaCursa->GetMeta();

		if (newPos.get_x() >= meta[0].get_x() and posicio.get_x() < meta[0].get_x()) {
			voltesFetes++;
		}
		else if (newPos.get_x() <= meta[0].get_x() and posicio.get_x() > meta[0].get_x()) {
			voltesFetes--;
		}

		// mirar si ha acabat la carrera
		if (voltesFetes >= instanciaCursa.getVoltes()) {
			cout << "He acabado la carrera hehe";
		}

		posicio = newPos;
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
