#ifndef LOOP_HPP
#define LOOP_HPP

#include "Game.hpp"
#include "Bonus_missiles.hpp"
#include "Shooter.hpp"
#include "Collision.hpp"

using namespace std;

/**
@author MAHTANI - BENHAMIDA
*/


class Loop
{

public:
	Game *My_game;

public:
			
	/**
	 Constructeur
	*/
	Loop(Game *My_game);

};

#endif