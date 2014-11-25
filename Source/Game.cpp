#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Configuracion.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame()
{
	tiempoFrameInicial = 0;
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{	delete(nave);
    // delete keys;
    
    delete *enemigoArreglo;
	SDL_FreeSurface(screen);
	SDL_Quit();
}


void CGame::Iniciando()
{
	if (SDL_Init(SDL_INIT_VIDEO)){

		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);
	/*if (screen == NULL)
	{
	screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	}
	if (screen == NULL)
	{
	screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	}*/
	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer Juego", NULL);

	nave = new Nave(screen, "../Data/minave.bmp", (WIDTH_SCREEN / 2), (HEIGHT_SCREEN - 80), MODULO_MINAVE_NAVE);
	menu = new Objeto(screen, "../Data/FondoMenu.bmp", 0, 0, MODULO_MENU_FONDO);
	textos = new Objeto(screen, "../data/Textos.bmp", 0, 0, MODULO_TEXTO_TITULO);
	fondo = new Objeto(screen, "../data/FondoJuego.bmp", 0, 0, MODULO_MENU_FONDO);
	for (int i = 0; i < 10; i++)
	{
		enemigoArreglo[i] = new Objeto(screen, "../Data/enemigo.bmp", i * 60, 0, MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);
	}

	tick = 0;
	
	opcionSeleccionada = MODULO_TEXTO_MENU_OPCION1;
	//delete nave;
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	int i = 0;
	while (salirJuego == false){

		//Maquina de estados
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO: //INICIALIZAR
			//printf("1. ESTADO_INICIANDO");
			Iniciando();
			estado = ESTADO_JUGANDO;// Se cambio de ESTADO_MENU
			break;
		case Estado::ESTADO_MENU: //MENÚ
			menu->Pintar();
			textos->Pintar(MODULO_TEXTO_TITULO,100,50);
			textos->Pintar(MODULO_TEXTO_NOMBRE, 300, 390);
			textos->Pintar(MODULO_TEXTO_MENU_OPCION1_SELECCIONADO, 110, 220);
			textos->Pintar(MODULO_TEXTO_MENU_OPCION2_SELECCIONADO, 110, 300);
			break;
		case Estado::ESTADO_JUGANDO:	//JUGAR	
			
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]->Actualizar();
			}
			MoverEnemigo();
			fondo->Pintar();
			//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_LEFT])
			{
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_IZQUIERDO))
					nave->MoverIzquierda();

			}

			if (keys[SDLK_RIGHT])
			{
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_DERECHO))
					nave->MoverDerecha();

			}//Los 3 casos siguientes son el primero aplicado a las demás direcciones


			//Mover en Y, arriba y abajo (opcional)
			if (keys[SDLK_UP])
			{
			if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_SUPERIOR))
			nave->MoverArriba();
			}

			if (keys[SDLK_DOWN])
			{
			if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_INFERIOR))
			nave->MoverAbajo();
			}
			//Aqui termina Y

			nave->Pintar();
			
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]->Pintar();
			}

			if (keys[SDLK_SPACE]) //Para evitar que se cicle en un estado, Pulsamos la tecla Abajo (en ese caso) y esa tecla nos dice que estamos en ESTADO_JUGANDO y nos manda a ESTADO_TERMINANDO;
			{
				printf("\n3. ESTADO_JUGANDO");
				estado = ESTADO_TERMINANDO;
			}
			break;

		case Estado::ESTADO_TERMINANDO: //SALIR
			printf("\n4. ESTADO_TERMINANDO");
			estado = ESTADO_MENU;
			break;

		case Estado::ESTADO_FINALIZANDO: //FINALIZAR
			printf("\n5. ESTADO_FINALIZANDO");
			getchar();
			salirJuego = true;
			break;
		}

		while (SDL_PollEvent(&event)) //SDL creará una lista de eventos ocurridos
		{
			if (event.type == SDL_QUIT) { salirJuego = true; }     //Si se detecta una salida de SDL o...
			if (event.type == SDL_KEYDOWN) {} //... una dirección (abajo) del teclado.
		}
		// ESTE CODIGO ESTARA PROVICIONALMENTE AQUI.
		SDL_Flip(screen);
		//CALCULANDO FPS
	    tiempoFrameFinal= SDL_GetTicks();
		while (tiempoFrameFinal < (tiempoFrameInicial + FPS_DELAY)){
			tiempoFrameFinal = SDL_GetTicks();
			SDL_Delay(2);

		}
		printf("Frame:%d Tiempo:%d Tiempo: %f Tiempo por Frame %d FPS:%f\n", tick, SDL_GetTicks(), (float)SDL_GetTicks()/ (float)tick, tiempoFrameFinal - tiempoFrameInicial,1000.0f /(float)(tiempoFrameFinal-tiempoFrameFinal));
		tiempoFrameInicial = tiempoFrameFinal;// Marcamos el inicio nuevamente
		tick++;

	}
	return true;
}

bool CGame::EsLimitePantalla(Objeto * objeto, int bandera)
{
	if (bandera & BORDE_IZQUIERDO)
		if (objeto->ObtenerX() <= 0)
			return true;
	if (bandera & BORDE_SUPERIOR)
		if (objeto->ObtenerY() <= 0)
			return true;
	if (bandera & BORDE_DERECHO)
		if (objeto->ObtenerX() >= WIDTH_SCREEN - objeto->ObtenerW())
			return true;
	if (bandera & BORDE_INFERIOR)
		if (objeto->ObtenerY() >= HEIGHT_SCREEN - objeto->ObtenerH())
			return true;
	return false;
}

void CGame::MoverEnemigo()
{
		for (int i = 0; i < 10; i++)
	{              //************//
			       //////////////PASO 0//////////////////
		if (enemigoArreglo[i]->ObtenerPasoActual() == 0)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_DERECHO))
			{
			enemigoArreglo[i]->MoverX(10);
			}
			else
			{
				
				enemigoArreglo[i]->IncrementarPasoActual();

			}
		              //////////////PASO 1/////////////
		if (enemigoArreglo[i]->ObtenerPasoActual() == 1)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_INFERIOR))
			{
			enemigoArreglo[i]->MoverY(10);//ABAJO
			}
			else
			{

				enemigoArreglo[i]->IncrementarPasoActual();

			}
		if (enemigoArreglo[i]->ObtenerPasoActual() == 2)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_IZQUIERDO))
			{

			enemigoArreglo[i]->MoverX(-10);//IZQUIERDA
			}
			else
			{
				
				enemigoArreglo[i]->IncrementarPasoActual();
			}//////////PASO3/////////////////////
		if (enemigoArreglo[i]->ObtenerPasoActual() == 3)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_SUPERIOR))
			{
			enemigoArreglo[i]->MoverY(-10);//ABAJO
			}
		
			else
			{

				enemigoArreglo[i]->IncrementarPasoActual();

			}
	}

}
void CGame::Menu(){
	for (int i = MODULO_TEXTO_MENU_OPCION1, j = 0; i <= MODULO_TEXTO_MENU_OPCION2; i++,j++)
	{
		if (i = opcionSeleccionada)
			textos->Pintar(i + 2, 200, 180 + (j * 80));
		else
			textos->Pintar(i , 200, 180 + (j * 80));
		}
};

bool Objeto::EstaColisionando(Objeto * b)
{
	return false;
}