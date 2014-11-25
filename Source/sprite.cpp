
#include  "Sprite.h"
#include <SDL.h>

Sprite::Sprite(SDL_Surface * screen)
{
this->screen = screen;
}

Sprite::~Sprite()
{
	SDL_FreeSurface(image);
}
void Sprite::CargarImagen(char * nombre)
{    
	image = SDL_LoadBMP(nombre);
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(image->format, 255, 0, 255));
	if (image == NULL)
	{
		printf("No se ha podido cargar la imagen");
		exit(1);
	}
	
}/*

void Sprite::PintarModulo(int nombre,int x, int y, int w, int h){
	SDL_Rect src;
	src.x = x;
	src.y = y;
    src.w = w;
    src.h = h;
    SDL_BlitSurface(image, &src, screen, NULL); 
}*/
void Sprite::PintarModulo(int nombre,int x, int y)
{
	SDL_Rect src;
	src.x = spriteDef.modulos[nombre].x;
	src.y = spriteDef.modulos[nombre].y;
    src.w = spriteDef.modulos[nombre].w;
    src.h = spriteDef.modulos[nombre].h;
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(image, &src, screen,&dest); 
}
int Sprite::WidthModule(int module)
{
	return spriteDef.modulos[module].w;
}
int Sprite::HeightModule(int module)
{
	return spriteDef.modulos[module].h;
}