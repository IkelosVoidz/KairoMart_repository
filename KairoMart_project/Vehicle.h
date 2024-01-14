#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle();
    Vehicle(int id, string& _vehicle, double _maxVel, double _adherencia);
  

    void accelerar(double increment);
    void frenar(double decrement);
    void girar(double graus);
    void assignarAdaptacio(int adaptacio); //assigna l'adaptadcio depenent del personatge -> per ferho senzill farem que redueixi la velMaxima
    const int getIdVehicle() const;
private:

	int id;
    string vehicle;
    double adherencia;
    double velocitatMaxima;
    double resistenciaXoc;
    double velocitatActual;

};



#endif // !VEHICLE_H


