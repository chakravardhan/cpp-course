

#include "Position.h"
class Disc
{
private:
	Position center;
	int radius;

public:

	Disc(Position pcenter, int rad);
	Disc(Disc& d1);
	
	void getCenter(int& x, int& y) {
		center.getCoords(x, y);
	}

	void setCenter(int x, int y) {
		center.setCoords(x, y);
	}

	int getRadius() { return radius; }
	void setRadius(int r){
		radius = r;
	}
	
	bool collides(Disc* odisc);

};

