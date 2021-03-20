#include "Wall.hpp"

//#define MIN_WALL_SIZE 100

/**
@author MAHTANI - BENHAMIDA
*/

/**
 Constructeur
 @param coordonnees des points du rectangle 
 */
Wall::Wall(int a, int b, int c, int d)
{
	/**
	 point haut gauche du rectangle
	*/

	rect.x = a;
	rect.y = b;
	rect.w = c;
	rect.h = d;
}


/**
 Methode
 @return un mur w de taille aleatoire
*/
Wall Wall::randomWall()
{
	/**
	 initialisation de rand
	*/
	srand(time(NULL)); 	

	/**
	 le mur aleatoire reste eloigne de 100px de chaque murs autour du terrain			
	*/
	int x = rand()%(1600-100);	
	int y = rand()%(700-100);
	int w = rand()%(1600-100);
	int h = rand()%(700-100);
	
	/**
	 on cree un mur a partir des variables precedentes
	*/
	Wall a = Wall(x,y,w,h);

	return a;
}

SDL_Rect Wall::GetRect(){return rect;}
int Wall::GetRectx() {return rect.x;}
int Wall::GetRecty() {return rect.y;}
int Wall::GetRectw() {return rect.w;}
int Wall::GetRecth() {return rect.h;}
void Wall::SetRectx(int x){rect.x = x;}
void Wall::SetRecty(int y){rect.y = y;}
void Wall::SetRectw(int w){rect.w = w;}
void Wall::SetRecth(int h){rect.h = h;}
