#ifndef COMPORTAMENTACCELERAR_H
#define COMPORTAMENTACCELERAR_H
#include<iostream>
#include "Punt2D.h"

using namespace std;

class ComportamentAccelerar
{
public:
	virtual Punt2D accelerar(const Punt2D& dirActual, const Punt2D& dirAGirar, const Punt2D& pos, int vel) abstract;
};

#endif // !COMPORTAMENTACCELERAR_H


