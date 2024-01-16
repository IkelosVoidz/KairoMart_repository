#include "Personatge.h"
Personatge::Personatge() {
	
	nom = " ";

}
Personatge::Personatge(const string& _nom) {
	nom = _nom;

}

const string Personatge::GetNom() const { return nom; }
