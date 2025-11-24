//
// Created by Elian on 22/11/2025.
//

#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int vida, int ataque, int defensa)
: Combatiente("Naylo", 'J', vida, ataque, defensa) {}

void Jugador::agregarObjeto(Objeto *objeto) {
    inventario.push_back(objeto);
    std::cout << "Has obtenido: " << objeto->getNombre() << std::endl;
}

void Jugador::mostrarInventario() const {
    std::cout << "----- Inventario -----\n";
    for (int i = 0; i < inventario.size(); i++) {
        std::cout << i << ") " << inventario[i]->getNombre() << std::endl;
    }
}

void Jugador::usarObjeto(int indice) {
    if (indice < 0 || indice >= inventario.size()) {
        return;
    }

    Objeto *objeto = inventario[indice];
    objeto->usar(*this);

    if (objeto->esConsumible()) {
        delete objeto;
        inventario.erase(inventario.begin() + indice);
    }
}

void Jugador::equiparObjeto(int indice) {
    if (indice < 0 || indice >= inventario.size()) {
        return;
    }

    Objeto* obj = inventario[indice];

    if (obj->esEquipable()) {
        obj->usar(*this);
        delete obj;
        inventario.erase(inventario.begin() + indice);
    }
}

void Jugador::recibirCuracion(int cantidad) {
    vida += cantidad;
    if (vida > vidaMax) vida = vidaMax;
    std::cout << nombre << " se cura " << cantidad << " | Vida actual: " << vida << "\n";
}

Jugador::~Jugador() {
    for (auto obj : inventario) {
        delete obj;
    }
    inventario.clear();
}

void Jugador::recibirObjeto(Objeto* obj) {
    inventario.push_back(obj);
}

char Jugador::getSimbolo() const {
    return simbolo;
}


void Jugador::Interactuar() const {} // No hace nada / no implementado de momento / revisar mas adelante

void Jugador::realizarTurno(Combatiente& enemigo) {
    int opcion;

    std::cout << "\n--- Tu turno ---\n";
    std::cout << "1) Atacar\n";
    std::cout << "2) Usar objeto\n";
    std::cout << "Elige una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            atacar(enemigo);
            break;

        case 2: {
            mostrarInventario();
            std::cout << "Indice del objeto: ";
            int i;
            std::cin >> i;
            usarObjeto(i);
            break;
        }

        default:
            std::cout << "Opcion invalida\n";
            break;
    }
}
