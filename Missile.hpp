#ifndef MISSILE_HPP
#define MISSILE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>       
#include <SDL2/SDL_image.h>        

#include "Shooter.hpp"

using namespace std;


/**
@author MAHTANI - BENHAMIDA
*/

class Missile : public Shooter
{

private:

	/**
	attributs
	*/

	int posx; int posy;
	const char* file;
	SDL_Surface *surf;
	SDL_Rect rect;
	SDL_Rect srcrect;

	int degat;

public:
			
	/**
	 Constructeur
	*/
	Missile(int x, int y, const char* file);

	/**
	 Methodes
	*/
	SDL_Rect GetRect();
	SDL_Rect GetSrcRect();
	SDL_Surface* GetSurf();

	int GetDegat();

	int GetRectx();
	int GetRecty();
	int GetRectw();
	int GetRecth();

	void SetRectx(int);
	void SetRecty(int);
	void SetRectw(int);
	void SetRecth(int);

	void SetSrcRectx(int);
	void SetSrcRecty(int);
	void SetSrcRectw(int);
	void SetSrcRecth(int);
	
	//void updateMissilePosition(Tank t);

};

#endif

