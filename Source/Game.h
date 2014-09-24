#include <SDL.h>
class CGame
{
public:
	bool Start();
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO
	};
	static CGame instanceGame;

	CGame();
	void Finalize();


private:
	//void iniciando();
	SDL_Surface *screen;
    SDL_Surface *nave;
	Estado estado;
};