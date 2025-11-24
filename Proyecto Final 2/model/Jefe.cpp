//
// Created by Elian on 23/11/2025.
//

#include "Jefe.h"
#include <iostream>

Jefe::Jefe(const std::string &nombre, char simbolo, int vida, int ataque, int def, Objeto *drop)
: Enemigo(nombre, simbolo, vida, ataque, def, drop),segundaFase(false) {};

void Jefe::activarSegundaFase() {
        segundaFase = true;
        std::cout << getNombre() << "Se sume en la oscuridad" <<std::endl;
        setAtaque(getAtaque() + 10);
        setDefensa(getDefensa() + 5);
};

void Jefe::ataqueEspecial(Combatiente &objetivo) {
    int dano = (ataque * 2) - objetivo.getAtaque();
    if (dano < 0) dano = 0;
    objetivo.recibirDano(dano);
    std::cout << getNombre() << "usa garra infesta y causa"<< dano << " de dano!\n" <<std::endl;
}

void Jefe::recibirObjeto(Objeto* obj) {}
void Jefe::realizarTurno(Combatiente& objetivo) {

    // Esta parte revisa si entra en la segunda fase
    if (!segundaFase && vida < vidaMax * 0.40) {
        activarSegundaFase();
    }

    // Esta parte lanza un numero random que es la probabilidad de que use el ataque especial
    int prob = rand() % 100;

    if (prob < 15) {
        // 15% prob ataque especial
        ataqueEspecial(objetivo);
    } else {
        // Ataque normal
        atacar(objetivo);
    }
}
