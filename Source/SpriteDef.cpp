# include "SpriteDef.h"
#include "configuracion.h"


SpriteDef::SpriteDef()
{
	modulos [0].id = MODULO_MINAVE_NAVE;
	modulos [0].x = 0;
	modulos [0].y = 0;
	modulos [0].w = 64;
	modulos [0].h = 64;

	modulos[1].id = MODULO_ENEMIGO_NAVE;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;

	modulos[2].id =MODULO_ENEMIGO_NAVE;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w =54;
	modulos[2].h = 61;

	modulos[3].id = MODULO_TEXTO_TITULO;
	modulos[3].x = 4;
	modulos[3].y = 67;
	modulos[3].w = 229;
	modulos[3].h = 107;

	modulos[4].id = MODULO_TEXTO_NOMBRE;
	modulos[4].x = 9;
	modulos[4].y = 202;
	modulos[4].w = 227;
	modulos[4].h = 77;

	modulos[5].id = MODULO_TEXTO_MENU_OPCION1;
	modulos[5].x = 300;
	modulos[5].y = 66;
	modulos[5].w = 96;
	modulos[5].h = 36;

	modulos[6].id = MODULO_TEXTO_MENU_OPCION2;
	modulos[6].x = 301;
	modulos[6].y = 303;
	modulos[6].w = 88;
	modulos[6].h = 36;

	modulos[7].id = MODULO_TEXTO_MENU_OPCION1_SELECCIONADO;
	modulos[7].x = 304;
	modulos[7].y = 208;
	modulos[7].w = 99;
	modulos[7].h = 33;

	modulos[8].id = MODULO_TEXTO_MENU_OPCION2_SELECCIONADO;
	modulos[8].x = 306;
	modulos[8].y = 245;
	modulos[8].w = 86;
	modulos[8].h = 35;
}



