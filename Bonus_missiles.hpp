#ifndef BONUS_MISSILES_HPP
#define BONUS_MISSILES_HPP

#include <ctime>
#include <SDL2/SDL.h>       
#include <SDL2/SDL_image.h>        

using namespace std;

#include "Missile.hpp"

/**
@author MAHTANI - BENHAMIDA
*/

class Bonus_missiles
{

private:

	/**
	attributs
	*/
	const char* file;
	SDL_Surface *surf;
	SDL_Rect rect;

	int type;

public:
			
	/**
	 Constructeur
	*/
	Bonus_missiles(const char* file);

	/**
	 Methodes
	*/
	SDL_Rect GetRect();
	SDL_Surface* GetSurf();

	int GetType();

	int GetRectx();
	int GetRecty();
	int GetRectw();
	int GetRecth();

	void SetRectx(int);
	void SetRecty(int);
	void SetRectw(int);
	void SetRecth(int);

	//void gotBonus(Tank t, SDL_Renderer* renderer);


};

#endif

