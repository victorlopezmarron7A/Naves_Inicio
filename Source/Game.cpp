#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	//ACT2:Mal, Aqui debes de darle a "estado" su valor inicial, para indicar en que estado iniciara. Si la dejas asi, sola, el juego nunca tendra estado inicial.
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO: //INICIALIZAR
			//Iniciando(); 
			{
				nave=SDL_LoadBMP("../DATA/MiNave.bmp");
				nave=IMG_LoadJPG_RW(SDL_RWFromfile("..Data/umi.jpg","rb"));
				nave=IMG_LoadJPG_RW(SDL_RWFromfile("..Data/tools.jpg","rb"));
				nave=IMG_LoadPNG_RW(SDL_RWFromfile("..Data/dados.jpg","rb"));
				nave=IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				fuente.x = 580;
				fuente.y = 381;
				fuente.w = 325;
				fuente.h = 20;
				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w = 100;
				destino.h = fuente.h;
				SDL_BlitSurface(nave, &fuente, screen, &destino);
							}
			break;
		case Estado::ESTADO_MENU:	   //MENU	
			break;
		case Estado::ESTADO_JUGANDO: //JUGAR
			break;
		case Estado::ESTADO_TERMINADO: //TERMINAR
			break;
		case Estado::ESTADO_FINALIZADO:  //FINALIZAR
				salirJuego = true;
			break;
		};
    }
	return true;
}
