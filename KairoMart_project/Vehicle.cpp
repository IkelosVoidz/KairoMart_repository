#include "Vehicle.h"
#include "Cursa.h"

Vehicle::Vehicle() {

	nomVehicle = " ";

	adherencia = 0;
	velocitatMaxima = 0;
	velocitatActual = 0;
	resistenciaXoc = 0;
	direccio = Punt2D();
	penalitzatPerXoc = false;
	vehicleBehaviour = nullptr;

}
Vehicle::Vehicle(const string& nom, int maxVel, int adherenci, int resistencia , int dirX , int dirY) {
	nomVehicle = nom;
	adherencia = adherenci;
	velocitatMaxima = maxVel;
	velocitatActual = 0;
	resistenciaXoc = resistencia;
	direccio = Punt2D(dirX, dirY);
	penalitzatPerXoc = false;
	vehicleBehaviour = nullptr;
}

Punt2D Vehicle::FesAccelerar(const Punt2D& dir, const Punt2D& pos)
{
	if (velocitatActual < velocitatMaxima) velocitatActual++;
	if (not direccio.es_igual(dir)) {
		if (velocitatActual - 1 > 0) velocitatActual--;
	}

	Punt2D nouPunt = vehicleBehaviour->accelerar(dir, pos , velocitatActual);

	if (Cursa::GetInstance()->EsTransitable(nouPunt)) {
		Vehicle* vehicleColisionat;
		if (Cursa::GetInstance()->NoColisiona(nouPunt,vehicleColisionat)) {
			direccio = dir;
			return nouPunt;
		}
		else {
			
		}
	}

	return Punt2D();
}
void Vehicle::CambiarAccelerar(ComportamentAccelerar* tipusVehile) {
	vehicleBehaviour = tipusVehile;
}
const string Vehicle::getNomVehicle() const {
		return nomVehicle;
}