#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;
#include"ComportamentAccelerar.h"
class Vehicle
{
public:
    Vehicle();
    Vehicle(const string& nom, int maxVel, int adherencia, int resistencia);
  
    void FesAccelerar();
    void CambiarAccelerar(ComportamentAccelerar tipusAcceleracio);

    const string getNomVehicle() const;
private:

	
    string nomVehicle;
    ComportamentAccelerar vehicleBehvior;
    int adherencia;
    int velocitatMaxima;
    int resistenciaXoc;
    int velocitatActual;
    pair<int, int> direccio;
    bool penalitzatPerXoc;
};



#endif // !VEHICLE_H


