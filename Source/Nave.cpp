#include "Nave.h"
#include "configuracion.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	this->x = x;
	this->y = y;
	autoMovimiento = false;

}
void Nave:: Pintar(){
	sprite->PintarModulo(0,x,y);
}
void Nave::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;

}
void Nave::Actualizar()
{
	if (autoMovimiento)
	{
		MoverX(1);
	}
}

void Nave::Pintar()
{
	sprite->PintarModulo(0, x, y);
}

void Nave::MoverX(int posicion)
{
	x += posicion;
}

