

class Game;


class Player
{
private:
	Game *game;

public:
	
	void setGame(Game *g) { game = g; }
	bool play();  // returns true if successfully completes the input

};

