#include "Player.h"
#include "Disc.h"
#include "Game.h"
#include <iostream>
using namespace std;


bool Player::play()
{
	bool gameOver = false;
	bool crashed = false;
	
	int x, y, r;
	cin >> x >> y >> r;
	
	while (!gameOver && !crashed) {
		if (x == 0 && y == 0 && r == 0) {
			cout << "Game Over - end of input found\n";
			gameOver = true;
		}
		else {
			Disc *d1 = new Disc(Position(x, y), r);
			crashed = !(game->addDisc(d1));
			if (!crashed) {
				cin >> x >> y >> r;
			}
		}
	}
	return (!crashed);
}
