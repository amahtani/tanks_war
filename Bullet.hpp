#ifndef BULLET_HPP
#define BULLET_HPP

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

class Bullet : public Shooter
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
	int dir;

public:
			
	/**
	 Constructeur
	*/
	Bullet(int x, int y, const char* file);

	/**
	 Methodes
	*/
	SDL_Rect GetRect();
	SDL_Rect GetSrcRect();
	SDL_Surface* GetSurf();

	int GetDegat();
	int GetDir();

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

	void updateBulletPosition(int direction);

};

#endif

