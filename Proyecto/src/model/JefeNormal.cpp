#include "JefeNormal.h"
#include "Jugador.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

JefeNormal::JefeNormal(const std::string& nombre, int x, int y, int vida, int ataque): Jefe(nombre, x, y, vida, ataque) {
    srand(static_cast<unsigned int>(time(0)));
}


void JefeNormal::atacar(Jugador& objetivo) {
    int chance = rand() % 100;

    if (chance < 5) { // 30% de probabilidad de ataque especial
        habilidadEspecial(objetivo);
    } else {
        std::cout << nombre << " ataca al jugador causando " << ataque << " de daño.";
        objetivo.setVida(objetivo.getVida() - ataque);
    }
}

void JefeNormal::habilidadEspecial(Jugador& objetivo) {
    int danoEspecial = ataque * 1.2;
    std::cout << nombre << " usa su habilidad especial y causa " << danoEspecial << " de daño";
    objetivo.setVida(objetivo.getVida() - danoEspecial);
}
