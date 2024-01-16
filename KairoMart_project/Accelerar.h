#pragma once
#ifndef ACCELERAR_H
#define ACCELERAR_H
#include<iostream>
#include "ComportamentAccelerar.h"
using namespace std;

class Accelerar : public ComportamentAccelerar
{
public:
    Punt2D accelerar(const Punt2D& dir, const Punt2D& dirAGirar, const Punt2D& pos, int vel) override;
};


#endif // !ACCELERAR_H

