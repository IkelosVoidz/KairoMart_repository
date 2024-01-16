#pragma once
#ifndef PERSONATGE_H
#define PERSONATGE_H
#include <iostream>
using namespace std;

class Personatge
{
public:
    Personatge();
    Personatge(const string& nom);

    const string GetNom() const;
private:
    string nom;
};

#endif // !VEHICLE_H