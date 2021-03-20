#ifndef WALL_HPP
#define WALL_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>       
#include <SDL2/SDL_image.h>        
#include <SDL2/SDL_ttf.h>

/**
@author MAHTANI - BENHAMIDA
*/

using namespace std;

/**
 un mur est un rectangle que les tanks ou les projectiles ne peuvent traverser
*/
class Wall 
{

private:

	/**
	attributs
	*/


	/**
	coordonnees haut gauche du mur 
	*/
	//int x1;	
	//int y1;

	/**
	coordonnes bas droite du mur
	*/
	//int x2;
	//int y2;

	SDL_Rect rect;

public:
			
	/**
	 Constructeur
	*/
	Wall(int a, int b, int c, int d);

	/**
	 Methodes
	*/
	Wall randomWall();

	SDL_Rect GetRect();

	int GetRectx();
	int GetRecty();
	int GetRectw();
	int GetRecth();

	void SetRectx(int);
	void SetRecty(int);
	void SetRectw(int);
	void SetRecth(int);

};

#endif
