#include "Bullet.hpp"

#define SPEED 3
#define WAITING 10

/**
@author MAHTANI - BENHAMIDA
*/


/**
 Constructeur
 @param les coordonnes et le fichier image
*/
Bullet::Bullet(int x, int y, const char* file) : Shooter()
{
	posx = x;
	posy = y;
	/**
	 Creation d'un projectile
	*/
	surf = IMG_Load(file);

	/**
	 taille d'un projectile toujours fixee a 20x20 px
	*/

	degat = 2;
	dir = 0;

	rect.x = posx;
	rect.y = posy;
	rect.h = 20;
	rect.w = 20;
		
	return;
}

void Bullet::updateBulletPosition(int direction)
{
	if(direction == 1)			// on va a droite
	{
		SetRectx(GetRectx() + SPEED);
		SetSrcRectx(165);
		SetSrcRecty(190);
		SetSrcRectw(145);
		SetSrcRecth(65);
	}
	else if(direction == 2)		// on va a gauche
	{
		SetRectx(GetRectx() - SPEED);
		SetSrcRectx(155);
		SetSrcRecty(35);
		SetSrcRectw(145);
		SetSrcRecth(65);
	}
	else if(direction == 3)		// on va en bas
	{
		SetRecty(GetRecty() + SPEED);
		SetSrcRectx(70);
		SetSrcRecty(12);
		SetSrcRectw(48);
		SetSrcRecth(128);
	}
	else if(direction == 4)		// on va en haut
	{
		SetRecty(GetRecty() - SPEED);
		SetSrcRectx(65);
		SetSrcRecty(180);
		SetSrcRectw(55);
		SetSrcRecth(130);
	}
	//usleep(WAITING);
}

int Bullet::GetDir(){return dir;}
int Bullet::GetDegat(){return degat;}
SDL_Surface* Bullet::GetSurf(){return surf;}
SDL_Rect Bullet::GetRect(){return rect;}
SDL_Rect Bullet::GetSrcRect(){return srcrect;}
int Bullet::GetRectx() {return rect.x;}
int Bullet::GetRecty() {return rect.y;}
int Bullet::GetRectw() {return rect.w;}
int Bullet::GetRecth() {return rect.h;}
void Bullet::SetRectx(int x){rect.x = x;}
void Bullet::SetRecty(int y){rect.y = y;}
void Bullet::SetRectw(int w){rect.w = w;}
void Bullet::SetRecth(int h){rect.h = h;}
void Bullet::SetSrcRectx(int x){srcrect.x = x;}
void Bullet::SetSrcRecty(int y){srcrect.y = y;}
void Bullet::SetSrcRectw(int w){srcrect.w = w;}
void Bullet::SetSrcRecth(int h){srcrect.h = h;}

