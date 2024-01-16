#pragma once
#ifndef ACCELERARGIRANT_H
#define ACCELERARGIRANT_H
#include<iostream>
using namespace std;
#include "ComportamentAccelerar.h"


class AccelerarGirant : public ComportamentAccelerar
{
public:
    Punt2D accelerar(const Punt2D& dir, const Punt2D& dirAGirar, const Punt2D& pos, int vel) override;
};

#endif // !ACCELERARGIRANT_H


