#include <string.h>
#include <personaje.h>

bool Personaje::Init(int x, int y, char *namep){
	this->x = x;
	this->y = y;
	name = namep;
	vel = 1;
	n_vidas = 3;
	printf("personaje %s posx %d posy %d\n",name,this->x,this->y);
	return true;
}

bool Personaje::Load_spr(const char *filename){
	/*carga los sprites y los corta*/

	spr[sheet] = new Sprite(filename,1,1);
	spr[sheet]->setTransparency(255,0,255); //aplica transparencia
	/* cut sprites */

	/* down */
	spr[down] = new Sprite(spr[sheet]->getRect(0, 0, 32 * 6, 32), 6, 60);

	/* up */
	spr[up] = new Sprite(spr[sheet]->getRect(0, 32 * 3, 32 * 6, 32), 6, 60);

	/* left */
	spr[left] = new Sprite(spr[sheet]->getRect(0, 32 * 1, 32 * 6, 32), 6, 60);
	spr[left]->reverseAnimation();

	/* right */
	spr[right] = new Sprite(spr[sheet]->getRect(0, 32 * 2, 32 * 6, 32), 6, 60);
	spr[right]->reverseAnimation();


	return true;
}
