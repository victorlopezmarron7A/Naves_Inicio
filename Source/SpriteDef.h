#ifndef _SPRITEDEF_H_
#define _SPRITEDEF_H_

class SpriteDef
{
public:
	struct Modulos
	{
	 int id;
	 int x;
	 int y;
	 int w;
	 int h;

	
	};
public:
	 Modulos modulos[1];
     SpriteDef();
};

#endif