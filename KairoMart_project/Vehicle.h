#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle();
    Vehicle(const string& nom, int maxVel, int adherencia);
  
    void FesAccelerar();
    void CanviarAccelerar(VehicleBehavior tipusVehile);

    const string getNomVehicle() const;
private:

	
    string nomVehicle;

    int adherencia;
    int velocitatMaxima;
    int resistenciaXoc;
    int velocitatActual;
    pair<int, int> direccio;
    bool penalitzatPerXoc;
};



#endif // !VEHICLE_H


