#include <SDL.h>
#include "Nave.h"
class CGame
{
public:
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

private:
	
	void Iniciando();                                        
	unsigned int x; 
	Uint8 *keys;// Uint8 es un signo entero de 8 bits, Esta variable nos servira para ver si determinadas teclas estan o no pulsadas 
	 SDL_Event event;// La variable event de tipo Evento en SDL nos servira para monitorizar el teclado

	SDL_Surface *screen;
	Nave *nave;
	Estado estado;
};