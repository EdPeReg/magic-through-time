#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include <sprite.h>

enum{
     sheet,
     up,
     down,
     left,
     right,
     sleep,
     max_sprites
     };


class Personaje{
	public:
		Personaje(){}
		~Personaje(){}
		bool Init(int x, int y,char *namep);
		bool Load_spr(const char *filename);// iniciara el sprite y lo cortara
		void up_(){y-=vel;}
		void down_(){y+=vel;}
		void lef_(){x-=vel;}
		void right_(){x+=vel;}
		int getVida(){return n_vidas;}
	private:
		int x;
		int y;
		int vel;
		int nivel;
		int n_vidas;
		char *name;
		Sprite *spr[max_sprites];
};


#endif
