#include "Tank.hpp"

#define SPEED 20
#define SPEED_IN_WALLS 1

/**
@author MAHTANI - BENHAMIDA
*/

/**
 Constructeur
*/
Tank::Tank(int x, int y)
{
	posx = x;
	posy = y;

	/*
	 Creation d'un tank
	*/		
	rect.x = x;
	rect.y = y;
	rect.h = 50;
	rect.w = 50;	

	orientation = 1;
	weapon = 1;
	/**
	 taille d'un tank toujours fixee a 50x50 px
	*/
	srcrect.x = 285;
	srcrect.y = 30;
	srcrect.h = 220;
	srcrect.w = 260;

	updateToFirstPosition();

	life = 15;
	cpt_bullet = 0;
	cpt_missile = 0;

	return;
}

void Tank::updateToFirstPosition()
{
	rect.x = posx;
	rect.y = posy;
	rect.h = 50;
	rect.w = 50;
}

void Tank::moveTankRight()
{
	orientation = 1;
	rect.x += SPEED;
	srcrect.x = 295;
	srcrect.y = 295;
	//updateToFirstPosition();
}
void Tank::moveTankLeft()
{
	orientation = 2;
	rect.x -= SPEED;
	srcrect.x = 285;
	srcrect.y = 20;
	srcrect.h = 260;
	srcrect.w = 235;
	//updateToFirstPosition();
}

void Tank::moveTankDown()
{
	orientation = 3;
	rect.y += SPEED;
	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.h = 225;
	srcrect.w = 260;
	//updateToFirstPosition();
}

void Tank::moveTankUp()
{
	orientation = 4;
	rect.y -= SPEED;
	srcrect.x = 10;
	srcrect.y = 305;
	srcrect.h = 230;
	srcrect.w = 260;
	//updateToFirstPosition();
}

void Tank::move1pxTankLeft()
{
	rect.x -= SPEED_IN_WALLS;
}

void Tank::move1pxTankRight()
{
	rect.x += SPEED_IN_WALLS;
}

void Tank::move1pxTankDown()
{
	rect.y += SPEED_IN_WALLS;
}

void Tank::move1pxTankUp()
{
	rect.y -= SPEED_IN_WALLS;
}

void Tank::updateMissilePosition(Missile m, Tank t)			// missile a tete chercheuse
{
	SDL_Rect missileRect = m.GetRect();
	int missX = m.GetRectx();
	int missY = m.GetRecty();

	while(!(SDL_HasIntersection(&(t.rect), &(missileRect)) == SDL_TRUE))
	{
		if(t.rect.x > missX){ m.SetRectx(missX + SPEED);}
		if(t.rect.x < missX){ m.SetRectx(missX - SPEED);}
		if(t.rect.y > missY){ m.SetRecty(missY + SPEED);}
		if(t.rect.y < missY){ m.SetRecty(missY - SPEED);}
	}	
}

void Tank::move1(SDL_Event event) 	//renvoie 1 si le tank a tire, effectue aussi son mouvement selon le keyboard
{
	if (event.type == SDL_KEYDOWN)
	{							
		switch (event.key.keysym.sym) 
		{  // Sous-switch de touches
	
			//////////////////////////    JOUEUR 1     ///////////////////////////////////
			case SDLK_RIGHT:
				cout << "droite" << endl;
				rect.x += SPEED;
				orientation = 1;
				srcrect.x = 295;
				srcrect.y = 295;
				break;

			case SDLK_LEFT:
				cout << "gauche" << endl;
				rect.x -= SPEED;
				orientation = 2;
				srcrect.x = 285;
				srcrect.y = 20;
				srcrect.h = 260;
				srcrect.w = 235;
				break;

			case SDLK_DOWN:
				cout << "bas" << endl;
				rect.y += SPEED;
				orientation = 3;
				srcrect.x = 0;
				srcrect.y = 0;
				srcrect.h = 225;
				srcrect.w = 260;
				break;

			case SDLK_UP:
				cout << "haut" << endl;
				rect.y -= SPEED;
				orientation = 4;
				srcrect.x = 10;
				srcrect.y = 305;
				srcrect.h = 230;
				srcrect.w = 260;
				break;

			default : break;

		}
	}
	else if( event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym) 
		{  // Sous-switch de touches
	
			//////////////////////////    JOUEUR 1     ///////////////////////////////////
			case SDLK_RIGHT:
				cout << "droite" << endl;
				//rect.x -= SPEED/5;
				break;

			case SDLK_LEFT:
				cout << "gauche" << endl;
				//rect.x += SPEED/5;
				break;

			case SDLK_DOWN:
				cout << "bas" << endl;
				//rect.y -= SPEED/5;
				break;

			case SDLK_UP:
				cout << "haut" << endl;
				//rect.y += SPEED/5;
				break;

			default : break;
		}
	}
	return;
}


