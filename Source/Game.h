#include <SDL.h>
#include "Nave.h"

#define BORDE_IZQUIERDO  1<<0
#define BORDE_SUPERIOR   1<<1
#define BORDE_DERECHO    1<<2
#define BORDE_INFERIOR   1<<3


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
	bool EsLimitePantalla(Nave * objeto, int bandera);

	Uint8 *keys;// Uint8 es un signo entero de 8 bits, Esta variable nos servira para ver si determinadas teclas estan o no pulsadas 
	SDL_Event event;// La variable event de tipo Evento en SDL nos servira para monitorizar el teclado
	
	SDL_Surface *screen;
	Nave * nave;
	Nave * enemigo;
	Estado estado;
};