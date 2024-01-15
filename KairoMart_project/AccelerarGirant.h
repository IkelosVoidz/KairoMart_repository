#pragma once
#ifndef ACCELERARGIRANT_H
#define ACCELERARGIRANT_H
#include<iostream>
using namespace std;
#include "ComportamentAccelerar.h"


class AccelerarGirant : public ComportamentAccelerar
{
    void accelerar() override;
};

#endif // !ACCELERARGIRANT_H


