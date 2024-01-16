#pragma once
#ifndef QUADRIGUE_H
#define QUADRIGUE_H

#include "Vehicle.h"
#include <iostream>
using namespace std;
class Quadrigue :
    public Vehicle
{
public:
    Quadrigue(const string& nom, int maxVel, int adherenci, int resistencia);
};

#endif // !QUADRIGUE_H


