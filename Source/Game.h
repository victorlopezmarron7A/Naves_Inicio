#pragma once
#include <SDL.h>
#include "Objeto.h"
#include "Nave.h"
class CGame
{
public:
	bool Start();
	static CGame instanceGame;
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

	CGame();
	void Finalize();

private:
	void Iniciando();
	void Menu();
	void MoverEnemigo();
	bool EsLimitePantalla(Objeto * objeto, int bandera);

	int opcionSeleccionada;
	Uint8 *keys; //Esta variable servir� para ver si determinadas teclas est�n o no pulsadas
	SDL_Event event; // La variable event de tipo evento de SDL servir� para monitorizar el teclado

	SDL_Surface * screen;
    Nave * nave;
	Objeto *enemigoArreglo[10];

	Objeto *menu; //Fondo del Menu
	Objeto *textos; //Textos del juego
	Objeto *fondo;//Fondo del juego



	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;

	Estado estado;
};