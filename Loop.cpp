#include "Loop.hpp"

#define DEFINE_Map_Width 1600
#define DEFINE_Map_Height 700
#define BULLETS_NUMBER 100
#define MISSILE_NUMBER 2

/**
Boucle principale
@author MAHTANI - BENHAMIDA
*/


Loop::Loop(Game *My_game)
{
	int px,py;
	int quit = 0;
	int game_start = 0;
	SDL_Event event;
	int randWallInit = 0;
	int shootTank[2];

	TTF_Font* Sans = TTF_OpenFont("Images/sans.ttf", 24);								// load la police
	SDL_Color color = {255, 255, 255, 255};  											// this is the color in rgb format for the text (ammo info)
	//SDL_Color couleurFond = {167, 103, 38, 230};  											// this is the color in rgb format for the background

	char chaine1[3], chaine2[3];														// affiche le nombres de bullets dispo pour chaque tank
	SDL_Surface* surfaceMessage1, *surfaceMessage2;
	SDL_Texture* Message1, *Message2;


	/**
	Definition des variables utilisees
	*/
	SDL_Rect r, r4, Message1_rect, Message2_rect, dstrect_lifeTank1, dstrect_lifeTank2, dstrect_explosion1, dstrect_explosion2, dstrect_ammo1, dstrect_ammo2;
	/*
	 Creation du menu start
	*/
	
	//SDL_Surface *icone = IMG_Load("Images/icone.png");

	SDL_Surface *start = IMG_Load("Images/Menus/start_menu.jpg"); 
	SDL_Texture *txt_start = SDL_CreateTextureFromSurface(My_game->renderer, start);
	SDL_Rect dstrect_start = {0, 0, DEFINE_Map_Width, DEFINE_Map_Height};

	SDL_Surface *violence = IMG_Load("Images/Menus/violence.png"); 
	SDL_Texture *txt_violence = SDL_CreateTextureFromSurface(My_game->renderer, violence);
	SDL_Rect dstrect_violence = {50, 500, 150, 150};

	SDL_Surface *pegi = IMG_Load("Images/Menus/pegi18.png"); 
	SDL_Texture *txt_pegi = SDL_CreateTextureFromSurface(My_game->renderer, pegi);
	SDL_Rect dstrect_pegi = {200, 500, 150, 150};

	SDL_Surface *pause = IMG_Load("Images/Menus/game_paused.jpg"); 
	SDL_Texture *txt_pause = SDL_CreateTextureFromSurface(My_game->renderer, pause);
	SDL_Rect dstrect_pause = {0, 0, DEFINE_Map_Width, DEFINE_Map_Height};

	SDL_Surface *options = IMG_Load("Images/Menus/options_menu.jpg"); 
	SDL_Texture *txt_options = SDL_CreateTextureFromSurface(My_game->renderer, options);
	SDL_Rect dstrect_options = {0, 0, DEFINE_Map_Width, DEFINE_Map_Height};

	SDL_Surface *explosion = IMG_Load("Images/Explosion.png"); 										// image d'explosion lorsqu'un tank perd tous ses points de vie
	SDL_Texture *txt_explosion = SDL_CreateTextureFromSurface(My_game->renderer, explosion);

	SDL_Surface *ammo = IMG_Load("Images/Ammo.png"); 
	SDL_Texture *txt_ammo = SDL_CreateTextureFromSurface(My_game->renderer, ammo);

	SDL_Surface *gameover = IMG_Load("Images/Menus/gameOver2.jpg"); 
	SDL_Texture *txt_gameover = SDL_CreateTextureFromSurface(My_game->renderer, gameover);
	SDL_Rect dstrect_gameover = {0, 0, DEFINE_Map_Width, DEFINE_Map_Height};

	SDL_Surface *lifeBar15 = IMG_Load("Images/HealthBars/lifeBar15.png");
	SDL_Surface *lifeBar14 = IMG_Load("Images/HealthBars/lifeBar14.png"); 
	SDL_Surface *lifeBar13 = IMG_Load("Images/HealthBars/lifeBar13.png"); 
	SDL_Surface *lifeBar12 = IMG_Load("Images/HealthBars/lifeBar12.png"); 
	SDL_Surface *lifeBar11 = IMG_Load("Images/HealthBars/lifeBar11.png"); 
	SDL_Surface *lifeBar10 = IMG_Load("Images/HealthBars/lifeBar10.png"); 
	SDL_Surface *lifeBar9 = IMG_Load("Images/HealthBars/lifeBar9.png"); 
	SDL_Surface *lifeBar8 = IMG_Load("Images/HealthBars/lifeBar8.png"); 
	SDL_Surface *lifeBar7 = IMG_Load("Images/HealthBars/lifeBar7.png"); 
	SDL_Surface *lifeBar6 = IMG_Load("Images/HealthBars/lifeBar6.png"); 
	SDL_Surface *lifeBar5 = IMG_Load("Images/HealthBars/lifeBar5.png"); 
	SDL_Surface *lifeBar4 = IMG_Load("Images/HealthBars/lifeBar4.png"); 
	SDL_Surface *lifeBar3 = IMG_Load("Images/HealthBars/lifeBar3.png"); 
	SDL_Surface *lifeBar2 = IMG_Load("Images/HealthBars/lifeBar2.png");
	SDL_Surface *lifeBar1 = IMG_Load("Images/HealthBars/lifeBar1.png"); 
	SDL_Surface *lifeBar0 = IMG_Load("Images/HealthBars/lifeBar0.png"); 
 
	SDL_Texture *txt_lifeBar15 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar15);
	SDL_Texture *txt_lifeBar14 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar14);
	SDL_Texture *txt_lifeBar13 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar13);
	SDL_Texture *txt_lifeBar12 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar12);
	SDL_Texture *txt_lifeBar11 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar11);
	SDL_Texture *txt_lifeBar10 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar10);
	SDL_Texture *txt_lifeBar9 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar9);
	SDL_Texture *txt_lifeBar8 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar8);
	SDL_Texture *txt_lifeBar7 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar7);
	SDL_Texture *txt_lifeBar6 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar6);
	SDL_Texture *txt_lifeBar5 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar5);
	SDL_Texture *txt_lifeBar4 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar4);
	SDL_Texture *txt_lifeBar3 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar3);
	SDL_Texture *txt_lifeBar2 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar2);
	SDL_Texture *txt_lifeBar1 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar1);
	SDL_Texture *txt_lifeBar0 = SDL_CreateTextureFromSurface(My_game->renderer, lifeBar0);

	Tank *tank1 = new Tank(1400, 50); 														// ajout du tank1	
	My_game->addTankToGame(*tank1);
	My_game->tankList[0].surf = IMG_Load("Images/Tank1/Capture.png");
	SDL_Texture *txt_tank1 = SDL_CreateTextureFromSurface(My_game->renderer, My_game->tankList[0].surf);

	Tank *tank2 = new Tank(100, 600); 														// ajout du tank2
	My_game->addTankToGame(*tank2);
	My_game->tankList[1].surf = IMG_Load("Images/Tank2/Capture.png");
	SDL_Texture *txt_tank2 = SDL_CreateTextureFromSurface(My_game->renderer, My_game->tankList[1].surf);

	SDL_Texture *txt_bul;
	Bullet *bul = new Bullet(5000, 5000, "Images/Shooters/Bullet/Bullet.png");												// on met la premiere bullet en dehors de la map
	for(unsigned int j = 0; j <= BULLETS_NUMBER; j++)																	// pour chaque bullet
	{
		My_game->tankList[0].bulletList.push_back(*bul);																// on les ajoute au tank
		My_game->tankList[1].bulletList.push_back(*bul);																// on les ajoute au tank
		txt_bul = SDL_CreateTextureFromSurface(My_game->renderer, My_game->tankList[0].bulletList[j].GetSurf());				// on cree une texture
		txt_bul = SDL_CreateTextureFromSurface(My_game->renderer, My_game->tankList[1].bulletList[j].GetSurf());				// on cree une texture
	}

	My_game->bonusList.push_back(Bonus_missiles("Images/Shooters/Missiles/icone.png")); 														// ajout du tank1	
	SDL_Texture *txt_bonus_missile = SDL_CreateTextureFromSurface(My_game->renderer, My_game->bonusList[0].GetSurf());

	SDL_Texture *txt_missile;
	Missile *missile = new Missile(5000, 5000, "Images/Shooters/Missiles/missiles.png");												// on met la premiere bullet en dehors de la map
	for(unsigned int j = 0; j <= MISSILE_NUMBER; j++)																	// pour chaque missile
	{
		My_game->tankList[0].missileList.push_back(*missile);				// on les ajoute au tank												// on les ajoute au tank
		My_game->tankList[1].missileList.push_back(*missile);
															
		txt_missile = SDL_CreateTextureFromSurface(My_game->renderer, My_game->tankList[0].missileList[0].GetSurf());				// on cree une texture
		txt_missile = SDL_CreateTextureFromSurface(My_game->renderer, My_game->tankList[1].missileList[0].GetSurf());				// on cree une texture
	}

	Collision collision;

	Mix_Music *music = Mix_LoadMUS( "Images/Sons/music.mp3");																	//Load the music
	if( music == NULL ) { cout << "error music";}																			//If there is a problem loading the music

	Mix_AllocateChannels(4); 																			//Allouer 32 canaux
	Mix_Volume(1, MIX_MAX_VOLUME); 																		//Mettre à mi-volume le post 1
	Mix_Chunk *tire = Mix_LoadWAV("Images/Sons/tire.wav");															//Créer un pointeur pour stocker un .WAV
	Mix_Chunk *touche = Mix_LoadWAV("Images/Sons/touche.wav");
	Mix_Chunk *perdu = Mix_LoadWAV("Images/Sons/perdu.wav");

	Mix_VolumeChunk(tire, MIX_MAX_VOLUME); //Mettre un volume pour ce wav
	Mix_VolumeChunk(touche, MIX_MAX_VOLUME); //Mettre un volume pour ce wav
	Mix_VolumeChunk(perdu, MIX_MAX_VOLUME);																		


	while (!quit)
    {
		if (SDL_PollEvent(&event))
		{

	        switch (event.type)
	        {
	           	case SDL_QUIT:
	               	quit = 1;
	               	break;


				case SDL_MOUSEBUTTONDOWN:      //lors d'un clic de la souris
					SDL_GetMouseState(&px, &py);
					printf("px=%d py=%d\n",px,py);
					
					if ((px>625) && (py>464) && (px<957) && (py<521) && (game_start == 0)){		// si on joue
						cout << "\n \t Let the game begin ! " << endl << endl;
						game_start = 1;
						Mix_PlayMusic(music, -1);								//Play the music
						break;}

					if ((px>625) && (py>525) && (px<957) && (py<585) && (game_start == 0)){		// si on clic sur option
						cout << "\n \t Menu options" << endl << endl;
						game_start = 2;
						break;}

					if ((px>415) && (py>475) && (px<680) && (py<515) && (game_start == 2)){		// si on quitte le menu des options
						cout << "\n \t Back from options " << endl << endl;
						game_start = 0;
						break;}

					if ((px>376) && (py>409) && (px<638) && (py<448) && (game_start == 3)){		// si on quitte le menu pause
						cout << "\n \t Back from pause " << endl << endl;
						game_start = 1;
						break;}

					if ((px>638) && (py>415) && (px<975) && (py<455) && (game_start == 1)){		// si on quitte a la fin d'une partie
						cout << "\n \t Quit from game over " << endl << endl;
						quit = 1;
						break;}

					if ((px>958) && (py>410) && (px<1225) && (py<450) && (game_start == 3)){		// si on quitte le menu pause
						cout << "\n \t Quit from pause " << endl << endl;
						quit = 1;
						break;}

					if ((px>625) && (py>587) && (px<957) && (py<644) && (game_start == 0)){		// si on clic sur quit
						cout << "\n \t Quitter" << endl << endl;
						quit = 1;
						break;}
	
				case SDL_KEYDOWN:
								
					switch (event.key.keysym.sym) 
					{  // Sous-switch de touches	
						case SDLK_ESCAPE: // touche echap ferme la fenetre
		        			quit = 1;
		        			break;

		        		case SDLK_RETURN: // touche entree met le jeu en pause MAIS IL ETEINT POUR L'INSTANT
							game_start = 3;
							break;

						case SDLK_v:
							cout << "Shoot1" << endl;
							shootTank[1] = My_game->tankList[1].cpt_bullet;
							Mix_PlayChannel(1, tire, 0);
							break;

						case SDLK_k:
							cout << "Shoot2" << endl;
							shootTank[0] = My_game->tankList[0].cpt_bullet;
							Mix_PlayChannel(2, tire, 0);
							break;
						default : break;
					}
				default : break;
			}
			My_game->tankList[0].move1(event);
			My_game->tankList[1].move2(event);
		}


	if(game_start == 0)														// tant qu'on est dans le menu
	{
		My_game->addToRenderer(dstrect_start, txt_start);
		My_game->addToRenderer(dstrect_violence, txt_violence);
		My_game->addToRenderer(dstrect_pegi, txt_pegi);
	}

	if(game_start == 2)														// si on clique sur le bouton options
	{
		My_game->addToRenderer(dstrect_options, txt_options);
	}

	if(game_start == 3)														// si on clique sur le bouton options
	{
		My_game->addToRenderer(dstrect_pause, txt_pause);
	}

	if(game_start == 1) 													// si l'on debute une partie
	{
		SDL_RenderClear(My_game->renderer);									//enleve le menu (et les autres textures) du renderer
		
		SDL_SetRenderDrawColor(My_game->renderer, 88, 41, 0, 230);			// couleur des murs

		My_game->initMapWalls();											// init les murs de la map
		for(int i=0; i<4; i++)
		{
			r = My_game->wallList[i].GetRect();										// initialisation des 4 murs
			SDL_RenderFillRect(My_game->renderer, &r);						// dessin des 4 murs
		}

		if(randWallInit == 0)
		{
			My_game->wallList.push_back(My_game->wallList[4].randomWall());		// ajout d'un mur randoms
			randWallInit = 1;
		}
		r4 = My_game->wallList[4].GetRect();
		SDL_RenderFillRect(My_game->renderer, &r4);					

		My_game->removeTankFromRenderer(*tank1);								// on supprime le tank de sa position precedente
		My_game->removeTankFromRenderer(*tank2);								// on supprime le tank de sa position precedente

		sprintf(chaine1, "%d", BULLETS_NUMBER - My_game->tankList[1].cpt_bullet);						// convertit un int en const char* afin de l'afficher
		surfaceMessage1 = TTF_RenderText_Solid(Sans, chaine1, color);				// surface contenant le message a afficher
		Message1 = SDL_CreateTextureFromSurface(My_game->renderer, surfaceMessage1);									
		Message1_rect.x = My_game->tankList[1].rect.x + 20;  							//controls the rect's x coordinate 
		Message1_rect.y = My_game->tankList[1].rect.y - 15; 							// controls the rect's y coordinte
		Message1_rect.w = 25; 															// controls the width of the rect
		Message1_rect.h = 25; 															// controls the height of the rect
		SDL_RenderCopy(My_game->renderer, Message1, NULL, &Message1_rect);

		sprintf(chaine2, "%d", BULLETS_NUMBER - My_game->tankList[0].cpt_bullet);														// convertit un int en const char* afin de l'afficher
		surfaceMessage2 = TTF_RenderText_Solid(Sans, chaine2, color);												// surface contenant le message a afficher
		Message2 = SDL_CreateTextureFromSurface(My_game->renderer, surfaceMessage2);
		Message2_rect.x = My_game->tankList[0].rect.x + 20;  														//controls the rect's x coordinate 
		Message2_rect.y = My_game->tankList[0].rect.y - 15; 														// controls the rect's y coordinte
		Message2_rect.w = 25; 																						// controls the width of the rect
		Message2_rect.h = 25; 																						// controls the height of the rect
		SDL_RenderCopy(My_game->renderer, Message2, NULL, &Message2_rect);

		dstrect_ammo1 = {My_game->tankList[0].rect.x, My_game->tankList[0].rect.y - 15, 20, 20};					// logo ammo pour le tank1
		dstrect_ammo2 = {My_game->tankList[1].rect.x, My_game->tankList[1].rect.y - 15, 20, 20};					// logo ammo pour le tank2
		My_game->addToRenderer(dstrect_ammo1, txt_ammo);
		My_game->addToRenderer(dstrect_ammo2, txt_ammo);

		My_game->addToRenderer(My_game->bonusList[0].GetRect(), txt_bonus_missile);
	
		
		// Si on roule sur un bonus missile : à terminer
					/*for(unsigned int cpt = 0; cpt < sizeof(My_game->bonusList); cpt++){
						bonusRect = My_game->bonusList[cpt].GetRect();
						if(SDL_HasIntersection(&(My_game->tankList[i].rect), &bonusRect) == SDL_TRUE){	// si un tank roule sur un bonus
							if(My_game->bonusList[0].GetType() != My_game->tankList[i].weapon)
							{
								My_game->tankList[i].weapon = My_game->bonusList[0].GetType();
								cout << "bonus" << endl;
							} 
							//My_game->bonusList[cpt]->gotBonus(Tank t, SDL_Renderer* renderer);
						}	
					}*/



		for(unsigned int i = 0; i < My_game->tankList.size();i++)										// On parcourt la liste des tanks
		{
			if((shootTank[i] == My_game->tankList[i].cpt_bullet) && (My_game->tankList[i].cpt_bullet < BULLETS_NUMBER))								// si le tank i tire 
			{	
				My_game->tankList[i].bulletList[My_game->tankList[i].cpt_bullet].SetRectx(My_game->tankList[i].rect.x + 25);		// position de depart du bullet partant a droite
				My_game->tankList[i].bulletList[My_game->tankList[i].cpt_bullet].SetRecty(My_game->tankList[i].rect.y + 10);

				My_game->tankList[i].cpt_bullet += 1;
				cout << "\t Il vous reste : "<< BULLETS_NUMBER - My_game->tankList[i].cpt_bullet << " bullets" << endl;
			}
		}
		
		if(My_game->tankList[1].weapon == 1)				// si on tire avec des bullets
		{
			for(int i = 0; i < My_game->tankList[1].cpt_bullet; i++)
			{
					My_game->tankList[1].bulletList[i].updateBulletPosition(My_game->tankList[1].orientation);												
					My_game->addToRenderer(My_game->tankList[1].bulletList[i].GetRect(), txt_bul, My_game->tankList[1].bulletList[i].GetSrcRect());
			}
		}
		if(My_game->tankList[0].weapon == 1) 
		{	
			for(int i = 0; i < My_game->tankList[0].cpt_bullet; i++)
			{
				My_game->tankList[0].bulletList[i].updateBulletPosition(My_game->tankList[0].orientation);
				My_game->addToRenderer(My_game->tankList[0].bulletList[i].GetRect(), txt_bul, My_game->tankList[0].bulletList[i].GetSrcRect());
			}
		}

		//Si on a changé de type d'arme/munitions
		/*if(My_game->tankList[1].weapon == 2) 
		{
			My_game->tankList[1].updateMissilePosition(My_game->tankList[1].missileList[0], My_game->tankList[0]);
			My_game->addToRenderer(My_game->tankList[1].missileList[0].GetRect(), txt_missile, My_game->tankList[1].missileList[0].GetSrcRect());
		}

		if(My_game->tankList[0].weapon == 2) 
		{	
			My_game->tankList[0].updateMissilePosition(My_game->tankList[0].missileList[0], My_game->tankList[1]);
			My_game->addToRenderer(My_game->tankList[0].missileList[0].GetRect(), txt_missile, My_game->tankList[0].missileList[0].GetSrcRect());
			tankList[0].missileList[0].GetRect(), txt_missile, My_game->tankList[0].missileList[0].GetSrcRect());
		}*/

		My_game->addToRenderer(My_game->tankList[0].rect, txt_tank1, My_game->tankList[0].srcrect);						// on ajoute le tank a la fenetre
		My_game->addToRenderer(My_game->tankList[1].rect, txt_tank2, My_game->tankList[1].srcrect);						// on ajoute le tank a la fenetre


		// Gestion des collisions du jeu
		(collision.bulletCollision(My_game));// Mix_PlayChannel(2, touche, 0);
		collision.tankCollision(&(My_game->tankList[0]), &(My_game->tankList[1]));
		collision.collisionTankWall(My_game);		
		if(collision.CollisionTankOponentBullet(BULLETS_NUMBER, My_game)) Mix_PlayChannel(2, touche, 0);
		if(collision.collisionBulletWall(My_game)) Mix_PlayChannel(2, touche, 0);


		dstrect_lifeTank1 = {My_game->tankList[0].rect.x - 15, My_game->tankList[0].rect.y + 45, 80, 30};								// points de vie du tank 2 (en bas a gauche)
		dstrect_lifeTank2 = {My_game->tankList[1].rect.x - 15, My_game->tankList[1].rect.y + 45, 80, 30};								// points de vie du tank 1 (en haut a droite)
		
		dstrect_explosion1 = {My_game->tankList[0].rect.x - 60, My_game->tankList[0].rect.y - 70, 200, 200};							// lieu d'explosion si le tank1 meurt
		dstrect_explosion2 = {My_game->tankList[1].rect.x - 60, My_game->tankList[1].rect.y - 70, 200, 200};							// lieu d'explosion si le tank2 meurt


		My_game->managingLife(dstrect_lifeTank1, dstrect_lifeTank2, txt_lifeBar15, txt_lifeBar14, txt_lifeBar13, txt_lifeBar12, txt_lifeBar11,
			txt_lifeBar10, txt_lifeBar9, txt_lifeBar8, txt_lifeBar7, txt_lifeBar6, txt_lifeBar5, txt_lifeBar4, txt_lifeBar3, txt_lifeBar2, txt_lifeBar1,
			dstrect_explosion1, dstrect_explosion2, txt_explosion);
		

		if(My_game->tankList[0].life < 1 || My_game->tankList[1].life < 1)
		{
			Mix_HaltMusic(); 																				//Arrête la musique
			//Mix_PlayChannel(3, perdu, 0);
			My_game->addToRenderer(dstrect_gameover, txt_gameover);
			cout << "\n End of game \n" << endl;
			SDL_Delay(5);
			//game_start = 0; 																					// Si on veut revenir au menu
		}
	}

	SDL_SetRenderDrawColor(My_game->renderer, 167, 103, 38, 230); 			// on met la fenetre en couleur alesan 
	SDL_RenderPresent(My_game->renderer); 									//appel du renderer

}

	Mix_FreeChunk(tire);
	Mix_FreeChunk(perdu);
	Mix_FreeChunk(touche);

	SDL_DestroyTexture(txt_tank1);
	SDL_DestroyTexture(txt_tank2);

	SDL_DestroyTexture(txt_start);
	SDL_DestroyTexture(txt_violence);
	SDL_DestroyTexture(txt_pegi);
	SDL_DestroyTexture(txt_options);
	SDL_DestroyTexture(Message1);
	SDL_DestroyTexture(Message2);
	SDL_DestroyTexture(txt_explosion);
	SDL_DestroyTexture(txt_gameover);
	SDL_DestroyTexture(txt_ammo);
	SDL_DestroyTexture(txt_pause);
	SDL_DestroyTexture(txt_bonus_missile);

	SDL_DestroyTexture(txt_lifeBar15);
	SDL_DestroyTexture(txt_lifeBar14);
	SDL_DestroyTexture(txt_lifeBar13);
	SDL_DestroyTexture(txt_lifeBar12);
	SDL_DestroyTexture(txt_lifeBar11);
	SDL_DestroyTexture(txt_lifeBar10);
	SDL_DestroyTexture(txt_lifeBar9);
	SDL_DestroyTexture(txt_lifeBar8);
	SDL_DestroyTexture(txt_lifeBar7);
	SDL_DestroyTexture(txt_lifeBar6);
	SDL_DestroyTexture(txt_lifeBar5);
	SDL_DestroyTexture(txt_lifeBar4);
	SDL_DestroyTexture(txt_lifeBar3);
	SDL_DestroyTexture(txt_lifeBar2);
	SDL_DestroyTexture(txt_lifeBar1);
	SDL_DestroyTexture(txt_lifeBar0);

	for(unsigned int i = 0; i < My_game->wallList.size()-1; i++)		// on supprime juste les murs crees 
	{
		delete &My_game->wallList[i];
	}
	SDL_DestroyTexture(txt_bul);
	SDL_DestroyTexture(txt_missile);
	for(unsigned int j = 0; j<sizeof(My_game->tankList); j++)
	{
		for(unsigned int i = 0; i<sizeof(My_game->tankList[j].bulletList); i++)
		{
			SDL_FreeSurface(My_game->tankList[j].bulletList[i].GetSurf());
		}

		for(unsigned int i = 0; i<sizeof(My_game->tankList[j].missileList); i++)
		{
			SDL_FreeSurface(My_game->tankList[j].missileList[i].GetSurf());
		}
		SDL_FreeSurface(My_game->tankList[j].surf);
	}

	SDL_FreeSurface(start);
	SDL_FreeSurface(pegi);
	SDL_FreeSurface(options);
	SDL_FreeSurface(violence);
	SDL_FreeSurface(surfaceMessage1);
	SDL_FreeSurface(surfaceMessage2);
	SDL_FreeSurface(explosion);
	SDL_FreeSurface(gameover);
	SDL_FreeSurface(ammo);
	SDL_FreeSurface(pause);

	SDL_FreeSurface(lifeBar15);
	SDL_FreeSurface(lifeBar14);
	SDL_FreeSurface(lifeBar13);
	SDL_FreeSurface(lifeBar12);
	SDL_FreeSurface(lifeBar11);
	SDL_FreeSurface(lifeBar10);
	SDL_FreeSurface(lifeBar9);
	SDL_FreeSurface(lifeBar8);
	SDL_FreeSurface(lifeBar7);
	SDL_FreeSurface(lifeBar6);
	SDL_FreeSurface(lifeBar5);
	SDL_FreeSurface(lifeBar4);
	SDL_FreeSurface(lifeBar3);
	SDL_FreeSurface(lifeBar2);
	SDL_FreeSurface(lifeBar1);
	SDL_FreeSurface(lifeBar0);

	Mix_FreeMusic(music);

	SDL_DestroyRenderer(My_game->renderer);
    SDL_DestroyWindow(My_game->window);
 		
 	Mix_CloseAudio(); //Fermeture de l'API
	SDL_Quit();

	delete &start;
	delete &txt_start;
	delete &violence;
	delete &txt_violence;
	delete &pegi;
	delete &txt_pegi;
	delete &pause;
	delete &txt_pause;
	delete &options;
	delete &txt_options;
	delete &explosion;
	delete &txt_explosion;
	delete &ammo;
	delete &txt_ammo;
	delete &gameover;
	delete &txt_gameover;
	delete &tire;
	delete &touche;
	delete &perdu;


	delete &My_game->tankList[0].bulletList;
	delete &My_game->tankList[1].bulletList;
	delete &My_game->tankList[0].missileList;
	delete &My_game->tankList[1].missileList;
	delete &bul;
	delete &My_game->wallList;
	delete &My_game->tankList;
	delete &tank1;
	delete &tank2;
	delete &My_game;

	return;

}