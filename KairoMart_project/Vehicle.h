#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;
#include"ComportamentAccelerar.h"
#include "Punt2D.h"
class Vehicle
{
public:
    Vehicle();
    Vehicle(const string& nom, int maxVel, int adherencia, int resistencia, int dirX, int dirY);
  
    Punt2D FesAccelerar(const Punt2D& dir, const Punt2D& pos);
    void CambiarAccelerar(ComportamentAccelerar* tipusAcceleracio);

    const string getNomVehicle() const;
private:

	
    string nomVehicle;
    ComportamentAccelerar* vehicleBehaviour;
    int adherencia;
    int velocitatMaxima;
    int resistenciaXoc;
    int velocitatActual;
    Punt2D direccio; // ??? no ens serveix no more 
    bool penalitzatPerXoc;
};
#endif // !VEHICLE_H


