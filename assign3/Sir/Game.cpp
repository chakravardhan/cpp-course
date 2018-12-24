
#include "Game.h"
#include "Disc.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Game::~Game() {
	for(int i=0;i< discs.size();i++) {
		delete discs[i];
	}
}

void Game::modifyDisc(Disc *d) {
	int toss = (rand() % 3)+1;

	if (toss & 0x1)
		moveRand(d);
	if (toss & 0x2)
		growRand(d);
}

void Game::moveRand(Disc *d)
{
	int x, y;
	d->getCenter(x, y);
	x += rand() % 40 - 20;
	y += rand() % 40 - 20;
	
	if (x > GAME_MAX_X)
		x = GAME_MAX_X;
	else if (x < 0)
		x = 0;

	if (y > GAME_MAX_Y)
		y = GAME_MAX_Y;
	else if (y < 0)
		y = 0;
	
	d->setCenter(x, y);

}

void Game::growRand(Disc *d)
{
	int rad = d->getRadius();
	rad += rand() % 20;
	if (rad > GAME_MAX_X / 5)
		rad = GAME_MAX_X / 5;
	d->setRadius(rad);

}


bool Game::addDisc(Disc *newDisc){
	bool success = true;
	// check with all existing discs

	for (unsigned int i = 0; i < discs.size() && success; i++) {
		success = !(newDisc->collides(discs[i]));
		if (!success) {
			int x1, y1, x2, y2, r1, r2;
			newDisc->getCenter(x1, y1);
			r1 = newDisc->getRadius();
			discs[i]->getCenter(x2, y2);
			r2 = discs[i]->getRadius();
			cout << ">> Collision: new disc:" << x1 << "," << y1 << "," << r1 << " with Old disc: [" << i << "] ," << x2 << "," << y2 << "," << r2 << endl;
		}
	}

	if (success) {
		int numDiscs = discs.size();
		cout << ">>>> Successfully added disc: score is now " << numDiscs << endl;

		discs.push_back(newDisc); // add to existing list of discs
		// change position/radius of existing discs, add new discs by cloning every 10th
		
		for (int i = 0; i < numDiscs+1; i++) {
			modifyDisc(discs[i]);
			if (i % 10 == 9) {   // every 5th disc - can be changed to modulo 10 if needed
				Disc *cd = new Disc(*discs[i]);
				discs.push_back(cd);
			}
		}
		cout << ">> Current set of discs: " << endl;
		for (int i = 0; i < discs.size(); i++) {
			int x, y;
			discs[i]->getCenter(x, y);
			cout << x << " " << y << " " << discs[i]->getRadius() << endl;
		}
	}
	else {
		cout << ">>>>> Collission found. Game Over..." << endl;
	}
	return success;
}
