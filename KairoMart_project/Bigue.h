#pragma once
#ifndef BIGUE_H
#define BIGUE_H

#include "Vehicle.h"
#include<iostream>
using namespace std;
class Bigue:public Vehicle
{
public:
    Bigue(const std::string& nom, int maxVelocitat);
};



#endif // !BIGUE_H

