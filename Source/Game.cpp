#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);

	if (SDL_Init(SDL_INIT_VIDEO)<0)//si regresa 1 el init de video si se activo y regresa -1 si no se pudo iniciar. 
	{
		printf("No se pudo iniciar SDL: %s\n", SDL_GetError());//
		exit(EXIT_FAILURE);
	}
	screen= SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);//(ancho,alto,bpp,bandera)
	if (screen==NULL)
	{
		printf("No se puede inicializar el modo grafico: \n",SDL_GetError());
		exit(1);
	}
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
     SDL_Quit();
}
void CGame :: Iniciando(){
	if (screen == NULL){
printf("Error %s ", SDL_GetError());
exit(EXIT_FAILURE);
}
SDL_WM_SetCaption( "Mi primer Juego", NULL );

}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			//Iniciando();
			{
				/*nave=SDL_LoadBMP("../Data/MiNave.bmp");*/
				nave=IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				fuente.x = 582;
				fuente.y = 383;
				fuente.w = 321;
				fuente.h = 16;
				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w =100;
				destino.h = fuente.h;
				SDL_BlitSurface(nave,&fuente,screen,&destino);
			}
			break;
		case Estado ::ESTADO_MENU:	
			break;
		case Estado ::ESTADO_JUGANDO:
			break;
		case Estado ::ESTADO_TERMINANDO:
			break;
		case Estado ::ESTADO_FINALIZANDO:
			salirJuego = true;
			break;
		};
		SDL_Flip(screen);
    }
	return true;
}
