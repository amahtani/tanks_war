#include "Game.hpp"
#include "Tank.hpp"
#include "Bullet.hpp"
#include "Missile.hpp"

/**
@author MAHTANI - BENHAMIDA
*/

/**
 Constructeur
 @param 2 entiers: la largeur et la hauteur de la carte
*/
Game::Game(int Map_Width, int Map_Height)
{
	SDL_Window *window;


	/**
	 Init SDL2
	*/
	SDL_Init(SDL_INIT_EVERYTHING);
	 													
	TTF_Init();

	/**
	Initialize SDL_mixer	
	*/
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) { return; }		
	
	
	/**
	Load the music
	*/
	Mix_Music *pegi = Mix_LoadMUS( "Images/Sons/pegi18.mp3" );
	/**
	If there was a problem loading the music							
	*/
	if( pegi == NULL ) { cout << "error pegi"; return; }	
	/**
	Play the music						
	*/
	if( Mix_PlayMusic( pegi, 1) == -1 ) { return; }								

	
	const char* title = "Tank War - MAHTANI & BEN HAMIDA";

	/**
		Creation de la fenetre d affichage
	*/
	window = SDL_CreateWindow(title, 100, 100, Map_Width, Map_Height, SDL_WINDOW_RESIZABLE);
	
	if(window == NULL)	{cout << "Impossible de creer l ecran de jeu !" << endl; return;}

	initRenderer(window);
	
	return;
}


/**
creer le renderer en noir
@param window
*/
void Game::initRenderer(SDL_Window *window) 	
{

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RenderClear(renderer);

	/**
	 on met la 1ere frame en noir 
	*/
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 230); 
	SDL_Rect rect = {0, 0, Map_Width, Map_Height}; 
	SDL_RenderFillRect(renderer, &rect);

	
	
	SDL_RenderPresent(renderer);

	return;
}

void Game::addToRenderer(SDL_Rect rect, SDL_Texture *text) 	// ajoute une image au renderer
{
	SDL_RenderCopy(renderer, text, NULL, &rect);
}

void Game::addToRenderer(SDL_Rect rect, SDL_Texture *text, SDL_Rect srcrect) 	// ajoute une image au renderer
{
	SDL_RenderCopy(renderer, text, &srcrect, &rect);
}

void Game::removeTankFromRenderer(Tank t)
{
	SDL_SetRenderDrawColor(renderer, 167, 103, 38, 230);	// on met le tank de la frame d'avant de la couleur du fond 
	SDL_Rect rect = t.rect;		//GetRect(); 
	SDL_RenderFillRect(renderer, &rect);
}

void Game::removeBulletFromRenderer(Bullet b)
{
	SDL_SetRenderDrawColor(renderer, 167, 103, 38, 230);	// on met le bullet de la frame d'avant de la couleur du fond 
	SDL_Rect rect = b.GetRect(); 
	SDL_RenderFillRect(renderer, &rect);
}

void Game::addTankToGame(Tank t)
{
	tankList.push_back(t);
}


void Game::initMapWalls()
{
	Wall *g = new Wall(0,0,1600,5);	// mur gauche
	wallList.push_back(*g);

	Wall *h = new Wall(0,0,5,700);	// mur haut
	wallList.push_back(*h);

	Wall *d = new Wall(1595,0,5,700);	//mur droite
	wallList.push_back(*d);

	Wall *b = new Wall(0,695,1600,5);	//mur en bas
	wallList.push_back(*b);

}

void Game::managingLife(SDL_Rect dstrect_lifeTank1, SDL_Rect dstrect_lifeTank2, SDL_Texture* txt_lifeBar15,SDL_Texture* txt_lifeBar14, 
			SDL_Texture* txt_lifeBar13, SDL_Texture* txt_lifeBar12, SDL_Texture* txt_lifeBar11, SDL_Texture* txt_lifeBar10, SDL_Texture* txt_lifeBar9, 
			SDL_Texture* txt_lifeBar8, SDL_Texture* txt_lifeBar7, SDL_Texture* txt_lifeBar6, SDL_Texture* txt_lifeBar5, SDL_Texture* txt_lifeBar4,
			SDL_Texture* txt_lifeBar3, SDL_Texture* txt_lifeBar2, SDL_Texture* txt_lifeBar1, SDL_Rect dstrect_explosion1, SDL_Rect dstrect_explosion2, 
			SDL_Texture* txt_explosion)
{
	for(unsigned int i = 0; i<sizeof(tankList);i++){
			switch(tankList[i].life)
			{
				case 15:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar15);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar15);}
					break;

			    case 14:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar14);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar14);}
					break;

				case 13:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar13);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar13);}
					break;

				case 12:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar12);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar12);}
					break;

				case 11:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar11);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar11);}
					break;

				case 10:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar10);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar10);}
					break;

				case 9:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar9);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar9);}
					break;

				case 8:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar8);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar8);}
					break;

				case 7:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar7);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar7);}
					break;

				case 6:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar6);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar6);}
					break;

				case 5:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar5);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar5);}
					break;


				case 4:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar4);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar4);}
					break;


				case 3:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar3);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar3);}
					break;


				case 2:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar2);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar2);}
					break;


				case 1:
					if(i == 0){addToRenderer(dstrect_lifeTank1, txt_lifeBar1);}
					else if (i==1){addToRenderer(dstrect_lifeTank2, txt_lifeBar1);}
					break;


				case 0:
					if(i == 0){
								addToRenderer(dstrect_explosion1, txt_explosion);		// trouver un moyen de faire tourner le jeu pendant l'animation de l'explosion
								cout << "\n Bleu est mort par Vert \n" << endl;
							}
					else if (i==1){
								addToRenderer(dstrect_explosion2, txt_explosion);
								cout << "\n Vert est mort par Bleu \n" << endl;}
					break;

				default :
					if(i == 0){addToRenderer(dstrect_explosion1, txt_explosion);cout << "\n Bleu est mort par Vert \n" << endl;}
					else if (i==1){addToRenderer(dstrect_explosion2, txt_explosion);cout << "\n Vert est mort par Bleu \n" << endl;}
					break;

			}
		}
}