#include "Nave.h"
#include "configuracion.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w = sprite->WidthModule(0);
	h = sprite->HeightModule(0);
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



void Nave::MoverX(int posicion)
{
	x += posicion;
}

int Nave::ObtenerX(){
	return x;
}

int Nave::ObtenerY(){
	return y;
}

int Nave::ObtenerW(){
	return w;
}

int Nave::ObtenerH(){
	return h;
}
                