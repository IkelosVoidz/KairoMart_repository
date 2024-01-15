#pragma once
#ifndef CAVALL_H
#define CAVALL_H

#include<iostream>
using namespace std;
#include "Vehicle.h"

class Cavall :
    public Vehicle
{
    Cavall(const string& nom, int maxVelocitat);
};


#endif // !CAVALL_H


