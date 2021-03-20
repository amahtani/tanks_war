#ifndef SHOOTER_HPP
#define SHOOTER_HPP

/**
@author MAHTANI - BENHAMIDA
*/
#include <SDL2/SDL.h>       
#include <SDL2/SDL_image.h>        


class Shooter
{
protected :

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
	Shooter();

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

	void updateShooterPosition(int direction);
};

#endif
