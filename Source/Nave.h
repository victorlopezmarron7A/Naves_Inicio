#ifndef _NAVE_H_
#define _NAVE_H_
#include "sprite.h"
#include "SDL.h"

class Nave
{
    Sprite *sprite;
     int x;
	 int y;
	 int w;
	 int h;
	 bool autoMovimiento;
	 int pasoActual;
	 int pasoLimite;
public:
	void MoverX(int posicion);
	Nave(SDL_Surface * screen,char * rutaImagen,int x, int y);//Constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void SetPasoLimite(int pasos);
	int ObtenerPasoActual();
	void IncrementarPasoActual();
	void Pintar();
	void Actualizar();
	int ObtenerX();
	int ObtenerY();
	int ObtenerW();
	int ObtenerH();
};

#endif