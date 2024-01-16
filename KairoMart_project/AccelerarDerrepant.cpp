#include "AccelerarDerrepant.h"

Punt2D AccelerarDerrepant::accelerar(const Punt2D& dir, const Punt2D& dirAGirar, const Punt2D& pos, int vel)
{
	Punt2D puntActual = pos;
	//accelera en diagonal
	for (int i = 0; i < vel; i++)
	{
		if (i % 2 == 0) puntActual.moure(Punt2D(1 * dir.get_x(), 1 * dir.get_y()));
		else puntActual.moure(Punt2D(1 * dirAGirar.get_x(), 1 * dirAGirar.get_y()));
	}

	cout << "Derrape" << endl;

	return puntActual;
}
