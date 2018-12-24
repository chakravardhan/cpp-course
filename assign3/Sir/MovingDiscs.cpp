

#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	
	bool gameOver = false;
	while (!gameOver) {
		cout << "Starting new game ... " << endl;
		Game game;
		Player player;
		player.setGame(&game);
		gameOver = player.play();
	}

	return 0;
}

#if 0
50 250 30
250 100 40
400 400 20
450 50 35
150 250 10
350 250 20
100 400 50
100 100 35
50 50 40
400 150 45
0 0 0

#endif
