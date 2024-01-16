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
	tornsRestantsPenalitzacio = 0;

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
	tornsRestantsPenalitzacio = 0;
}

Punt2D Vehicle::FesAccelerar(const Punt2D& dir, const Punt2D& pos)
{
	if (penalitzatPerXoc) {
		cout << "El vehicle esta penalitzat per un xoc" << endl;
		tornsRestantsPenalitzacio--;

		if (tornsRestantsPenalitzacio == 0) penalitzatPerXoc = false;
	}

	if (velocitatActual < velocitatMaxima) velocitatActual++;
	if (not direccio.es_igual(dir)) {
		if (velocitatActual - 1 > 0) velocitatActual--;
	}

	Punt2D nouPunt = vehicleBehaviour->accelerar(direccio, dir, pos, velocitatActual);

	if (Cursa::GetInstance()->EsTransitable(nouPunt)) {
		shared_ptr<Vehicle> vehicleColisionat;
		if (not Cursa::GetInstance()->HiHaColisio(nouPunt,vehicleColisionat)) {
			direccio = dir;
			return nouPunt;
		}
		else {
			penalitzar();
			vehicleColisionat->penalitzar();
		}
	}

	return Punt2D();
}
void Vehicle::CambiarAccelerar(shared_ptr<ComportamentAccelerar> newBehaviour) {
	vehicleBehaviour = newBehaviour;
}
const string Vehicle::GetNomVehicle() const {
		return nomVehicle;
}

int Vehicle::GetVelocitat() const
{
	return velocitatActual;
}

Punt2D Vehicle::GetDireccio() const
{
	return direccio;
}

void Vehicle::SetDireccio(const Punt2D& dir)
{
	direccio = dir;
}

void Vehicle::penalitzar()
{
	penalitzatPerXoc = true;
	tornsRestantsPenalitzacio = resistenciaXoc;
	velocitatActual = 0;
}
