#include "Position.h"


Position::Position(int x, int y) :xc(x), yc(y){
}

void Position::setCoords(int x, int y){
	xc = x;
	yc = y;
}

void Position::getCoords(int& x, int& y){
	x = xc;
	y = yc;
}

int Position::distSqrd(Position& p1, Position& p2)
{
	int delx = p1.xc - p2.xc;
	int dely = p1.yc - p2.yc;
	return (delx*delx + dely*dely);

}