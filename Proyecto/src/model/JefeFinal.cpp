#include "JefeFinal.h"
#include "Jugador.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

JefeFinal::JefeFinal(const std::string& nombre, int x, int y, int vida, int ataque) : Jefe(nombre, x, y, vida, ataque), fase(1) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void JefeFinal::atacar(Jugador& objetivo) {
    int chance = rand() % 100;

    if (chance < 15) {
        ataqueEspecial(objetivo);
    } else {
        std::cout << nombre << " ataca al jugador causando " << ataque << " de dano.\n";
        objetivo.setVida(objetivo.getVida() - ataque);
    }
}

void JefeFinal::ataqueEspecial(Jugador& objetivo) {
    int danoEspecial = ataque * fase;
    std::cout << nombre << " usa ataque especial de fase " << fase << " y causa " << danoEspecial << " de dano!\n";
    objetivo.setVida(objetivo.getVida() - danoEspecial);
}

void JefeFinal::cambiarFase() {
    if (getVida() < 50 && fase == 1) {
        fase = 2;
        std::cout << nombre << " se sumerge en las sombras y entra en Fase 2!\n";
    }
}
