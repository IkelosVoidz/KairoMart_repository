#include "Personatge.h"
Personatge::Personatge() {
	id = 0;
	nom = " ";
	adaptacio = 0;
}
Personatge::Personatge(int i, string& _nom) {
	id = i;
	nom = _nom;
	adaptacio = 0;
}

const string Personatge::getNom() const { return nom; }
void Personatge::getAdaptacio(Vehicle p) {
	int reduccio;

	reduccio = p.getIdVehicle() - id;
	if (reduccio < 0) { reduccio *= -1; }

	adaptacio = reduccio;

	p.assignarAdaptacio(reduccio);

}//troba el grau d'adaptacio amb el personatge