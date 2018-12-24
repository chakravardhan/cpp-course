
class Position
{
private:
	int xc, yc;
public:
	Position(int x, int y);
	void setCoords(int x, int y);

	void getCoords(int& x, int& y);

	static int distSqrd(Position& p1, Position& p2);

};

