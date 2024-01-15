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
Vehicle::Vehicle(const string& nom, int maxVel, int adherenci, int resistencia) {
	nomVehicle = nom;

	adherencia = adherenci;
	velocitatMaxima = maxVel;
	velocitatActual = 0;
	resistenciaXoc = resistencia;
	direccio = make_pair(0, 0);
	penalitzatPerXoc = false;
}
void Vehicle::FesAccelerar() {
	vehicleBehvior.accelerar();
}
void Vehicle::CambiarAccelerar(ComportamentAccelerar tipusVehile) {
	vehicleBehvior = tipusVehile;
	FesAccelerar();

}
const string Vehicle::getNomVehicle() const {
		return nomVehicle;
}