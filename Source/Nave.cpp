#include "Nave.h"
#include "SDL.h"
#include "Objeto.h"

Nave::Nave(SDL_Surface*screen, char*rutaImagen, int x, int y, int module){
	nave = new Objeto(screen, rutaImagen, x, y, module);

}
void Nave::Pintar(){
	nave->Pintar();
}

void Nave::MoverAbajo(){
	nave->MoverY(15);
}
void Nave::MoverArriba(){
	nave->MoverY(-15);
}
void Nave::MoverDerecha(){
	nave->MoverX(15);
}
void Nave::MoverIzquierda(){
	nave->MoverX(-15);
}
Objeto* Nave::GetNaveObjeto(){
	return nave;
}