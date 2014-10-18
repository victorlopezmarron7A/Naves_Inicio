#ifndef _NAVE_H_
#define _NAVE_H_
#include "sprite.h"
#include "SDL.h"

class Nave{
    Sprite *sprite;
     int x;
	 int y;
	 bool autoMovimiento;
public:
	void Mover(int posicion);
	Nave(SDL_Surface * screen,char * rutaImagen,int x, int y);//Constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void Pintar();
	void Actualizar();
};

#endif