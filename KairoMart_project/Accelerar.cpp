#include "Accelerar.h"

Punt2D Accelerar::accelerar(const Punt2D& dir, const Punt2D& dirAGirar, const Punt2D& pos, int vel)
{
	Punt2D p = Punt2D(vel * dir.get_x(), vel * dir.get_y());
	p.moure(pos);
	return p;
}
