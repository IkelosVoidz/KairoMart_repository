#pragma once
#ifndef BIGUE_H
#define BIGUE_H

#include "Vehicle.h"
#include<iostream>
#include <memory>
using namespace std;
class Bigue:public Vehicle
{
public:
    Bigue(const string& nom, int maxVel, int adherenci, int resistencia);
};



#endif // !BIGUE_H

