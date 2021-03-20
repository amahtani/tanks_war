#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>       
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

/**
@author MAHTANI - BENHAMIDA
*/
#include "Game.hpp"

class Collision
{

private:
	/**
	attributs
	*/


public:
			
	/**
	 Constructeur
	*/
	Collision();

	/**
	 Methodes
	*/
	
	bool collisionBulletWall(Game* My_game);

	bool bulletCollision(Game* My_game);

	bool CollisionTankOponentBullet(unsigned int BULLETS_NUMBER, Game* My_game);

	void tankCollision(Tank* t1, Tank* t2);

	void collisionTankWall(Game* My_game);
};

#endif
