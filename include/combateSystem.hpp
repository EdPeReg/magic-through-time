#ifndef COMBATE_H_
#define COMBATE_H_

#include <personaje.h>

class Combate{
    public:
        Combate(){}
        ~Combate(){}
        bool LoadPersonaje(Personaje* newPerson);
    private:
        Personaje* personaje;
};

#endif 
