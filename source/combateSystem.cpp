#include "combateSystem.hpp"

bool Combate::LoadPersonaje(Personaje* newPerson){
    personaje = newPerson;
    if(personaje != NULL){
        return true;
    }
    return false;
}
