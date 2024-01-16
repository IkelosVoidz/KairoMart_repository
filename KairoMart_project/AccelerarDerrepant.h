#pragma once
#ifndef ACCELERARDERREPANT_H
#define ACCELERARDERREPANT_H
#include "ComportamentAccelerar.h"
#include<iostream>
using namespace std;
class AccelerarDerrepant : public ComportamentAccelerar
{
public:
    Punt2D accelerar(const Punt2D& dir, const Punt2D& dirAGirar, const Punt2D& pos, int vel) override;
};


#endif // !ACCELERARDERREPANT_H

