#include "Vehicle.h"

Vehicle::Vehicle() {

	nomVehicle = " ";

	adherencia = 0;
	velocitatMaxima = 0;
	velocitatActual = 0;
	resistenciaXoc = 0;
	direccio = make_pair(0, 0);
	penalitzatPerXoc = false;

}
Vehicle::Vehicle(const string& nom, int maxVel, int adherenci) {
	nomVehicle = nom;

	adherencia = adherenci;
	velocitatMaxima = maxVel;
	velocitatActual = 0;
	resistenciaXoc = 0;
	direccio = make_pair(0, 0);
	penalitzatPerXoc = false;
}
void Vehicle::FesAccelerar() {
}
void Vehicle::CanviarAccelerar(VehicleBehavior tipusVehile) {

}
const string Vehicle::getNomVehicle() const {
		return nomVehicle;
}