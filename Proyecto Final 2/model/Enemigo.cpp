//
// Created by Elian on 23/11/2025.
//

#include "Enemigo.h"
#include <iostream>


Enemigo::Enemigo(const std::string& nombre,char simbolo,int vida, int ataque, int defensa,Objeto* drop)
    : Combatiente(nombre, simbolo, vida, ataque, defensa),drop(drop) {}

Objeto* Enemigo::soltarObjeto() {
    return drop;
}

void Enemigo::realizarTurno(Combatiente& objetivo) {
    this->atacar(objetivo);
}
void Enemigo::recibirObjeto(Objeto* obj) {}


