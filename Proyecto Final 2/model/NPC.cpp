//
// Created by Elian on 22/11/2025.
//

#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& nombre, const std::string& dialogo)
: Entidad(nombre, 'N'), dialogo(dialogo) {}


std::string NPC::getDialogo() const {
    return dialogo;
}

void NPC::Interactuar() const {
    std::cout << nombre << ": " << dialogo << std::endl;
}
char NPC::getSimbolo() const {
    return simbolo;
}
