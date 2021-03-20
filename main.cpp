#include "Loop.hpp"

#define DEFINE_Map_Width 1600
#define DEFINE_Map_Height 700

/**
Programme principal
@author MAHTANI - BENHAMIDA


*/


int main()
{
	

	/*
	 Creation d'une game
	*/
	Game *My_game = new Game(DEFINE_Map_Width, DEFINE_Map_Height);

	Loop *boucle = new Loop(My_game);

	delete &My_game;
	delete &boucle; 

	return 1;
}