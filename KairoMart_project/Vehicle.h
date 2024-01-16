#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;
#include"ComportamentAccelerar.h"
#include "Punt2D.h"
#include "Personatge.h"
class Vehicle
{
public:
    Vehicle();
    Vehicle(const string& nom, int maxVel, int adherencia, int resistencia, int dirX, int dirY);
  
    Punt2D FesAccelerar(const Punt2D& dir, const Punt2D& pos);
    void CambiarAccelerar(shared_ptr<ComportamentAccelerar> newBehaviour);

    const string GetNomVehicle() const;
    int GetVelocitat() const;
    Punt2D GetDireccio() const;
    void SetDireccio(const Punt2D& dir);
protected:

	
    void penalitzar();

    string nomVehicle;
    shared_ptr<ComportamentAccelerar> vehicleBehaviour;
    int adherencia;
    int velocitatMaxima;
    int resistenciaXoc;
    int tornsRestantsPenalitzacio;
    int velocitatActual;
    Punt2D direccio; 
    bool penalitzatPerXoc;
};
#endif // !VEHICLE_H


