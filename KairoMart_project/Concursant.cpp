#include "Concursant.h"
Concursant::Concursant() {
	id = 0;
	nom = " ";
	personatgeSelecionat = " ";
	vehicleSeleccionat = " ";
	posicio.first = 0;
	posicio.second = 0;
	voltesFetes = 0;
}
Concursant::Concursant(const string& _nom, int _id) {
	id = _id;
	nom = _nom;
	personatgeSelecionat = " ";
	vehicleSeleccionat = " ";
	posicio.first = 0;
	posicio.second = 0;
	voltesFetes = 0;
}
void Concursant::conduir() {
	//implementar logica per moure vehicle
}
const string Concursant::getNom() const { return nom; }
const int Concursant::getIdConcursant() const { return id; }
const pair<int, int> Concursant::getPosicioConcursant() const { return posicio; }
void Concursant::seleccionarVehicle(const string& nomVehicle) { vehicleSeleccionat = nomVehicle; }
void Concursant::seleccionarPersonatge(const string& personatge) {
	personatgeSelecionat = personatge;
}