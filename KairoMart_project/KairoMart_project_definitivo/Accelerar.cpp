#include "Accelerar.h"
#include <memory>

Punt2D Accelerar::accelerar(const Punt2D& dir, const Punt2D& dirAGirar, const Punt2D& pos, int vel)
{
	Punt2D p = Punt2D(vel * dirAGirar.get_x(), vel * dirAGirar.get_y());
	p.moure(pos);
	return p;
}
