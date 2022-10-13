#include <graphic.h>
#include <personaje.h>
#include "combateSystem.hpp"
#include <string.h>
Window *w;
SDL_Joystick *pad;
SDL_Event event;
Personaje *edward;
Combate *combateSystem;

int control_press(){
	int button_down;
	int button_up;
	while(SDL_PollEvent(&event)){
		//button down
		switch(event.type){
			case SDL_JOYBUTTONDOWN:
				switch(event.jbutton.button){
					case PS2_CROSS:    return PS2_CROSS;   
					case PS2_CIRCULE:  return PS2_CIRCULE; 
					case PS2_TRIANGLE: return PS2_TRIANGLE;
					case PS2_SCUARE:   return PS2_SCUARE;  
					case PS2_START:    return PS2_START;   
					case PS2_SELECT:   return PS2_SELECT;  
					case PS2_L1:       return PS2_L1;      
					case PS2_L2:       return PS2_L2;      
					case PS2_R1:       return PS2_R2;      
					case PS2_UP:       return PS2_UP;      
					case PS2_DOWN:     return PS2_DOWN;    
					case PS2_LEFT:     return PS2_LEFT;    
					case PS2_RIGHT:    return PS2_RIGHT;   
					default: return -1;
				}//button down
			/*case SDL_JOYBUTTONUP:
				switch(event.jbutton.button){
					case PS2_CROSS:    button_up = PS2_CROSS;    break;
					case PS2_CIRCULE:  button_up = PS2_CIRCULE;  break;
					case PS2_TRIANGLE: button_up = PS2_TRIANGLE; break;
					case PS2_SCUARE:   button_up = PS2_SCUARE;   break;
					case PS2_START:    button_up = PS2_START;    break;
					case PS2_SELECT:   button_up = PS2_SELECT;   break;
					case PS2_L1:       button_up = PS2_L1;       break;
					case PS2_L2:       button_up = PS2_L2;       break;
					case PS2_R1:       button_up = PS2_R2;       break;
					case PS2_UP:       button_up = PS2_UP;       break;
					case PS2_DOWN:     button_up = PS2_DOWN;     break;
					case PS2_LEFT:     button_up = PS2_LEFT;     break;
					case PS2_RIGHT:    button_up = PS2_RIGHT;    break;
					default: button_up = -1;
				}//button down*/

		}//switch
	}//while

	return -1;
}

int main(int argc, char** argv){
	w = new Window;
	w = Init_Window(320,240,16,"game");

	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	pad = SDL_JoystickOpen(0);

	edward = new Personaje;
	edward->Init(100,10,"edward");//iniciamos personaje
	edward->Load_spr("cdrom:\\DATA\\SHEET.BMP");//cargamos sprites

	combateSystem = new Combate;
	combateSystem->LoadPersonaje(edward);
	int dir;
	while(1){
		char name[20];
		sprintf(name,"Edward nivel_vida %d",edward->getVida());
		w->draw_text(name,10,30,RGB(14,255,25));
		
		SDL_JoystickUpdate();
		dir = control_press();
		printf("dir: %d\n",dir);
		if(dir == PS2_CROSS){w->draw_text("Cross button down",10,10,RGB(255,255,255));}
		if(dir == PS2_CIRCULE){w->draw_text("Circule button down",10,10,RGB(255,255,255));}
		if(dir == PS2_SCUARE){w->draw_text("SCUARE button down",10,10,RGB(255,255,255));}
		if(dir == PS2_TRIANGLE){w->draw_text("Triangle button down",10,10,RGB(255,255,255));}
		if(dir == PS2_DOWN){w->draw_text("down pad button down",10,10,RGB(255,255,255));}// no funciona bien con button debe usarse hat
		if(dir == PS2_UP){w->draw_text("up pad button down",10,10,RGB(255,255,255));}
		if(dir == PS2_LEFT){w->draw_text("LEFT pad button down",10,10,RGB(255,255,255));}
		if(dir == PS2_RIGHT){w->draw_text("RIGHT pad button down",10,10,RGB(255,255,255));}
		/*while(SDL_PollEvent(&event)){
			if(event.type == SDL_JOYBUTTONDOWN){
				if(event.jbutton.button == PS2_SCUARE){
					w->draw_text("button down",10,10,RGB(255,255,255));

				}
			}
		}*/

		

		
		
		w->flip();
		w->clean();
	}


	return 0;
}
