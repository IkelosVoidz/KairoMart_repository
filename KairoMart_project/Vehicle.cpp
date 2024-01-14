#include "Vehicle.h"
Vehicle::Vehicle() {
	vehicle = " ";
	id = 0;
	adherencia = 0;
	velocitatMaxima = 0;
	velocitatActual = 0;
	resistenciaXoc = 0;
}
Vehicle::Vehicle(int _id, string& _vehicle, double _maxVel, double _adherencia) {
	id = _id;
	vehicle = _vehicle;
	adherencia = _adherencia;
	velocitatMaxima = _maxVel;
	velocitatActual = 0;
	resistenciaXoc = 0;
}


void Vehicle::accelerar(double increment) { velocitatActual += increment; }
void Vehicle::frenar(double decrement) { if (velocitatActual > 0) { velocitatActual -= decrement; } else { velocitatActual = 0; } }
void Vehicle::girar(double graus) {
	//no ho fem servir de moment
}
void Vehicle::assignarAdaptacio(int adaptacio) {
	float reduccio = adaptacio * 0.2;
	velocitatMaxima -= reduccio;
}
const int Vehicle::getIdVehicle() const {
	return id;
}