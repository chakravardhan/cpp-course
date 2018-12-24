
#include "Disc.h"

Disc::Disc(Position pcenter, int rad) : center(pcenter), radius(rad)
{
}


Disc::Disc(Disc& d1) :center(d1.center), radius(d1.radius)
{
}


bool Disc::collides(Disc* odisc) {
	int rsum = radius + odisc->radius;
	return (Position::distSqrd(center, odisc->center) <= rsum*rsum);
}

