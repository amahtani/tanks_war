#ifndef GAME_HPP
#define GAME_HPP

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

#include "Tank.hpp"
#include "Wall.hpp"
#include "Bullet.hpp"
#include "Missile.hpp"
#include "Shooter.hpp"
#include "Bonus_missiles.hpp"

using namespace std;

/**
@author MAHTANI - BENHAMIDA
*/


class Game
{

public:
	/**
	attributs
	*/

	int Map_Width;
	int Map_Height;

	/**
		Ecran a afficher
	*/
	SDL_Window *window;
	SDL_Renderer *renderer; 

	vector<Tank> tankList;
	vector<Bonus_missiles> bonusList;

	vector<Wall> wallList;

public:
			
	/**
	 Constructeur
	*/
	Game(int Map_Width, int Map_Height);

	/**
	 Methodes
	*/

	void removeTankFromRenderer(Tank t);
	void removeBulletFromRenderer(Bullet b);

	void addTankToGame(Tank t);

	void initRenderer(SDL_Window *window);

	void addToRenderer(SDL_Rect rect, SDL_Texture *text);

	void addToRenderer(SDL_Rect rect, SDL_Texture *text, SDL_Rect srcrect);

	void initMapWalls();

	void managingLife(SDL_Rect dstrect_lifeTank1, SDL_Rect dstrect_lifeTank2, SDL_Texture* txt_lifeBar15,SDL_Texture* txt_lifeBar14, 
			SDL_Texture* txt_lifeBar13, SDL_Texture* txt_lifeBar12, SDL_Texture* txt_lifeBar11, SDL_Texture* txt_lifeBar10, SDL_Texture* txt_lifeBar9, 
			SDL_Texture* txt_lifeBar8, SDL_Texture* txt_lifeBar7, SDL_Texture* txt_lifeBar6, SDL_Texture* txt_lifeBar5, SDL_Texture* txt_lifeBar4,
			SDL_Texture* txt_lifeBar3, SDL_Texture* txt_lifeBar2, SDL_Texture* txt_lifeBar1, SDL_Rect dstrect_explosion1, SDL_Rect dstrect_explosion2, 
			SDL_Texture* txt_explosion);
};

#endif