void Tank::move2(SDL_Event event) 	//renvoie 1 si le tank a tire, effectue aussi son mouvement selon le keyboard
{
	if (event.type == SDL_KEYDOWN)
	{							
		switch (event.key.keysym.sym) 
		{  // Sous-switch de touches
	
			//////////////////////////    JOUEUR 2     ///////////////////////////////////
			case SDLK_d:
				cout << "droite" << endl;
				rect.x += SPEED;
				orientation = 1;
				srcrect.x = 295;
				srcrect.y = 295;
				break;

			case SDLK_q:
				cout << "gauche" << endl;
				rect.x -= SPEED;
				orientation = 2;
				srcrect.x = 285;
				srcrect.y = 20;
				srcrect.h = 260;
				srcrect.w = 235;
				break;

			case SDLK_s:
				cout << "bas" << endl;
				rect.y += SPEED;
				orientation = 3;
				srcrect.x = 0;
				srcrect.y = 0;
				srcrect.h = 225;
				srcrect.w = 260;
				break;

			case SDLK_z:
				cout << "haut" << endl;
				rect.y -= SPEED;
				orientation = 4;
				srcrect.x = 10;
				srcrect.y = 305;
				srcrect.h = 230;
				srcrect.w = 260;
				break;

			default : break;
		}
	}
	else if( event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym) 
		{  // Sous-switch de touches
	
			case SDLK_d:
				cout << "droite" << endl;
				//rect.x -= SPEED/5;
				break;

			case SDLK_q:
				cout << "gauche" << endl;
				//rect.x += SPEED/5;
				break;

			case SDLK_s:
				cout << "bas" << endl;
				//rect.y -= SPEED/5;
				break;

			case SDLK_z:
				cout << "haut" << endl;
				//rect.y += SPEED/5;
				break;

			default : break;
		}
	}
	return;
}

/*int Tank::GetPosx(){return posx;}
int Tank::GetPosy(){return posy;}
int Tank::GetOrientation(){return orientation;}
int Tank::GetWeapon(){return weapon;}
int Tank::GetCpt_bullet(){return cpt_bullet;}
int Tank::GetCpt_Missile(){return cpt_missile;}
int Tank::GetLife(){return life;}
vector<Bullet> Tank::GetBulletList(){return bulletList;}
vector<Missile> Tank::GetMissileList(){return missileList;}
SDL_Surface* Tank::GetSurf(){return surf;}
SDL_Rect Tank::GetRect(){return rect;}
SDL_Rect Tank::GetSrcRect(){return srcrect;}
int Tank::GetRectx() {return rect.x;}
int Tank::GetRecty() {return rect.y;}
int Tank::GetRectw() {return rect.w;}
int Tank::GetRecth() {return rect.h;}

void Tank::SetLife(int a){life = a;}
void Tank::SetCpt_bullet(int a){cpt_bullet = a;} 
void Tank::SetSurf(const char *file){surf = IMG_Load(file);}
void Tank::SetRectx(int x){rect.x = x;}
void Tank::SetRecty(int y){rect.y = y;}
void Tank::SetRectw(int w){rect.w = w;}
void Tank::SetRecth(int h){rect.h = h;}
void Tank::SetSrcRectx(int x){srcrect.x = x;}
void Tank::SetSrcRecty(int y){srcrect.y = y;}
void Tank::SetSrcRectw(int w){srcrect.w = w;}
void Tank::SetSrcRecth(int h){srcrect.h = h;}*/