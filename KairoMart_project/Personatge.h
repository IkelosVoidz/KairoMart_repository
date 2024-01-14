#pragma once
#ifndef PERSONATGE_H
#define PERSONATGE_H
#include <iostream>
using namespace std;

class Personatge
{
public:
    Personatge();
    Personatge(int _id, string& nom);

    const string getNom() const;
private:
    int id;
    string nom;
};

#endif // !VEHICLE_H