#include"Cavall.h"
#include <memory>
/*
Cavall::Cavall(const std::string& nom, int maxVelocitat)
    : Vehicle(nom, maxVelocitat, 4, 8) {}
*/

Cavall::Cavall(const string& nom, int maxVel, int adherenci, int resistencia)
{
    nomVehicle = nom;
    velocitatMaxima = maxVel;
    adherencia = adherenci;
    resistenciaXoc = resistencia;
}
