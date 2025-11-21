#include "Combatiente.h"
#include <algorithm>
#include <iostream>

Combatiente::Combatiente(const std::string &nombre_, int x, int y, int vida, int ataque)
    : Entidad(nombre_, x, y), vida(vida), ataque(ataque) {}

Combatiente::~Combatiente() {}

int Combatiente::getVida() const {
    return vida;
}

void Combatiente::setVida(int v) {
    vida = std::max(0, v);
}

int Combatiente::getAtaque() const {
    return ataque;
}

int Combatiente::atacar() const {
    return ataque;
}

void Combatiente::recibirDano(int cantidad) {
    vida = std::max(0, vida - cantidad);
}

void Combatiente::mostrarInfo() const {
    std::cout << "Combatiente: " << nombre << std::endl;
    std::cout << "Vida: " << vida << std::endl;
    std::cout << "Ataque: " << ataque << std::endl;
}
