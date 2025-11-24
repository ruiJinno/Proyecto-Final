//
// Created by Elian on 24/11/2025.
//

#include "Mapa.h"
#include <iostream>

Mapa::Mapa() : indexHabActual(0), jugador(nullptr) {}

Mapa::~Mapa() {
    for (auto habitacion : habitaciones) {
        delete habitacion;
    }
}

void Mapa::setJugador(Jugador *jugador) {
    this->jugador = jugador;
    if (habitaciones.size() > 0) {
        jugador->fijarPos(0, 0);
    }
}

Jugador* Mapa::getJugador() const {
    return jugador;
}

void Mapa::agregarHabitacion(Habitacion *habitacion) {
    habitaciones.push_back(habitacion);
}

Habitacion* Mapa::getHabitacion() const { // Habitacion actual
    if (indexHabActual < 0 || indexHabActual >= habitaciones.size()) {
        return nullptr;
    }
    return habitaciones[indexHabActual];
}

void Mapa::moverJugador(char tecla) {
    if (!jugador) {
        return;
    }
    Habitacion *habitacion = getHabitacion();
    if (!habitacion) {
        return;
    }
    int jug_x = jugador->getPosX();
    int jug_y = jugador->getPosY();

    switch (tecla) {
        case 'w': case 'W': jug_y--; break;
        case 's': case 'S': jug_y++; break;
        case 'a': case 'A': jug_x--; break;
        case 'd': case 'D': jug_x++; break;

        default:
            std::cout << "Tecla invalida.(1)" << std::endl;
            return;
    }

    if (jug_x < 0 || jug_x >= 3 || jug_y < 0 || jug_y >= 3) {
        std::cout << "Jugada invalida (2)." << std::endl;
        return;
    }

    jugador->fijarPos(jug_x, jug_y);

    // Parte destinada a las interacciones
    if (Enemigo* enemigo = habitacion->obtenerEnemigo(jug_x, jug_y)) {
        Combate::iniciarCombate(*jugador,*enemigo,habitacion,this);
    }
    else if (NPC* Npc = habitacion->obtenerNPC(jug_x, jug_y)) {
        Npc -> Interactuar();
    }
    else if (Objeto* objeto = habitacion->obtenerObjeto(jug_x, jug_y)) {
        jugador->agregarObjeto(objeto);
        habitacion->removerObjeto(jug_x, jug_y);
    }
}

void Mapa::ir_A_sig() {
    int siguiente = indexHabActual + 1;
    if (siguiente >= habitaciones.size()) {
        std::cout << "Has ganado.\n";
        return;
    }

    indexHabActual = siguiente;
    Habitacion* nueva = habitaciones[siguiente];
    jugador->fijarPos(0, 0);
}

