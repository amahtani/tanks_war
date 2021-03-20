#include "Bonus_missiles.hpp"

#define WAITING 10

/**
@author MAHTANI - BENHAMIDA
*/


/**
 Constructeur
 @param les coordonnes et le fichier image
*/
Bonus_missiles::Bonus_missiles(const char* file)
{
	/**
	 Creation d'un projectile
	*/
	surf = IMG_Load(file);

	/**
	 initialisation de rand
	*/
	srand(time(NULL)); 

	/**
	 taille d'un projectile toujours fixee a 20x20 px
	*/
	type = 2;			// type de munitions

	rect = {rand()%(1600-100)+100,rand()%(700-100)+100, 50, 50};

	return;
}

/*void Bonus_missiles::gotBonus(Tank t, SDL_Renderer* renderer)
{
	SetRectx(6000);				// on sort le bonus de la fenetre lorsqu'un tank roule dessus
	SetRecty(6000);
	
	t.weapon = 2;				// le tank va tirer des missiles
	

}*/

SDL_Surface* Bonus_missiles::GetSurf(){return surf;}
SDL_Rect Bonus_missiles::GetRect(){return rect;}
int Bonus_missiles::GetType() {return type;}
int Bonus_missiles::GetRectx() {return rect.x;}
int Bonus_missiles::GetRecty() {return rect.y;}
int Bonus_missiles::GetRectw() {return rect.w;}
int Bonus_missiles::GetRecth() {return rect.h;}
void Bonus_missiles::SetRectx(int x){rect.x = x;}
void Bonus_missiles::SetRecty(int y){rect.y = y;}
void Bonus_missiles::SetRectw(int w){rect.w = w;}
void Bonus_missiles::SetRecth(int h){rect.h = h;}
