/**
@author MAHTANI - BENHAMIDA
*/
#include "Collision.hpp"

Collision::Collision(){}

bool Collision::bulletCollision(Game* My_game)								// detecte et supprime 2 bullets s'ils entrent en collision
{
	SDL_Rect bul1, bul2;
	for(unsigned int a = 0; a < My_game->tankList[0].bulletList.size(); a++)
	{
		bul1 = My_game->tankList[0].bulletList[a].GetRect();
		for(unsigned int i = 0; i < My_game->tankList[1].bulletList.size(); i++)
		{
			bul2 = My_game->tankList[1].bulletList[i].GetRect();
			if(SDL_HasIntersection(&(bul1), &(bul2)) == SDL_TRUE)
			{
				My_game->tankList[0].bulletList[a].SetRectx(50000);
				My_game->tankList[1].bulletList[i].SetRectx(50000);		// on met la bullet en dehors de la map pour qu'elle continue de traverser le tank (et de lui faire perdre des pv)
				return true;
			}
		}
	}
	return false;
}


bool Collision::CollisionTankOponentBullet(unsigned int BULLETS_NUMBER, Game* My_game)
{
	SDL_Rect bulletRect;
	for(unsigned int a = 0; a < BULLETS_NUMBER; a++){																// verifie les collisions entre bullets du tank1 et tank0
		bulletRect = My_game->tankList[1].bulletList[a].GetRect();
		if(SDL_HasIntersection(&(bulletRect), &(My_game->tankList[0].rect)) == SDL_TRUE){		// return true s'il il y intersection entre 2 rect
			cout << "\n Vert touche Bleu \n" << endl;
			My_game->tankList[1].bulletList[a].SetRectx(5000);														// on met la bullet en dehors de la map pour qu'elle continue de traverser le tank (et de lui faire perdre des pv)
			My_game->tankList[1].bulletList[a].SetRecty(5000);

			My_game->tankList[0].life -= My_game->tankList[1].bulletList[a].GetDegat();
			return true;																			// on perd les pv 3 par 3 avec ces missiles
		}
	}

	for(unsigned int a = 0; a < BULLETS_NUMBER; a++){																// verifie les collisions entre bullets du tank0 et tank1
		bulletRect = My_game->tankList[0].bulletList[a].GetRect();
		if(SDL_HasIntersection(&(bulletRect), &(My_game->tankList[1].rect)) == SDL_TRUE){		// return true s'il il y intersection entre 2 rect
			cout << "\n Bleu touche Vert \n" << endl;

			My_game->tankList[0].bulletList[a].SetRectx(50000);														// on met la bullet en dehors de la map pour qu'elle continue de traverser le tank (et de lui faire perdre des pv)

			My_game->tankList[1].life -= My_game->tankList[0].bulletList[a].GetDegat();
			return true;
		}
	}
	return false;

}

void Collision::tankCollision(Tank* t1, Tank* t2)																					// detecte et supprime 2 bullets s'ils entrent en collision
{
	SDL_Rect tank1, tank2;
	tank1 = t1->rect;
	tank2 = t2->rect;																					// variable temporaire
	
	if(SDL_HasIntersection(&tank1, &tank2) == SDL_TRUE)
	{
		t1->updateToFirstPosition();
		t2->updateToFirstPosition();
		cout << " Repulsion des 2 tanks " << endl << endl;	
	}
}

void Collision::collisionTankWall(Game* My_game)																				// gere les collisions entre les bords de la map et les tanks
{
	SDL_Rect wall, tankrect;
	for(unsigned int i = 0; i < My_game->tankList.size(); i++)
	{
		tankrect = My_game->tankList[i].rect;
		for(unsigned int j = 0; j < My_game->wallList.size()-1; j++)														// on ne rebondit pas sur le dernier mur (l'aleatoire)
		{
			wall = My_game->wallList[j].GetRect();																		// variable temporaire
			if(SDL_HasIntersection(&wall, &tankrect) == SDL_TRUE)
			{
				if(My_game->tankList[i].orientation == 1)	{My_game->tankList[i].moveTankLeft();}							//mouvements opposes lorsqu'on rencontre un mur
				if(My_game->tankList[i].orientation == 2)	{My_game->tankList[i].moveTankRight();}							// permet de ne pas traverser les murs
				if(My_game->tankList[i].orientation == 3)	{My_game->tankList[i].moveTankUp();}
				if(My_game->tankList[i].orientation == 4)	{My_game->tankList[i].moveTankDown();}
			}
		}
	}
}


bool Collision::collisionBulletWall(Game* My_game)			// supprime une bullet si elle rentre dans un mur
{
	SDL_Rect wall, bull, rect;
	for(unsigned int a = 0; a < My_game->tankList.size(); a++)
	{
		for(unsigned int i = 0; i < My_game->tankList[a].bulletList.size(); i++)
		{
			bull = My_game->tankList[a].bulletList[i].GetRect();
			for(unsigned int j = 0; j < My_game->wallList.size(); j++)
			{
				wall = My_game->wallList[j].GetRect();												// variable temporaire
				if(SDL_HasIntersection(&(bull), &(wall)) == SDL_TRUE)
				{
					My_game->tankList[a].bulletList[i].SetRectx(50000);		// on met la bullet en dehors de la map pour qu'elle continue de traverser le tank (et de lui faire perdre des pv)
					return true;
				}
			}
		}
	}
	return false;
}