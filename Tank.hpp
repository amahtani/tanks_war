#ifndef TANK_HPP
#define TANK_HPP

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>       
#include <SDL2/SDL_image.h>      

#include "Bullet.hpp"
#include "Missile.hpp"
#include "Shooter.hpp"

using namespace std;

/**
@author MAHTANI - BENHAMIDA
*/


class Tank
{

public:

	/**
	attributs
	*/

	int posx; 
	int posy;
	int orientation;
	SDL_Surface *surf;
	SDL_Rect rect;
	SDL_Rect srcrect;

	vector<Bullet> bulletList;
	vector<Missile> missileList;

	int weapon;

	int cpt_bullet;
	int cpt_missile;
	int life;


public:
			
	/**
	 Constructeur
	*/
	Tank(int x, int y);

	// Getters et setters
	/*SDL_Rect GetRect();
	SDL_Rect GetSrcRect();
	SDL_Surface* GetSurf();
	int GetPosx();
	int GetPosy();
	int GetOrientation();
	int GetWeapon();
	int GetCpt_bullet();
	int GetCpt_Missile();
	int GetLife();
	vector<Bullet> GetBulletList();
	vector<Missile> GetMissileList();
	int GetRectx();
	int GetRecty();
	int GetRectw();
	int GetRecth();

	void SetLife(int a);
	void SetCpt_bullet(int a);
	void SetSurf(const char *file);
	void SetRectx(int);
	void SetRecty(int);
	void SetRectw(int);
	void SetRecth(int);
	void SetSrcRectx(int);
	void SetSrcRecty(int);
	void SetSrcRectw(int);
	void SetSrcRecth(int);
	*/

	/**
	 Methodes
	*/
	void updateToFirstPosition();

	void moveTankLeft();
	void moveTankRight();
	void moveTankDown();
	void moveTankUp();

	void move1pxTankLeft();
	void move1pxTankRight();
	void move1pxTankDown();
	void move1pxTankUp();

	void move1(SDL_Event event);
	void move2(SDL_Event event);

	void updateMissilePosition(Missile m, Tank t);

};

#endif
