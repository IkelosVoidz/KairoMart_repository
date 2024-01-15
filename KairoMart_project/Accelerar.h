#pragma once
#ifndef ACCELERAR_H
#define ACCELERAR_H
#include<iostream>
#include "ComportamentAccelerar.h"
using namespace std;

class Accelerar :
    public ComportamentAccelerar
{
    void accelerar();
};


#endif // !ACCELERAR_H

