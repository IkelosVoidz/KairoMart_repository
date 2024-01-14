#pragma once
#ifndef PERSONATGE_H
#define PERSONATGE_H
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Personatge
{
public:
    Personatge();
    Personatge(int _id, string& nom);

    const string getNom() const;
    void getAdaptacio(Vehicle p); //troba el grau d'adaptacio amb el personatge
private:
    int id;
    string nom;
    int adaptacio;

};



#endif // !VEHICLE_H


