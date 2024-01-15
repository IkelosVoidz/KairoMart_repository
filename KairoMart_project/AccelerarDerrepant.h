#pragma once
#ifndef ACCELERARDERREPANT_H
#define ACCELERARDERREPANT_H
#include "ComportamentAccelerar.h"
#include<iostream>
using namespace std;
class AccelerarDerrepant :
    public ComportamentAccelerar
{
    void accelerar() override;
};


#endif // !ACCELERARDERREPANT_H

