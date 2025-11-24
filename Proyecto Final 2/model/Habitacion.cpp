#include "Habitacion.h"
#include <iostream>

Habitacion::Habitacion() : completada(false) {}

void Habitacion::colocarEnemigo(Enemigo *e, int x, int y) {
    e->fijarPos(x, y);
    enemigos.push_back(e);
}

void Habitacion::colocarNPC(NPC *npc, int x, int y) {
    npc->fijarPos(x, y);
    npcs.push_back(npc);
}

void Habitacion::colocarObjeto(Objeto *o, int x, int y) {
    o->fijarPos(x, y);
    objetos.push_back(o);
}

Enemigo *Habitacion::obtenerEnemigo(int x, int y) const {
    for (auto* e : enemigos) {
        if (e->getPosX() == x && e->getPosY() == y && e->estaVivo())
            return e;
    }
    return nullptr;
}

NPC* Habitacion::obtenerNPC(int x, int y) const {
    for (auto* n : npcs) {
        if (n->getPosX() == x && n->getPosY() == y)
            return n;
    }
    return nullptr;
}

Objeto* Habitacion::obtenerObjeto(int x, int y) const {
    for (auto* o : objetos) {
        if (o->getPosX() == x && o->getPosY() == y)
            return o;
    }
    return nullptr;
}

bool Habitacion::estaCompleta() const {
    return completada;
} // revisar

void Habitacion::marcarCompletada() {
    completada = true;
}

void Habitacion::removerObjeto(int x, int y) {
    auto it = objetos.begin();
    while (it != objetos.end()) {
        if ((*it)->getPosX() == x && (*it)->getPosY() == y) {
            it = objetos.erase(it);
            return;
        }
        else {
            it++;
        }
    }
}


void Habitacion::mostrar(const Jugador& jugador) const {
    char matriz[TAM][TAM];

    // Llenar con '.'
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = '.';

    // Jugador
    matriz[jugador.getPosX()][jugador.getPosY()] = jugador.getSimbolo();

    // Enemigos
    for (auto* e : enemigos) {
        if (e->estaVivo())
            matriz[e->getPosX()][e->getPosY()] = e->getSimbolo();
    }

    // NPC
    for (auto* n : npcs) {
        matriz[n->getPosX()][n->getPosY()] = n->getSimbolo();
    }

    // Objetos
    for (auto* o : objetos) {
        matriz[o->getPosX()][o->getPosY()] = o->getSimbolo();
    }

    // Imprimir matriz
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            std::cout << matriz[i][j] << " ";
        std::cout << "\n";
    }
}
