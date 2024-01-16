#pragma once
#ifndef CAVALL_H
#define CAVALL_H

#include<iostream>
using namespace std;
#include "Vehicle.h"
#include <memory>

class Cavall :
    public Vehicle
{
public:
    Cavall(const string& nom, int maxVel, int adherenci, int resistencia);
};


#endif // !CAVALL_H


