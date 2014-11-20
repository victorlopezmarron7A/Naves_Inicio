#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <SDL.h>
#include "SpriteDef.h"

class Sprite // Un Sprite es un manipulador de imagenes
{  
	SDL_Surface * image;// Imagen a manipular
	SDL_Surface * screen;// La pantalla
	SpriteDef spriteDef;  // Definiciones de sprite
public:
	Sprite(SDL_Surface * screen);// Constructor que recibe pantalla
	~Sprite();// Destructor, se llama con ´delete´
	void CargarImagen(char * nombre);
	//void PintarModulo(int nombre, int x, int y, int w, int h);
	void PintarModulo(int nombre, int x, int y);
	int WidthModule(int module);
	int HeightModule(int module);
};
#endif