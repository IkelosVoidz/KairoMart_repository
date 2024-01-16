#include "Bigue.h"

/*
Bigue::Bigue(const std::string& nom, int maxVelocitat)
    : Vehicle(nom, maxVelocitat, 3, 10) {}
*/

Bigue::Bigue(const string& nom, int maxVel, int adherenci, int resistencia)
{
    nomVehicle = nom;
    velocitatMaxima = maxVel;
    adherencia = adherenci;
    resistenciaXoc = resistencia;
}