#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "configuracion.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame()
{
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);
	//ACT3: Mal este codigo no debe de ir aqui
	/////ACT3: Mal, esta seccion no debe de ir aqui, si no en el metodo iniciando.
	//if (SDL_Init(SDL_INIT_VIDEO)<0)//si regresa 1 el init de video si se activo y regresa -1 si no se pudo iniciar. 
	//{
	//	printf("No se pudo iniciar SDL: %s\n", SDL_GetError());//
	//	exit(EXIT_FAILURE);
	//}
	//screen= SDL_SetVideoMode(WIDTH_SCREEN,HEIGHT_SCREEN,24,SDL_HWSURFACE);//(ancho,alto,bpp,bandera)
	//if (screen==NULL)
	//{
	//	printf("No se puede inicializar el modo grafico: \n",SDL_GetError());
	//	exit(1);
	//}
	////ACT3: Hasta aqui.
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete(nave);
	SDL_FreeSurface(screen);
	SDL_Quit();
}
void CGame::Iniciando(){
	///ACT3:Mal. Aqui hacia falta este codigo
	if (SDL_Init(SDL_INIT_VIDEO) < 0)//si regresa 1 el init de video si se activo y regresa -1 si no se pudo iniciar. 
	{
		printf("No se pudo iniciar SDL: %s\n", SDL_GetError());//
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);//(ancho,alto,bpp,bandera)
	if (screen == NULL)
	{
		 printf("Error %s ", SDL_GetError());
         exit(EXIT_FAILURE);
     }
     SDL_WM_SetCaption( "Mi primer Juego", NULL );
    
     nave  = new Nave(screen,"../Data/Minave.bmp",(WIDTH_SCREEN/2)/*-(sprite->WidthModule(0)/2)*/,(HEIGHT_SCREEN-80)/*-(sprite->HeightModule(0)*/);
     enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);
	 enemigo-> SetAutoMovimiento(true);
	 //delete nave;

}
	
bool CGame::Start()

{

	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	int i = 0;
	while (salirJuego == false){

		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			printf("\n1. ESTADO_INICIANDO");
			Iniciando();
			estado = ESTADO_MENU;
			break;

		case Estado::ESTADO_MENU:
			if (i == 0)
			{
				printf("\n2. ESTADO_MENU");
				Estado::ESTADO_FINALIZANDO://ESTO NO TE LLEVA A NINGUNA PARTE
				I = 1;//ESTA VARIABLE NO EXISTE
			}
			else
			{
				printf("\n2. ESTADO_MENU");
				estado = ESTADO_FINALIZANDO;
			}
			break;
		case Estado::ESTADO_JUGANDO:
			enemigo->Actualizar();
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT]){
				nave->Mover(1);

			}
			nave->Pintar();
			enemigo->Pintar();
			
			if (keys[SDLK_DOWN])
			{
				printf("\n3. ESTADO_JUGANDO");
				estado = ESTADO_TERMINANDO;
			}
			break;

		case Estado::ESTADO_TERMINANDO:
			printf("\n4. ESTADO_TERMUNANDO");
			estado = ESTADO_MENU;
			break;
		
		case Estado ::ESTADO_FINALIZANDO:
			printf("\n5. ESTADO_FINALIZANDO");
			getchar();
            salirJuego = true;
			break;
		}
		while(SDL_PollEvent(&event)) // Aqui SDL creara una lista de eventos ocurrido
		{
			if(event.type == SDL_QUIT) {salirJuego = true;} // Si se detect una salida de SDL o....
			if(event.type == SDL_KEYDOWN) {  }

		}

		// Este codigo estara provicionalmente aqui.
		SDL_Flip(screen);
	}
	return true;

}
