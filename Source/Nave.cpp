#include "Nave.h"
#include "Configuracion.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
<<<<<<< HEAD
	this->x = x;
	this->y = y;
	autoMovimiento = false;
=======
	w = sprite->WidthModule(0);
	h = sprite->HeightModule(0);
	this->x = x;
	this->y = y;
	autoMovimiento = false;
	pasoActual = 0;
	pasoLimite = -1;
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
	if (pasoLimite > 0)
	{
		//pasoActual++;
		if (pasoActual >= pasoLimite)
			pasoActual = 0;
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
>>>>>>> 0ad159d502fc479c34d96d8966b4854fdfc603fd

void Nave::MoverY(int posicion)
{
	y += posicion;
}

int Nave::ObtenerX()
{
	return x;
}

int Nave::ObtenerY()
{
	return y;
}

int Nave::ObtenerW()
{
	return w;
}
<<<<<<< HEAD
void Nave::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;
=======
>>>>>>> 0ad159d502fc479c34d96d8966b4854fdfc603fd

int Nave::ObtenerH()
{
	return h;
}
<<<<<<< HEAD
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

=======

void Nave::SetPasoLimite(int pasos)
{
	this->pasoLimite = pasos;
}

int Nave::ObtenerPasoActual()
{
	return pasoActual;
}

void Nave::IncrementarPasoActual()
{
	pasoActual++;
}
>>>>>>> 0ad159d502fc479c34d96d8966b4854fdfc603fd
