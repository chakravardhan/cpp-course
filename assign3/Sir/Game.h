

class Disc;
class Player;
#include <vector>
using namespace std;

#define GAME_MAX_X 500
#define GAME_MAX_Y 500

class Game
{
private:
	vector<Disc *> discs;

	void moveRand(Disc *);
	void growRand(Disc *);

	void modifyDisc(Disc *);
public:
	~Game();
	bool addDisc(Disc *newDisc);   // true if successful, false otherwise
};

