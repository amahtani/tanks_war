#include "Missile.hpp"
#include "Shooter.hpp"

#define SPEED 1
#define WAITING 10

/**
@author MAHTANI - BENHAMIDA
*/


/**
 Constructeur
 @param les coordonnes et le fichier image
*/
Missile::Missile(int x, int y, const char* file) : Shooter()
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

	degat = 8;

	rect.x = posx;
	rect.y = posy;
	rect.h = 20;
	rect.w = 20;
		
	return;
}

/*void Missile::updateMissilePosition(Tank t)			// missile a tete chercheuse
{
	while(SDL_HasIntersection(&(t.rect), &GetRect()) != SDL_TRUE)
	{
		if(t.rect.x > GetRectx()){ SetRectx(GetRectx() + SPEED);}
		if(t.rect.x < GetRectx()){ SetRectx(GetRectx() - SPEED);}
		if(t.rect.y > GetRecty()){ SetRecty(GetRecty() + SPEED);}
		if(t.rect.y < GetRecty()){ SetRecty(GetRecty() - SPEED);}
	}	


	//usleep(WAITING);
}*/


int Missile::GetDegat(){return degat;}
SDL_Surface* Missile::GetSurf(){return surf;}
SDL_Rect Missile::GetSrcRect(){return srcrect;}
SDL_Rect Missile::GetRect(){return rect;}
int Missile::GetRectx() {return rect.x;}
int Missile::GetRecty() {return rect.y;}
int Missile::GetRectw() {return rect.w;}
int Missile::GetRecth() {return rect.h;}
void Missile::SetRectx(int x){rect.x = x;}
void Missile::SetRecty(int y){rect.y = y;}
void Missile::SetRectw(int w){rect.w = w;}
void Missile::SetRecth(int h){rect.h = h;}
void Missile::SetSrcRectx(int x){srcrect.x = x;}
void Missile::SetSrcRecty(int y){srcrect.y = y;}
void Missile::SetSrcRectw(int w){srcrect.w = w;}
void Missile::SetSrcRecth(int h){srcrect.h = h;}

