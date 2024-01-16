#include "Quadrigue.h"

#include <memory>

/*Quadrigue::Quadrigue(const std::string& nom, int maxVelocitat)
    : Vehicle(nom, maxVelocitat, 5, 5) {}*/

Quadrigue::Quadrigue(const string& nom, int maxVel, int adherenci, int resistencia)
{
    nomVehicle = nom;
    velocitatMaxima = maxVel;
    adherencia = adherenci;
    resistenciaXoc = resistencia;
}
