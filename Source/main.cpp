#include "Game.h"
#include  <stdlib.h>

// La funci�n principal del juego
int main(int argc, char *argv[]){
	CGame *navesGame = new CGame();//Cra un objeto usando apuntadores
	/*for (int i = 0; i < 15; i++)
	{
		int azar = rand();
		printf("%d\n", azar%16);
	}getchar();*/
		
	if(navesGame->Start())   
		navesGame->Finalize(); // Liberamos los recursos utilizados.
    
    return EXIT_SUCCESS;
}
