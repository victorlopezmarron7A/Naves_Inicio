#include <SDL.h>;
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
<<<<<<< HEAD
	void Iniciando();   

	Uint8 *keys;// Uint8 es un signo entero de 8 bits, Esta variable nos servira para ver si determinadas teclas estan o no pulsadas 
	SDL_Event event;// La variable event de tipo Evento en SDL nos servira para monitorizar el teclado
	
	SDL_Surface *screen;
	Nave * nave;
	Nave * enemigo;
=======
	void Iniciando();
	void MoverEnemigo();
	bool EsLimitePantalla(Nave * objeto, int bandera);

	Uint8 *keys; //Esta variable servirá para ver si determinadas teclas están o no pulsadas
	SDL_Event event; // La variable event de tipo evento de SDL servirá para monitorizar el teclado

	SDL_Surface * screen;

	Nave * nave;
	Nave *enemigoArreglo[10];
	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;
>>>>>>> 0ad159d502fc479c34d96d8966b4854fdfc603fd
	Estado estado;
	
};