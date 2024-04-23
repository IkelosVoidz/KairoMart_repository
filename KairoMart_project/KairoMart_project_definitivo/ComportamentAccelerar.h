#pragma once
#ifndef COMPORTAMENTACCELERAR_H
#define COMPORTAMENTACCELERAR_H
#include<iostream>
#include <memory>
#include "Punt2D.h"

using namespace std;

class ComportamentAccelerar
{
public:
	virtual Punt2D accelerar(const Punt2D& dirActual, const Punt2D& dirAGirar, const Punt2D& pos, int vel) = 0;
};

#endif // !COMPORTAMENTACCELERAR_H


