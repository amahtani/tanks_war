#include "Shooter.hpp"


/**
@author MAHTANI - BENHAMIDA
*/


/**
 Constructeur
 @param les coordonnes et le fichier image
*/
Shooter::Shooter()
{
	degat = 0;
	surf = NULL;
	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;
	return;
}


int Shooter::GetDegat(){return degat;}
SDL_Surface* Shooter::GetSurf(){return surf;}
SDL_Rect Shooter::GetSrcRect(){return srcrect;}
SDL_Rect Shooter::GetRect(){return rect;}
int Shooter::GetRectx() {return rect.x;}
int Shooter::GetRecty() {return rect.y;}
int Shooter::GetRectw() {return rect.w;}
int Shooter::GetRecth() {return rect.h;}
void Shooter::SetRectx(int x){rect.x = x;}
void Shooter::SetRecty(int y){rect.y = y;}
void Shooter::SetRectw(int w){rect.w = w;}
void Shooter::SetRecth(int h){rect.h = h;}
void Shooter::SetSrcRectx(int x){srcrect.x = x;}
void Shooter::SetSrcRecty(int y){srcrect.y = y;}
void Shooter::SetSrcRectw(int w){srcrect.w = w;}
void Shooter::SetSrcRecth(int h){srcrect.h = h;}
