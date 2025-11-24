//
// Created by Elian on 22/11/2025.
//

#include "Combatiente.h"
#include <iostream>

// Constructor
Combatiente::Combatiente(const std::string& nombre,char simbolo, int vida, int ataque, int defensa)
: Entidad(nombre, simbolo), vida(vida), vidaMax(vida), ataque(ataque), defensa(defensa) {}

// Getters
int Combatiente::getVida() const {
    return vida;
}
int Combatiente::getVidaMax() const {
    return vidaMax;
}
int Combatiente::getAtaque() const {
    return ataque;
}
int Combatiente::getDefensa() const {
    return defensa;
}

// Setters
void Combatiente::setVida(int v) {
    vida = v;
}
void Combatiente::setAtaque(int a) {
    ataque = a;
}
void Combatiente::setDefensa(int d) {
    defensa = d;
}
void Combatiente::setVidaMax(int vm) {
    vidaMax = vm;
}

// Mejoras
void Combatiente::mejorarAtaque(int cant) {
    ataque += cant;
}
void Combatiente::mejorarDefensa(int cant) {
    defensa += cant;
}
void Combatiente::mejorarVida(int cant) {
    vidaMax += cant;
}

// Recibir daño
void Combatiente::recibirDano(int cantidad) {
    int danoRecibido = cantidad - defensa;
    if (danoRecibido < 0) {
        danoRecibido = 0;
    }

    vida -= danoRecibido;
    if (vida < 0) {
        vida = 0;
    }

    std::cout << nombre << " recibe " << danoRecibido << " de dano. su vida restante es: " << vida << std::endl;
}

// Atacar
void Combatiente::atacar(Combatiente& objetivo) {
    std::cout << nombre << " ataca causando " << ataque << " de dano." << std::endl;
    objetivo.recibirDano(ataque);
}

// Restaurar vida
void Combatiente::restaurarVida() {
    vida = vidaMax;
}
