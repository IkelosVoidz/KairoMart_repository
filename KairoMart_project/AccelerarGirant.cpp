#include "AccelerarGirant.h"

Punt2D AccelerarGirant::accelerar(const Punt2D& dir, const Punt2D& dirAGirar, const Punt2D& pos, int vel)
{
	//accelera fins la meitat de vel, gira 90 graus i accelera fins l'altra meitat de vel
	
	//accelera fins la meitat de vel
	int velMitja = vel / 2;
	Punt2D puntMig = Punt2D(pos.get_x() + velMitja * dir.get_x(), pos.get_y() + velMitja * dir.get_y());

	//gira 90 graus i accelera fins l'altra meitat de vel
	int velFinal = vel - velMitja;
	return Punt2D(puntMig.get_x() + velFinal * dirAGirar.get_x(), puntMig.get_y() + velFinal * dirAGirar.get_y());
}
